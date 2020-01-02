//Seda Sugur 150160130



#ifndef _VECTOR_H         
#define _VECTOR_H
#include<fstream>
#include <iostream>
using namespace std;

class Vector{
    int size;
    int *value;
public:
	static int vector_list_length;
    Vector();//Def. Constructor
    Vector(int, int*);//Constructor
    Vector(Vector &);//Copy Constructor
    Vector& operator+(Vector &) ;
    Vector& operator*(int) ;//For scalar mult.
    int operator*(Vector&);//dot product
    void operator=(Vector&);
    int* get_value();
    int get_size();
    friend ostream& operator<<(ostream& ,Vector&);
    static Vector * create_list(const char *);
   
};


#endif
