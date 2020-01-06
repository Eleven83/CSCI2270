#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

void addnode();
void delnode();
void display();
void show();
void search();

node *start=NULL, *temp1, *temp2, *temp3;

int main()
{
    char ch;
    do
    {
        char i;
        cout<<"Press 'a' to add node , 'd' to delete"<<endl;
        cout<<" 's' for search, 'v' for display ,'e' for backward display"<<endl;
        cin>>i;
       switch (i)
       {
       case'a':
          addnode();
          break;
       case'd':
          delnode();
          break;
       case'v' :
          display();
          break;
       case's':
          search();
          break;
       case'e':
           show();
          break;
       default:
          cout<<"Bad input"<<endl;
          break;
       }
       cout<<"want to process more y/n"<<endl;
       cin>>ch;
     }
     while(ch!='n');
       return 0;
}

void addnode()          //adding node
{
    char r;
    temp1=new node;
    cout<<"enter int to store"<<endl;
    cin>>temp1->data;
    cout<<"press 's' to add in start,'m' for midd , 'e' for end"<<endl;
    cin>>r;
    switch (r)
    {
    case's':
        if(start==NULL)
        {
            start=temp1;
            temp1->next=NULL;
            temp1->prev=NULL;
        }
        else
        {
            temp2=start;
            temp1->next=temp2;
            temp1->prev=NULL;
            start=temp1;
            temp2->prev=temp1;
        }
        break;
    case'e':
        if(start==NULL)
        {
            start=temp1;
            temp1->next=NULL;
            temp1->prev=NULL;
        }
        else
        {
            temp2=start;
            while(temp2->next!=NULL)
                temp2=temp2->next;
            temp2->next=temp1;
            temp1->prev=temp2;
            temp1->next=NULL;
        }
        break;
    case'm':
        int num;
        cout<<"enter node after which you want to enter"<<endl;
        cin>>num;
        temp2=start;
        for(int i=0;i<num;i++)
        {
            if(start==NULL)
                cout<<"given node not found"<<endl;
            else
            {
               temp3=temp2;
               temp2=temp2->next;

            }
        }
         temp1->next=temp2;
         temp3->next=temp1;
         temp1->prev=temp3;
         temp2->prev=temp1;
        break;
    }
}

void display()        //displaying
{

    temp3=start;
    if(start==NULL)
        cout<<"no node to display"<<endl;
    else
    {
      while(temp3->next!=NULL)
      {
          cout<<"Data stored is "<<temp3->data<<" at "<<temp3<<endl;
         temp3=temp3->next;
      }
      cout<<"Data stored is "<<temp3->data<<" at "<<temp3<<endl;
    }
}

void search()            //searching
{
    int p;
    cout<<"enter no to search"<<endl;
    cin>>p;
    temp1=start;
    while(temp1->next!=NULL)
    {
        if(temp1->data==p)
        {
            cout<<temp1->data<<" is stored in "<< temp1->next<<endl;
        }
        temp1=temp1->next;
    }
}

void delnode()           //deleting
{

    char d;
    cout<<"press 's' to delete from start,'m' for midd , 'e' for end"<<endl;
    cin>>d;
    switch (d)
    {
      case's':               //delete start
          if(start==NULL)
          {
              cout<<"no node to delete"<<endl;
          }
          else
          {
              temp1=start;
              start=start->next;
              start->prev=NULL;
              delete temp1;
          }
         break;
      case'e':            //delete end
          if(start==NULL)
          {
              cout<<"no node to delete"<<endl;
          }
         else
         {
             temp1=start;
             while(temp1->next!=NULL)
             {
                temp2=temp1;
                temp1=temp1->next;
             }
              delete temp1;
             temp2->next=NULL;
         }
        break;
      case'm':               //delete mid
          int num;
          cout<<"enter node you want to delete"<<endl;
          cin>>num;

          temp1=start;
          for(int i=1;i<num;i++)
          {
              if(start==NULL)
               cout<<"given node does not exist"<<endl;
              else
              {
                temp2=temp1;
                temp1=temp1->next;
              }
          }
          temp3=temp1->next;
          temp2->next=temp3;
          temp3->prev=temp2;
          delete temp1;
          break;
    }
}

void show()               //backward display
{
    cout<<"backward display"<<endl;
    temp3=start;
    if(start==NULL)
        cout<<"no node to display"<<endl;
    else
    {
       while(temp3->next!=NULL)
       {
           temp3=temp3->next;
       }
       while(temp3->prev!=NULL)
       {
           cout<<"Data stored is "<<temp3->data<<" at "<<temp3<<endl;
           temp3=temp3->prev;
       }
       cout<<"Data stored is "<<temp3->data<<" at "<<temp3<<endl;
    }
}
