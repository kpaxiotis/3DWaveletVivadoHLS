import json
import numpy as np
import matplotlib.pyplot as plt


#solutions = ['Initial', 'Inverse', 'Inline']
latency_avg = []
sol_list = []


for i in range(1, 13):
    directory = "dwt_prj" + str(i) + "/solution1/solution1_data.json"
    with open(directory) as f:
        data = json.load(f)

        #data_list.append(int(data['ModuleInfo']['Metrics']['dwt3D']['Latency']['LatencyAvg']))
    latency_avg.append(int(data['ModuleInfo']['Metrics']['dwt3D']['Latency']['LatencyAvg']))
    sol_list.append("prj" + str(i))

    # print(solutions[i - 1], data['ModuleInfo']['Metrics']['dwt3D']['Latency']['LatencyAvg'], '\n')
    
plt.bar(sol_list, latency_avg)


for a,b in zip(sol_list, latency_avg):
    plt.text(a,b,str(b) + "__" + str(round((b - latency_avg[0])/latency_avg[0] * 100, 2))+ "%")
plt.show()
