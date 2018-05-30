# Release 1.0.0
- This is the first public version of the OTC FPGA design instance. For details about its functions, see **FPGA Design Instance Feature Overview** and **FPGA Design Instance Feature Description**.

---
# FPGA Design Instance Feature Overview

* Interfaces available for FPGA users are as follows:
  - `One PCIe Gen3 x16` interface    
  - `Four DDR4` RDIMM interfaces

* PCIe features are as follows:
  - `One physical function (PF)`
  - `One virtual function (VF)`
  - `Eight` queues for each VF  

* Interface features supported between user logic and static logic are as follows:
  - The DMA data channel from static logic to user logic uses the AXI4-Stream interface with a bit width of `512 bits`.
  - The DMA data channel from user logic to static logic uses the AXI4-Stream interface with a bit width of `512 bits`.
  - The DMA buffer description (BD) channel from static logic to user logic uses the AXI4-Stream interface with a bit width of `256 bits`.
  - The DMA BD channel from user logic to static logic uses the AXI4-Stream interface with a bit width of `256 bits`.
  - The register access and BAR space mapping use the AXI4-Lite interface.
  - DDRs use the AXI4 interface with a bit width of `512 bits`.

* The DDR interface partition is as follows:
  - One DDR controller is placed in the static logic partition.
  - Three DDR controllers are placed in the user logic partition.
  - A maximum of four DDR controllers can be used.


---
# FPGA Design Instance Feature Description

# Contents

## 1 [Project Building](#Project Building)
## 2 [User Simulation](#User Simulation)
## 3 [Application Tests](#Application Tests)
## 4 [Tools and Environment](#Tools and Environment)
## 5 [License Requirements](#License Requirements)
## 6 [Features To Be Supported](#Features To Be Supported)
***
<a name="Project Building"></a>
# Project Building

## Overview
Before building a project, `ensure that Vivado and license are installed`. Project building aims to design a project that meets the timing requirements through the minimum modification.

## Features

* Vivado and SDAccel designs

* `VHDL and Verilog` coding

* `OpenCL, C, and C++` coding

* `Automatic scanning and encryption` of VHDL, Verilog, OpenCL, C, C++, and SystemVerilog code

* User configuration and command execution decoupling. To build a project, you only need to `define the project name and path`.

* Flexible configuration and selection of all Vivado synthesis policies. Available synthesis policies are as follows:
  - DEFAULT
  - AreaOptimized_high
  - AreaOptimized_medium
  - AreaMultThresholdDSP
  - AlternateRoutability
  - PerfOptimized_high
  - PerfThresholdCarry
  - RuntimeOptimized

* Flexible configuration of all Vivado implementation policies. Available implementation policies are as follows:
  - DEFAULT
  - Explore
  - ExplorePostRoutePhysOpt
  - WLBlockPlacement
  - WLBlockPlacementFanoutOpt
  - NetDelay_high
  - NetDelay_low
  - Retiming
  - ExtraTimingOpt
  - RefinePlacement
  - SpreadSLLs
  - BalanceSLLs
  - SpreadLogic_high
  - SpreadLogic_medium
  - SpreadLogic_low
  - SpreadLogic_Explore
  - SSI_SpreadLogic_high
  - SSI_SpreadLogic_low
  - SSI_SpreadLogic_Explore
  - Area_Explore
  - Area_ExploreSequential
  - Area_ExploreWithRemap
  - Power_DefaultOpt
  - Power_ExploreArea
  - Flow_RunPhysOpt
  - Flow_RunPostRoutePhysOpt
  - Flow_RuntimeOptimized
  - Flow_Quick

* Automatic timing report checking and check result printing after project building

* IP customizing by using Vivado IP catalog

* PR verification

* `Execution in steps` for synthesis, implementation, PR verification, and target file generation

* `Scheduled execution` of projects

* Automatic scanning of user code, Huawei IP, and Xilinx IP

* `One-click` user directory creation

* MD5 verification of shell


## Features To Be Optimized
 * None


## Known Issues
 * None

---

<a name="User Simulation"></a>

# User Simulation

## Overview
Before executing a project, ensure that `Vivado and license are installed`. User simulation aims to verify whether the existing designs are as required through the verification platform.

## Features

* `Standard SystemVerilog 2012 syntax` supported in Testbench

* Code coverage collection and report generation
  - Customizable code coverage collection files

* AXI4 and AXI4-Lite verification features
  - `burstlen` of the AXI4 interface supported `from 1 to 255`
  - `outstanding` feature of the AXI4 AW and AR channels
  - Consistency check of the `burst` length and the actual length
  - Coverage collection based on the AXI4 and AXI4-Lite protocols
  - Assertion check based on the AXI4 and AXI4-Lite protocols

* Customizable incentives
  - Customizable incentives based on configuration files
  - Incentive generating and sending by users

* Customizable callback methods
  - Customizable callback task/function (Modifying Testbench is not needed.)

* Decoupling of Testbench and Testcase
  - `Testcase design and implementation without modifying Testbench`

* Simple Scoreboard
  - Basic packet comparison based on `stream_id` and `fsn`

* Function coverage collection and report generation
  - Function coverage based on the AXI4 and AXI4-Lite interfaces
  - A function coverage of `burst_len, burst_size, burst_mode, and strobe`

* Interface assertion
  - Assertion based on the `AXI4 and AXI4-Lite interfaces`
  - Assertion covering the X/Z status check

* Debugging tools
  - `Verdi, DVE, QuestaSim, and Vivado` for debugging

* Precompiling Xilinx simulation libraries
  - `unisims`, `unimacro`, `secureip`, and more provided to improve the speed of simulation compilation


## Features To Be Optimized
* C and C++

## Known Issues
* None

---


<a name="Application Tests"></a>

# Application Tests

## Overview

In the `fpga_design/software/` directory, there is an application project subdirectory. You can compile an application project by using script code (applications) to test features or functions of the project. For details, see `readme` in the `fpga_design/software/` directory.

## Features To Be Optimized

* None

## Known Issues
* None

---

<a name="Tools and Environment"></a>

# Tool and Environment

* The supported tool and environment are as follows:
  - Linux `CentOS 7.3`
  - Xilinx `Vivado 2017.2` 

---

<a name="License Requirements"></a>

# License Requirements
* The required licenses are as follows:      
  - Xilinx Vivado 2017.2   
  - encryption tool  Version 2  

---
<a name="Features To Be Supported"></a>

# Features To Be Supported
* Peer-to-peer
