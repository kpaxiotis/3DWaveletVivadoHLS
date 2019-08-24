# This TCL script sets up the project and initial solution
# then runs synthesis that solution

open_project -reset dwt2.prj
add_files dwt.c
add_files -tb dwt_test.c
add_files -tb in_image.dat
add_files -tb out.dat 
add_files -tb out.gold.dat

set_top dwt3D

open_solution "solution1"
set_part  {xc7z010clg400-1}
create_clock -period 10

csynth_design

exit
