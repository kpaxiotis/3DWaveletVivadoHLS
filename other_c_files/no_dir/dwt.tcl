# This TCL script sets up the project and initial solution
# then runs synthesis that solution

open_project -reset dwt.prj
add_files dwt.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D

open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 10

csim_design
csynth_design
cosim_design

exit
