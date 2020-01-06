#include "doubLL.h"

List::List()
{
    head=tail=NULL;
}

List::~List()
{
    if(head)
    {
        Node *t=head;
        head=head->next;
        while(head!=NULL)
        {
            delete t;
            t=head;
            head=head->next;
        }
    }
}
bool List::createNode(string name, int id, int age, float gpa)
{
    Node *tmp=new Node;
    tmp->name=name;
    tmp->id=id;
    tmp->age=age;
    tmp->gpa=gpa;
    tmp->next=NULL;
    if(!head)
    {
        head=tail=tmp;
        tmp=NULL;
        return true;
    }else{
        tail->next=tmp;
        tail=tail->next;
        tmp=NULL;
        return true;
    }

}
void List::display()
{
    if(!head)
        cout<<"Linked List does not exist"<<endl;
    else{
        Node *t=head;
        while(t!=NULL)
        {
            cout<<"ID: "<<t->id<<endl;
            cout<<"Name: "<<t->name<<endl;
            cout<<"Age: "<<t->age<<endl;
            cout<<"GPA: "<<t->gpa<<endl;
            cout<<"----------------------"<<endl;
            t=t->next;
        }
    }
}
