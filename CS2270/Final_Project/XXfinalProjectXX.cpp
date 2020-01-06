// ==========================================
// File: Assignment 3 starter code
// Author: Matt Bubernak
// Date: 1/29/2018
// Modified: Fall 2016 E.S.Boese, Fall 2018 Alex Curtiss
// Fall 2018 S. Gupta
// Description: Linked List Fun
// ==========================================
/*
Assignment 3
Modified by Ryan Hoffman
CSCI 2270 Fall 2018 Gupta
Date: 9-21-2018
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// DO NOT MODIFY THIS STRUCT
struct city
{
    string name; // name of the city
    city *next; // pointer to the next city
    int numberMessages; // how many messages passed through this city
    string message; // message we are sending accross
};

/* Function prototypes */
city* addCity(city *head, city *previous, string cityName );
city* deleteCity(city *head, string cityName);
city* deleteEntireNetwork(city *head);
city* searchNetwork(city *head, string cityName);
city* loadDefaultSetup(city *head);
void transmitMsg(city *head, string receiver, string message);
void printPath(city *head);
void displayMenu();
city* handleUserInput(city *head);

/* Purpose: displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu()
{
    cout << "Choose a Number to Start:" << endl;
    cout << "    ======Main Menu=====" << endl;
    //cout << "1. Build Network" << endl;
    cout << "1. Print Network Path" << endl;
    cout << "2. Transmit Secret Encoded Message" << endl;
    cout << "3. Add New Agent to the Network" << endl;
    cout << "4. Remove Agent from the Network" << endl;
    cout << "5. Clear Network" << endl;
    cout << "6. Quit" << endl;
}
/*
 * Purpose: handle the interaction with the user
 * @param head: the start of the linked list
 * @return: the start of the linked list
 *
 * DO NOT MODIFY THIS FUNCTION
 */
city* handleUserInput(city *head)
{
    bool quit = false;
    string s_input;
    int input;
    head = loadDefaultSetup(head);
    printPath(head);
    // loop until the user quits
    while (!quit)
    {
        displayMenu();
        // read in input, assuming a number comes in
        getline(cin, s_input);
        input = stoi(s_input);
        switch (input)
        {
            // print all nodes
            // case 1: //rebuild network
            // head = loadDefaultSetup(head);
            // printPath(head);
            // break;

            case 1: // print path
                printPath(head);
            break;

            case 2: //message is read in from file
            {
                string cityReceiver;

                cout << "Enter name of the agent to receive the message: "
                << endl;
                getline(cin, cityReceiver);
                cout << "Enter the message to send: " << endl;
                string message;
                getline(cin, message);

                transmitMsg(head, cityReceiver, message);
            }
            break;

            case 3:
            {
                string newCityName;
                string prevCityName;
                cout << "Enter a new agent name: " << endl;
                getline(cin, newCityName);
                cout << "Enter the previous agent name (or First): " << endl;
                getline(cin, prevCityName);
                // find the node containing prevCity
                city *tmp = NULL;
                if(prevCityName !="First")
                tmp = searchNetwork(head, prevCityName);
                // add the new node
                head = addCity(head, tmp, newCityName);
                printPath(head);
            }
            break;

            case 4: // delete agent
            {
                string city;
                cout << "Enter the agent to be terminated: " << endl;
                getline(cin, city);
                cout<<city<<" has been terminated."<<endl;
                head = deleteCity(head, city);
                printPath(head);

            }
            break;

            case 5: // delete network
            head = deleteEntireNetwork(head);
            break;

            case 6: // quit
            quit = true;
            cout << "Quitting... cleaning up path: " << endl;
            break;

            default: // invalid input
            cout << "Invalid Input" << endl;
            break;
        }
    }
    return head;
}

/*
 * Purpose: Add a new city to the network
 * between the city *previous and the city that follows it in the network.
 * Prints: `prev: <city name> new: <city name>` when a city is added,
 * prints _nothing_ if the city is being added to the _first_ position in
 * the list.
 * @param head: pointer to start of the list
 * @param previous: name of the city that comes before the new city, or null if
 *    the city is being added to the first position
 * @param cityName: name of the new city
 * @return: pointer to first node in list
 */
city* addCity(city *head, city *previous, string cityName )
{
    if(head==NULL)
    {
        city *newCity=new city;
        newCity->name=cityName;
        newCity->message="";
        newCity->numberMessages=0;
        newCity->next=NULL;
        head=newCity;
        return head;
    }
    city *newCity=new city;
    newCity->name=cityName;
    newCity->message="";
    newCity->numberMessages=0;
    newCity->next=NULL;
    if(previous==NULL)
    {
        newCity->next=head;
        head=newCity;
        return head;
    }
    newCity->next=previous->next;
    previous->next=newCity;
    // Only print this if previous is not NULL
    cout<<"prev: "<<previous->name<<"  new: "<<cityName<<endl;

    return head;
}

/*
 * Purpose: Search the network for the specified city and return a pointer
 * to that node
 * @param head: head of the list
 * @param cityName: name of the city to look for in network
 * @return: pointer to node of cityName, or NULL if not found
 * @see addCity, deleteCity
 */
city *searchNetwork(city *ptr, string cityName)
{
    while(ptr!=NULL)
    {
        if(ptr->name==cityName)
        {
            break;
        }else{
            ptr=ptr->next;
        }
    }
  return ptr;
}

/*
 * Purpose: deletes all cities in the network starting at the head city.
 * @param head: head of list
 * @return: NULL as the list is empty
 */
city* deleteEntireNetwork(city *head)
{
    if(head==NULL)
    {
        return head;
    }
    while(head!=NULL)
    {
        cout << "deleting: " << head->name << endl;
        city *next=head->next;
        delete head;
        head=next;
    }
    cout << "Deleted network" << endl;
    // Return head, which should be NULL
    return head;
}

/*
 * Purpose: transmit a message from city to city
 * @param head: pointer to head of the list
 * @param receiver: the name of the City to receive the message
 * @param message: the message to transmit*/
void transmitMsg(city *head, string receiver, string message)
{
    if(head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    city *sender=head;
    while(sender->name!=receiver)
    {
        sender->message=message;
        sender->numberMessages++;
        // Use the following output statements to print each node of the linked list:
        cout<<sender->name<<" [# messages passed: "<<sender->numberMessages<<"] received: "<<sender->message<<endl;
        sender=sender->next;
    }
    sender->message=message;
    sender->numberMessages++;
    // Use the following output statements to print each node of the linked list:
    cout<<sender->name<<" [# messages passed: "<<sender->numberMessages<<"] received: "<<sender->message<<endl;
}

/*
 * Purpose: delete the city in the network with the specified name.
 * @param head: first node in list
 * @param cityName: name of the city to delete in the network
 * @return: head node of list
 */
city* deleteCity(city *head, string cityName)
{
    city *previous=NULL;
    city *current=head;
    while(current!=NULL)
    {
        if(current->name==cityName)
        {
            if(previous==NULL)
            {
                head=current->next;
            }else{
                previous->next=current->next;
            }
            delete current;
            return head;
        }
        previous=current;
        current=current->next;
    }
    // If the city dosn't exist, use this output statement:
    cout << "Agent does not exist." << endl;
    return head;
}

/*
 * Purpose: prints the current list nicely
 * @param head: head of list
 */
void printPath(city *head)
{
    // Add code here to print the network path.
    cout<<"== CURRENT PATH =="<<endl;
    if(head==NULL)
    {
        cout<<"nothing in path"<<endl;
        return;
    }
    city *temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            cout<<temp->name;
            cout<<" -> ";
            cout<<" NULL"<<endl;
            break;
        }else{
            cout<<temp->name;
            cout<<" -> ";
            temp=temp->next;
        }
    }
    cout << "===" << endl;
}

/*
 * Purpose: populates the network with the predetermined cities
 * @param head: start of list
 * @return: head of list
 */
city* loadDefaultSetup(city *head)
{
    // Add code here to populate the LinkedList with the default values
    string names[]={"Agent 1", "Agent 2", "Agent 3", "Agent 4", "Agent 5", "Agent 6"};
    head=deleteEntireNetwork(head);
    head=addCity(head,NULL,"Agent 1");

    city *current=head;
    for(int i=1; i<6; i++)
    {
        head=addCity(head, current, names[i]);
        current=current->next;
    }
    return head;
}
/* Do NOT modify main function */
int main(int argc, char* argv[])
{
    // pointer to the head of our network of cities
    city *head = NULL;

    head = handleUserInput(head);
    printPath(head);
    head = deleteEntireNetwork(head);

    if (head == NULL)
        cout << "Path cleaned" << endl;
    else
        printPath(head);

    cout << "Goodbye!" << endl;

    return 0;
}
