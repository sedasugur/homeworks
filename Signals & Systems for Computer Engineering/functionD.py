#	Seda SUGUR 150160130

import sys
import matplotlib.pyplot as plt
import operator
import math


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

def normalized_func(a):
	sum1=0
	sum2=0
	normalized_a=[]
	for i in range(0,len(a)):
		sum1 = a[i]+sum1

	arit_mean=(sum1)/float(len(a))  #arithmetic mean

	for i in range(0,len(a)):
		subt=(arit_mean)-a[i]
		sum2=sum2+(subt)*(subt)

	standard_deviation=math.sqrt(sum2/float(len(a)-1))

	for i in range(0,len(a)):
		normalized_a.append((a[i]-arit_mean)/float(standard_deviation))
	return normalized_a


	
normalized_xValues = normalized_func(int_list_xValues)
normalized_yValues = normalized_func(int_list_yValues)

n=len(int_list_yValues)+len(int_list_xValues)-1
for i in range(0,n-len(int_list_xValues)):
	normalized_xValues.append(0)

for i in range(0,n-len(int_list_yValues)):
	normalized_yValues.append(0)

result=[0 for i in range(n)]
for i in range(0,n):
	for j in range(0,i+1):
		result[i]=(result[i]+normalized_xValues[j]*normalized_yValues[i-j])
print(result)





















