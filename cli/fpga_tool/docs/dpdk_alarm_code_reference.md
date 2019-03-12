| 错误码 |寄存器名称|寄存器基址|寄存器说明|寄存器偏移|告警名称|描述|
| ----- | ------- :  | ------- :  | : ----------------  : | : ---------------- : | :------: | :------: |
| 7000 | reg_clkm_err | 0x2080 | 时钟丢失告警 | 15 | mmcm_lock_err | mmcm_sys失锁告警 |
| 7013 | reg_clkm_err | 0x2080 | 时钟丢失告警 | 2 | clk_ddrc_err | ddrc时钟丢失告警 |
| 7014 | reg_clkm_err | 0x2080 | 时钟丢失告警 | 1 | clk_pcie_err | pcie 250M时钟丢失告警 |
| 7015 | reg_clkm_err | 0x2080 | 时钟丢失告警 | 0 | clks_err | clks丢失告警   |
| 7040 | reg_parrlt_err | 0x44080 | rxm接收处理解析报文处理告警寄存器 | 7 | reg_axi_err | axi接口异常告警 |
| 7041 | reg_parrlt_err | 0x44080 | rxm接收处理解析报文处理告警寄存器 | 6 | reg_axi_dis_pkt | axi接口丢包告警 |
| 7043 | reg_parrlt_err | 0x44080 | rxm接收处理解析报文处理告警寄存器 | 4 | bd_outtime_dis | bd查询空闲地址超时丢弃的报文告警 |
| 7044 | reg_parrlt_err | 0x44080 | rxm接收处理解析报文处理告警寄存器 | 3 | reg_mode_err | 接收ae非尾拍报文mode位非0告警 |
| 7045 | reg_parrlt_err | 0x44080 | rxm接收处理解析报文处理告警寄存器 | 2 | vf_err_dis | 接收到队列大于15的报文的告警 |
| 7046 | reg_parrlt_err | 0x44080 | rxm接收处理解析报文处理告警寄存器 | 1 | rst_dis | 队列复位丢弃告警 |
| 7047 | reg_parrlt_err | 0x44080 | rxm接收处理解析报文处理告警寄存器 | 0 | overlong_err | 超长帧告警 |
| 7071 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 8 | bd_outtime_dis0 | bd查询空闲地址超时首次丢弃告警 |
| 7072 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 7 | reg_len_err | 接收到报文长度大于4096的告警 |
| 7073 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 6 | reg_des_addr_err | 接收到dma目的地址为0的告警 |
| 7074 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 5 | rx_bd_dis | 前级bd写丢告警 |
| 7075 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 4 | bd_outtime_dis1 | bd查询空闲地址超时后连续丢弃告警 |
| 7076 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 3 | bd_outtime_err | bd查询空闲地址超时告警 |
| 7077 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 2 | addr_not_enough_err | 缺少空闲地址告警 |
| 7078 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 1 | rspbd_rxff_ovf | respond bd接收fifo上溢告警 |
| 7079 | reg_rspbd_err | 0x44081 | rxm接收处理响应BD告警寄存器 | 0 | rspbd_rxff_unf | respond bd接收fifo下溢告警 |
| 7080 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 31 | rxqm2dmae_txffc_prty_err | rxqm2dmae_txffc奇偶校验错误 |
| 7081 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 30 | rxm_lenerr | rxm长度错误 |
| 7082 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 29 | dram_rd_underflow | rxm RAM读下溢告警 |
| 7083 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 28 | rxm_bram_len_eop_err | RXM payload Cfifo BRAM长度EOP不匹配告警 |
| 7084 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 27 | rxm_bram_wptr_err | rxm payload BRAM写地址不连续告警 |
| 7085 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 26 | rxm_drop_err | 前级RXM err标签丢弃告警 |
| 7090 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 21 | txqm2dmae_ptr_txffd_rerr | txqm2dmae_ptr_txffd_rerr下溢 |
| 7091 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 20 | txqm2dmae_ptr_txffd_werr | txqm2dmae_ptr_txffd_werr上溢 |
| 7094 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 17 | txqm2dmae_txffc_rerr | txqm2dmae_txffc_rerr下溢 |
| 7095 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 16 | txqm2dmae_txffc_werr | txqm2dmae_txffc_werr上溢 |
| 7096 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 15 | txm2dmae_txffc_rerr | txm2dmae_txffc_rerr下溢 |
| 7097 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 14 | txm2dmae_txffc_werr | txm2dmae_txffc_werr上溢 |
| 7098 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 13 | rxqm2dmae_txffc_rerr | rxqm2dmae_txffc_rerr下溢 |
| 7099 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 12 | rxqm2dmae_txffc_werr | rxqm2dmae_txffc_werr上溢 |
| 7100 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 11 | rxm2dmae_txffc_rerr | rxm2dmae_txffc_rerr下溢 |
| 7101 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 10 | rxm2dmae_txffc_werr | rxm2dmae_txffc_werr上溢 |
| 7102 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 9 | rxm2dmae_ptr_txffd_rerr | rxm2dmae_ptr fifo下溢 |
| 7103 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 8 | rxm2dmae_ptr_txffd_werr | rxm2dmae_ptr fifo上溢 |
| 7106 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 5 | route2dmae_cfifo_overflow | route2dmae_cfifo上溢 |
| 7107 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 4 | route2dmae_cfifo_underflow | route2dmae_cfifo下溢 |
| 7110 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 1 | route2dmae_dfifo_overflow | route2dmae_dfifo上溢 |
| 7111 | reg_dmae_0err | 0x40080 | dmae err0告警寄存器 | 0 | route2dmae_dfifo_underflow | route2dmae_dfifo下溢 |
| 7112 | reg_dmae_1err | 0x40081 | dmae err1告警寄存器 | 5 | txqm2dmae_ptr_txffc_prty_err | txqm2dmae_ptr_txffc奇偶校验错误 |
| 7113 | reg_dmae_1err | 0x40081 | dmae err1告警寄存器 | 4 | txqm2dmae_ptr_dram_prty_err | txqm2dmae_ptr_dram奇偶校验错误 |
| 7114 | reg_dmae_1err | 0x40081 | dmae err1告警寄存器 | 3 | rxm2dmae_txffc_prty_err | rxm2dmae_txffc奇偶校验错误 |
| 7115 | reg_dmae_1err | 0x40081 | dmae err1告警寄存器 | 2 | rxm2dmae_ram_prty_err | rxm2dmae_ram奇偶校验错误 |
| 7116 | reg_dmae_1err | 0x40081 | dmae err1告警寄存器 | 1 | txqm2dmae_txffc_prty_err | txqm2dmae_txffc奇偶校验错误 |
| 7117 | reg_dmae_1err | 0x40081 | dmae err1告警寄存器 | 0 | txm2dmae_txffc_prty_err | txm2dmae_txffc奇偶校验错误 |
| 7118 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 8 | reg_dmae_c_chk_err | dmae返回c命令奇偶信息解校验错误 |
| 7119 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 7 | reg_chk_result_cfifo_err | bdqm c fifo 校验错误 |
| 7120 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 6 | reg_dmae_d_chk_err | dmae返回d数据奇偶信息解校验错误 |
| 7121 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 5 | reg_bd_softprty_err | bd内奇偶校验信息解校验错误 |
| 7122 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 4 | reg_chk_result_bd_ram | bdqm ram校验错误 |
| 7123 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 3 | reg_tmout_us_err | axis模块等待ready信号超时告警 |
| 7124 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 2 | axi_rxff_err | axi模块内fifo错误信号 |
| 7125 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 1 | bdqm_rxff_werr | BD C FIFO写上溢 |
| 7126 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 0 | bdqm_rxff_rerr | BD C FIFO读下溢 |
| 7127 | reg_bdqm_err | 0x41080 | txqm错误告警信息 | 3 | reg_bd_code_err | BD code 校验错误 |
| 7128 | reg_mulqm_err0 | 0x41081 | txqm BD错误告警信息 | 2 | reg_length_err | BD长度校验为0告警 |
| 7129 | reg_mulqm_err0 | 0x41081 | txqm BD错误告警信息 | 1 | reg_daddr_err | BD目的地址校验为0告警 |
| 7130 | reg_mulqm_err0 | 0x41081 | txqm BD错误告警信息 | 0 | reg_saddr_err | BD源地址校验为0告警 |
| 7135 | reg_prty_err | 0x42080 | txm校验错误告警 | 2 | reg_index_ram_prty_err | txm的index ram读出数据出现校验错误 |
| 7136 | reg_prty_err | 0x42080 | txm校验错误告警 | 1 | reg_dmae2txm_dram_prty_err | dmae2txm的数据ram读出数据出现校验错误 |
| 7137 | reg_prty_err | 0x42080 | txm校验错误告警 | 0 | reg_dmae2txm_cfifo_prty_err | dmae2txm的指令fifo读出数据出现校验错误 |
| 7138 | reg_txm_err | 0x42081 | txm错误告警信息 | 11 | reg_ae2txm_length_max_err | ae发送给txm的长度大于4096，指令丢弃告警 |
| 7139 | reg_txm_err | 0x42081 | txm错误告警信息 | 10 | reg_ae2txm_length_zero_err | ae发送给txm的长度为0，指令丢弃告警 |
| 7140 | reg_txm_err | 0x42081 | txm错误告警信息 | 9 | reg_sh2ul_axi_tm_out | txm到ae方向的axi模块超时指示 |
| 7141 | reg_txm_err | 0x42081 | txm错误告警信息 | 8 | reg_cfifo_length_err | 从cfifo读出来的长度为0告警 |
| 7142 | reg_txm_err | 0x42081 | txm错误告警信息 | 7 | reg_dram_raddr_err | dram读地址不连续告警 |
| 7143 | reg_txm_err | 0x42081 | txm错误告警信息 | 6 | reg_cfifo_ovfl | dmae到txm方向的cfifo上溢告警 |
| 7144 | reg_txm_err | 0x42081 | txm错误告警信息 | 5 | reg_cfifo_udfl | dmae到txm方向的cfifo下溢告警 |
| 7145 | reg_txm_err | 0x42081 | txm错误告警信息 | 4 | reg_bukect_time_over | 漏桶超时告警 |
| 7146 | reg_txm_err | 0x42081 | txm错误告警信息 | 3 | reg_bukect_err | 漏桶核查不一致错误 |
| 7147 | reg_txm_err | 0x42081 | txm错误告警信息 | 2 | reg_index_sqs_err | index 不连续告警 |
| 7148 | reg_txm_err | 0x42081 | txm错误告警信息 | 1 | req_txm2ae_fifo_err | txm到ae的fifo即空又满告警 |
| 7149 | reg_txm_err | 0x42081 | txm错误告警信息 | 0 | req_ae2txm_fifo_err | ae到txm的fifo即空又满告警 |
| 7162 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 15 | reg_rxqm_err | rxqm VF0队列7驱动按门铃错误告警 |
| 7163 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 14 | reg_rxqm_err | rxqm VF0队列6驱动按门铃错误告警 |
| 7164 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 13 | reg_rxqm_err | rxqm VF0队列5驱动按门铃错误告警 |
| 7165 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 12 | reg_rxqm_err | rxqm VF0队列4驱动按门铃错误告警 |
| 7166 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 11 | reg_rxqm_err | rxqm VF0队列3驱动按门铃错误告警 |
| 7167 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 10 | reg_rxqm_err | rxqm VF0队列2驱动按门铃错误告警 |
| 7168 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 9 | reg_rxqm_err | rxqm VF0队列1驱动按门铃错误告警 |
| 7169 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 8 | reg_rxqm_err | rxqm VF0队列0驱动按门铃错误告警 |
| 7170 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 7 | reg_rxqm_err | rxqm PF队列7驱动按门铃错误告警 |
| 7171 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 6 | reg_rxqm_err | rxqm PF队列6驱动按门铃错误告警 |
| 7172 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 5 | reg_rxqm_err | rxqm PF队列5驱动按门铃错误告警 |
| 7173 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 4 | reg_rxqm_err | rxqm PF队列4驱动按门铃错误告警 |
| 7174 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 3 | reg_rxqm_err | rxqm PF队列3驱动按门铃错误告警 |
| 7175 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 2 | reg_rxqm_err | rxqm PF队列2驱动按门铃错误告警 |
| 7176 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 1 | reg_rxqm_err | rxqm PF队列1驱动按门铃错误告警 |
| 7177 | reg_rxqm_err | 0x43080 | rxqm PF与 VF0队列驱动按门铃错误告警 | 0 | reg_rxqm_err | rxqm PF队列0驱动按门铃错误告警 |
| 7178 | rxm_req_busy | 0x43082 | RXM在RXQM未准备好时发起请求 | 8 | rxm_req_busy | rxm在RXQM未准备好时发起请求 |
| 7179 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 15 | reg_bdqm_err_3rd | rxm导致VF0的队列7读指针下溢告警 |
| 7180 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 14 | reg_bdqm_err_3rd | rxm导致VF0的队列6读指针下溢告警 |
| 7181 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 13 | reg_bdqm_err_3rd | rxm导致VF0的队列5读指针下溢告警 |
| 7182 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 12 | reg_bdqm_err_3rd | rxm导致VF0的队列4读指针下溢告警 |
| 7183 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 11 | reg_bdqm_err_3rd | rxm导致VF0的队列3读指针下溢告警 |
| 7184 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 10 | reg_bdqm_err_3rd | rxm导致VF0的队列2读指针下溢告警 |
| 7185 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 9 | reg_bdqm_err_3rd | rxm导致VF0的队列1读指针下溢告警 |
| 7186 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 8 | reg_bdqm_err_3rd | rxm导致VF0的队列0读指针下溢告警 |
| 7187 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 7 | reg_bdqm_err_3rd | rxm导致PF的队列7读指针下溢告警 |
| 7188 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 6 | reg_bdqm_err_3rd | rxm导致PF的队列6读指针下溢告警 |
| 7189 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 5 | reg_bdqm_err_3rd | rxm导致PF的队列5读指针下溢告警 |
| 7190 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 4 | reg_bdqm_err_3rd | rxm导致PF的队列4读指针下溢告警 |
| 7191 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 3 | reg_bdqm_err_3rd | rxm导致PF的队列3读指针下溢告警 |
| 7192 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 2 | reg_bdqm_err_3rd | rxm导致PF的队列2读指针下溢告警 |
| 7193 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 1 | reg_bdqm_err_3rd | rxm导致PF的队列1读指针下溢告警 |
| 7194 | reg_bdqm_err_3rd | 0x43083 | rxm强读队列告警 | 0 | reg_bdqm_err_3rd | rxm导致PF的队列0读指针下溢告警 |
| 7220 | reg_trm_ff_err | 0xb080 | hpi访问告警 | 6 | reg_hpi_tmout_ack_err | 读取bar2的数据返回超时告警 |
| 7221 | reg_trm_ff_err | 0xb080 | hpi访问告警 | 5 | reg_pciex4_bar_rxff_prty_err | 从fifo读出的数据校验告警 |
| 7253 | reg_hpi_txff_err | 0xb083 | hpi入口fifo告警 | 5 | pcie0_bar_rxff_overflow | 入口异步fifo上溢告警 |
| 7254 | reg_hpi_txff_err | 0xb083 | hpi入口fifo告警 | 4 | pcie0_bar_rxff_underflow | 入口异步fifo下溢告警 |
| 7257 | reg_hpi_txff_err | 0xb083 | hpi入口fifo告警 | 1 | pciex4_bar_rxff_overflow | 入口同步fifo上溢告警 |
| 7258 | reg_hpi_txff_err | 0xb083 | hpi入口fifo告警 | 0 | pciex4_bar_rxff_underflow | 入口同步fifo下溢告警 |
| 7284 | reg_bar_access_err | 0xb084 | 通过pf访问bar告警 | 6 | reg_bar_access_err | 通过pf访问bar告警；bit[6:0]分别对应BAR6~BAR0 |
| 7285 | reg_bar_access_err | 0xb084 | 通过pf访问bar告警 | 5 | reg_bar_access_err | 通过pf访问bar告警；bit[6:0]分别对应BAR6~BAR0 |
| 7286 | reg_bar_access_err | 0xb084 | 通过pf访问bar告警 | 4 | reg_bar_access_err | 通过pf访问bar告警；bit[6:0]分别对应BAR6~BAR0 |
| 7287 | reg_bar_access_err | 0xb084 | 通过pf访问bar告警 | 3 | reg_bar_access_err | 通过pf访问bar告警；bit[6:0]分别对应BAR6~BAR0 |
| 7288 | reg_bar_access_err | 0xb084 | 通过pf访问bar告警 | 2 | reg_bar_access_err | 通过pf访问bar告警；bit[6:0]分别对应BAR6~BAR0 |
| 7289 | reg_bar_access_err | 0xb084 | 通过pf访问bar告警 | 1 | reg_bar_access_err | 通过pf访问bar告警；bit[6:0]分别对应BAR6~BAR0 |
| 7290 | reg_bar_access_err | 0xb084 | 通过pf访问bar告警 | 0 | reg_bar_access_err | 通过pf访问bar告警；bit[6:0]分别对应BAR6~BAR0 |
| 7292 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 30 |  | bffifo 奇偶校验出错 |
| 7293 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 29 |  | bffifo 满写错误 |
| 7294 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 28 |  | bffifo 空读错误 |
| 7300 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 22 |  | wcfifo 奇偶校验出错 |
| 7301 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 21 |  | wcfifo 满写错误 |
| 7302 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 20 |  | wcfifo 空读错误 |
| 7308 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 14 |  | refifo 奇偶校验出错 |
| 7309 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 13 |  | refifo 满写错误 |
| 7310 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 12 |  | refifo 空读错误 |
| 7316 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 6 |  | rdfifo 奇偶校验出错 |
| 7317 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 5 |  | rdfifo 满写错误 |
| 7318 | axi_fifo_status | 0x17048 | axi模块的 fifo状态 | 4 |  | rdfifo 空读错误 |
| 7345 | axi_addr_err | 0x1704c | axi地址错误 | 9 |  | 读通道地址不对齐错误 |
| 7346 | axi_addr_err | 0x1704c | axi地址错误 | 8 |  | 写通道地址不对齐错误 |
| 7372 | cm_status | 0x17120 | cm状态 | 14 |  | ch1_fifo 奇偶校验出错 |
| 7373 | cm_status | 0x17120 | cm状态 | 13 |  | ch1_fifo 满写错误 |
| 7374 | cm_status | 0x17120 | cm状态 | 12 |  | ch1_fifo 空读错误 |
| 7380 | cm_status | 0x17120 | cm状态 | 6 |  | ch0_fifo 奇偶校验出错 |
| 7381 | cm_status | 0x17120 | cm状态 | 5 |  | ch0_fifo 满写错误 |
| 7382 | cm_status | 0x17120 | cm状态 | 4 |  | ch0_fifo 空读错误 |
| 7396 | dc_status | 0x17124 | dc状态 | 22 |  | worder_fifo 奇偶校验出错 |
| 7397 | dc_status | 0x17124 | dc状态 | 21 |  | worder_fifo 满写错误 |
| 7398 | dc_status | 0x17124 | dc状态 | 20 |  | worder_fifo 空读错误 |
| 7412 | dc_status | 0x17124 | dc状态 | 6 |  | rorder_fifo 奇偶校验出错 |
| 7413 | dc_status | 0x17124 | dc状态 | 5 |  | rorder_fifo 满写错误 |
| 7414 | dc_status | 0x17124 | dc状态 | 4 |  | rorder_fifo  空读错误 |
| 7420 | mac_status | 0x17148 | mac状态 | 30 |  | split_fifo 奇偶校验出错 |
| 7421 | mac_status | 0x17148 | mac状态 | 29 |  | split_fifo 满写错误 |
| 7422 | mac_status | 0x17148 | mac状态 | 28 |  | split_fifo 空读错误 |
| 7428 | mac_status | 0x17148 | mac状态 | 22 |  | bank_fifo 奇偶校验出错 |
| 7429 | mac_status | 0x17148 | mac状态 | 21 |  | bank_fifo 满写错误 |
| 7430 | mac_status | 0x17148 | mac状态 | 20 |  | bank_fifo 空读错误 |
| 7435 | mac_status | 0x17148 | mac状态 | 15 |  | 读写长度非法检测 |
| 7443 | mac_status | 0x17148 | mac状态 | 7 |  | 初始化状态 |
| 7444 | mac_status | 0x17148 | mac状态 | 6 |  | fifo 奇偶校验出错 |
| 7445 | mac_status | 0x17148 | mac状态 | 5 |  | fifo 满写错误 |
| 7446 | mac_status | 0x17148 | mac状态 | 4 |  | fifo 空读错误 |
| 7451 | SYS_FIFO_STAT | 0x4080 | 用户访问读写命令fifo告警 | 14 | pcie_tx1_cfifo_parity | 读命令fifo奇偶校验 |
| 7452 | SYS_FIFO_STAT | 0x4080 | 用户访问读写命令fifo告警 | 13 | pcie_tx1_cfifo_overflow | 读命令fifo满写 |
| 7453 | SYS_FIFO_STAT | 0x4080 | 用户访问读写命令fifo告警 | 12 | pcie_tx1_cfifo_underflow | 读命令fifo空读 |
| 7454 | SYS_FIFO_STAT | 0x4080 | 用户访问读写命令fifo告警 | 6 | pcie_tx0_cfifo_parity | 写命令fifo奇偶校验 |
| 7455 | SYS_FIFO_STAT | 0x4080 | 用户访问读写命令fifo告警 | 5 | pcie_tx0_cfifo_overflow | 写命令fifo满写 |
| 7456 | SYS_FIFO_STAT | 0x4080 | 用户访问读写命令fifo告警 | 4 | pcie_tx0_cfifo_underflow | 写命令fifo空读 |
| 7457 | SYS_FLAG | 0x4011 | 请求0长告警 | 8 | ch1_len_zero_err_flag | 读通道命令0长告警 |
| 7458 | SYS_FLAG | 0x4011 | 请求0长告警 | 0 | ch0_len_zero_err_flag | 写通道命令0长告警 |
| 7459 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 30 | dma1_cfifo_parity | 切包读命令fifo奇偶校验 |
| 7460 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 29 | dma1_cfifo_overflow | 切包读命令数据fifo满写 |
| 7461 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 28 | dma1_cfifo_underflow | 切包读命令数据fifo空读 |
| 7462 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 22 | dma0_cfifo_parity | 切包写命令fifo奇偶校验 |
| 7463 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 21 | dma0_cfifo_overflow | 切包写命令fifo满写 |
| 7464 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 20 | dma0_cfifo_underflow | 切包写命令fifo空读 |
| 7465 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 14 | adapt_dfifo_parity | 组包数据fifo奇偶校验 |
| 7466 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 13 | adapt_dfifo_overflow | 组包数据fifo满写 |
| 7467 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 12 | adapt_dfifo_underflow | 组包数据fifo空读 |
| 7468 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 6 | adapt_cfifo_parity | 组包命令fifo奇偶校验 |
| 7469 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 5 | adapt_cfifo_overflow | 组包命令fifo满写 |
| 7470 | TX_FIFO_STAT1 | 0x4040 | 发送fifo告警1 | 4 | adapt_cfifo_underflow | 组包命令fifo空读 |
| 7471 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 22 | user_order_fifo_parity | 用户保序fifo奇偶校验 |
| 7472 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 21 | user_order_fifo_overflow | 用户保序fifo满写 |
| 7473 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 20 | user_order_fifo_underflow | 用户保序fifo空读 |
| 7474 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 14 | dma_order_fifo_parity | dma保序fifo奇偶校验 |
| 7475 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 13 | dma_order_fifo_overflow | dma保序fifo满写 |
| 7476 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 12 | dma_order_fifo_underflow | dma保序fifo空读 |
| 7477 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 6 | dma0_dfifo_parity | 切包写数据fifo奇偶校验 |
| 7478 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 5 | dma0_dfifo_overflow | 切包写数据fifo满写 |
| 7479 | TX_FIFO_STAT2 | 0x4041 | 发送fifo告警2 | 4 | dma0_dfifo_underflow | 切包写数据fifo空读 |
| 7480 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 30 | bau_fifo_parity | axififo奇偶校验 |
| 7481 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 29 | bau_fifo_overflow | axififo满写 |
| 7482 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 28 | bau_fifo_underflow | axififo空读 |
| 7483 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 14 | bar_tx_fifo_parity | 寄存器发送fifo奇偶校验 |
| 7484 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 13 | bar_tx_fifo_overflow | 寄存器发送数据fifo满写 |
| 7485 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 12 | bar_tx_fifo_underflow | 寄存器发送数据fifo空读 |
| 7486 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 6 | bar_order_fifo_parity | 寄存器保序fifo奇偶校验 |
| 7487 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 5 | bar_order_fifo_overflow | 寄存器保序数据fifo满写 |
| 7488 | BUS_FIFO_STAT1 | 0x4042 | 总线fifo告警 | 4 | bar_order_fifo_underflow | 寄存器保序数据fifo空读 |
| 7489 | dma_sop_eop_chk_error | 0x4044 | 总线fifo告警 | 24 | dma_sop_eop_chk_error | 用户写请求数据命令不匹配 |
| 7490 | USR_FIFO_STATUS | 0x404a | 用户返回fifo告警 | 14 | pcie_rx_fifo_parity | 接受fifo奇偶校验 |
| 7491 | USR_FIFO_STATUS | 0x404a | 用户返回fifo告警 | 13 | pcie_rx_fifo_overflow | 接受fifo满写 |
| 7492 | USR_FIFO_STATUS | 0x404a | 用户返回fifo告警 | 12 | pcie_rx_fifo_underflow | 接受fifo空读 |
| 7493 | USR_FIFO_STATUS | 0x404a | 用户返回fifo告警 | 6 | user_order_fifo_parity | 用户保序fifo奇偶校验 |
| 7494 | USR_FIFO_STATUS | 0x404a | 用户返回fifo告警 | 5 | user_order_fifo_overflow | 用户保序fifo满写 |
| 7495 | USR_FIFO_STATUS | 0x404a | 用户返回fifo告警 | 4 | user_order_fifo_underflow | 用户保序fifo空读 |
| 7496 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 15 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7497 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 14 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7498 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 13 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7499 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 12 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7500 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 11 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7501 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 10 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7502 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 9 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7503 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 8 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7504 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 7 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7505 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 6 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7506 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 5 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7507 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 4 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7508 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 3 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7509 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 2 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7510 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 1 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7511 | rx_len_unvld_cnt | 0x4081 | 完成报文长度异常 | 0 | rx_len_unvld_cnt | 完成报文长度异常 |
| 7512 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 15 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7513 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 14 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7514 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 13 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7515 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 12 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7516 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 11 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7517 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 10 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7518 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 9 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7519 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 8 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7520 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 7 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7521 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 6 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7522 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 5 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7523 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 4 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7524 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 3 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7525 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 2 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7526 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 1 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7527 | rx_stat_unvld_cnt | 0x4082 | 完成报文状态异常 | 0 | rx_stat_unvld_cnt | 完成报文状态异常 |
| 7528 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 15 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7529 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 14 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7530 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 13 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7531 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 12 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7532 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 11 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7533 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 10 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7534 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 9 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7535 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 8 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7536 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 7 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7537 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 6 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7538 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 5 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7539 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 4 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7540 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 3 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7541 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 2 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7542 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 1 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7543 | rx_tag_unvld_cnt | 0x4083 | 完成报文tag异常 | 0 | rx_tag_unvld_cnt | 完成报文tag异常 |
| 7544 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 15 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7545 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 14 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7546 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 13 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7547 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 12 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7548 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 11 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7549 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 10 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7550 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 9 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7551 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 8 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7552 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 7 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7553 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 6 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7554 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 5 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7555 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 4 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7556 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 3 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7557 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 2 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7558 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 1 | rx_tag_unvld_cnt | 完成报文超时异常 |
| 7559 | pld_timeout_cnt | 0x4088 | 完成报文超时异常 | 0 | rx_tag_unvld_cnt | 完成报文超时异常 |
