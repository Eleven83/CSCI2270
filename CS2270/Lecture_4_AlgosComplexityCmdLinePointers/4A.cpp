#include <iostream>

//Command line args are arguments to the main function
//which run when the program runs
//argc is the number of arguments
//*argv is an array of pointers to the arguments

int main(int argc, char const *argv[]) {
    cout<<"Hello world"<<endl;

    cout<<argc<<endl;
    //argv[0] is name of program running
    cout<<argv[0]<<endl;
    //cout<<argv[1]<<endl;

    //loop through the arguments
    //Don't have to know how many arguments because that is set with argc

    for(int i=1; i<argc; i++0)
    {
        cout<<argv[i]<<endl;
        //Let's remove the index and see what happens...
        //...Brings us to the next part of the lecture...
    }
    return 0;
}
