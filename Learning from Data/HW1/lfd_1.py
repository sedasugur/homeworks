# -*- coding: utf-8 -*-
#Seda SUGUR  150160130

import random

iter_num=1000
learning_rate=0.01

m=[]
sum_x=0
sum_y=0
m.append([])
m.append([])
with open('./regression_data.txt','r') as file:
    file.readline()
    a=0
    lines=file.readlines()
    for line in lines:
        for word in line.split():
            word=float(word)/1000
            if a==0:
                m[0].append(word)
                a=1
            else:   
                m[1].append(word)
                a=0
         
lines=[]
for i in range(len(m[0])):
    lines.append([m[0][i],m[1][i]])
    
for i in range(len(m[0])):
    sum_x += m[0][i]
    sum_y +=m[1][i]
av_x=sum_x/len(m[0])#for init w
av_y=sum_y/len(m[1])#for init b

def cost_func(x,y,w,b):
    sum_error=0
    for i in range (len(x)):
        y_calc= w * x[i] + b
        error= y_calc-y[i]
        sum_error += error**2    
    return sum_error /(2 * len(x))

def deriv_cost_func(x,y,w_current,b_current):
    w_der=0
    b_der=0
    for i in range(len(x)):
        w_der += ((w_current*x[i]+b_current)-y[i]) * x[i] /len(x)
        b_der += ((w_current*x[i]+b_current)-y[i]) / len(x)
    return [b_der,w_der]

def gradient_descent(x,y,w,b,learning_rate,num_iter):    
    for i in range(num_iter):
        delta_b,delta_w=deriv_cost_func(x,y,w,b)
        w = w - learning_rate * delta_w
        b= b - learning_rate * delta_b
    return [b,w]

def fold(lines,k,data_size,size=0):
    size=round(data_size/k)
    lines_cpy=[row[:] for row in lines]
    random.shuffle(lines_cpy)
    fold=[]
    for x in range(0,k):
        if x==k-1:
            fold.append([])
            for y in range(data_size-(k-1)*size):
                fold[x].append([])
                for z in range(2):
                    fold[x][y].append(lines_cpy[size*(k-1)+y][z])
            break
        fold.append([])
        for y in range(size):
            fold[x].append([])
            for z in range(2):             
                fold[x][y].append(lines_cpy[size*x+y][z])
    return fold

def function_for_take_list_from_folds(fold_al,train1,train2,train3,train4):
    fold1,fold2,fold3,fold4=[],[],[],[]
 
    fold1=fold_al[train1]
    fold2=fold_al[train2]
    fold3=fold_al[train3]
    fold4=fold_al[train4]
    y_list=[]
    x_list=[]
    size=len(fold1)
    for i in range(size):
        x_list.append(fold1[i][0])
        y_list.append(fold1[i][1])

    size=len(fold2)
    for i in range(size):
        x_list.append(fold2[i][0])
        y_list.append(fold2[i][1])

    size=len(fold3)
    for i in range(size):
        x_list.append(fold3[i][0])
        y_list.append(fold3[i][1])

    size=len(fold4)
    for i in range(size):
        x_list.append(fold4[i][0])
        y_list.append(fold4[i][1])
    
    return [x_list,y_list]

fold_al=[]
fold_al=fold(lines,5,199)

def list_for_test(fold_al,test_index):#x and y data set for test
    test=[]
    xlist=[]
    ylist=[]
    test=fold_al[test_index]
    size=len(test)
    for i in range(size):
        xlist.append(test[i][0])
        ylist.append(test[i][1])
    return [xlist,ylist]

def overall_mse(error):#for calculate the overall mse , error is the array which include error's in the each model.In this example there are 5 models.
    _sum=0
    for i in range(len(error)):
        _sum+=error[i]
    return _sum/len(error)

#for model1 folds:0,1,2,3 train set, fold 5. is test set
error=[]
x_list,y_list=function_for_take_list_from_folds(fold_al,0,1,2,3)
b,w= gradient_descent(x_list,y_list,av_x,av_y,learning_rate,iter_num)
x_test,y_test=list_for_test(fold_al,4)
error.insert(0,cost_func(x_test,y_test,w,b))

#for model2
x_list,y_list=function_for_take_list_from_folds(fold_al,0,1,2,4)
b,w= gradient_descent(x_list,y_list,av_x,av_y,learning_rate,iter_num)
x_test,y_test=list_for_test(fold_al,3)
error.insert(1,cost_func(x_test,y_test,w,b))

#for model3
x_list,y_list=function_for_take_list_from_folds(fold_al,0,1,3,4)
b,w= gradient_descent(x_list,y_list,av_x,av_y,learning_rate,iter_num)
x_test,y_test=list_for_test(fold_al,2)
error.insert(2,cost_func(x_test,y_test,w,b))

#for model4
x_list,y_list=function_for_take_list_from_folds(fold_al,0,3,2,4)
b,w= gradient_descent(x_list,y_list,av_x,av_y,learning_rate,iter_num)
x_test,y_test=list_for_test(fold_al,1)
error.insert(3,cost_func(x_test,y_test,w,b))

#for model5
x_list,y_list=function_for_take_list_from_folds(fold_al,3,1,2,4)
b,w= gradient_descent(x_list,y_list,av_x,av_y,learning_rate,iter_num)
x_test,y_test=list_for_test(fold_al,0)
error.insert(4,cost_func(x_test,y_test,w,b))


print(overall_mse(error))
