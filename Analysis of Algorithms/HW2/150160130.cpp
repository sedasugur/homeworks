//Seda Sugur
//150160130

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;
class event{
    public:

    string event_name;
    string event_type;
    int time;
};

struct MinHeap 
{
private:
	// vector to store heap elements(events)
	vector<event> A;
	int PARENT(int i) 
	{ 
		return (i - 1) / 2; 
	}

	// return left child of A[i]	
	int LEFT(int i) 
	{ 
		return (2 * i + 1); 
	}

	// return right child of A[i]	
	int RIGHT(int i) 
	{ 
		return (2 * i + 2); 
	}

	void heapify_down(int i)
	{
		// get left and right child of node at index i
		int left = LEFT(i);
		int right = RIGHT(i);

		int smallest = i;

		// compare A[i] with its left and right child
		// and find smallest value
		if (left < size() && A[left].time < A[i].time)
			smallest = left;

		if (right < size() && A[right].time < A[smallest].time)
			smallest = right;

		// swap with child having lesser value and 
		// call heapify-down on the child
		if (smallest != i) {
			swap(A[i], A[smallest]);
			heapify_down(smallest);
		}
	}

	
	void heapify_up(int i)
	{
		
		if (i && A[PARENT(i)].time > A[i].time) 
		{
		
			swap(A[i], A[PARENT(i)]);
			
			// call Heapify-up on the parent
			heapify_up(PARENT(i));
		}
	}
	//for clock
	int Time_t = 0;
public:
	//clock ticks
	int Time(){
		return ++Time_t;
	}

	int size()
	{
		return A.size();
	}

	
	
	// insert event into the heap
	void insert(event event)
	{
		// insert the new event to the end of the vector
		A.push_back(event);

		int index = size() - 1;
		heapify_up(index);
	}

	// remove event at root
	void remove()
	{
		try {
			// if heap has no elements throw an exception
			if (size() == 0)
				throw Time_t;

			// replace the root of the heap with the last element
			// of the vector
			A[0] = A.back();
			A.pop_back();
			heapify_down(0);
		}
		// catch exception
		catch (int x) {
			cout <<"TIME "<< x <<": NO MORE EVENTS, SCHEDULER EXITS" << endl;
			exit(0);
		}
	}

	// return event with highest priority
	event top()
	{
		try {
			// if heap has no elements, throw an exception
			if (size() == 0)
			{
				throw Time_t;

			}// else return the top element
			
					return A[0];	
				
		}

		catch (int x) {
			cout <<"TIME "<< x <<": NO MORE EVENTS, SCHEDULER EXITS" << endl;
			exit(0);
		}
	}
};


int main(int argc, char *argv[])
{   
    MinHeap pq;
    ifstream myfile (argv[1]);
    while(!(myfile.eof())){
        event obj;
        string event_name;
        myfile >> event_name;
        obj.event_name=event_name;
        obj.event_type = "STARTED";
        myfile >> obj.time;
        pq.insert(obj);
        obj.event_type = "ENDED";
        myfile >> obj.time;
        pq.insert(obj);
    }


while (1)
{	
	int clock = pq.Time();
	if(clock < pq.top().time)
	{
		cout << "TIME "<< clock << ": NO EVENT" <<endl; 
	}

	else if(clock == pq.top().time)
	{
		
		
		while (clock == pq.top().time)
        {
            cout<<"TIME "<< clock << ": "<<pq.top().event_name << " "<< pq.top().event_type<<endl;            
            pq.remove();
			

		}  

	}
	
}

    return 0;
}