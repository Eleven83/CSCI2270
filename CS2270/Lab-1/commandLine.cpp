/*
Recitation 1
#4b
Program to:
    • practice using the command line to compile and run files
    • practice using command line arguments from the main function
*/
/*
C:\Users\ryhof\Desktop\CS2270\Lab-1>commandLine arg1 arg2 arg3
OUTPUT AFTER COMPILE AND RUNNING THE ABOVE ARGUMENTS 
Number of arguments: 4
Program arguments:
Argument #0: commandLine
Argument #1: arg1
Argument #2: arg2
Argument #3: arg3
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //The parameters in the main will be passed in from the terminal
    //argc is the total number of arguments you passed to the main function from
    //the terminal.
    //argv is an array storing each of the arguments passed

    cout<<"Number of arguments: ";
    cout<<argc<<endl;
    cout<<"Program arguments: "<<endl;
    for(int i=0; i<argc; i++)
    {
        cout<<"Argument #"<<i<<": ";
        cout<<argv[i]<<endl;
    }
}
