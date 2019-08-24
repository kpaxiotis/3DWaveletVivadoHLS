# This TCL script sets up the project and initial solution
# then runs synthesis that solution

open_project -reset dwt_prj
add_files inverse.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D

#Pipeline dwt1D and dataflow

open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 10

set_directive_pipeline -II 4 -enable_flush dwt1D/CALC_LOOP
#set_directive_dataflow dwt3D/X_I_LOOP

#csim_design
csynth_design

exit
