/*
Recitation 1
#5
• separate header file to declare a function is useful when we
    need to reuse the function in multiple source files
• include the header file in the funcdef.cpp file and the main.cpp file
    define the function in the funcdef.cpp
• In the main.cpp we call the declared function
*/
#include <iostream>
#include "function.h"

using namespace std;

//Compile and run in the terminal as follows:
// g++ -std=c++11 main.cpp funcdef.cpp -o func
int main()
{
    cout<<"2+3="<<add(2,3)<<endl;
    //outputs 2+3=5
    return 0;
}
