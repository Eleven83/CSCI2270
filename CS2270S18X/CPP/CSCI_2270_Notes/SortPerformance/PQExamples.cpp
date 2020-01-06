#include <iostream>
#include <queue>
using namespace std;

// Operator overloading - overload the () operator when used with the compare
// struct. Let's overload it such that when it is called with patient type,
// it outputs a boolean TRUE if the x member of 'a' is greater than the x member
// of 'b'.
struct compare
{
    bool operator()(const int & a, const int & b)
    {
        cout<<(a.x > b.x)<<endl;
        return a>b;
    }
};


int main()
{
    //default parameters, type is only parameter required.
    //uses default container - vector, and default compare - less than
    //less than checks if the new input is less than values it's compared to
    //less is left < right

    cout<<"pa.x "<<pa.x<<endl;
    priority_queue<int> pq;

    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(8);

    cout << "default priority_queue: maxHeap " << endl;
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }

    // Now let's declare a PQ and specify the other parameters
    priority_queue<int,vector<int>, compare > pq3;

    // int is the type, vector<int> is the containter type,
    // compare is a user defined struct
    pq3.push(3);
    pq3.push(5);
    pq3.push(1);
    pq3.push(8);


    cout<<"PQ: min-heap: "<<endl;
    while(!pq3.empty())
    {
        cout<<pq3.top()<<endl;
        pq3.pop();
    }

    return 0;
}
