//Assignment 6 Main CPP
//Ryan Hoffman
//CSCI 2270
//
//
#include <iostream>
#include <string>
#include "MovieTree.cpp"

using namespace std;

void menu(MovieTree* m)
{
    string title;

    cout<<"======Main Menu====="<<endl;
    cout<<"1. Find a movie"<<endl;
    cout<<"2. Rent a movie"<<endl;
    cout<<"3. Print the inventory"<<endl;
    cout<<"4. Delete a movie"<<endl;
    cout<<"5. Count the movies"<<endl;
    cout<<"6. Quit"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"Enter title: "<<endl;
            getline(cin, title);
            m->findMovie(title);
            system("cls");
            break;
        case 2:
            cout<<"Enter title: "<<endl;
            getline(cin, title);
            m->rentMovie(title);
            system("cls");
            break;
        case 3:
            m->printMovieInventory();
            system("cls");
            break;
        case 4:
            cout<<"Enter title: "<<endl;
            getline(cin, title);
            m->deleteMovieNode(title);
            system("cls");
            break;
        case 5:
            m->countMovieNodes();
            system("cls");
            break;
        case 6:
            cout<<"Goodbye!"<<endl;
            return;
        default:
            cout<<"Invalid choice. Try again."<<endl;
            system("cls");
            menu(m);
    }
    menu(m);
}

int main()
{
    MovieTree *m=new MovieTree();
    menu(m);
    return 0;
}
