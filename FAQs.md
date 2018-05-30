# Frequently Asked Questions

[Overview](#Overview) 

[Application Market](#Application Market)

[Development Language](#Development Language)

[FPGA](#FPGA)

[FPGA Shell](#FPGA Shell) 

[Troubleshooting](#Troubleshooting)

[High-risk Operations](#High-risk Operations)


## Overview

**Q: What is HDK?**

HDK is short for Hardware Development Kit, including all design files and scripts for RTL (Verilog or VHDL) design, verification, and build.

**Q: What is SDK?**

SDK is short for Software Development Kit, including the drivers, tools, running environment, and applications required for running FPGA instances.


## Application Market
**Q: What is Huawei Cloud FPGA Marketplace?**

FPGA developers can share or sell their AEI files to other FPGA users on the Huawei Cloud FPGA Marketplace. 


## Development Language
**Q: What development languages does Huawei Cloud FPGA support?**

Currently, two types of Huawei Cloud FPGA are available: general-purpose (OpenCL) and high-performance (DPDK). OpenCL is developed by using the C language, and the DPDK is developed by using the Verilog hardware language.


## FPGA
**Q: What is the FPGA model used by Huawei Cloud FPGA?**

Currently, Huawei Cloud FPGA uses Xilinx UltraScale+ series xcvu9p-flgb2104-2-i cards.


## FPGA Shell
**Q: What is Shell?**

Shell is static logic provided by the HDK, including peripheral interfaces such as PCIe and DDR4.

**Q: Does Shell use AXI4 as its interface protocol?**

Currently, Shell uses AXI4, AXI4-Stream, and AXI4-Lite protocols to process different types of data.

## Troubleshooting
**Q: An error message "Current CONFIG_RTE_MAX_MEMSEG=256 is not enough" displayed when I ran the packet sending program packet_process. What do I do?** 

**Causes** 
The huge page allocation fails due to excessive memory fragments. As a result, the number of huge pages is too large, and the DPDK fails to initialize the huge pages. 

**Solution** 
- Run the `sysctl -w vm.nr_hugepages=8192` command to configure huge pages when the system is started and few memory fragments exist. Otherwise, the DPDK fails to initialize huge pages due to excessive memory fragments. 
- Modify the startup parameters of the Linux system on a VM. Add the startup parameters `default_hugepagesz=2M`, `hugepagesz=2M`, and `hugepages=8192` to the grub file. The procedure is as follows: 
  a.	Edit the `/etc/default/grub` file. 
  Set `GRUB_CMDLINE_LINUX="………"` to `GRUB_CMDLINE_LINUX ="……… default_hugepagesz=2M hugepagesz=2M hugepages=8192"`. 
  b.	Update the grub file of the VM. 
  `grub2-mkconfig > /boot/grub2/grub.cfg` 
  c.	Restart the VM.  

**Q: An error message "Cannot init data mbuf pool for port" displayed when I ran the packet sending program packet_process. What do I do?** 

**Symptoms**  
-  When the packet length is long and a large number of queues exist, the default 8192 huge pages are insufficient. As a result, the contiguous memory is insufficient. For example, when the packet length is 1 MB and the number of queues is 8, this problem occurs when you run packet_process.
-  When the packet length is 10 MB, 24576 huge pages are configured, and the contiguous memory is sufficient, this problem occurs when you run packet_process using a single queue. 

**Causes**   
- In the first case, the applied number of huge pages is 8192, and the contiguous physical memory is 16 GB. If the number of queues is too large and the packet length is too long, the total memory required will be greater than 16 GB. As a result, the contiguous memory is insufficient, failing to apply for the mbuf pool.  
- In the second case, fragments are generated in the DPDK contiguous memory during system running. As a result, sufficient 10 MB contiguous memory fails to be obtained during initialization. 

**Solutions** 
-  For the first case:
  a. When the total physical memory is sufficient, apply for a larger number of huge pages. For example, the maximum load (8 queues and 1 MB packet length) needs 24576 huge pages, that is, 48 GB contiguous physical memory. The configuration command is `sysctl -w vm.nr_hugepages=24576`.
  b. Allocate the packet length and the number of queues based on the total capacity of the contiguous memory. If the packet length is long, use a small number of queues to send packets. When you use multiple queues to send packets, do not use long packets. For example, when the packet length is 1 MB, the memory size required by a queue is the memory occupied by BD messages (reserve 1 GB) plus: 

    Packet receiving queue: 1 MB x 2048 bytes. If the FPGA memory manage unit (FMMU) function is used, the value is (1 MB + 32) x 2048 bytes. 
    Packet sending queue: 1 MB x 2048 bytes. If the FMMU function is used, the value is (1 MB + 32) x 2048 bytes. 
  Each queue is about 2 GB. By default, 8192 huge pages are configured when the packet length is 1 MB. That is, 16 GB contiguous physical memory supports only three concurrent queues.  
-  For the second case: 
  Restart the VM, run the `sysctl -w vm.nr_hugepages=24576` command to configure 24576 huge pages, and send packets again. 

**Q: What should I do if the license cache files generated by Vivado have security risks?**

The FPGA design tool Vivado provided by Xilinx checks the license and generates cache files in the following directories:
`/tmp/FLEXnet/` 
`/usr/local/share/macrovision/storage/`
`/usr/local/share/macrovision/storage/FLEXnet`
The cache files have the global write permission. Therefore, the data can be modified and damaged by any user in the system, which may damage the system.

**Solution**
These files are used only when Vivado checks the license, and are generated each time they are used. You are advised to manually or write scripts to delete all files in the preceding three directories each time you use Vivado. Deleting these files does not affect Vivado.

**Q: How can I design high-performance and high-quality code?**

For details about the FPGA development of the high-performance architecture, see the [UltraFast Design Methodology Guide for the Vivado Design Suite](https://www.xilinx.com/support/documentation/sw_manuals/xilinx2018_1/ug949-vivado-design-methodology.pdf).

For details about the FPGA development of the general-purpose architecture, see the [SDAccel Environment Profiling and Optimization Guide](https://www.xilinx.com/support/documentation/sw_manuals/xilinx2017_4/ug1207-sdaccel-optimization-guide.pdf).


## High-risk Operations

**Q: When I pressed Ctrl+C during the execution of xbsk test in OCL SDK, xbsk test failed to be executed again. What do I do?**

This operation is prohibited. Otherwise, reinstall the XDMA driver to rectify the fault.

**Q: When I pressed Ctrl+C during the example execution in OCL SDK, the example failed to be executed again. What do I do?**

This operation is prohibited. Otherwise, use FpgaCmdEntry to manually load the example again to rectify the fault.


