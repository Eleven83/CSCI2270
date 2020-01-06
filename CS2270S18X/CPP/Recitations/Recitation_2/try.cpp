#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct CarData
{
    string make;
    string model;
    string year;
};

int main()
{
    CarData car[10];
    string line make, model, year;
    ifstream inFile;
    inFile.open("carfile.txt");
    if(inFile.is_open())
    {
        cout<<"Opened successfully"<<endl;
        while(getline(inFile, line)) //parse the lines in the File
        {
            // stringstream sso(line);
            // for(int i=0; i<1; i++)
            // {
            //     line
            // }
            for(int i=0; i<10; i++)
            {
                getline(inFile, car[i].make, ' ');
                getline(inFile, car[i].model, '\0');
                getline(inFile, car[i].year);
            }
            ofstream outFile;
            outFile.open("outfile.txt");
            for(int c=0; c<10; c++)
            {
                outFile<<"Make: "<<car[c].make<<" Model: "<<car[c].model<<" Year: "<<car[c].year<<endl;
            }
            outFile.close();
        }
        inFile.close();
    }else{
        cout<<"File unsuccessfully opened"<<endl;
    }
    return 0;
}
