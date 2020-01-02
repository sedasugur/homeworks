//Seda Sugur 150160130


#include"vector.h"

#include<fstream>
using namespace std;


Vector::Vector(){
    size=0;
    value=NULL;
}

Vector::Vector(int size,int *valuelist){
    this->size=size;
    this->value=new int[size];
    for(int i=0; i<this->size; i++){
        this->value[i]=valuelist[i];
    }
}

 Vector::Vector(Vector &object){
     size=object.size;
     value=new int[size];
     for(int i=0; i<size; i++){
         value[i]=object.value[i];
     }
 }

Vector& Vector::operator+(Vector &object){
    int *values_list=new int[this->size];
    for(int i=0; i<this->size; i++){
        values_list[i]=this->value[i]+object.value[i];
        
    }
    Vector *result=new Vector(this->size,values_list);
    return *result;
}

Vector& Vector::operator*(int scalar){//for scalar mult.
    int* values_list= new int[this->size];
    for(int i=0; i<this->size; i++){
        values_list[i]=this->value[i]*scalar;
    }
    Vector *result=new Vector(this->size,values_list);
    return *result;
}

int Vector::operator*(Vector &object){//for dot product
    int result=0;

    for(int i=0; i<this->size; i++){
        result+=this->value[i]*object.value[i];
    }
    return result;
}

int Vector::get_size(){
	return this->size;
}

int* Vector::get_value(){
	return this->value;
}

Vector * Vector::create_list(const char * file)
{
	Vector* list = NULL;
	ifstream myfile(file);
	if (myfile.is_open()) { // reading from file

		int obj_count=0;
		myfile >> obj_count;
		Vector::vector_list_length = obj_count;
		list = new Vector[obj_count]; 

		int size;
		for (int obj_number = 0; obj_number < obj_count; obj_number++)
		{
			myfile >> size;
			int* value = new int[size];
			for (int index = 0; index < size; index++)
			{
				myfile >> value[index];
			} 
            Vector vector(size, value);
			list[obj_number] = vector; 
			delete value; 
		}
	}
	myfile.close();
	return list;
}

ostream& operator<<(ostream& os,Vector& vector){
    int size = vector.get_size();
	os << "(";
	int *value = vector.get_value();
	for (int i = 0; i < size; i++) {
		os << value[i];
		if (i != size - 1)
		{
			os << ", ";
		}
	}
	os << ")";
    return os;
}
void Vector::operator=(Vector& obj)
{
	this->size = obj.size;
	delete[] this->value;
	this->value = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->value[i] = obj.value[i];
	}
}

