/*
Recitation 1
#6d
    •Showing how the function call in main() is the same as the way it was done
     in arrExmp.cpp
*/
#include <iostream>

using namespace std;

void add2(int* a, int len)
{
    for(int i=0; i<len; i++)
    {
        a[i]+=2;
    }
}

int main()
{
    int a[]={1,2,3};
    add2(&a[0], 3); //the same as add2(a, 3)
    for(int i=0; i<3; i++)
    {
        cout<<a[i]<<endl; //outputs 3 4 5
    }
    return 0;
}
