Implementation Process of SDAccel-Based Hardware Development
=======================

**Notes**
After the SDX tool is installed, you need to delete the corresponding installation package to free hard disk space.

Contents
-------------------------

[SDAccel-Based Operation Process](#sec-1)

[Configuring the Development Environment](#sec-2)

[Creating a User Project](#sec-3)

[Implementing SDAccel-Based Development](#sec-4)

[Implementing SDAccel-Based Simulation](#sec-5)

[Configuring a Project](#sec-6)

[Version Compilation](#sec-7)


<a id="sec-1" name="sec-1"></a>

SDAccel-Based Operation Process
-------------------------

The compilation and execution processes of the SDAccel platform are based on the SDx tool compilation environment and the execution environment that supports FPGA cards.

**Notes**

SDAccel compilation environment and execution environment can be deployed on the same VM.

The SDAccel platform provides two methods for creating a project.

-   Create a project and upload user-developed code to the compilation environment, or develop code on the platform to meet user requirements.

-   Copy an example project, modify parameters, and add user code to meet user requirements.


### User Operation Process

User operation processes include the simulation development process and the hardware development process.

#### Simulation Development Process

![](media/hdk_st.jpg)

#### Hardware Development Process

![](media/SDAccel_example.jpg)

#### The following table describes each step of the user operation process.

| Procedure                                | Operation                                | Description                              |
| ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| Go to the compilation environment.       | Go to the compilation environment in which SDx is installed. | Go to the compilation environment in which SDx is installed. |
| Develop code.                            | Develop code.                            | Develop host and kernel code based on user requirements. SDAccel supports C/C++ for host code development and C/C++/OpenCl C/Verilog/VHDL for kernel code development. The source files must be stored in the **src** folder in the directory where the user project is located. |
| Configure the development environment.   | Configure the hardware development environment. | Configure and run the **setup.cfg** script to configure the hardware development environment. |
| Create a user project.                   | Create a user project.                   | Run a command to create a user project in one-click mode. |
| Compile source files.                    | Compile source files.                    | After the project configuration is complete, run the **compile.sh** script to compile, link, and generate the host program, and to compile the kernel, implement synthesis, placing, and routing, and generate target files. |
| Generate target files.                   | Generate target files.                   | The generated target files are stored in the **/prj/bin/** directory. |
| Modify configuration files.              | Modify configuration files according to README.md. | Modify configuration files of AEI_Regsiter.sh and fisclient before registering an image. |
| Register an image.                       | Register an SDAccel image.               | Use AEI_Regsiter.sh to register an SDAccel image with the SDAccel image management module. After the registration, an ID is assigned to the SDAccel image. |
| Check the image registration status.     | Check whether the SDAccel image is successfully registered. | Use the image ID to check whether the SDAccel image is successfully registered. |
| Go to the execution environment.         | Go to the hardware test environment.     | Go to the hardware test environment.     |
| Develop host code.                       | Develop host code.                       | Develop host code before performing the hardware test. |
| Copy the .xclbin file to the execution environment. | Copy the compiled .xclbin file from the compilation environment to the target directory in the execution environment. | Copy the compiled .xclbin file from the compilation environment to the target directory in the execution environment. |
| Run the host program.                    | Run the host program.                    | Perform the hardware test.               |


<a id="sec-2" name="sec-2"></a>
Configuring the Development Environment
------------

The SDAccel is stored in the `otc-fpga/fp1` directory on a VM by default. Configure the hardware development environment before SDAccel development.

#### Step 1 Configure the EDA tool mode.

Open the **setup.cfg** file in the **otc-fpga/fp1/** directory, and set `FPGA_DEVELOP_MODE` to the required FPGA development tool.

To use SDAccel as a development tool, set the parameter as follows:

`FPGA_DEVELOP_MODE="sdx"`

**Note**
The default development tool is sdx.

#### Step 2 Configure the license file of EDA.

Set `XILINX_LIC_SETUP` in the setup.cfg file to the IP address of the license server.

```bash
XILINX_LIC_SETUP="2100@fpga-lic.eu-de.otc.t-systems.com"
```


#### Step 3 Configure the version of EDA.

Set `VIVADO_VER_REQ` in the `setup.cfg` file to the version of the selected tool.

To use SDAccel as a development tool, set the parameter of `VIVADO_VER_REQ` as follows:
```bash
VIVADO_VER_REQ="2017.4.op"
```

#### Step 4 Set the software installation path

The software installation path is stored in the `/software` folder by default. 
If you do not install the relevant software under this folder, you need to modify the `SOFT_INSTALL_DIR` parameter in the `setup.cfg` file for the user to install the tool path.

```bash
SOFT_INSTALL_DIR="/software"
```

**Notes**
The default development tool version is 2017.4.op.

Only user **root** has the right to use the Xilinx license file.

#### Step 4 Complete the development environment configuration.

Run the `setup.sh` script to configure the hardware development environment.

```bash
cd otc-fpga/fp1  
export HW_FPGA_DIR=$(pwd) 
source $HW_FPGA_DIR/setup.sh
```

**Note**
You can copy all the files of SDAccel to any directory on a VM. The following sections use the default directory as an example.
The fisclient tool must be installed before executing the `setup.sh` script。

<a id="sec-3" name="sec-3"></a>
Creating a User Project
------------

By default, user projects are stored in the `$HW_FPGA_DIR/hardware/sdacel_design/user` directory. Run the `create_prj.sh` script to create a project.

```bash
cd $HW_FPGA_DIR/hardware/sdaccel_design/user 
sh create_prj.sh <usr_prj_name> <kernel_mode>
```

**Note**
usr_prj_name is the user project name and is specified when users create a project. kernel_mode is the user project type, and users can select `temp_cl, temp_c, or temp_rtl`. For details, see `$HW_FPGA_DIR/hardware/sdacel_design/user/README.md`.

<a id="sec-4" name="sec-4"></a>
Implementing SDAccel-Based Development
-----------
1. SDAccel supports OpenCL/C/Verilog/VHDL for kernel development. The source files must be stored in the `$HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/src` directory of the `<usr_prj_name>` directory.
2. After the compilation is complete, modify the Makefile in the `$HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/src` directory of `<usr_prj_name>`, and modify variables `HOST_EXE=User host program name` and `KERNEL_NAME=Kernel name compiled by the user`.
3. After the Makefile is modified, go to the `$HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/scripts/` directory and run `sh compile.sh hw` to complete the compilation and generate the executable files of the host program and the .xclbin file.

**Note**
The name of kernel compiled by users must be the same as the name of the kernel module.  

**Each compilation clears the previously compiled contents. Back up the compiled files before a new compilation.**

<a id="sec-5" name="sec-5"></a>
Implementing SDAccel-Based Simulation
-----------

SDAccel supports the cpu-emulation and hw-emulation simulation modes.

#### Step 1 Develop host and kernel code.

```bash
cd $HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/src
```

The code must be stored in the **src** directory.

#### Step 2 Configure compilation scripts.

```bash
cd $HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/src
```
Configure host and kernel names in the Makefile file.

#### Step 3 Implement simulation compilation.

```bash
cd $HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/scripts  
sh compile.sh <emulation_mode>
```

#### Step 4 Implement the simulation.

```bash
cd $HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/scripts  
sh run.sh emu ../prj/bin/<example_host> ../prj/bin/<xclbin>
```

**Note**
For details about how to implement the simulation, see `HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/README.md`.

<a id="sec-6" name="sec-6"></a>
Configuring a Project
--------

SDAccel supports one-click project building. Modify the `Makefile` file in the `$HW_FPGA_DIR/hardware/SDAccel_design/user/<usr_prj_name>/src/` directory to configure a project.

#### The configuration items include:

-   Host name

-   Kernel name

<a id="sec-7" name="sec-7"></a>
Version Compilation
------------

Run the `compile.sh` script to compile, link, and generate the host program, and to compile the kernel, implement synthesis, placing, and routing, and generate the target file.

```bash
cd $HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/scripts/ 
sh compile.sh hw
```

**Note**
For details, see `HW_FPGA_DIR/hardware/sdaccel_design/user/<usr_prj_name>/README.md`.  

**Each compilation clears the previously compiled contents. Back up the compiled files before a new compilation.**






