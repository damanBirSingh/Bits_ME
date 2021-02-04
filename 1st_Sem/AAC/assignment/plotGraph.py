import matplotlib.pyplot as plt
import csv

plt.clf()
x_r = []
y_r = []
with open('recursive.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x_r.append(int(row[0]))
        y_r.append(int(row[1]))

x_dp = []
y_dp = []
with open('dynamicProg.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x_dp.append(int(row[0]))
        y_dp.append(int(row[1]))

x_b = []
y_b = []
with open('backtracking.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x_b.append(int(row[0]))
        y_b.append(int(row[1]))

plt.plot(x_r,y_r, label='Recursion')
plt.plot(x_dp,y_dp, label='Dyanamic Programming')
plt.plot(x_b,y_b, label='Backtracking')

plt.xlabel('Array size')
plt.ylabel('microseconds')
plt.title('Time Taken by different appoaches for subset sum')
plt.legend()
plt.show()
