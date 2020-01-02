
import matplotlib.pyplot as plt
import numpy as np

file=open("./classification_train.txt",'r')
lines=file.read().split("\n")
lines=np.array([[float(data)for data in line.split()] for line in lines[1::]])
x_1=[]
y_1=[]
y_0=[]
x_0=[]
for line in lines:
    if line[2]==0:
        x_0.append(line[0])
        y_0.append(line[1])
        
    if line[2]==1:
        x_1.append(line[0])
        y_1.append(line[1])

#for calculate the probabilities
labels=[int (line[2]) for line in lines]
label_ones=labels.count(1)
label_zeros=labels.count(0)

p_zeros=label_zeros/len(labels)
p_ones=label_ones/len(labels)

#for plot the training dataset
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')

for i in range(len(labels)):
    plt.plot(x_0,y_0,"r.")
    plt.plot(x_1,y_1,"b.")
    
plt.legend(["Class: 1","Class: 2"])
plt.show()
