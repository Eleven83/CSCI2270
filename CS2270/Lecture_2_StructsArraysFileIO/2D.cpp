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
    //this will be populated with file data
    Student allStudents[10];

    //streams
    ifstream myFile("students.txt");

    cout<<"First we will print the String Stream"<<endl<<endl;
    if(myFile.is_open())
    {
        //Read the file
        string line;
        int counter=0;
        while(getline(myFile, line))
        {
            cout<<line<<endl;
            //String Stream include sstream
            stringstream ss;
            //write line string in to string stream
            ss<<line;
            string item;

            getline(ss, item, ',');
            allStudents[counter].ID=stoi(item);

            getline(ss, item, ',');
            allStudents[counter].name=item;

            getline(ss, item);
            allStudents[counter].major=item;

            counter++;
        }
    }else
        cout<<"Error!"<<endl;
    //verify contents of allStudents array
    cout<<endl<<endl<<"Now we will print out the contents of the array"<<endl<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<allStudents[i].ID<<" "<<allStudents[i].name<<" "<<allStudents[i].major<<endl<<endl;
    }

    return 0;
}
