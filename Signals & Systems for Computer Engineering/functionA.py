#	Seda SUGUR 150160130

import sys #for read the data commandline
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
	xValues.append(sys.argv[4+i]) #take the x values and add xValues

for i in range(1,int(yUpperB)- int(yLowerB) + 2):
	yValues.append(sys.argv[4+len(xValues)+i])

fig=plt.figure()
ax=plt.subplot("211")
ax.set_title("x[n]")

int_list_xValues = [int(element) for element in xValues] #sys.argv take the values commandline with type str.So i changed the type  
int_list_yValues = [int(element) for element in yValues]

ax.scatter(n_for_x, int_list_xValues, color='b',marker='o') #for adding dot
ax.vlines(n_for_x,0, int_list_xValues, colors='b',linestyles='-',label='') #for adding vertical lines 

ay = plt.subplot("212")
ay.set_title("y[n]")


ay.scatter(n_for_y, int_list_yValues, color='b',marker='o')
ay.vlines(n_for_y,0, int_list_yValues, colors='b',linestyles='-',label='')


if min(n_for_x)<0:
	if min(int_list_xValues)<0:
		ax.axis([min(n_for_x)-2,int(xUpperB)+2 ,min(int_list_xValues)-2,max(int_list_xValues)+2])
	else:

		ax.axis([min(n_for_x)-2,int(xUpperB)+2 ,0,max(int_list_xValues)+2])
else :
	if min(int_list_xValues)<0:
		ax.axis([0,int(xUpperB)+2 ,min(int_list_xValues)-2,max(int_list_xValues)+2])
	else:
		ax.axis([0,int(xUpperB)+2 ,0,max(int_list_xValues)+2])
#for y[n]axis
if min(n_for_y)<0:
	if min(int_list_yValues)<0:
		ay.axis([min(n_for_y)-2,int(yUpperB)+2 ,min(int_list_yValues)-2,max(int_list_yValues)+2])
	else:

		ay.axis([min(n_for_y)-2,int(yUpperB)+2 ,0,max(int_list_yValues)+2])
else :
	if min(int_list_yValues)<0:
		ay.axis([0,int(yUpperB)+2 ,min(int_list_yValues)-2,max(int_list_yValues)+2])
	else:
		ay.axis([0,int(yUpperB)+2 ,0,max(int_list_yValues)+2])


plt.show()









