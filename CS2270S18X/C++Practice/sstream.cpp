#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

    cout<<"Enter an integer value: "<<endl;
    int input;
    cin>>input;
    //now use stringstream to go from int to string
    stringstream ss;
    ss<<input;
    string temp;
    ss>>temp;
    cout<<"The integer form of the number: "<<input<<endl;
    cout<<"The string form of the number: "<<temp<<endl;

    //now use stringstream to go from string to int
    stringstream sso;
    int num;
    cout<<"Enter a number: "<<endl;
    cin>>num;
    cout<<"This is the number in integer form: "<<num<<endl;



    return 0;
}
