//Seda Sugur 150160130

#include"vector.h"
#include"polynomial.h"
#include<iostream>
#include<fstream>

using namespace std;
int Pol::pol_list_length = 0;
int Vector::vector_list_length = 0;

void for_vector(Vector*);
void for_pol(Pol*);

int main(){
    Vector* vector_list = Vector::create_list("./Vector.txt");
    Pol* pol_list = Pol::create_list("./Polynomial.txt");
  	cout << "Polynomial and Vector List Program!" << endl;
    cout << "Polynomials and Vectors are read from text files!" << endl;
	
    bool flag=false;
    cout << "Possible Actions:\n1. Print Polynomial and Vector lists\n2. Do a polynomial operation\n3. Do a vector operation\n4. Help: Print possible actions\n0. Exit the program\n\n";
    while(!flag){
        int option;
		cout << "Enter an option: ";
		cin >> option;
    	switch (option)
		{
		default:
			break;
		case 1: // print polynomial & vector lists
            cout << "Vectors:" << endl;
	        for (int i = 0; i < Vector::vector_list_length; i++)
	    {
            cout << i + 1 << ". " << vector_list[i] << endl;
	    }
	        cout << endl;
			cout << "Polynomials:" << endl;
	        for (int i = 0; i < Pol::pol_list_length; i++)
	    {
		    cout << i + 1 << ". " << pol_list[i] << endl;
	    }
	        cout << endl;			
			break;
		case 2: // polynomial operations
			for_pol(pol_list);
			break;
		case 3: // vector operations
            	cout << "Which vector operation would you like to do?(+: addition, *: scalar multiplication, .: dot product):" << endl;
	        for_vector(vector_list);
			break;
		case 4: //help
			cout << "Possible Actions:\n1. Print Polynomial and Vector lists\n2. Do a polynomial operation\n3. Do a vector operation\n4. Help: Print possible actions\n0. Exit the program\n\n";
			break;
		case 0:
			flag = true;
			break;
		}
	}
    
    return 0;
}
void for_vector(Vector* vector_list){
    int input_1, input_2;
	        char operation;
	        cin >> input_1 >> operation >> input_2;
	        cout << vector_list[input_1 - 1] << " " << operation << " "; 
	        if (operation == '*') {
		        cout << input_2 << " = " << vector_list[input_1 - 1] * input_2 << "\n\n"; 
		        return;
	        }
	        cout << vector_list[input_2 - 1];
	        if (vector_list[input_1 - 1].get_size() == vector_list[input_2 - 1].get_size()){
		        if (operation == '+') {
			    cout << " = " << vector_list[input_1 - 1] + vector_list[input_2 - 1] << "\n\n";
		        }
		    else if (operation == '.') {
		    	cout << " = " << vector_list[input_1 - 1] * vector_list[input_2 - 1] << "\n\n";
		        }
	        }
	        else {
		        cout << " operation can not be performed, since their size is not equal\n\n";
	        }
			
}

void for_pol(Pol* pol_list)
{
	cout << "Which polynomial operation would you like to do?(+: addition, *: multiplication):" << endl;
	int input_1, input_2;
	char operation;
	cin >> input_1 >> operation >> input_2;
	cout << "( " << pol_list[input_1 - 1] << " ) " << operation << " ( " << pol_list[input_2 - 1] << " ) = "; 
	if (operation == '+') {
		cout << pol_list[input_1 - 1] + pol_list[input_2 - 1] << "\n\n";
	}
	else if (operation == '*') {
		cout << pol_list[input_1 - 1] * pol_list[input_2 - 1] << "\n\n";
	}
}
