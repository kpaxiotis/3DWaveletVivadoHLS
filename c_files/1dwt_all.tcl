# This TCL script sets up the project and initial solution
# then runs synthesis that solution



#sol1

open_project -reset dwt_prj1
add_files single_sub_loops.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D



open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"

csynth_design
# export_design



#sol2

open_project -reset dwt_prj2
add_files single_sub_loops.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_loop_flatten dwt3D/X_I_LOOP
set_directive_loop_flatten dwt3D/Y_J_LOOP
set_directive_loop_flatten dwt3D/Z_K_LOOP
set_directive_loop_flatten dwt3D/IN_K_LOOP
set_directive_loop_flatten dwt3D/OUT_K_LOOP


csynth_design
# export_design

#sol3

open_project -reset dwt_prj3
add_files single_sub_loops.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_pipeline dwt3D/X_I_LOOP
set_directive_pipeline dwt3D/Y_J_LOOP
set_directive_pipeline dwt3D/Z_K_LOOP

csynth_design
# export_design

#sol4

open_project -reset dwt_prj4
add_files single_sub_loops.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_pipeline -II 3  dwt3D/X_I_LOOP
set_directive_pipeline -II 3  dwt3D/Y_J_LOOP
set_directive_pipeline -II 3  dwt3D/Z_K_LOOP


csynth_design
# export_design




#sol5

open_project -reset dwt_prj5
add_files single_sub_loops.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_unroll dwt3D/X_I_LOOP
set_directive_unroll dwt3D/Y_J_LOOP
set_directive_unroll dwt3D/Z_K_LOOP
set_directive_unroll dwt3D/IN_K_LOOP
set_directive_unroll dwt3D/OUT_K_LOOP


csynth_design
# export_design



#sol6

open_project -reset dwt_prj6
add_files single_sub_loops.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_array_partition -type block -factor 4 dwt3D temp1->data3D
set_directive_array_partition -type block -factor 4 dwt3D temp2->data3D


csynth_design
# export_design



#sol7

open_project -reset dwt_prj7
add_files single_sub_loops.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_array_partition -type complete -dim 0 dwt3D temp1->data3D
set_directive_array_partition -type complete -dim 0 dwt3D temp2->data3D


csynth_design
# export_design


exit