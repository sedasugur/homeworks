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

fig=plt.figure()
ax=plt.subplot("211")
ax.set_title("x[n]")

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

ax.scatter(n_for_x, normalized_xValues, color='b',marker='o')
ax.vlines(n_for_x,0, normalized_xValues, colors='b',linestyles='-',label='')

ay = plt.subplot("212")
ay.set_title("y[n]")


ay.scatter(n_for_y, normalized_yValues, color='b',marker='o')
ay.vlines(n_for_y,0, normalized_yValues, colors='b',linestyles='-',label='')


if min(n_for_x)<0:
	if min(normalized_xValues)<0:
		ax.axis([min(n_for_x)-2,int(xUpperB)+2 ,min(normalized_xValues)-2,max(normalized_xValues)+2])
	else:

		ax.axis([min(n_for_x)-2,int(xUpperB)+2 ,0,max(normalized_xValues)+2])
else :
	if min(normalized_xValues)<0:
		ax.axis([0,int(xUpperB)+2 ,min(normalized_xValues)-2,max(normalized_xValues)+2])
	else:
		ax.axis([0,int(xUpperB)+2 ,0,max(normalized_xValues)+2])
#for y[n]axis
if min(n_for_y)<0:
	if min(normalized_yValues)<0:
		ay.axis([min(n_for_y)-2,int(yUpperB)+2 ,min(normalized_yValues)-2,max(normalized_yValues)+2])
	else:

		ay.axis([min(n_for_y)-2,int(yUpperB)+2 ,0,max(normalized_yValues)+2])
else :
	if min(normalized_yValues)<0:
		ay.axis([0,int(yUpperB)+2 ,min(normalized_yValues)-2,max(normalized_yValues)+2])
	else:
		ay.axis([0,int(yUpperB)+2 ,0,max(normalized_yValues)+2])


plt.show()









