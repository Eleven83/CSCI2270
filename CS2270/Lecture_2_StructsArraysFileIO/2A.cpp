#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Student
{
    //ID, name, major
    int ID;
    string name;
    string major;
    Student(){}
    Student(int id, string n, string m)
    {
        ID=id;
        name=n;
        major=m;
    }
};

int main()
{
    //Create instance of Student called s
    Student s;
    s.ID=5; //Setting the ID property of student s to 5
    s.name="Bob";
    s.major="Skiing";
    Student s2(6, "Jimmy", "Swimming"); //Setting the attributes
    cout<<s.ID<<" "<<s.name<<" "<<s.major<<endl;
    cout<<s2.ID<<" "<<s2.name<<" "<<s2.major<<endl;
      
    return 0;
}
