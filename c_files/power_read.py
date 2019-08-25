import numpy as np
import matplotlib.pyplot as plt


num_of_prj = 3
sol_list = []
power = []

for i in range(1, num_of_prj):

    directory = "C:/vThesis/c_files/dwt_prj" + str(i) + "/solution1/project1/project1.runs/impl_1/design_1_wrapper_power_routed.rpt"
    sol_list.append("sol" + str(i))
    
    
    with open(directory) as myfile:
        power.append(myfile.readlines()[32].split()[6])
        #print (myfile.readlines()[32].split()[6])

power = [float(i) for i in power]        

plt.bar(sol_list, power)

for a,b in zip(sol_list, power):
    plt.text(a,b,str(b)+ "__" + str(round((power[0] - b)/power[0] * 100, 2))+ "%")
plt.show()