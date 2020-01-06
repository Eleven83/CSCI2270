#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;
struct node
{
    string key;
    //int key;
    node *next;
    node(string k, node *n)
    {
        key=k;
        next=n;
    }
};

node *search(string value, node *head, int &position)
{
    node *current=head;
    while(current!=NULL)
    {
        if(current->key==value)
        {
            return current;
        }
        current=current->next;
        position++;
    }
    return NULL;
}

int main()
{
    //int i=1;
    //vector<string> lyrics;
    string first;
    node *head=new node(first, NULL);
    node *p=head; //head and p point to same memory
    // i++;
    // while(i<=10)
    // {
    //     node *n=new node(i, NULL); //n->next=NULL, n->key=i
    //     p->next=n; //set p's next node to point to n
    //     p=n; //same as p = p->next
    //     i++;
    // }
    string temp1="Today";
    string temp2="was";
    string temp3="a";
    string temp4="good";
    string temp5="day";

    node *n1=new node(temp1, NULL); //n->next=NULL, n->key=i
    p->next=n1; //set p's next node to point to n
    p=n1; //same as p = p->next
    node *n2=new node(temp2, NULL); //n->next=NULL, n->key=i
    p->next=n2; //set p's next node to point to n
    p=n2; //same as p = p->next
    node *n3=new node(temp3, NULL); //n->next=NULL, n->key=i
    p->next=n3; //set p's next node to point to n
    p=n3; //same as p = p->next
    node *n4=new node(temp4, NULL); //n->next=NULL, n->key=i
    p->next=n4; //set p's next node to point to n
    p=n4; //same as p = p->next
    node *n5=new node(temp5, NULL); //n->next=NULL, n->key=i
    p->next=n5; //set p's next node to point to n
    p=n5; //same as p = p->next
    //how do I find something in the list?
    //do any of the key value = 4?
    int position=0;
    string value;
    cout<<"What value are you searching for? \n";
    getline(cin, value);
    p=search(value, head, position);
    if(p!=NULL)
    {
        cout<<"Found it!"<<endl;
        cout<<"Position of the node: "<<position<<endl;
    }else{
        cout<<"Not in the list."<<endl;
    }

    return 0;
}
