/*
CSCI 2270 - 300
Author: Ryan Hoffman
TA: Abhidip Bhattacharyya
Assignment 1
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

struct Board //Define a struct to hold the data
{
    string type;
    string status;
    string price;
};

int main()
{
    const int MAX_SIZE=100;
    Board arrBoard[MAX_SIZE];
    //string filename;
    fstream inFile;
    string line, type, status, price;
    inFile.open("garageSale.txt");
    if(!inFile.is_open())
    {    cout<<"Something went wrong!"<<endl;
        return 0;
    }
    while(getline(inFile, line))
    {
        stringstream sso(line);
        getline(sso, type, ',');
        getline(sso, status, ',');
        getline(sso, price);
        for(int i=0; i<line.length(); i++)
        {
            if(line[i]=='f') //for sale will be 0.
                status="0";
            else if(line[i]=='w' && line[i+2]=='n') //wanted will be 1.
                status="1";
        }
        for(int j=0; j<3; j++)
        {
            arrBoard[j].type=type;
            arrBoard[j].status=status;
            arrBoard[j].price=price;
        }
    }
    inFile.close();
    cout<<arrBoard[1].type<<" "<<arrBoard[1].status<<" "<<arrBoard[1].price<<endl;
    return 0;
}
