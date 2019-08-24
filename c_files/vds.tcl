create_project project1 C:/vThesis/c_files/dwt_prj2/solution1/project1 -part xc7z010clg400-1
set_property board_part digilentinc.com:zybo-z7-10:part0:1.0 [current_project]
set_property target_language VHDL [current_project]
set_property simulator_language VHDL [current_project]

set_property  ip_repo_paths  C:/vThesis/c_files/dwt_prj2/solution1/impl/ip [current_project]
update_ip_catalog

create_bd_design "design_1"
update_compile_order -fileset sources_1
startgroup
create_bd_cell -type ip -vlnv xilinx.com:hls:dwt3D:1.0 dwt3D_0
endgroup
startgroup
apply_bd_automation -rule xilinx.com:bd_rule:bram_cntlr -config {BRAM "Auto" }  [get_bd_intf_pins dwt3D_0/in_r_PORTA]
apply_bd_automation -rule xilinx.com:bd_rule:bram_cntlr -config {BRAM "Auto" }  [get_bd_intf_pins dwt3D_0/in_r_PORTB]
endgroup
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 processing_system7_0
endgroup
apply_bd_automation -rule xilinx.com:bd_rule:processing_system7 -config {make_external "FIXED_IO, DDR" apply_board_preset "1" Master "Disable" Slave "Disable" }  [get_bd_cells processing_system7_0]
startgroup
set_property -dict [list CONFIG.PCW_USE_FABRIC_INTERRUPT {1} CONFIG.PCW_IRQ_F2P_INTR {1} CONFIG.PCW_QSPI_GRP_SINGLE_SS_ENABLE {1} CONFIG.PCW_ENET0_PERIPHERAL_ENABLE {0} CONFIG.PCW_SD0_PERIPHERAL_ENABLE {0} CONFIG.PCW_GPIO_MIO_GPIO_ENABLE {0}] [get_bd_cells processing_system7_0]
endgroup
connect_bd_net [get_bd_pins processing_system7_0/IRQ_F2P] [get_bd_pins dwt3D_0/interrupt]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins dwt3D_0/s_axi_dwt_io]
validate_bd_design
make_wrapper -files [get_files C:/vThesis/c_files/dwt_prj2/solution1/project1/project1.srcs/sources_1/bd/design_1/design_1.bd] -top
add_files -norecurse C:/vThesis/c_files/dwt_prj2/solution1/project1/project1.srcs/sources_1/bd/design_1/hdl/design_1_wrapper.vhd
launch_runs synth_1
wait_on_run synth_1

launch_runs impl_1
wait_on_run impl_1
