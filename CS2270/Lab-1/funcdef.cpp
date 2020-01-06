/*
Recitation 1
#5
• separate header file to declare a function is useful when we
    need to reuse the function in multiple source files
• include the header file in the source file and define the function in the .cpp
•  
*/

#include "function.h"

int add(int a, int b)
{

    return a+b;
}
