#include <iostream>
#include <fstream>

using namespace std;


int userChoice=0;
char endPrg=' ';

//Function to build the new network.
city *buildNetwork()
{
    system("CLS");
    cout<<"__________________________________________________________\n"<<endl;
    cout<<"Type any key to return to the main menu: "<<endl;
    int userChoice=0;
    char endPrg=' ';
    cin>>endPrg;
    endPrg=toupper(endPrg);
    switch(endPrg)
        {
            default:
                system("CLS");
                mainMenu();
        }
    return 0;
}
//Function to build the new network.
int printPath()
{
    system("CLS");
    cout<<"__________________________________________________________\n"<<endl;
    cout<<"Type any key to return to the main menu: "<<endl;
    int userChoice=0;
    char endPrg=' ';
    cin>>endPrg;
    endPrg=toupper(endPrg);
    switch(endPrg)
        {
            default:
                system("CLS");
                mainMenu();
        }
    return 0;
}
//Function to build the new network.
int transmitMsg()
{
    system("CLS");
    cout<<"__________________________________________________________\n"<<endl;
    cout<<"Type any key to return to the main menu: "<<endl;
    int userChoice=0;
    char endPrg=' ';
    cin>>endPrg;
    endPrg=toupper(endPrg);
    switch(endPrg)
        {
            default:
                system("CLS");
                mainMenu();
        }
    return 0;
}
//Function to build the new network.
int addCity()
{
    system("CLS");
    cout<<"__________________________________________________________\n"<<endl;
    cout<<"Type any key to return to the main menu: "<<endl;
    int userChoice=0;
    char endPrg=' ';
    cin>>endPrg;
    endPrg=toupper(endPrg);
    switch(endPrg)
        {
            default:
                system("CLS");
                mainMenu();
        }
    return 0;
}

//Function that displays a main menu with specific choices for each user.
int mainMenu()
{
    int userChoice=0;
    char mainOut=' ';
    bool exOut=true;
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast"<<endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Quit"<<endl;
    cin>>userChoice;
    while(exOut)
    {
        switch(userChoice)
        {
            case 1:
                buildNetwork();
                exOut=false;
                break;
            case 2:
                printPath();
                exOut=false;
                break;
            case 3:
                transmitMsg();
                exOut=false;
                break;
            case 4:
                addCity();
                exOut=false;
                break;
            case 5://If the user enters anything other than 'y' return to the main menu
                    exOut=false;
                    system("CLS");
                    mainMenu();
                    break;
            default:
                cout<<"You entered an incorrect choice. Try again."<<endl;
        }
    }
    return 0;
}
