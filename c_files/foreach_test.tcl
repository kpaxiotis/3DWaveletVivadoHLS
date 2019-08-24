open_project -reset dwt_prj
add_files dwt_w_names.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D

#Pipeline

set all_solution [list "solution4" "solution5" "solution6" "solution7"]
set all_level [list 4 5 6 7]

foreach solution $all_solution level $all_level {

    open_solution $solution -reset
    set_part  {xc7z010clg400-1}
    create_clock -period 10

    set_directive_pipeline -II $level dwt1D/CALC_LOOP
    #set_directive_dataflow dwt1D/CALC_LOOP
    
    #csim_design
    csynth_design

}

#Loop Interchange

open_project -reset dwt_prj
add_files interchange.c
add_files -tb dwt_test.c
add_files -tb in_images 
add_files -tb out_images 
add_files -tb out_gold_images

set_top dwt3D

open_solution "solution1" -reset
set_part  {xc7z010clg400-1}
create_clock -period 10

#csim_design
csynth_design

exit