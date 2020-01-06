#include <iostream>

using namespace std;

void passByValue(int a)
{
    a++;
}
void passByPointer(int *ptr)
{
    cout<<"Address stored in pointer: "<<ptr<<endl;
    *ptr=*ptr+1;
    (*ptr)++;

}
int main()
{
    int a=5; //regular variable
    cout<<&a<<endl;
    //pointer and address it points to have to be the same type
    int *b=&a; //b is a pointer. It stores the address of a.
    //* has two meanings
    //use it to declare a pointer
    //use it to dereference a pointer
    //dereference-go to address stored in pointer and get the value at that address

    cout<<&b<<", "<<b<<", "<<*b<<endl;

    a=10;
    //what is the value of *b? It has changed to 10.
    cout<<&b<<", "<<b<<", "<<*b<<endl;
    //
    int c=20;
    b=&c; //change address stored in b to address of c (instead of a)
    cout<<*b<<endl; //prints 20

    int arrayA[5];
    cout<<arrayA<<endl; //name of array gives us address of first element in array
    //
    // //functions
    passByValue(a);
    cout<<a<<endl; //prints 10, a unchanged
    cout<<"address stored in b: "<<b<<endl;
    passByPointer(b); //updates the value at the address stored in b
    cout<<*b<<endl; //prints 22

    return 0;
}
