
//Seda Sugur 150160130

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<random>
#include <stdexcept>

using namespace std;

float exp_num(int n){
    float exp_number = 0.0;
    exp_number = (n - 1)/float(2);
    return exp_number;
}
int main(int argc, char* argv[]){
    int array_size=0; //-> 1 time
    int ENC_DUP = 0; // 1 time
    try
    {
        array_size = stoi(argv[1]);
    }
    catch(invalid_argument& e)
    {
        cout<<  "You must use integer numbers!"<<endl;
    return 0;
    }
    try
    {
        if(array_size <= 0)
        {
            throw array_size;
        }   
    int* array = NULL;   // Pointer to int, initialize to nothing.         
    array = new int[array_size];  // Allocate n ints and save ptr in a. n time

    mt19937 gen(time(NULL));
    uniform_int_distribution<int> distr(1, array_size);
    //fill the array with uniformly random numbers
    for (int i=0; i < array_size; i++) // n+1 times
    { 
        array[i] = distr(gen);  // n times
    }
    //print the array
    cout<<"ARRAY:"<<endl;
    for (int a=0; a < array_size; a++) //n+1 times
    {
        if((a)%10==0 && a!=0)
        {
            cout<<'\n';
        }
        cout<<array[a]<<' ' ; // n times
        
    }

    //Calculate expected number
    cout << "\n\nEXPECTED NUMBER OF DUPLICATIONS = " << exp_num(array_size) << endl; // 1 time

    //print dupl. indexes
    for(int i=0; i<array_size-1 ; i++)
    {
        for(int j=i+1 ; j<array_size; j++)
        {
            if(array[i]==array[j])
            {
                if ((ENC_DUP)%10==0)
                {
                    cout<<'\n';
                }
                cout<< "("<<(i+1)<<","<<(j+1)<<") ";
                ENC_DUP++;
            }
        }
    }

    //count dup.
    cout << "\n\nENCOUNTERED NUMBER OF DUPLICATIONS = " << ENC_DUP <<'\n' << endl; // 1 time
    delete [] array;  // When done, free memory.
    }

    catch(int a)
    {
        cout<< "Number should be greater than 0!"<<endl;
    }

    return 0;
}