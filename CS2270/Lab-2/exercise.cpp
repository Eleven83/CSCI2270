#include <iostream>
#include <fstream>

using namespace std;

//Dynamically doubling array 
void resize(int **arrayPtr, int *capacity) //pointer to a pointer allows to return a value
{
	// Implement the resizing logic here
	int newCapacity=*capacity*2;
	//resizing from *capacity to newCapacity
	int *newArray=new int[newCapacity];
	//copying the data
	for(int i=0; i<*capacity; i++)
	{
		newArray[i]=(*arrayPtr)[i];
	}
	delete [] *arrayPtr;
	*arrayPtr=newArray;
	*capacity=newCapacity;
}

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		return -1;
	}
	string filename=argv[1];
	ifstream data;
	data.open(filename);

	int cap=10;
	int *arrPtr;

	// Dynamically allocate space here for the array
	arrPtr=new int[cap];
	int numOfElement=0;
	string temp;

	if(data.is_open())
	{
		while(getline(data, temp))
		{
			int toBeInsert=stoi(temp);
			if(numOfElement==cap)
			{
				// Implement this function
				resize(&arrPtr, &cap);
			}
			arrPtr[numOfElement]=toBeInsert;
			numOfElement++;
		}
		data.close();
	}

	for(int i=0; i<numOfElement; i++)
	{
		cout<<"Num: "<<arrPtr[i]<<endl;
	}
	return 0;
}
