#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <queue>
#include "patStruct.h"
// #include "PQLL.cpp"
// #include "PQMinHeap.cpp"

using namespace std;

struct compare
{
    bool operator()(const Patient* A, const Patient* B)
    {
        int ap = A->priority *1000 + A->treatment;
        int bp = B->priority*1000+B->treatment;
        return ap>bp;
    }
};

int main()
{
    // PQLL* dll=new PQLL();
    // PQMinHeap* minH=new PQMinHeap();
    priority_queue<Patient*, vector<Patient*>, compare> pq;

    const int MAX_SIZE=880;
    Patient patientData[MAX_SIZE];

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
            pq.push(&patientData[i]);
            i++;
        }
        while(!pq.empty())
        {
            Patient* p= pq.top();
            cout<<p->name<<" "<<p->priority<<" "<<p->treatment<<endl;
            pq.pop();
        }
    }
    return 0;
}
