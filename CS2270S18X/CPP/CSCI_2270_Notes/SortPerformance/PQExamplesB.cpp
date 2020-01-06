#include <iostream>
#include <queue>
using namespace std;

struct patient
{
    int x;
    int y;
    patient(int inX, int inY)
    {
        x = inX;
        y=inY;
    }
};
struct compare
{
    bool operator()(const patient &a, const patient &b)
    {
        //cout<<(a.x > b.x)<<endl;
        if(a.x == b.x)
            return a.y > b.y;
        return a.x > b.x;
    }
};

int main()
{
    //but, it's still just integers
    //we need a pq of objects
    //once we create object, we need to say which member of object we're comparing
    patient p1(5, 1);
    patient p2(51, 2);
    patient p3(15, 3);
    patient p4(51, 4);
    patient p5(16, 5);
    patient p6(52, 6);
    //cout<<p4.x<<endl;

    priority_queue<patient,vector<patient>, compare > pq4;

    pq4.push(p1);
    pq4.push(p2);
    pq4.push(p3);
    pq4.push(p4);
    pq4.push(p5);
    pq4.push(p6);
    while(!pq4.empty())
    {
        patient pTemp=pq4.top();
        cout<<pTemp.x<<", "<<pTemp.y<<endl;
        pq4.pop();
    }

    return 0;
}
