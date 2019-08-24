num_of_prj = 3

for i in range(1, num_of_prj):

    directory = "C:/vThesis/c_files/dwt_prj" + str(i) + "/solution1/project1/project1.runs/impl_1/design_1_wrapper_power_routed.rpt"

    with open(directory) as myfile:
        print (myfile.readlines()[32].split()[6])