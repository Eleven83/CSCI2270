#include "PriorityQueue.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void menu()
{
cout<<"======Main Menu====="<<endl;
cout<<"1. Get Patient Information from File"<<endl;
cout<<"2. Add Patient to Priority Queue"<<endl;
cout<<"3. Show Next Patient"<<endl;
cout<<"4. Treat Next Patient"<<endl;
cout<<"5. Treat Entire Queue"<<endl;
cout<<"6. Quit"<<endl;
}

//Driver for handling program navigation
int main(int argc, char const *argv[])
{
    //Only argument from command line is the max queue size
    PriorityQueue newPQ(atoi(argv[1]));
    string fileName, name, severity, tTime;
    int totalTrtTime=0;
    int choice=0;
    while(choice!=6)
    {
        menu();
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                cout<<"Enter filename: "<<endl;
                cin>>fileName;
                ifstream inFile(fileName);
                if(!inFile.is_open())
                {
                    cout<<"Error: Could Not Read File."<<endl;
                    break;
                }else{
                    string line;
                    while(getline(inFile, line))
                    {
                        stringstream ss(line);
                        ss>>name;
                        ss>>severity;
                        ss>>tTime;
                        newPQ.enqueue(name, stoi(severity), stoi(tTime));
                    }
                }
                break;
            }
            case 2:
            {
                cout<<"Enter Patient Name:"<<endl;
                cin.ignore();
                getline(cin, name);
                cout<<"Enter Patient Severity:"<<endl;
                getline(cin, severity);
                cout<<"Enter Treatment Time:"<<endl;
                getline(cin, tTime);
                newPQ.enqueue(name, stoi(severity), stoi(tTime));
                break;
            }
            case 3:
            {
                if(!newPQ.isEmpty())
                {
                    cout<<"Patient Name: "<<newPQ.peekName()<<endl;
                    cout<<"Injury Severity: "<<newPQ.peekInjurySeverity()<<endl;
                    cout<<"Treatment Time: "<<newPQ.peekTreatmentTime()<<endl;
                }else{
                    cout<<"Queue empty."<<endl;
                    break;
                }
                break;
            }
            case 4:
            {
                if(!newPQ.isEmpty())
                {
                    totalTrtTime+=newPQ.peekTreatmentTime();
                    cout<<"Patient Name: "<<newPQ.peekName()<<" - Total Time Treating Patients: "<<totalTrtTime<<endl;
                    newPQ.dequeue();
                }else{
                    cout<<"Queue empty."<<endl;
                    break;
                }
                break;
            }
            case 5:
            {
                if(!newPQ.isEmpty())
                {
                    for(int i=0; i<atoi(argv[1]); i++)
                    {
                        totalTrtTime+=newPQ.peekTreatmentTime();
                        cout<<"Patient Name: "<<newPQ.peekName()<<" - Total Time Treating Patients: "<<totalTrtTime<<endl;
                        newPQ.dequeue();
                    }
                }else{
                    cout<<"Queue empty."<<endl;
                    break;
                }
                break;
            }
            case 6:
            {
                cout<<"Goodbye!"<<endl;
                break;
            }
        }
    }
    return 0;
}
