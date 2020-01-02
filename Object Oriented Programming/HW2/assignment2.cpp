// Seda SUGUR
// 150160130
#include<fstream>
#include <iostream>
using namespace std;
#define  MAX_OPERATOR_SIZE 9

class Operator
{
private:
    int center_x;
    int center_y;
    int op_size;
public:
    Operator(int new_x, int new_y, int new_size);
    
    void reset(int new_x, int new_y, int new_size){
        center_x = new_x;
        center_y = new_y;
        op_size = new_size;
    };
    void set_x(int new_x){
        center_x = new_x;
    };
    int get_x(){
        return center_x;
    };

    void set_y(int new_y){
        center_y = new_y;
    };
    int get_y(){
        return center_y;
    };

    void set_size(int new_size){
        op_size = new_size;
    };
    int get_size(){
        return op_size;
    };
};
Operator::Operator(int new_x, int new_y, int new_size)
{
    center_x = new_x;
    center_y = new_y;
    op_size = new_size;
}

class ArithmeticOperator: public Operator
{
private:
    char sign;
public:
    ArithmeticOperator(int x, int y, int size, char sign);
    char get_sign(){
        return sign;
    };
    //prints out operator's center location, size and sign character
    void print_operator();
};

ArithmeticOperator::ArithmeticOperator(int x, int y, int size, char sign):Operator(x, y, size)
{   
    if(sign == 'x' || sign== 'X' || sign== '+' || sign== '-' || sign== '/'){
        this->sign = sign;
    }
    else{
        cout<<"SIGN parameter is invalid!"<< endl;
        
    }    
}

class OperatorGrid
{
private:
    int grid_rows;
    int grid_cols;
    char **grid;
    int num_operators=0;
    ArithmeticOperator *operators[MAX_OPERATOR_SIZE];
public:
    OperatorGrid(int rows, int cols);
    ~OperatorGrid();
    int delete_operator(int num);
    int find_which_operator(int,int);
    bool placed_old_place(ArithmeticOperator *F);
    bool border(ArithmeticOperator *);
    int conflict(ArithmeticOperator *,int *count);
    bool place_operator(ArithmeticOperator *);
    bool move_operator(int x,int y, char direction,int move_by);
    void print_operators(){
    for(int i =0;i<num_operators;i++)
    {   
        operators[i]->ArithmeticOperator::print_operator();
    }
    };
};

OperatorGrid::OperatorGrid(int rows, int cols)
{
    grid_rows= rows;
    grid_cols = cols;
    grid=new char*[grid_rows];

    for(int i=0; i< grid_rows;i++){
       grid[i]=new char[grid_cols];
        for(int j=0; j<grid_cols; j++){
            grid[i][j] = '0';
        }
    }
}
OperatorGrid::~OperatorGrid()
{
    for(int i=0; i<grid_rows; i++){
        delete[] grid[i];
    }
    delete[] grid;

    cout<<"DESTRUCTOR: GIVE BACK["<<grid_rows<<","<<grid_cols<<"] chars."<< endl;
    cout<< "DESTRUCTOR: GIVE BACK["<<num_operators<<"] Operators."<< endl;
}
int OperatorGrid::find_which_operator(int x,int y)
{
    char _sign = grid[x-1][y-1];
    for(int j=0; j<num_operators; j++){
        char sign = operators[j]->get_sign();
        if(sign == _sign){//which operator have this sign
        int op_size = operators[j]->get_size();
        int center_x = operators[j]->get_x();
        int center_y = operators[j]->get_y();
            if(sign=='x' || sign=='X'){		
		        for (int i = 1; i < op_size+1; i++){
                    if((((center_x)== x) && ((center_y)== y)) ||(((center_x+i)== x) && ((center_y+i) == y)) || (((center_x-i) == x) && ((center_y-i) ==y))|| (((center_x+i) == x) && ((center_y-i)== y)) || (((center_x-i)== x) && ((center_y+i)== y)))
                    {   
                        return j;//return place of object in the operators array
                    }          			
                }		
            }
            if (sign=='+')
	        {  
		        for (int i = 1; i < op_size+1; i++){
                    if(((center_x) == x && (center_y) == y) || ((center_x)==x  && (center_y+i)== y) || ((center_x)== x && (center_y-i)== y) || (((center_x+i) ==x)&& ((center_y)== y)) || ((center_x-i)== x && (center_y)== y))
                    {
                        return j;
                    }
			    }
            }
            if(sign=='-'){
		        for (int i = 1; i < op_size+1; i++){
                    if(((center_x)== x && (center_y-1)== y) || ((center_x)== x && (center_y+i)== y) || ((center_x)== x && (center_y-i)== y))
                    {
                        return j;
                    }			
                }
            }
            if(sign=='/'){				
		        for (int i = 1; i < op_size+1; i++){
                    if(((center_x)== x && (center_y)== y) || ((center_x+i)== x && (center_y-i)== y) || ((center_x-i)== x && (center_y+i)== y))
                    {
                        return j;
                    }		
			    }	 
            }
        } 
    }
    return 0;
}
int OperatorGrid::delete_operator(int num)
{//for delete before move operation
    char sign = operators[num]->get_sign();
    int op_size = operators[num]->get_size();
    int center_x = operators[num]->get_x();
    int center_y = operators[num]->get_y();
    if (sign=='+')
	{  
		for (int i =op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='0';
            grid[center_x-1][center_y-1+i]='0';
            grid[center_x-1][center_y-1-i]='0';
            grid[center_x-1+i][center_y-1]='0';
            grid[center_x-1-i][center_y-1]='0';
		}
    }
    if(sign=='x' || sign=='X')
    {		
	    for (int i = op_size; i > 0; i--){
    		grid[center_x-1][center_y-1]='0';
            grid[center_x-1+i][center_y-1+i]='0';
            grid[center_x-1-i][center_y-1-i]='0';         
            grid[center_x-1+i][center_y-1-i]='0';
            grid[center_x-1-i][center_y-1+i]='0';			
        }		
    }
    if(sign=='-')
    {
		for (int i = op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='0';
            grid[center_x-1][center_y-1+i]='0';
            grid[center_x-1][center_y-1-i]='0';
        }
    }

    if(sign=='/')
    {				
		for (int i = op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='0';
            grid[center_x-1+i][center_y-1-i]='0';
            grid[center_x-1-i][center_y-1+i]='0';
		}	 
    }
    return 0;
}
bool OperatorGrid::placed_old_place(ArithmeticOperator *F)
{
  
    char sign = F->get_sign();
    if(sign == 'x' || sign == 'X' || sign == '+' || sign == '-' || sign == '/'){
    int op_size = F->get_size();
    int center_x = F->get_x();
    int center_y = F->get_y();

    if (sign=='+')
	    {  
		  for (int i =op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='+';
            grid[center_x-1][center_y-1+i]='+';
            grid[center_x-1][center_y-1-i]='+';
            grid[center_x-1+i][center_y-1]='+';
            grid[center_x-1-i][center_y-1]='+'	;
			}
        }

        if(sign=='x' || sign=='X'){		
		  for (int i = op_size; i > 0; i--){
    		grid[center_x-1][center_y-1]='x';
            grid[center_x-1+i][center_y-1+i]='x';
            grid[center_x-1-i][center_y-1-i]='x'  ;         
            grid[center_x-1+i][center_y-1-i]='x';
            grid[center_x-1-i][center_y-1+i]='x';			
            }		
        }
        if(sign=='-'){
	
		  for (int i = op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='-';
            grid[center_x-1][center_y-1+i]='-';
            grid[center_x-1][center_y-1-i]='-';
          }
        }

        if(sign=='/'){				
		for (int i = op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='/';
            grid[center_x-1+i][center_y-1-i]='/';
            grid[center_x-1-i][center_y-1+i]='/';
			}	 
        }    
    }
    return true;
}
bool OperatorGrid::move_operator(int x,int y, char direction,int move_by)
{
    int num = find_which_operator(x,y);//find the which operator num
    char sign = operators[num]->get_sign();
    if(sign == 'x' || sign == 'X' || sign == '+' || sign == '-' || sign == '/'){
    
    int old_center_x= operators[num]->get_x();
    int old_center_y = operators[num]->get_y();
    
    int op_size = operators[num]->get_size();
    int new_center_x= old_center_x;
    int new_center_y = old_center_y;

    delete_operator(num);//delete the operator in grid

    int *count=new int[1];
    *count=0;

    if(direction == 'D'){
        new_center_x = operators[num]->get_x()+move_by;
        operators[num]->set_x(new_center_x);
    }
    if(direction == 'R'){
        new_center_y = operators[num]->get_y()+move_by;
        operators[num]->set_y(new_center_y);
    }
    if(direction == 'L'){
        new_center_y = operators[num]->get_y()-move_by;
        operators[num]->set_y(new_center_y);
    }
    if(direction == 'U'){
        new_center_x = operators[num]->get_x()-move_by;
        operators[num]->set_x(new_center_x);
    }
   
    if(border(operators[num])==false){
        cout << "BORDER ERROR: "<<sign <<" can not be moved from ("<< old_center_x <<","<< old_center_y<<") to ("<< new_center_x <<","<<  new_center_y << ")."<<endl;      
    }
    conflict(operators[num],count);
    if(count[0]==0){
        cout << "CONFLICT ERROR: "<<sign<<" can not be moved from ("<< old_center_x <<","<< old_center_y<<") to ("<< new_center_x <<","<<  new_center_y << ")."<<endl;    
    }
    if((border(operators[num]) == true) && (count[0]==1)){
        cout << "SUCCESS: "<<sign <<" moved from ("<< old_center_x <<","<< old_center_y<<") to ("<< new_center_x <<","<<  new_center_y << ")."<<endl;
        
       
        //place on grid
        if (sign=='+')
	    {  
		  for (int i =op_size; i > 0; i--){
			grid[new_center_x-1][new_center_y-1]='+';
            grid[new_center_x-1][new_center_y-1+i]='+';
            grid[new_center_x-1][new_center_y-1-i]='+';
            grid[new_center_x-1+i][new_center_y-1]='+';
            grid[new_center_x-1-i][new_center_y-1]='+'	;
			}
        }

        if(sign=='x' || sign=='X'){		
		  for (int i = op_size; i > 0; i--){
    		grid[new_center_x-1][new_center_y-1]='x';
            grid[new_center_x-1+i][new_center_y-1+i]='x';
            grid[new_center_x-1-i][new_center_y-1-i]='x'  ;         
            grid[new_center_x-1+i][new_center_y-1-i]='x';
            grid[new_center_x-1-i][new_center_y-1+i]='x';			
            }		
        }
        if(sign=='-'){
	
		  for (int i = op_size; i > 0; i--){
			grid[new_center_x-1][new_center_y-1]='-';
            grid[new_center_x-1][new_center_y-1+i]='-';
            grid[new_center_x-1][new_center_y-1-i]='-';
          }
        }

        if(sign=='/'){				
		for (int i = op_size; i > 0; i--){
			grid[new_center_x-1][new_center_y-1]='/';
            grid[new_center_x-1+i][new_center_y-1-i]='/';
            grid[new_center_x-1-i][new_center_y-1+i]='/';
			}	 
        }
    
    return true;
    }
    //If can not moved set the old center values and place on grid because you deleted 
    operators[num]->set_y(old_center_y);
    operators[num]->set_x(old_center_x);
    placed_old_place(operators[num]);
    }
    return false;
}
int OperatorGrid::conflict(ArithmeticOperator *F,int *count)
{
    
    char sign = F->get_sign();
    int op_size = F->get_size();
    int center_x = F->get_x();
    int center_y = F->get_y();
    
    if (sign=='+')
	{  
		  for (int i =0; i < op_size+1; i++){
            if(center_x+i>grid_rows || center_x-i < 1 || center_y+i > grid_cols || center_y-i < 1){
                *count=1;
                return 0;
            }
			if((grid[center_x-1][center_y-1]=='0')&& (grid[center_x-1][center_y-1+i]=='0') && (grid[center_x-1][center_y-1-i]=='0') && (grid[center_x-1+i][center_y-1]=='0') && (grid[center_x-1-i][center_y-1]=='0')){
				*count=1;
			}
             else{
                *count=0;
                return 0;
             } 
        }
    }
    if(sign=='x' || sign=='X'){		
		for (int i =0; i < op_size+1; i++){
            if(center_x+i>grid_rows || center_x-i < 1 || center_y+i > grid_cols || center_y-i < 1){
                *count=1;
                return 0;
            }
    		if( ( grid[center_x-1][center_y-1]=='0') && (grid[center_x-1+i][center_y-1+i]=='0')&& (grid[center_x-1-i][center_y-1-i]=='0') && (grid[center_x-1+i][center_y-1-i]=='0') && (grid[center_x-1-i][center_y-1+i]=='0')){
				*count=1;
			}
            else{
                *count=0;
                return 0;
            }}		}
    if(sign=='-'){	
		for (int i = 0; i < op_size+1; i++){
            if(center_y+op_size > grid_cols || center_y-op_size < 1)
            {
                *count=1;
                return 0;
            }
			if((grid[center_x-1][center_y-1]=='0') && (grid[center_x-1][center_y-1+i]=='0') && (grid[center_x-1][center_y-1-i]=='0')){
				*count=1;
			}
            else{
                *count=0;
                return 0;
            }
        }		
    }
    if(sign=='/')
    {			
        for (int i =0; i < op_size+1; i++){
            if(center_x+i>grid_rows || center_x-i < 1 || center_y+i > grid_cols || center_y-i < 1){
                *count=1;
                return 0;
            }
			if(  (grid[center_x-1][center_y-1]=='0') && (grid[center_x-1+i][center_y-1-i]=='0') && (grid[center_x-1-i][center_y-1+i]=='0')){
				*count=1;
			}
			else{
            	*count=0;
                return 0;
			}                                  
        }
    }	 
   
   return 0;
}
bool OperatorGrid::border(ArithmeticOperator *F)
{
    char sign = F->get_sign();
    int op_size = F->get_size();
    int center_x = F->get_x();
    int center_y = F->get_y();
    
    if (sign=='+' || sign=='x' || sign=='X' || sign=='/'){
        //for BORDER ERROR
        if(center_x+op_size>grid_rows || center_x-op_size < 1 || center_y+op_size > grid_cols || center_y-op_size < 1)
        {
            return false;     
        }
    }
    if (sign=='-'){
        //for border error
        if(center_y+op_size > grid_cols || center_y-op_size < 1)
        {
            return false;
        }
    }
    return true;
}
bool OperatorGrid::place_operator(ArithmeticOperator *F)
{   
    char sign = F->get_sign();
     
    if(sign == 'x' || sign == 'X' || sign == '+' || sign == '-' || sign == '/'){
        
    int op_size = F->get_size();
    int center_x = F->get_x();
    int center_y = F->get_y();
    int *count=new int[1];
    if(border(F)==false){
        cout << "BORDER ERROR: Operator "<<sign <<" with size "<< op_size << " can not be placed on ("<< center_x <<","<<  center_y << ")."<<endl;
    }
    conflict(F,count);
    if(*count==2){
        return 0;
    }
    //operators içine yerleşicek olanları atıcam en fazla 9 tane olucak. sonra bunu aritmeticteki print şeyini göstericem ama bunları print_operators de yapıcam
    if(count[0]==0){
        cout << "CONFLICT ERROR: Operator "<<sign<<" with size "<< op_size << " can not be placed on ("<< center_x <<","<<  center_y << ")."<<endl;
    }
    if((border(F) == true) && (count[0]==1)){
        cout << "SUCCESS: Operator "<< sign <<" with size "<< op_size<<" is placed on ("<< center_x <<","<<  center_y << ")."<<endl;
        
        operators[num_operators]=F;//operators arrayine basarılı olan operatorleri ve bilgilerini atadım.
        num_operators=num_operators+1;
        //gride yerlestirmeyi yaz
        if (sign=='+')
	    {  
		    for (int i =op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='+';
            grid[center_x-1][center_y-1+i]='+';
            grid[center_x-1][center_y-1-i]='+';
            grid[center_x-1+i][center_y-1]='+';
            grid[center_x-1-i][center_y-1]='+'	;
			}
        }

        if(sign=='x' || sign=='X'){		
		    for (int i = op_size; i > 0; i--){
    		grid[center_x-1][center_y-1]='x';
            grid[center_x-1+i][center_y-1+i]='x';
            grid[center_x-1-i][center_y-1-i]='x'  ;         
            grid[center_x-1+i][center_y-1-i]='x';
            grid[center_x-1-i][center_y-1+i]='x';			
            }		
        }
        if(sign=='-'){
	
		    for (int i = op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='-';
            grid[center_x-1][center_y-1+i]='-';
            grid[center_x-1][center_y-1-i]='-';
            }
        }

        if(sign=='/'){				
		    for (int i = op_size; i > 0; i--){
			grid[center_x-1][center_y-1]='/';
            grid[center_x-1+i][center_y-1-i]='/';
            grid[center_x-1-i][center_y-1+i]='/';
			}	 
        }
    }  
    }
    return true;
}
void ArithmeticOperator::print_operator(){
    cout << "ARITHMETIC_OPERATOR[" << this->get_sign() <<"], CENTER_LOCATION["<< this->get_x() << ","<<this->get_y() <<"], SIZE["<< this->get_size()<<"]"<< endl;

}
