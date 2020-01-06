/*
Assignment 3 - Communication between towers
Author: Ryan Hoffman
Class: CSCI 2270
Instructor: Zagrodzki
TA: Abhidip Bhattacharyya
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct city
{
	string cityName;
	string message;
	city *next;
	city(){};
	city(string initName, city *initNext, string initMessage)
    {
		cityName=initName;
		next=initNext;
		message=initMessage;
	}
};

city *buildNetwork()
{
	string names[]={"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
	city *head=new city(names[0], NULL, "");
	city *p=head;
	for(int i=1; i<10; i++)
    {
		city *temp=new city(names[i], NULL, "");
		p->next=temp;
		p=temp;
	}
	return head;
}

city *addCity(city *head, city *previous, string cityName)
{
	if(head==NULL)
    {
		city *newCity=new city(cityName, NULL, "");
		head=newCity;
		return head;
	}
	city *newCity=new city(cityName, NULL, "");
	if(previous==NULL)
    {
		newCity->next=head;
		head=newCity;
		return head;
	}
	newCity->next=previous->next;
	previous->next=newCity;
	return head;
}

void transmitMsg(city *head)
{
	if(head==NULL)
    {
		cout<<"Empty list"<<endl;
		return;
	}
	ifstream msgFile;
	msgFile.open("messageIn.txt");
	string word;
	if(msgFile.is_open())
    {
		city *temp=head;
		while(msgFile>>word)
        {
			temp=head;
			temp->message=word;
			while(temp!=NULL)
            {
				if(temp->next==NULL)
                {
					cout<<temp->cityName;
					cout<<" received ";
					cout<<temp->message<<endl;
					break;
				}
				cout<<temp->cityName;
				cout<<" received ";
				cout<<temp->message<<endl;
				temp->next->message=temp->message;
				temp->message="";
				temp=temp->next;
			}
		}
	}
	msgFile.close();
}

void printPath(city *head)
{
	cout<<"===CURRENT PATH==="<<endl;
	if(head==NULL)
    {
		cout<<"NULL"<<endl;
		return;
	}
	city *temp=head;
	while(temp!=NULL)
    {
		if (temp->next==NULL)
        {
			cout<<temp->cityName;
			cout<<" -> ";
			cout<<" NULL"<<endl;
			break;
		}else{
			cout<<temp->cityName;
			cout<<" -> ";
			temp=temp->next;
		}
	}
	cout<<"=================="<<endl;
}

city *locateCity(city *head, string previous)
{
	city *temp=head;
	while(temp!=NULL)
    {
		if(temp->cityName==previous)
        {
			return temp;
		}else
			temp=temp->next;
	}
	return NULL;
}

void printMenu()
{
	cout<<"======Main Menu======"<<endl;
	cout<<"1. Build Network"<<endl;
	cout<<"2. Print Network Path"<<endl;
	cout<<"3. Transmit Message Coast-To-Coast"<<endl;
	cout<<"4. Add City"<<endl;
	cout<<"5. Quit"<<endl;
}

int main()
{
	string names[]={"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
	city *head=new city();
	string userInput;
	string cityNew, cityPrevious;
	while(userInput!="5")
    {
		printMenu();
		getline(cin, userInput);
		if(userInput=="1"){
			head=buildNetwork();
			//printPath(head);
		}else if(userInput=="2")
			printPath(head);
		else if(userInput=="3")
			transmitMsg(head);
		else if(userInput=="4")
        {
			cout<<"Enter a City name:"<<endl;
			getline(cin, cityNew);
			cout<<"Enter a previous City name: "<<endl;
			getline(cin, cityPrevious);
			head=addCity(head, locateCity(head, cityPrevious), cityNew);
		}
		else if(userInput=="5")
			cout<<"Goodbye!"<<endl;
		else
			cout<<"Invalid Input!"<<endl;
	}
	delete head;
	return 0;
}
