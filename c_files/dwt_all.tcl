# This TCL script sets up the project and initial solution
# then runs synthesis that solution



#set_directive_loop_flatten dwt3D/X_I_LOOP
#set_directive_pipeline dwt3D/X_I_LOOP
#set_directive_loop_merge dwt3D
#set_directive_array_partition -type block -factor 4 dwt3D temp1->data3D
#set_directive_array_partition -type complete -dim 0 dwt3D temp1->data3D
#set_directive_expression_balance dwt3D


#sol1

open_project -reset dwt_prj1g
add_files dwt.c
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
export_design



#sol2

open_project -reset dwt_prj2
add_files col_accessing.c
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
export_design

#sol3

open_project -reset dwt_prj3
add_files interchange.c
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
export_design

#sol4

open_project -reset dwt_prj4
add_files non_var_loops.c
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
export_design




#sol5

open_project -reset dwt_prj5
add_files inverse.c
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
export_design



#sol6

open_project -reset dwt_prj6
add_files inverse.c
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
export_design



#sol7

open_project -reset dwt_prj7
add_files inverse.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_pipeline dwt3D/X_J_LOOP
set_directive_pipeline dwt3D/Y_K_LOOP
set_directive_pipeline dwt3D/Z_I_LOOP

csynth_design
# export_design


#sol8

open_project -reset dwt_prj8
add_files inverse.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_pipeline dwt1D/CALC_LOOP
set_directive_pipeline dwt1D/CALC_LOOP
set_directive_pipeline dwt1D/CALC_LOOP

csynth_design
export_design


#sol9

open_project -reset dwt_prj9
add_files inverse.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D


open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 11

set_directive_interface -mode s_axilite -bundle dwt_io "dwt3D"
set_directive_loop_flatten dwt3D

csynth_design
export_design



#sol10

open_project -reset dwt_prj9
add_files singe_sub_loops.c
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
export_design

exit