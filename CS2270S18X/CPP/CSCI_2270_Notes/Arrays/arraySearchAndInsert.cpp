#include <iostream>

using namespace std;

//Declare a variable to hold the size of the array
int arrSize=10;
//Declare variable to be the index of the array
int index=0;
//Function to search an array for a specific value and return the index position of that value
int searchArray(int arr[], int value)
{
	bool found=false;
	//int index=-1;
	int i=0;
	while(!found && i<=arrSize-1)
	{
		if(arr[i]==value)
		{
			found=true;
			index=i;
		}else
			i++;
	}
	return index;
}

//Function to insert a new value in to the array
int insertElement(int arr[], int newElement, int position, int numElements)
{
	position=index;
	for(int i=numElements-1; i<index; i++)
	{
		arr[i+1]=arr[i];
	}
	arr[index]=newElement;
	numElements++;

	return 0;
}

int main()
{
	//cout<<index<<endl;
	int arr1[arrSize];
	//Outside loop iterates through,inside loop assigns values to each position
	for(int i=0; i<arrSize; i++)
	{
		for(int j=0; j<arrSize; j++)
			arr1[j]=j;
		cout<<"["<<arr1[i]<<"] ";
	}
	cout<<"\n\n";
	int n;
	int nVal;
	cout<<"What number would you like to find, 1-10"<<endl;
	cin>>n;
	searchArray(arr1, n);
	cout<<"We found "<<n<<" at position "<<index<<endl;
	cout<<"Enter the number you want to add: "<<endl;
	cin>>nVal;
	insertElement(arr1, nVal, index, arrSize);
	for(int k=0; k<arrSize; k++)
	{
		cout<<"["<<arr1[k]<<"] ";
	}
	return 0;
}
