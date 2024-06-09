# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: E:\vivado_data\timer_with_BRAM_editCLK\vitis3_maxCH\timer_bram_unmerged_system\_ide\scripts\debugger_timer_bram_unmerged-default.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source E:\vivado_data\timer_with_BRAM_editCLK\vitis3_maxCH\timer_bram_unmerged_system\_ide\scripts\debugger_timer_bram_unmerged-default.tcl
# 
connect -url tcp:127.0.0.1:3121
source D:/SOFTware/vivado2020/Vitis/2020.2/scripts/vitis/util/zynqmp_utils.tcl
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Digilent JTAG-SMT2 C305945EABCD" && level==0 && jtag_device_ctx=="jsn-JTAG-SMT2-C305945EABCD-14710093-0"}
fpga -file E:/vivado_data/timer_with_BRAM_editCLK/vitis3_maxCH/timer_bram_unmerged/_ide/bitstream/timer_with_BRAM_wrapper.bit
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw E:/vivado_data/timer_with_BRAM_editCLK/vitis3_maxCH/timer_with_BRAM_wrapper/export/timer_with_BRAM_wrapper/hw/timer_with_BRAM_wrapper.xsa -mem-ranges [list {0x80000000 0xbfffffff} {0x400000000 0x5ffffffff} {0x1000000000 0x7fffffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
set mode [expr [mrd -value 0xFF5E0200] & 0xf]
targets -set -nocase -filter {name =~ "*A53*#0"}
rst -processor
dow E:/vivado_data/timer_with_BRAM_editCLK/vitis3_maxCH/timer_with_BRAM_wrapper/export/timer_with_BRAM_wrapper/sw/timer_with_BRAM_wrapper/boot/fsbl.elf
set bp_49_7_fsbl_bp [bpadd -addr &XFsbl_Exit]
con -block -timeout 60
bpremove $bp_49_7_fsbl_bp
targets -set -nocase -filter {name =~ "*A53*#0"}
rst -processor
dow E:/vivado_data/timer_with_BRAM_editCLK/vitis3_maxCH/timer_bram_unmerged/Debug/timer_bram_unmerged.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "*A53*#0"}
con
