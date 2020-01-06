/*
Recitation 1
#6a
    •Showing how the function call in main() only passes a copy of the argument
     is passed to the funtion. The function cannot modify the original argument
*/
#include <iostream>

using namespace std;

void add2(int num)
{
    num=num+2;
}

int main()
{
    int a=10; //assigning the value 10 to variable 'a'

    add2(a); //when add2(a) is called here it does what it's supposed to, but it
            //doesn't change the value of 'a' that we're using in the main()
            //function because a=10 is sent only as a copy to add2().

    cout<<a; //The output will be 10 not 12

    return 0;
}
