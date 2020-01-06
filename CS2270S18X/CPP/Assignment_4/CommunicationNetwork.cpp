/*
Assignment 4 - Communication between towers Part II
Author: Ryan Hoffman
Class: CSCI 2270
Instructor: Zagrodzki
TA: Abhidip Bhattacharyya
*/
#include "CommunicationNetwork.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
    //constructor
}
CommunicationNetwork::~CommunicationNetwork()
{
    //destructor
    head=tail=NULL;
    deleteNetwork();
}
void CommunicationNetwork::addCity(string newCityName, string previousCityName)
{
	City *newCity=new City(newCityName, nullptr, nullptr, "");
	City *current=head;
	if(head==nullptr)
    {
		head=tail=newCity;
		return;
	}
	if(previousCityName=="First")
    {
		newCity->next=current;
		current->previous=newCity;
		head=newCity;
		return;
	}
	if(previousCityName=="")
    {
		City *temp=tail;
		temp->next=newCity;
		newCity->previous=temp;
		tail=newCity;
		return;
	}
	while(current!=nullptr)
    {
		if(current->cityName==previousCityName)
        {
			newCity->next=current->next;
			current->next=newCity;
			newCity->previous=current;
			return;
		}else{
			current=current->next;
		}
	}
}
void CommunicationNetwork::buildNetwork()
{
    string nameData[]={"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
    City *temp1, *temp2;
    head=new City(nameData[0], nullptr, nullptr, "");
    temp1=head;
    for(int i=1; i<10; i++)
    {
        temp2=new City(nameData[i], nullptr, nullptr, "");
        temp1->next=temp2;
        temp2->previous=temp1;
        temp1=temp2;
    }
    tail=temp1;
    CommunicationNetwork::printNetwork();
}
void CommunicationNetwork::transmitMsg(char *filename) //this is like a string
{
	if(head==nullptr)
    {
		cout<<"Empty list!"<<endl;
		return;
	}
	ifstream myFile;
	myFile.open(filename);
	string word;
	bool checkTail=false;
	if(myFile.is_open())
    {
		City *current=head;
		while(myFile>>word)
        {
			current=head;
			current->message=word;
			while(current!=nullptr)
            {
				if(current->next==nullptr)
                {
					cout<<current->cityName;
					cout<<" received ";
					cout<<current->message<<endl;
					checkTail=true;
				}
				if(current->previous==nullptr && checkTail==true)
                {
					checkTail=false;
					break;
				}
				if(checkTail==false)
                {
					cout<<current->cityName;
					cout<<" received ";
					cout<<current->message<<endl;
					current->next->message=current->message;
					current->message="";
					current=current->next;
				}
				if(checkTail==true)
                {
					current->previous->message=current->message;
					current->message="";
					current=current->previous;
					cout<<current->cityName;
					cout<<" received ";
					cout<<current->message<<endl;
				}
			}
		}
	}
	myFile.close();
}
void CommunicationNetwork::printNetwork()
{
    cout<<"===CURRENT PATH==="<<endl;
    City *temp=head;
    cout<<"NULL <- ";
    if(head==nullptr)
    {
        cout<<"Empty List!"<<endl;
        return;
    }else{
        while(temp!=nullptr)
        {
            if(temp->next==nullptr)
            {
                cout<<temp->cityName<<" -> ";
                cout<<"NULL"<<endl;
                break;
            }else{
                cout<<temp->cityName<<" <-> ";
                temp=temp->next;
            }
        }
    }
    cout<<"=================="<<endl;
}
void CommunicationNetwork::deleteCity(string cityNameIn)
{
    City *current=head;
	bool found=false;
	while(current!=nullptr)
    {
		if(current->cityName==cityNameIn)
        {
			if(current->previous==nullptr)
            {
				current->next->previous=current->previous;
				head=current->next;
			}else if(current->next==nullptr){
				current->previous->next=current->next;
				tail=current->previous;
			}else{
				current->previous->next=current->next;
				current->next->previous=current->previous;
			}
			found=true;
			delete current;
			break;
		}else{
			current=current->next;
		}
	}
	if(found==false)
        cout<<cityNameIn<<" not found"<<endl;
}
void CommunicationNetwork::deleteNetwork()
{
    City *current=head;
    while(current!=nullptr)
    {
        cout<<"deleting "<<current->cityName<<endl;
        deleteCity(current->cityName);
        current=current->next;
    }
}
