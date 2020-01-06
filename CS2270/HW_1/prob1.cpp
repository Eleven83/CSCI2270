/*
CSCI 2270 Fall 2018, Professor Gupta
TA: Saumya Sinha
Assignment 1
Author: Ryan Hoffman
9-5-2018
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

/*
Sorting algorithms to consider (Ch. 4):
    -Bubble sort
    -Insertion sort
    -Quicksort
    -Heapsort
    -Mergesort
For this problem I'll use Bubble sort.
*/

//Function to sort an array
void bubbleSort(int myArray[], int numEnts)
{
    //initialize the length to be the number of entries
    int length=numEnts;
    int temp;
    //Loop from to one less than the number of elements
    for(int i=0; i<length-1; i++)
    {
        //Inner loop will bubble the largest value to the last spot in the array
        for(int j=0; j<length-i-1; j++)
        {
            //Comparing the values
            if(myArray[j]>myArray[j+1])
            {
                //If [j] is bigger we let temp hold that value
                temp=myArray[j];
                //swap it with [j+1]
                myArray[j]=myArray[j+1];
                myArray[j+1]=temp;
            }
        }
    }
}

//Function to insert a new value into a sorted array
int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
    myArray[numEntries]=newValue;
    numEntries++;
    bubbleSort(myArray, numEntries);

    return numEntries;
}

int main(int argc, char const *argv[])
{
    int cap=10;
    int arr[cap];
    int numEnts=0; //actual number of filled entries in arr[]
    int newVal; //new value to be added to arr[]

    //ifstream myfile(argv[1]);
    ifstream myfile("prob1.txt");
    if(myfile.is_open())
    {
        string line;
        while(getline(myfile, line))
        {
            stringstream ss;
            ss<<line;
            ss>>newVal;
            numEnts=insertIntoSortedArray(arr, numEnts, newVal); //Updating the number of entries
            for(int i=0; i<numEnts; i++)
            {
                if(i!=0 || i==cap-1)
                {
                    cout<<", ";
                }
                cout<<arr[i];
            }
            cout<<endl;
        }
    }else
        cout<<"Error: Could not read from file."<<endl;

    return 0;
}
