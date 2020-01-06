/*
Recitation 1
#4a
Program to:
    • practice using the command line to compile and run files
*/
#include <iostream>

using namespace std;

/*
    To run from command line:
        1. Open command prompt/terminal
        2. Navigate to the folder where this file is located using the following:
            cd desktop\cs2270\Lab-1
        3. type the following to compile the file and give it an 'exe' filename:
            g++ -std=c++11 hello.cpp -o hello
        NOTE: 'g++' is the name of the compiler program and '-std=c++11' tells
               the compiler to use the 2011 version of c++.
               hello.cpp is the file that we are compiling and '-o' tells the
               compiler to write the output to a file called 'hello' which will
               become hello.exe in the same folder.
        4. After the file compiles, just type hello and hit enter to run it.
*/
int main()
{
    cout<<"Hello World!"<<endl;

    return 0;
}
