#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Hello
{
    int counter;
    string id;
};


int main()
{
    cout<<"Struct Practice"<<endl;
    Hello check;
    check.counter=21;
    check.id="Ability Power";
    if(check.counter>=10)
    {
        cout<<"The "<<check.id<<" of this one is "<<check.counter<<endl;
    }
}
