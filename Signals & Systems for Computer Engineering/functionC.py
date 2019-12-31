#	Seda SUGUR 150160130

import sys
import matplotlib.pyplot as plt
import operator



xLowerB = sys.argv[1]
xUpperB = sys.argv[2]
n_for_x = []

for i in range(int(xLowerB),int(xUpperB) + 1):
	n_for_x.append(i)

yLowerB = sys.argv[3]
yUpperB = sys.argv[4]
n_for_y = []

for i in range(int(yLowerB),int(yUpperB) + 1):
	n_for_y.append(i)



xValues = []
yValues = []

for i in range(1,int(xUpperB) - int(xLowerB) + 2):
	xValues.append(sys.argv[4+i])

for i in range(1,int(yUpperB)- int(yLowerB) + 2):
	yValues.append(sys.argv[4+len(xValues)+i])
int_list_xValues = [int(element) for element in xValues]
int_list_yValues = [int(element) for element in yValues]



n=len(int_list_yValues)+len(int_list_xValues)-1
for i in range(0,n-len(int_list_xValues)):
	int_list_xValues.append(0)

for i in range(0,n-len(int_list_yValues)):
	int_list_yValues.append(0)

result=[0 for i in range(n)]
for i in range(0,n):
	for j in range(0,i+1):
		result[i]=(result[i]+int_list_xValues[j]*int_list_yValues[i-j])

	
print(result)

