#include <iostream>
#include <string>

using namespace std;
/*
class Time12
{
    private:
        int hour;
        int minute;
        string mer;
    public:
        Time12(int h, int m, string me) //constructor definition *special thus no return type needed
        {
            hour=h;     //initialize
            minute=m;   //initialize
            mer=me;     //initialize
        }

        void printDate()
        {
            cout<<hour<<":"<<minute<<mer<<endl;
        }

        void setHour(int h)
        {
            if(h>=0 && h<=12)
                hour=h;
            else
                cout<<"ERROR"<<endl;
        }

};


int main()
{
    Time12 t(10, 30, "am");
    t.setHour(12);
    t.printDate();

    return 0;
}
*/

//linkedListClass.cpp
struct Node
{
    string item;
    Node *next;
};

class List
{
private:
    Node* head;
    Node* tail;

public:
    List() //constructor
    {
        head=NULL;
        tail=NULL;
    }
    ~List()
    {
        //define constructor

    }
    void growList(string newItem)
    {
        //first, determine if the list is empty:
        if(head==NULL)
        {
            head=new Node;
            head->item=newItem;
            head->next=NULL;
            tail=head;
        }else{//the list is not empty so add nodes to the end
            Node* temp=new Node;
            temp->item=newItem;
            //next, link tail with new node
            tail->next=temp;
            tail=temp;
            tail->next=NULL;
        }
    }
    void displayList()
    {
        Node* current=head;
        while(current!=NULL)
        {
            cout<<current->item<<endl;
            current=current->next;
        }
    }
};

int main()
{
    List List1; //instance of list class (object)
    string arr[]={"one", "two", "three"};
    int arrLength=3;
    for(int i=0; i<arrLength; i++)
    {
        List1.growList(arr[i]);
    }
    List1.displayList();
    return 0;
}
