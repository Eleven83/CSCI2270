#include <iostream>

using namespace std;

struct node
{
    int number;
    node *next;
};

bool isEmpty(node *head);
char menu();
void insertFirst(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void showList(node *current);

int main()
{
    node *head=NULL;
    node *last=NULL;
    char choice;
    int number;

    do {
        choice=menu();
        switch (choice) {
            case '1':
                cout<<"Please enter a number: "<<endl;
                cin>>number;
                insert(head, last, number);
                break;
            case '2':
                remove(head, last);
                break;
            case '3':
                showList(head);
                break;
            default:
                cout<<"System Exit"<<endl;

        }
    } while(choice!='4');

    return 0;
}

bool isEmpty(node *head)
{
    if(head==NULL)
        return true;
    else
        return false;
}

char menu()
{
    char choice;

    cout<<"======Main Menu======"<<endl;
    cout<<"1. Add an item"<<endl;
    cout<<"2. Remove an item"<<endl;
    cout<<"3. Show the list"<<endl;
    cout<<"4. Exit"<<endl;
    cin>>choice;

    return choice;

}

void insertFirst(node *&head, node *&last, int number)
{
    node *temp=new node;
    temp->number=number;
    temp->next=NULL;
    head=temp;
    last=temp;
}

void insert(node *&head, node *&last, int number)
{
    if(isEmpty(head))
        insertFirst(head, last, number);
    else{
        node *temp=new node;
        temp->number=number;
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }

}

void remove(node *&head, node *&last)
{
    if(isEmpty(head))
        cout<<"The list is already empty."<<endl;
    else if(head==last)
    {
        delete head;
        head=NULL;
        last=NULL;
    }else{
        node *temp=head;
        head=head->next;
        delete temp;
    }
}

void showList(node *current)
{
    if(isEmpty(current))
        cout << "The list is empty." << endl;
    else{
        cout<<"The list contains: "<<endl;
        while (current!=NULL)
        {
            cout<<current->number<<endl;
            current=current->next;
        }
    }
}
