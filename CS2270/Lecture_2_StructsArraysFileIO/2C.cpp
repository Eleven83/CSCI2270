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
    //array of students
    //this will be populated manually
    Student allStudents[3];

    allStudents[0].ID=1;
    allStudents[0].name="Jessica";
    allStudents[0].major="Computer Science";

    allStudents[1].ID=2;
    allStudents[1].name="Harrison";
    allStudents[1].major="Mechanical Engineering";

    allStudents[2].ID=3;
    allStudents[2].name="Tom";
    allStudents[2].major="Aerospace Engineering";

    //verify contents of allStudents array
    for(int i=0; i<3; i++)
    {
        cout<<allStudents[i].ID<<" "<<allStudents[i].name<<" "<<allStudents[i].major<<endl;
    }
    
    return 0;
}
