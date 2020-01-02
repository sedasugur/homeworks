# -*- coding: utf-8 -*-
"""
Created on Sun Mar 31 21:17:16 2019

@author: Seda Sügür
"""

import numpy as np


file = open("./classification_train.txt", "r")
lines = file.read().split("\n")
lines = np.array([[float(data) for data in line.split()] for line in lines[1::]])

x_1=[]#for feature1 in second class
y_1=[]#for feature2 in second class
y_0=[]
x_0=[]
for line in lines:
    if line[2]==0:
        x_0.append(line[0])
        y_0.append(line[1])
        
    if line[2]==1:
        x_1.append(line[0])
        y_1.append(line[1])
        
def meanVector(x,y):#x for class's first features,y is second features
    sum_x=0
    sum_y=0
    for i in range(len(x)):
        sum_x+=x[i]
        sum_y+=y[i]
    mean_x=sum_x/len(x)
    mean_y=sum_y/len(y)
    return [mean_x,mean_y]




x_mean_c1,y_mean_c1=meanVector(x_0,y_0)#for class1
print(x_mean_c1,y_mean_c1)

x_mean_c2,y_mean_c2=meanVector(x_1,y_1)#for class1
print(x_mean_c2,y_mean_c2)

