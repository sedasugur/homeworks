//Seda Sugur 150160130

#include"polynomial.h"

#include<fstream>
using namespace std;


Pol::Pol(){
    degree=0;
    value=NULL;
}

Pol::Pol(int degree,int *valuelist){
    this->degree=degree;
    this->value=new int[degree+1];
    for(int i=degree; i>=0; i--){
        this->value[i]=valuelist[i];
    }
}

 Pol::Pol(Pol &object){
     degree=object.degree;
     value=new int[degree+1];
     for(int i=degree; i>=0; i--){
         value[i]=object.value[i];
     }
 }
Pol::~Pol(){
	delete[] value;
}

Pol& Pol::operator+(Pol &object){

    Pol *bigger_pol, *smaller_pol;
	if (this->degree > object.degree)
	{
		bigger_pol = this;
		smaller_pol = &object;
	}
	else
	{
		bigger_pol = &object;
		smaller_pol = this;
	}
	
	Pol* result = new Pol(bigger_pol->degree,bigger_pol->value);

	for (int i = smaller_pol->degree; i >=0; i--)
	{
		result->value[i] += smaller_pol->value[i];
	}

	return *result;
    
}

Pol& Pol::operator*(Pol& object){
	int new_degree = this->degree + object.degree;
	int* result_values = new int[new_degree + 1];
	for (int i = 0; i < new_degree + 1; i++)
	{
		result_values[i] = 0;
	}
	for (int i = this->degree; i >=0; i--)
	{
		for (int k = object.degree; k >=0; k--)
		{
			result_values[i + k] += this->value[i] * object.value[k];
		}
	}

	Pol *result = new Pol(new_degree, result_values);
	return *result;
}

int Pol::get_degree(){
	return this->degree;
}

int* Pol::get_value(){
	return this->value;
}

void Pol_read(){
    
}
ostream& operator<<(ostream& os,Pol& pol){
    int degree = pol.get_degree();
	int *value = pol.get_value();
	for (int i = degree; i >=0; i--) {
		if (value[i] == 0)
		{
			continue;
		}
		if (i != degree && value[i] > 0)
		{
			os << " + ";
		}
		if (value[i] != 1 || (value[i] == 1 && i == 0))
		{
			os << value[i];
		}
		if( i==1)
		{ 
			os << "x" ;
			continue;
		}

		if (i != 0)
		{
			os << "x^" << i;
		}
	}
    return os;
}
Pol* Pol::create_list(const char * file)
{
	Pol* list = NULL;
	ifstream myfile(file);
	if (myfile.is_open()) { 

		int obj_count;
		myfile >> obj_count;
		Pol::pol_list_length = obj_count;
		list = new Pol[obj_count]; 

		
		int degree;
		for (int obj_number = 0; obj_number < obj_count; obj_number++)
		{
			myfile >> degree;
			int* value = new int[degree + 1]; 
			for (int coefficient_index = degree; coefficient_index >=0; coefficient_index--)
			{
				myfile >> value[coefficient_index];
			}
			Pol pol(degree, value); 
			list[obj_number] = pol; 
			delete value; 
		}
	}
	myfile.close();
	return list;
}
void Pol::operator=(Pol& obj) 
{
	this->degree = obj.degree;
	delete[] this->value;
	this->value = new int[this->degree + 1];
	for (int i = 0; i < this->degree + 1; i++)
	{
		this->value[i] = obj.value[i];
	}
}

