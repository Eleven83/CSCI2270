#include <iostream>
#include <sstream>
#include "Queue.cpp"

using namespace std;

//Menu to allow the user to choose between several options including quit,
//enqueue a word, dequeue a word, print the contents of the queue and enqueue a sentence.
void menu()
{
    bool repeat=false; //to be used to exit the menu if needed.
    string line, word;
    Queue q(10); //Per instructions
    while(!repeat) //While repeat is false
    {
        cout<<"======Main Menu====="<<endl;
        cout<<"1. Enqueue word"<<endl;
        cout<<"2. Dequeue word"<<endl;
        cout<<"3. Print queue"<<endl;
        cout<<"4. Enqueue sentence"<<endl;
        cout<<"5. Quit"<<endl;
        int choice=0; //initialized to avoid a garbage variable.
        cin>>choice; //user chooses which option they would like
        switch(choice) //switch case
        {
            case 1: //enqueue a word
                cout<<"word: ";
                cin>>word;
                q.enqueue(word);
                break;
            case 2: //dequeue a word
                q.dequeue();
                break;
            case 3: //print the contents of the queue
                q.printQueue();
                break;
            case 4: //enqueue a sentence
                cout<<"sentence: ";
                cin.ignore();
                getline(cin, line);
                q.enqueueSentence(line);
                break;
            case 5: //Quit the program
                cout<<"Goodbye!"<<endl;
                repeat=true;
                break;
            default:
                cout<<"Invalid Option, Try again"<<endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}
