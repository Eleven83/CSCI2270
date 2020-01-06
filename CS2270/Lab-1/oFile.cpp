/*
Recitation 1
#7a
    •Showing file operations
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //File writing
    //Creates instance of ofstream and opens the file
    ofstream oFile("filename.txt");

    //Outputs to filename.txt through oFile
    oFile<<"Inserted this text into filename.txt";

    //Close the file stream
    oFile.close(); 

    return 0;
}
