#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Student
{
    //ID, name, major
    int ID;
    string name;
    string major;
    Student(){}
    Student(int id, string n, string m)
    {
        ID=id;
        name=n;
        major=m;
    }
};

int main()
{
    //arrays
    int a[10]; //array of 10 integers called a
    for(int i=0; i<10; i++)
    {
        a[i]=i; //initialize a[i] to i
        cout<<a[i]<<endl;
    }
    int b[10];
    //b=a; //this does not copy a into b

    cout<<"a="<<a<<endl; //prints address of a

    return 0;
}
