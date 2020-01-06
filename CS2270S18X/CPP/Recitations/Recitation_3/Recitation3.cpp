/*
CSCI 2270
Author: Ryan Hoffman
TA: Abhidip Bhattacharyya
Recitation 3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// void resize(int* &oldArray, int *capacity)
// {
//     int newCapacity=(*capacity)*2;
//     int *newArray=new int[newCapacity];
//     //copy data from oldArray to newArray
//     for(int i=0; i<*capacity; i++)
//     {
//         newArray[i]=oldArray[i];
//     }
//     delete [] oldArray;
//     oldArray=newArray;
//     *capacity=newCapacity;
// }
int main()
{
    int A[]={30, 10, 12};
    int capacity=3;
    int newCapacity=(capacity)*3;
    int *newArray=new int[newCapacity];
    //copy data from oldArray to newArray
    for(int i=0; i<*capacity; i++)
    {
        newArray[i]=A[i];
    }
    delete [] A;
    A=newArray;
    *capacity=newCapacity;
    for(int i=0; i<newCapacity; i++)
    {
        if(i%3==0)
        {
            newArray[i]=A[i/3];
        }else
            newArray[i]=0;
    }
// int main(int argc, char const *argv[])
// {
//     if(argc!=2)
//     {
//         return -1;
//     }else{
//         ifstream inFile;
//         inFile.open(argv[1]);
//         //array=dynamically allocate space of length capacity
//         int* oldArray;
//         int numOfElement=0;
//         if(inFile.is_open())
//         {
//             int capacity=3;
//             oldArray=new int[capacity];
//             string line;
//             int numOfElement=0;
//             while(getline(inFile, line))
//             {
//                 if(numOfElement==capacity)
//                 {
//                     resize(oldArray, &capacity);
//                 }
//                 oldArray[numOfElement]=(int)stoi(line);
//                 numOfElement++;
//                 cout<<"Num of element "<<numOfElement<<" capacity "<<capacity<<" "<<oldArray[numOfElement-1]<<endl;
//             }
//             for(int i=0; i<numOfElement; i++)
//             {
//                 cout<<oldArray[i]<<endl;
//             }
//         }
//         inFile.close();
    }
    return 0;
}
