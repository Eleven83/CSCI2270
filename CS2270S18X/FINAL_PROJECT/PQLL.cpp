#include "PQLL.h"
#include <ctime>
#include <chrono>
using namespace std;

//Constructor
PQLL::PQLL()
{
    head=tail=NULL;
    size=0;
}
//Destructor
PQLL::~PQLL()
{
    //Empty
}
void PQLL::push(string n, int pTime, int tTime)
{
    Node* temp=new Node(n, pTime, tTime);
    if(tail==NULL)
        head=tail=temp;
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    size++;
}
Node* PQLL::pop2()
{
    if(!isEmpty())
    {
        Node* temp=head;
        Node* popel=head;
        if(head==tail)
        {
            popel = head;
            head = NULL;
            tail=NULL;
            return popel;
        }
        while(temp!=NULL){
            if(compare(temp,popel))
                popel = temp;
            temp = temp->next;
        }
        if(popel==head)
        {
            head->next->prev = NULL;
            head = head->next;
            return popel;
        }
        else if(popel==tail)
        {
            tail->prev->next =NULL;
            tail = tail->prev;
            return popel;
        }
        else{
            popel->prev->next = popel->next;
            popel->next->prev =  popel->prev;
            return popel;
        }

    }
    return 0;
}
bool PQLL::compare(Node* A, Node* B) // return true when A should be attended before B
{
    int ap = A->priority *1000 + A->treatment;
    int bp = B->priority*1000+B->treatment;
    return ap<bp;
}
bool PQLL::isEmpty()
{
    if(size<=0)
    {
        return true;
    }
    return false;
}
void PQLL::display()
{
    Node* temp=head;

    cout<<"\nCurrent patients in the queue:\n";
    while(temp!=NULL)
    {
        cout<<temp->name<<" -> ";
        temp=temp->next;
    }
    cout<<" NULL";
}
int PQLL::length()
{
    return size;
}
void PQLL::search(string n)
{
    if(!isEmpty())
    {
        Node* temp=head;
        while(temp)
        {
            if(temp->name==n)
            {
                cout<<temp->name<<" is in the list and her wait time is "<<temp->priority<<" minutes"<<endl;
                break;
            }
            temp=temp->next;
        }
    }
    else
    {
        cout<<"List is empty"<<endl;
    }
}
int main()
{
    PQLL* dll=new PQLL();
    const int MAX_SIZE=880;
    Patient patientData[MAX_SIZE];
    double arr1[MAX_SIZE];
    int count=0;
    ifstream inFile("patientData2270.csv");
    if(!inFile.is_open())
    {
        cout<<"Something Went Wrong."<<endl;
        return 0;
    }else{
        int i=0;
        string line, temp, next, name, priority, treatment;
        getline(inFile, temp, '\r'); //ignore the first line consisting of "Name, priority, treatment"
        while(getline(inFile, line, '\r')) //Starting from the second line, store the name, priority time and treatment times.
        {
            stringstream ss(line);
            getline(ss, name, ',');
            patientData[i].name=name;
            getline(ss, priority, ',');
            patientData[i].priority=stoi(priority);
            getline(ss, treatment);
            patientData[i].treatment=stoi(treatment);
            i++;
        }
        count=i;
        // for(int j=0; j<MAX_SIZE; j++)
        //     cout<<patientData[j].name<<" "<<patientData[j].priority<<" "<<patientData[j].treatment<<endl;
    }
    inFile.close();
    //START
    int exCount=0;
    while(exCount<count)
    {
        // Record start time
        auto start=chrono::high_resolution_clock::now();
        for(int j=0; j<count; j++)
        {
            dll->push(patientData[j].name,patientData[j].priority,patientData[j].treatment);
            if(!dll->isEmpty())
            {
                Node* popel=dll->pop2();
                //cout<<popel->name<<" "<<popel->priority<<" "<<popel->treatment<<endl;
            }
        }
        // Record end time
        auto finish=chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed=(finish-start);
        //store in an array
        arr1[exCount]=elapsed.count();
        //cout<<"Elapsed time: "<<elapsed.count()<<" s\n";
        exCount++;
    }
    for (int k=0; k<MAX_SIZE; k++)
    {
        cout<<arr1[k]<<endl;
    }
    //
    // // Record start time
    // auto start2 = std::chrono::high_resolution_clock::now();
    // for(int k=0; k<count; k++)
    // {
    //     if(!dll->isEmpty())
    //     {
    //         Node* popel=dll->pop2();
    //         //cout<<popel->name<<" "<<popel->priority<<" "<<popel->treatment<<endl;
    //     }
    // }
    // // Record end time
    // auto finish2 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed2 = (finish2 - start2);
    // std::cout << "Elapsed time: " << elapsed2.count() << " s\n";
    return 0;
}
