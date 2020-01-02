//Seda Sugur 150160130

#include<fstream>
#ifndef _POLYNOMIAL_H     
#define _POLYNOMIAL_H
#include <iostream>
using namespace std;


class Pol{
    int degree;
    int *value;
public:
	static int pol_list_length;
    Pol();
    Pol(int,int*); //Constructor
    Pol(Pol &);//Copy Constructor
    ~Pol();
    Pol& operator+(Pol&);
    Pol& operator*(Pol&);
    void operator=(Pol& obj);
    void pol_read();
    int get_degree();
    int* get_value();
    friend ostream& operator<<(ostream& ,Pol&);
    

    static Pol* create_list(const char *);




};
#endif
