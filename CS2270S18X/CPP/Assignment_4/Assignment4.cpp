/*
Assignment 4 - Communication between towers Part II
Author: Ryan Hoffman
Class: CSCI 2270
Instructor: Zagrodzki
TA: Abhidip Bhattacharyya
*/
#include "CommunicationNetwork.h"
#include <iostream>

using namespace std;

int main()
{
	CommunicationNetwork test;
	char choice;
	cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;
	do{
        cin>>choice;
        choice=toupper(choice);
        switch(choice){
            case '1':
                test.buildNetwork();
                break;
            case '2':
                test.printNetwork();
                break;
            case '3':
				char* filename=(char*)"messageIn.txt";
				test.transmitMsg(filename);
            	break;
			case '4':
				string newCityName, previousCityName;
				cout<<"Enter a city name:"<<endl;
				cin.ignore();
				getline(cin, newCityName);
				cout<<"Enter a previous city name:"<<endl;
				cin.ignore();
				getline(cin, previousCityName);
				test.addCity(newCityName, previousCityName);
                break;
            case '5':
				string cityNameIn;
				cout<<"Enter a city name:"<<endl;
				cin.ignore();
				getline(cin, cityNameIn);
				test.deleteCity(cityNameIn);
                break;
            case '6':
				test.deleteNetwork();
                break;
			case '7':
				cout<<"Goodbye!"<<endl;
				return 0;
				break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice!='7');
	return 0;
}
