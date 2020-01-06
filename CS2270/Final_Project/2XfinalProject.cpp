// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <cstdlib>
// #include <string>
// #include <iomanip>
//
// using namespace std;
//
// /*
// Function Prototypes
// */
// string getString(string);
// int getNum(int);
// void questionnaire();
// // void fileReader(string);
// int choiceMenu();
// int adventureMenu();
// // void endMenu();
//
// /*
// Driver Function (- MAIN -)
// */
// int main()
// {
//     bool valid = true;
//     while(valid)
//     {
//         int choice = choiceMenu();
//         switch(choice)
//         {
//             case 1:
//                 {
//                     questionnaire();
//                     // fileReader("intro.txt");
//                     int advChoice = adventureMenu();
//                     if(advChoice==1)
//                     {
//                         cout<<"Step Brothers is a 2008 American comedy film directed by Adam McKay, written by Will Ferrell\n";
//                         cout<<"and McKay from a story by Ferrell, McKay, and John C. Reilly and starring Ferrell and Reilly.\n";
//                         //fileReader("Adventure1.txt");
//                     }else{
//                         cout<<"Anchorman: The Legend of Ron Burgundy is a 2004 American comedy film directed by \n";
//                         cout<<"Adam McKay, produced by Judd Apatow, starring Will Ferrell, and written by McKay and Ferrell.\n";
//                         //fileReader("Adventure2.txt");
//                     }
//                     //fileReader("conclusion.txt");
//                     cout<<"It's the end of the world as we know it\n";
//                     cout<<"It's the end of the world as we know it\n";
//                     cout<<"It's the end of the world as we know it\n";
//                     cout<<"And I feel fine\n";
//                 }
//                 break;
//             case 2:
//                 {
//                     //fileReader("readme.txt");
//                     cout<<"How to Play:\n";
//                     cout<<"-----------\n";
//                     cout<<"Simply fill in the blanks with the required information and enjoy the\n";
//                     cout<<"hilarious story that is created!\n";
//                 }
//                 break;
//             case 3:
//                 cout<<"\n<<<<<<<< GAME OVER >>>>>>>>\n";
//                 valid=false;
//                 break;
//             default:
//                 cout<<"\nYou Made an Invalid Choice. Try Again.\n";
//                 choiceMenu();
//         }
//     }
//     valid=false;
//     return 0;
// }
//
// string getString(string prompt)
// {
//     string response;
//     cout<<prompt;
//     getline(cin, response);
//     return response;
// }
//
// int getNum(string prompt)
// {
//     int numResponse;
//     cout<<prompt;
//     cin>>numResponse;
//     return numResponse;
// }
//
// void questionnaire()
// {
//     cin.ignore();
//     string parent=getString("Please enter your mom's or dad's name: ");
//     string fastFood=getString("Please enter your favorite fast food place: ");
//     string nextPlanet=getString("Please enter a car brand: ");
//     int plugIn=getNum("Please enter a number between 1 and 100: ");
// }
//
// void fileReader(string fileToRead)
// {
//     string line;
//     ifstream inFile(fileToRead);
//     if(!inFile.is_open())
//     {
//         cout<<"ERROR: Could Not Open File!"<<endl;
//     }else{
//         while(!getline(inFile, line).eof())
//         {
//             cout<<line; list.popword()<<endl;
//         }
//     }
// }
//
// int choiceMenu()
// {
//     cout<<"<<<<<<<< Main Menu >>>>>>>>\n";
//     cout<<"===========================\n";
//     cout<<"Please Select from the Following Options:\n";
//     cout<<"1. Begin a New Adventure\n";
//     cout<<"2. Read the Instructions\n";
//     cout<<"3. Quit\n";
//
//     int choice;
//     cin>>choice;
//     return choice;
// }
//
// int adventureMenu()
// {
//     cout<<"<<<<<<<< CHOOSE WISELY >>>>>>>>\n";
//     cout<<"1. Take the Red Pill (Adventure 1)\n";
//     cout<<"2. Take the Blue Pill (Adventure 2)\n";
//
//     int choice;
//     cin>>choice;
//     return choice;
// }
//
// void endMenu()
// {
//     char continue=='y';
//     cout<<"\nDo You Want to Read the Stunning Conclusion? (y/n):\n";
//     cin>>continue;
//     if(continue!='y')
//     {
//         cout<<"\n<<<<<<<< GAME OVER >>>>>>>>\n";
//     }else{
//         fileReader("conclusion.txt");
//         cout<<"\n<<<<<<<< GAME OVER >>>>>>>>\n";
//     }
//     return;
// }


/*
*************************************************************************************************************************
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct Node
{
    string word;
    Node *next;
};

class WordList
{
public:
    WordList();
    ~WordList();
    int size;
    int capacity;
    int choiceMenu();
    int adventureMenu();
    void createQueue();
    bool isEmpty();
    bool isFull();
    void addWord(string input);
    void printQueue();
    Node* popWord();
    Node* peek();
    Node* getQueueFront(){return head;}
    Node* getQueueEnd(){return tail;}

private:
    Node* head; // the item in the list that will be dequeued next
    Node* tail; // the item in the list that was most recently enqueued
};

WordList::WordList()
{
    this->head=NULL;
    this->tail=NULL;
    size=0;
    capacity=10;
}

WordList::~WordList()
{
    while(head!=NULL)
    {
        Node* temp=head->next;
        delete head;
        head=temp;
    }
}

void WordList::createQueue()
{
    string name, fruit, city, animal;
    cout<<"Please enter a name:\n";
    getline(cin, name);
    cout<<"Please enter a fruit:\n";
    getline(cin, fruit);
    cout<<"Please enter a city:\n";
    getline(cin, city);
    cout<<"Please enter your favorite animal:\n";
    getline(cin, animal);

    Node *node1 = new Node;
    node1->word=name;
    node1->next = NULL;
    this->head = this->tail = node1;
    this->size++;

    Node *node2 = new Node;
    node2->word=fruit;
    node2->next = NULL;
    this->head->next = node2;
    this->tail = node2;
    this->size++;

    Node *node3 = new Node;
    node3->word=city;
    node3->next = NULL;
    this->head->next->next = node3;
    this->tail = node3;
    this->size++;

    Node *node4 = new Node;
    node4->word=animal;
    node4->next = NULL;
    this->head->next->next->next = node4;
    this->tail = node4;
    this->size++;
}

void WordList::printQueue()
{
    cout<<"QUEUE ELEMENTS:"<<endl;
    Node *iterator=this->head;
    while(iterator->next!=NULL)
    {
        cout<<iterator->word<<" ";
        iterator=iterator->next;
    }
    cout<<iterator->word<<endl;
}

bool WordList::isEmpty()
{
    return (size==0);
}

bool WordList::isFull()
{
    return(size==10);
}

//enqueue
void WordList::addWord(string word)
{
    Node *temp=new Node;
    if(!isFull())
    {
        tail->next=temp;
        temp->word=word;
        tail=temp;
        temp->next=NULL;
    }else{
        cout<<"Queue is full, cannot add word."<<endl;
    }
    size++;
}

//dequeue
Node* WordList::popWord()
{
    Node *trash;
    trash=head;
    head=head->next;
    delete trash;
    size--;

    return NULL;
}

Node* WordList::peek()
{
    if(head==NULL)
    {
        cout<<"Queue empty, cannot peek."<<endl;
    }else{
        cout<<"The front of the queue is: "<<head->word<<endl;
        return head;
    }
    return head;
}

int WordList::adventureMenu()
{
    cout<<"\n<<<<<<<< CHOOSE WISELY >>>>>>>>\n";
    cout<<"1. Take the Red Pill (Adventure 1)\n";
    cout<<"2. Take the Blue Pill (Adventure 2)\n";

    int choice;
    cin>>choice;
    return choice;
}

int WordList::choiceMenu()
{
    cout<<"<<<<<<<< Main Menu >>>>>>>>\n";
    cout<<"===========================\n";
    cout<<"Please Select from the Following Options:\n";
    cout<<"1. Begin a New Adventure\n";
    cout<<"2. Read the Instructions\n";
    cout<<"3. Quit\n";

    int choice;
    cin>>choice;
    return choice;
}

//Driver Main()
int main()
{
    WordList List;
    List.createQueue();
    List.printQueue();
    vector<string> lyrics;
    string line, tempWord;
    fstream inFile("lyrics.txt");
    if(!inFile.is_open())
    {
        cout<<"ERROR: Could Not Open File!"<<endl;
        //return -1;
    }else{
        while(!getline(inFile, line).eof())
        {
            stringstream ss;
            ss<<line;
            getline(ss, tempWord);
            if(tempWord=="1")
            {
                lyrics.push_back();
            }else
                lyrics.push_back(tempWord);
        }
        vector<string>::iterator i;
        for(i=lyrics.begin(); i<lyrics.end(); ++i)
        {
            cout<<*i<<" "<<endl;
        }
    }
    bool valid = true;
    while(valid)
    {
        int choice = List.choiceMenu();
        switch(choice)
        {
            case 1:
                {
                    int advChoice = List.adventureMenu();
                    if(advChoice==1)
                    {
                        cout<<"Hello\n";
                    }else{
                        cout<<"Anchorman: The Legend of Ron Burgundy is a 2004 American comedy film directed by \n";
                    }
                    //Conclusion Here:
                    cout<<"It's the end of the world as we know it\n";
                }
                break;
            case 2:
                {
                    cout<<"How to Play:\n";
                    cout<<"-----------\n";
                    cout<<"Simply fill in the blanks with the required information and enjoy the\n";
                    cout<<"hilarious story that is created!\n";
                }
                break;
            case 3:
                cout<<"\n<<<<<<<< GAME OVER >>>>>>>>\n";
                valid=false;
                break;
            default:
                cout<<"\nYou Made an Invalid Choice. Try Again.\n";
                List.choiceMenu();
        }
    }
    valid=false;

    return 0;
}
