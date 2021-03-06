/*******************************************************************************
Vendor: Xilinx 
Associated Filename: test-cl.c
Purpose: OpenCL Host Code for Matrix Multiply Example
Revision History: July 1, 2013 - initial release
                                                
*******************************************************************************
Copyright (C) 2013 XILINX, Inc.

This file contains confidential and proprietary information of Xilinx, Inc. and 
is protected under U.S. and international copyright and other intellectual 
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials 
distributed herewith. Except as otherwise provided in a valid license issued to 
you by Xilinx, and to the maximum extent permitted by applicable law: 
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX 
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, 
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR 
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether 
in contract or tort, including negligence, or under any other theory of 
liability) for any loss or damage of any kind or nature related to, arising under 
or in connection with these materials, including for any direct, or any indirect, 
special, incidental, or consequential loss or damage (including loss of data, 
profits, goodwill, or any type of loss or damage suffered as a result of any 
action brought by a third party) even if such damage or loss was reasonably 
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any 
application requiring fail-safe performance, such as life-support or safety 
devices or systems, Class III medical devices, nuclear facilities, applications 
related to the deployment of airbags, or any other applications that could lead 
to death, personal injury, or severe property or environmental damage 
(individually and collectively, "Critical Applications"). Customer assumes the 
sole risk and liability of any use of Xilinx products in Critical Applications, 
subject only to applicable laws and regulations governing limitations on product 
liability. 

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT 
ALL TIMES.

*******************************************************************************/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <CL/opencl.h>

////////////////////////////////////////////////////////////////////////////////

// Use a static matrix for simplicity
//
#define MATRIX_RANK 16
#define DATA_SIZE MATRIX_RANK*MATRIX_RANK

////////////////////////////////////////////////////////////////////////////////

int
load_file_to_memory(const char *filename, char **result)
{ 
    size_t size = 0;
    FILE *f = fopen(filename, "rb");
    if (f == NULL) 
        { 
            *result = NULL;
            return -1; // -1 means file opening fail 
        } 
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    *result = (char *)malloc(size+1);
    if (size != fread(*result, sizeof(char), size, f)) 
        { 
            free(*result);
            return -2; // -2 means file reading fail 
        } 
    fclose(f);
    (*result)[size] = 0;
    return size;
}

int main(int argc, char** argv)
{
#if defined(SDX_PLATFORM) && !defined(TARGET_DEVICE)
  #define STR_VALUE(arg)      #arg
  #define GET_STRING(name) STR_VALUE(name)
  #define TARGET_DEVICE GET_STRING(SDX_PLATFORM)
#endif
    //TARGET_DEVICE macro needs to be passed from gcc command line
    const char *target_device_name = TARGET_DEVICE;

    int err;                            // error code returned from api calls
     
    int a[DATA_SIZE];                   // original data set given to device
    int b[DATA_SIZE];                   // original data set given to device
    int results[DATA_SIZE];             // results returned from device
    int sw_results[DATA_SIZE];          // results returned from device
    unsigned int correct;               // number of correct results returned
#ifndef C_KERNEL

    size_t global[2];                   // global domain size for our calculation
    size_t local[2];                    // local domain size for our calculation
#endif

    cl_platform_id platforms[16];       // platform id
    cl_platform_id platform_id;         // platform id
    cl_uint platform_count;
    cl_device_id device_id;             // compute device id 
    cl_context context;                 // compute context
    cl_command_queue commands;          // compute command queue
    cl_program program;                 // compute program
    cl_kernel kernel;                   // compute kernel
   
    char cl_platform_vendor[1001];
   
    cl_mem input_a;                     // device memory used for the input array
    cl_mem input_b;                     // device memory used for the input array
    cl_mem output;                      // device memory used for the output array
   
    if (argc != 2){
        printf("%s <inputfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Fill our data sets with pattern
    //
    int i = 0;
    for(i = 0; i < DATA_SIZE; i++) {
        a[i] = (int)i;
        b[i] = (int)i;
        results[i] = 0;
    }

    // 
    // Get all platforms and then select Xilinx platform
    err = clGetPlatformIDs(16, platforms, &platform_count);
    if (err != CL_SUCCESS)
        {
            printf("Error: Failed to find an OpenCL platform!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }
    printf("INFO: Found %d platforms\n", platform_count);

    // Find Xilinx Plaftorm
    int platform_found = 0;
    for (unsigned int iplat=0; iplat<platform_count; iplat++) {
        err = clGetPlatformInfo(platforms[iplat], CL_PLATFORM_VENDOR, 1000, (void *)cl_platform_vendor,NULL);
        if (err != CL_SUCCESS) {
            printf("Error: clGetPlatformInfo(CL_PLATFORM_VENDOR) failed!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }
        if (strcmp(cl_platform_vendor, "Xilinx") == 0) {
            printf("INFO: Selected platform %d from %s\n", iplat, cl_platform_vendor);
            platform_id = platforms[iplat];
            platform_found = 1;
        }
    }
    if (!platform_found) {
        printf("ERROR: Platform Xilinx not found. Exit.\n");
        return EXIT_FAILURE;
    }
  
    // Connect to a compute device
    // find all devices and then select the target device
    cl_device_id devices[16];  // compute device id 
    cl_uint device_count = 0;
    unsigned int device_found = 0;
    char cl_device_name[1001];
    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR,
                         16, devices, &device_count);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to create a device group!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    //iterate all devices to select the target device. 
    for (int i=0; i < (int)device_count; i++) {
        err = clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 1024, cl_device_name, 0);
        if (err != CL_SUCCESS) {
            printf("Error: Failed to get device name for device %d!\n", i);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }
        //printf("CL_DEVICE_NAME %s\n", cl_device_name);
        if(strcmp(cl_device_name, target_device_name) == 0) {
            device_id = devices[i];
            device_found = 1;
            printf("INFO: Selected %s as the target device\n", cl_device_name);
        }
    }
    
    if (!device_found) {
        printf("ERROR: Target device %s not found. Exit.\n", target_device_name);
        return EXIT_FAILURE;
    }


    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR,
                         1, &device_id, NULL);
    if (err != CL_SUCCESS)
        {
            printf("Error: Failed to create a device group!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }
  
    // Create a compute context 
    //
    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (!context)
        {
            printf("Error: Failed to create a compute context!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Create a command commands
    //
    commands = clCreateCommandQueue(context, device_id, 0, &err);
    if (!commands)
        {
            printf("Error: Failed to create a command commands!\n");
            printf("Error: code %i\n",err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    int status;

    // Create Program Objects
    //
  
    // Load binary from disk
    unsigned char *kernelbinary;
    char *xclbin=argv[1];
    printf("INFO: Loading %s\n", xclbin);
    int n_i = load_file_to_memory(xclbin, (char **) &kernelbinary);
    if (n_i < 0) {
        printf("failed to load kernel from xclbin: %s\n", xclbin);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
    size_t n = n_i;
    // Create the compute program from offline
    program = clCreateProgramWithBinary(context, 1, &device_id, &n,
                                        (const unsigned char **) &kernelbinary, &status, &err);
    if ((!program) || (err!=CL_SUCCESS)) {
        printf("Error: Failed to create compute program from binary %d!\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Build the program executable
    //
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS)
        {
            size_t len;
            char buffer[2048];

            printf("Error: Failed to build program executable!\n");
            clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
            printf("%s\n", buffer);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Create the compute kernel in the program we wish to run
    //
    kernel = clCreateKernel(program, "mmult", &err);
    if (!kernel || err != CL_SUCCESS)
        {
            printf("Error: Failed to create compute kernel!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Create the input and output arrays in device memory for our calculation
    //
    input_a = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(int) * DATA_SIZE, NULL, NULL);
    input_b = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(int) * DATA_SIZE, NULL, NULL);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE, NULL, NULL);
    if (!input_a || !input_b || !output)
        {
            printf("Error: Failed to allocate device memory!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }    
    
    // Write our data set into the input array in device memory 
    //
    err = clEnqueueWriteBuffer(commands, input_a, CL_TRUE, 0, sizeof(int) * DATA_SIZE, a, 0, NULL, NULL);
    if (err != CL_SUCCESS)
        {
            printf("Error: Failed to write to source array a!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Write our data set into the input array in device memory 
    //
    err = clEnqueueWriteBuffer(commands, input_b, CL_TRUE, 0, sizeof(int) * DATA_SIZE, b, 0, NULL, NULL);
    if (err != CL_SUCCESS)
        {
            printf("Error: Failed to write to source array b!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }
    
    // Set the arguments to our compute kernel
    //
    err = 0;
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &input_a);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &input_b);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &output);
    if (err != CL_SUCCESS)
        {
            printf("Error: Failed to set kernel arguments! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Execute the kernel over the entire range of our 1d input data set
    // using the maximum number of work group items for this device
    //

#ifdef C_KERNEL
    err = clEnqueueTask(commands, kernel, 0, NULL, NULL);
#else
    global[0] = MATRIX_RANK;
    global[1] = MATRIX_RANK;
    local[0] = MATRIX_RANK;
    local[1] = MATRIX_RANK;
    err = clEnqueueNDRangeKernel(commands, kernel, 2, NULL, 
                                 (size_t*)&global, (size_t*)&local, 0, NULL, NULL);
#endif
    if (err)
        {
            printf("Error: Failed to execute kernel! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Read back the results from the device to verify the output
    //
    cl_event readevent;
    err = clEnqueueReadBuffer( commands, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE, results, 0, NULL, &readevent );  
    if (err != CL_SUCCESS)
        {
            printf("Error: Failed to read output array! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    clWaitForEvents(1, &readevent);
    
    printf("A\n");
    for (i=0;i<DATA_SIZE;i++) {
        printf("%x ",a[i]);
        if (((i+1) % 16) == 0)
            printf("\n");
    }
    printf("B\n");
    for (i=0;i<DATA_SIZE;i++) {
        printf("%x ",b[i]);
        if (((i+1) % 16) == 0)
            printf("\n");
    }
    printf("res\n");
    for (i=0;i<DATA_SIZE;i++) {
        printf("%x ",results[i]);
        if (((i+1) % 16) == 0)
            printf("\n");
    }
    
    // Validate our results
    //
    correct = 0;
    for(i = 0; i < DATA_SIZE; i++)
        {
            int row = i/MATRIX_RANK;
            int col = i%MATRIX_RANK;
            int running = 0;
            int index;
            for (index=0;index<MATRIX_RANK;index++) {
                int aIndex = row*MATRIX_RANK + index;
                int bIndex = col + index*MATRIX_RANK;
                running += a[aIndex] * b[bIndex];
            }
            sw_results[i] = running;
        }
    
    for (i = 0;i < DATA_SIZE; i++) 
        if(results[i] == sw_results[i])
            correct++;
    printf("Software\n");
    for (i=0;i<DATA_SIZE;i++) {
        printf("%x ",sw_results[i]);
        if (((i+1) % 16) == 0)
            printf("\n");
    }
    
    
    // Print a brief summary detailing the results
    //
    printf("Computed '%d/%d' correct values!\n", correct, DATA_SIZE);
    
    // Shutdown and cleanup
    //
    clReleaseMemObject(input_a);
    clReleaseMemObject(input_b);
    clReleaseMemObject(output);
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(commands);
    clReleaseContext(context);

    if(correct == DATA_SIZE){
        printf("Test passed!\n");
        return EXIT_SUCCESS;
    }
    else{
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
}

// XSIP watermark, do not delete 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
