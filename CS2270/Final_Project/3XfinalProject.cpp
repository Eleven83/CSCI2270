#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct MadLibNode
{
    int nodeNumber; //number of the MadLibNode
    MadLibNode *next; //pointer to the next MadLibNode
    string message; //message we are sending accross
};

/* Function prototypes */
MadLibNode* addMadLibNode(MadLibNode *head, MadLibNode *previous, int nodeNumber);
MadLibNode* deleteMadLibNode(MadLibNode *head, int nodeNumber);
MadLibNode* deleteEntireNetwork(MadLibNode *head);
MadLibNode* searchNetwork(MadLibNode *head, int nodeNumber);
MadLibNode* loadDefaultSetup(MadLibNode *head);

void transmitMsg(MadLibNode *head, string message);
void printPath(MadLibNode *head);
int displayMenu();
MadLibNode* handleUserInput(MadLibNode *head);

/* Main Function*/
int main(int argc, char* argv[])
{
    //pointer to the head of our network of nodes
    MadLibNode *head = NULL;
    head=handleUserInput(head);
    printPath(head);
    head=deleteEntireNetwork(head);
    if(head==NULL)
        cout<<"Path has Been Scrubbed Clean!"<<endl;
    else
        printPath(head);
    cout<<"Thanks for playing! Goodbye."<<endl;
    return 0;
}

//Function to handle interaction with the user
MadLibNode* handleUserInput(MadLibNode *head)
{
    bool quit=false;
    // Loop until the user quits
    while(!quit)
    {
        int choice=displayMenu();
        //Read in option from user
        switch(choice)
        {
            //Build the network and print all nodes
            case 1:
            {
                head = loadDefaultSetup(head);
                printPath(head);
            }
            break;
            //Function to print the path
            case 2:
            {
                printPath(head);
            }
            break;
            //Get the message from the user
            case 3:
            {
                cin.ignore();
                string name, city, animal;
                cout<<"Enter a name: "<<endl;
                getline(cin, name);
                transmitMsg(head, name);
                // cin.ignore();
                // cout<<"Enter a city: "<<endl;
                // getline(cin, city);
                // transmitMsg(head, city);
                // cin.ignore();
                // cout<<"Enter an animal: "<<endl;
                // getline(cin, animal);
                // transmitMsg(head, animal);
            }
            break;
            //Add a new node to the list
            case 4:
            {
                int newNodeNum;
                int prevNodeNum;
                cout<<"Enter a new MadLibNode Number: "<<endl;
                cin>>newNodeNum;
                cout<<"Enter the previous MadLibNode number (or -1): "<<endl;
                cin>>prevNodeNum;
                //Find the node containing prevNodeNum
                MadLibNode *tmp = NULL;
                if(prevNodeNum != -1)
                    tmp = searchNetwork(head, prevNodeNum);
                //Add the new node
                head = addMadLibNode(head, tmp, newNodeNum);
                printPath(head);
            }
            break;
            //Delete the MadLibNode
            case 5:
            {
                int nodeNumber;
                cout<<"Enter a MadLibNode number: "<<endl;
                cin>>nodeNumber;
                head = deleteMadLibNode(head, nodeNumber);
                printPath(head);
            }
            break;
            //Delete the network of nodes
            case 6:
            {
                head = deleteEntireNetwork(head);
            }
            break;
            //Quit the game
            case 7:
            {
                quit = true;
                cout<<"Quitting... cleaning up path: "<<endl;
            }
            break;
            //Default case to handle invalid input
            default:
            cout<<"Invalid Input. Please Try Again"<<endl;
            break;
        }
    }
    return head;
}

//Function to add a new node to the network
MadLibNode* addMadLibNode(MadLibNode *head, MadLibNode *previous, int nodeNumber)
{
    if(head==NULL)
    {
        MadLibNode *newMadLibNode=new MadLibNode;
        newMadLibNode->nodeNumber = nodeNumber;
        newMadLibNode->message = "";
        newMadLibNode->next=NULL;
        head=newMadLibNode;
        return head;
    }
    MadLibNode *newMadLibNode=new MadLibNode;
    newMadLibNode->nodeNumber=nodeNumber;
    newMadLibNode->message="";
    newMadLibNode->next=NULL;
    if(previous==NULL)
    {
        newMadLibNode->next=head;
        head=newMadLibNode;
        return head;
    }
    newMadLibNode->next=previous->next;
    previous->next=newMadLibNode;
    //If previous is NULL, print the following:
    cout<<"prev: "<<previous->nodeNumber<<" new: "<<nodeNumber<<endl;

    return head;
}

//Function to search the network for the specified MadLibNode and return a pointer to that node
MadLibNode *searchNetwork(MadLibNode *ptr, int nodeNum)
{
    while(ptr!=NULL)
    {
        if(ptr->nodeNumber==nodeNum)
        {
            break;
        }else{
            ptr=ptr->next;
        }
    }
    return ptr;
}

//Function to delete all nodes in the network starting at the head MadLibNode
MadLibNode* deleteEntireNetwork(MadLibNode *head)
{
    if(head==NULL)
    {
        return head;
    }
    while(head!=NULL)
    {
        cout<<"deleting: "<<head->nodeNumber<<endl;
        MadLibNode *next=head->next;
        delete head;
        head=next;
    }
    cout<<"Deleted network"<<endl;
    //Return head, which should be NULL
    return head;
}

//Function to send a word from the queue to each MadLibNode node
void transmitMsg(MadLibNode *head, string message)
{
    if(head == NULL)
    {
        cout<<"Empty list"<<endl;
        return;
    }
    MadLibNode *sender=head;
    while(head!=NULL)
    {
        sender->message=message;
        if(sender->nodeNumber==1)
        {
            cout<<"The "<<sender->message<<" wanted to stay."<<endl;
            sender=sender->next;
        }else if(sender->nodeNumber==2)
        {
            cout<<"The "<<sender->message<<" wanted to go."<<endl;
            sender=sender->next;
        }else if(sender->nodeNumber==3)
        {
            cout<<"The "<<sender->message<<" wanted to have tea."<<endl;
            sender=sender->next;
        }else if(sender->nodeNumber==4)
        {
            cout<<"The "<<sender->message<<" wanted to go to the zoo."<<endl;
            sender=sender->next;
        }else if(sender->nodeNumber==5)
        {
            cout<<"The "<<sender->message<<" wanted to be free."<<endl;
            sender=sender->next;
        }else if(sender->nodeNumber==6)
        {
            cout<<"The "<<sender->message<<" wanted to move around."<<endl;
            sender=sender->next;
        }
    }
    sender->message=message;
    return;
}

//Function to delete the MadLibNode in the network with the specified number
MadLibNode* deleteMadLibNode(MadLibNode *head, int nodeNum)
{
    MadLibNode *previous=NULL;
    MadLibNode *current=head;
    while(current!=NULL)
    {
        if(current->nodeNumber==nodeNum)
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
    // If the MadLibNode dosn't exist, use this output statement:
    cout<<"MadLibNode does not exist."<<endl;
    return head;
}

//Function to print the current list of nodes
void printPath(MadLibNode *head)
{
    // Add code here to print the network path.
    cout<<"== CURRENT PATH =="<<endl;
    if(head==NULL)
    {
        cout<<"nothing in path"<<endl;
        return;
    }
    MadLibNode *temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            cout<<temp->nodeNumber;
            cout<<" ---->>>>---- ";
            cout<<"NULL"<<endl;
            break;
        }else{
            cout<<temp->nodeNumber;
            cout<<" ---->>>>---- ";
            temp=temp->next;
        }
    }
    cout<<"==="<<endl;
}

//Build a default list
MadLibNode* loadDefaultSetup(MadLibNode *head)
{
    //Populate the LinkedList with the default values
    int nodeNumbers[]={1,2,3,4,5,6};
    head=deleteEntireNetwork(head);
    head=addMadLibNode(head,NULL,1);

    MadLibNode *current=head;
    for(int i=1; i<6; i++)
    {
        head=addMadLibNode(head, current, nodeNumbers[i]);
        current=current->next;
    }
    return head;
}

//Function to display a menu with options
int displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message" << endl;
    cout << "4. Add MadLibNode" << endl;
    cout << "5. Delete MadLibNode" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;
    int choice;
    cin>>choice;
    return choice;
}
