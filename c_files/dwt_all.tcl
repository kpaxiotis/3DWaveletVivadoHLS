# This TCL script sets up the project and initial solution
# then runs synthesis that solution


#Initial Design

#open_project -reset dwt_prj
#add_files dwt_w_names.c
#add_files -tb dwt_test.c
#add_files -tb in_images 
#add_files -tb out_images 
#add_files -tb out_gold_images

#set_top dwt3D

#open_solution "solution1" -reset
#set_part  {xc7z010clg400-1}
#create_clock -period 12

#csim_design
#csynth_design



# #sol1

# open_project -reset dwt_prj1
# add_files inverse.c
# add_files -tb dwt_test.c
# add_files -tb in_images 
# add_files -tb out_images 
# add_files -tb out_gold_images

# set_top dwt3D



# open_solution "solution1" -reset
# set_part  {xc7z010clg400-1}
# create_clock -period 12

# set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"

# csynth_design
# export_design



#sol2

open_project -reset dwt_prj2
add_files inverse.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 12

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_dependence -variable temp -class array -dependent true -direction WAW dwt1D/CALC_LOOP
set_directive_pipeline dwt1D/CALC_LOOP
set_directive_dataflow dwt3D


csynth_design
# export_design

#sol3

open_project -reset dwt_prj3
add_files inverse.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 12

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_dependence -variable temp -class array -dependent true -direction WAW dwt1D/CALC_LOOP
set_directive_pipeline -II 4 dwt1D/CALC_LOOP
set_directive_dataflow dwt3D

csynth_design
# export_design

#sol4

open_project -reset dwt_prj4
add_files inverse.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 12

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_dependence -variable temp -class array -dependent true -direction WAW dwt1D/CALC_LOOP
set_directive_pipeline -II 6 dwt1D/CALC_LOOP
set_directive_dataflow dwt3D


csynth_design
# export_design

exit