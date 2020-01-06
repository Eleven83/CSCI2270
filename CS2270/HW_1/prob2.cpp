/*
CSCI 2270 Fall 2018, Professor Gupta
TA: Saumya Sinha
Assignment 1
Author: Ryan Hoffman
9-5-2018
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

/*
Program to read a csv file and store the information in an array of structs
Where each line in the file is a struct element of the array
Print contents of the array
*/

//Defining the struct
struct User
{
    string username;
    float gpa;
    int age;
};

//Function to add a new student struct to the vector of structs
void addUser(vector<User> &users, string _username, float _gpa, int _age)
{
    //create a struct and store username, gpa, and age
    //add the struct to the vector
    User newUser;
    newUser.username=_username;
    newUser.gpa=_gpa;
    newUser.age=_age;

    //adding the struct to the vector list
    users.push_back(newUser);

    return;
}

//Function to print out each struct with its info
void printList(const vector<User> users)
{
    //Loop thru populated list
    //Print each element in the list as: "<USERNAME> [<GPA>] age: <AGE>"
    for(int i=0; i<users.size(); i++)
    {
        cout<<users[i].username<<" ["<<users[i].gpa<<"] age: "<<users[i].age<<endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    //Declare a vector of type User and initialize the variables
    vector<User> v;
    float gpa=0.0;
    string username;
    int age=0;

    //Open and read the file to store each line in a struct then add that struct
    //to the vector
    ifstream inFile(argv[1]);
    if(inFile.is_open())
    {
        string line, item;
        while(getline(inFile, line))
        {
            stringstream ss(line);
            getline(ss, item, ',');
            username=item;
            getline(ss, item, ',');
            gpa=stof(item);
            getline(ss,item);
            age=stoi(item);
            addUser(v, username, gpa, age);
        }
    }else
        cout<<"ERROR!"<<endl;
    printList(v);
    inFile.close();
    return 0;
}
