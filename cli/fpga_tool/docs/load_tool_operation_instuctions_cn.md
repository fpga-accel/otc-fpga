FPGA镜像加载工具使用说明
===================================
[Switch to the English version](./load_tool_operation_instuctions.md)

FPGA镜像加载工具FpgaCmdEntry，是一款linux系统中的命令行工具。用户需要传入指定的操作码以及参数来实现相应的功能。

命令格式为：**FpgaCmdEntry 操作码 -参数**

其中操作码具体指：DF（查询虚拟机FPGA设备）、LF（加载镜像到FPGA）、IF（查询FPGA卡镜像状态信息）、SF（查询FPGA卡告警信息）、CF（清除FPGA卡镜像）、IL（查询虚拟点灯状态）、IV（查询工具版本号信息）。

工具帮助信息
-------------------------
### 命令功能

查询当前工具支持的命令。

### 命令格式

**FpgaCmdEntry -?**

**FpgaCmdEntry -h**

### 参数说明

None

查询虚拟机FPGA设备方法
----------------------------
### 命令功能

查询用户虚拟机上所有的FPGA卡信息（包含type、slot、DBDF、vendor id、device id）。

### 命令格式

**FpgaCmdEntry DF -D**

**FpgaCmdEntry DF -?**

**FpgaCmdEntry DF -h**

### 参数说明

| 参数       | 参数说明                      |
|-----------|-----------------------------------|
|   -D      | 显示FPGA设备信息。    |
|   -?      | 显示帮助信息。        |
|   -h      | 显示帮助信息。        |

加载镜像到FPGA方法
--------------------------------
### 命令功能

将指定编号的FPGA镜像加载到指定槽位的FPGA，用户需要传入槽位信息以及FPGA镜像编号信息。

### 命令格式

**FpgaCmdEntry LF -S** *FPGA槽位号* **-I** *FPGA镜像编号*

**FpgaCmdEntry LF -?**

**FpgaCmdEntry LF -h**

### 参数说明

| 参数       | 参数说明                                                                                                                                 |
|-----------|--------------------------------------------------------------------------------------------------|
| -S        | 被加载FPGA的槽位号，通过执行**FpgaCmdEntry DF -D**得到，范围0~7。 |
| -I        | 用户的FPGA镜像编号。                                                                                                                 |
| -?        | 显示帮助信息。                                                                                                                 |
| -h        | 显示帮助信息。                                                                                                                |

查询FPGA卡镜像状态方法
-----------------------------------------
### 命令功能

查询指定槽位的FPGA镜像加载状态，用户需要传入槽位信息。

### 命令格式

**FpgaCmdEntry IF -S** *FPGA槽位号*

**FpgaCmdEntry IF -?**

**FpgaCmdEntry IF -h**

### 参数说明

| 参数       | 参数说明                                                                                                                                |
|-----------|----------------------------------------------------------------------------------------------------------------------------------------------|
|  -S       | 需要查询的FPGA的槽位号，通过执行**FpgaCmdEntry DF -D**得到，范围0~7。 |
|  -?       | 显示帮助信息。                                                                                                                  |
|  -h       | 显示帮助信息。                                                                                                                 |
查询FPGA卡告警信息方法
--------------------------------
### 命令功能

查询指定槽位的FPGA卡记录等级告警信息，告警寄存器值和告警错误码。

### 命令格式

**FpgaCmdEntry SF -T** *信息类型* **-L** *告警级别* **-S** *FPGA槽位号*

**FpgaCmdEntry SF -?**

**FpgaCmdEntry SF -h**

### 参数说明

| 参数       | 参数说明                                                                                        |
|-----------|--------------------------------------------------------------------------------------------------|
| -T        | 查询信息类型，0代表告警信息，当前只支持0。                                               |         
| -L        | 告警级别类型，0代表所有支持级别告警，1代表记录级别告警，2代表器件故障级别告警。                   |         
| -S        | 被加载FPGA的槽位号，通过执行**FpgaCmdEntry DF -D**得到，范围0~7。                                |                                                                                                                
| -?        | 显示帮助信息。                                                                                   |
| -h        | 显示帮助信息。                                                                                   |

fp1 告警错误码，请参考 [DPDK 告警列表](fp1_dpdk_alarm_code_reference.md) 和 [OCL 告警列表](fp1_ocl_alarm_code_reference.md) 的说明。 

fc1 告警错误码，请参考 [OCL 告警列表](fc1_ocl_alarm_code_reference.md) 的说明。

清除FPGA卡镜像方法
--------------------------------
### 命令功能

清除指定槽位的FPGA卡镜像，用户需要传入槽位信息。

### 命令格式

**FpgaCmdEntry CF -S** *FPGA槽位号*

**FpgaCmdEntry CF -?**

**FpgaCmdEntry CF -h**

### 参数说明

| 参数       | 参数说明                                                                                                                                 |
|-----------|--------------------------------------------------------------------------------------------------|
| -S        | 被加载FPGA的槽位号，通过执行**FpgaCmdEntry DF -D**得到，范围0~7。 |                                                                                                                
| -?        | 显示帮助信息。                                                                                                                 |
| -h        | 显示帮助信息。                                                                                                                |

查询虚拟点灯状态方法
-------------------------------
### 命令功能

查询指定槽位的FPGA点灯状态，用户需要传入槽位信息。

### 命令格式

**FpgaCmdEntry IL -S** *FPGA槽位号*

**FpgaCmdEntry IL -?**

**FpgaCmdEntry IL -h**

### 参数说明

| 参数      | 参数说明                                                                                                                                 |
|-----------|----------------------------------------------------------------------------------------------------------------------------------------------|
|   -S      | 需要查询的FPGA的槽位号，通过执行**FpgaCmdEntry DF -D**得到，范围0~7。  |
|   -?      | 显示帮助信息。                                                                                                                   |
|   -h      | 显示帮助信息。                                                                                                                  |

查询工具版本号方法
-------------------------
### 命令功能

查询当前的工具的版本号。

### 命令格式

**FpgaCmdEntry IV**

### 参数说明

None



\----End