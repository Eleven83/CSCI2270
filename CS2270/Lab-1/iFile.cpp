/*
Recitation 1
#7b
    •Showing file operations
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //File reading
    char str[10];

    //Opens the file for reading
    //Ensure the filename.txt is present in the same directory as the source file
    ifstream iFile("filename.txt");

    //Reads one string from the file
    iFile>>str;

    //Outputs the file contents
    cout<<str<<endl;

    //waits for a keypress
    cin.get();
    //iFile is closed

    return 0;
}
