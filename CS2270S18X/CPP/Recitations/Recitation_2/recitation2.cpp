/*
CSCI 2270
Author: Ryan Hoffman
TA: Abhidip Bhattacharyya
Recitation 2
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct CarData
{
    string make;
    string model;
    string year;
};

int main(int argc, char *argv[])
{
    CarData car[10];
    ifstream inFile;
    string line;
    inFile.open(argv[1]);
    if(inFile.is_open())
    {
        cout<<"Opened successfully"<<endl;
        while(!inFile.eof()) //parse the lines in the File
        {
            for(int i=0; i<10; i++)
            {
                getline(inFile, car[i].make, ' ');
                getline(inFile, car[i].model, '\0');
                getline(inFile, car[i].year);
            }
            ofstream outFile;
            outFile.open(argv[2]);
            for(int c=0; c<1; c++)
            {
                outFile<<car[c].make<<" "<<car[c].model<<" "<<car[c].year;
            }
            outFile.close();
        }
        inFile.close();
    }else{
        cout<<"File unsuccessfully opened"<<endl;
    }
    return 0;
}
