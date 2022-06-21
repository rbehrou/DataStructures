import matplotlib.pyplot as plt
import numpy as np
  
x = np.array(list(range(0, 55)))
y_recursive = []
y_dptopdown = []
y_dpbottomup = []
for line in open('time_recursive.txt', 'r'):
    y_recursive.append(int(line))
y_recursive = np.array(y_recursive)

for line in open('time_dptopdown.txt', 'r'):
    y_dptopdown.append(int(line))
y_dptopdown = np.array(y_dptopdown)

for line in open('time_dpbottomup.txt', 'r'):
    y_dpbottomup.append(int(line))
y_dpbottomup = np.array(y_dpbottomup)

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
plt.plot(x, y_recursive, marker = 'o', c = 'r', label = 'brute-force recursive')
plt.plot(x, y_dptopdown, marker = '*', c = 'b', label = 'dynamic programming, top-down memorization')
plt.plot(x, y_dpbottomup, marker = '>', c = 'g', label = 'dynamic programming, bottom-up tabulation')      
plt.legend()
plt.xlabel('N')
plt.ylabel('time (nano-seconds)')
# plt.show()
# major_ticks_x = np.arange(0, len(x)+1, 5)
# major_ticks_y = np.arange(0, max(y_recursive), 1e3)
# ax.set_xticks(major_ticks_x)
# ax.set_yticks(major_ticks_y)
fig_name = "compare_times_all.png"
plt.savefig(fig_name)
plt.close()


fig = plt.figure()
ax = fig.add_subplot(1,1,1)
plt.plot(x, y_dptopdown, marker = '*', c = 'b', label = 'dynamic programming, top-down memorization')
plt.plot(x, y_dpbottomup, marker = '>', c = 'g', label = 'dynamic programming, bottom-up tabulation')      
plt.legend()
plt.xlabel('N')
plt.ylabel('time (nano-seconds)')
# plt.show()
# major_ticks_x = np.arange(0, len(x)+1, 5)
# major_ticks_y = np.arange(0, max(y_recursive), 1e3)
# ax.set_xticks(major_ticks_x)
# ax.set_yticks(major_ticks_y)
fig_name = "compare_times_dp.png"
plt.savefig(fig_name)
plt.close()