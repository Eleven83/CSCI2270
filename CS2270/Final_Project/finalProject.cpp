/*
CSCI 2270 - Data Structures
Professor: Shayon Gupta, Fall 2018
Final Project
Authors: Ryan Hoffman & Phil Amell
*/
/*
Choose Your Own Mad-Libs Adventure!
This program will take several inputs from the user and inject them into a
pre-written story line. The story pauses at different points to allow the user
to choose between multiple options that continue the story in a unique direction.
In the end, the user is provided with a conclusion that makes use of all of the
various inputs used throughout their story.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class WordList{
    struct Node{
        string x;
        Node *next;
    };
public:
    WordList(){
        head = NULL;
    }
    ~WordList(){
        Node *next=head;
        while(next){
            Node *deleteMe=next;
            next=next->next;
            delete deleteMe;
        }
    }
    int choiceMenu(){
        cout<<"<<<<<<<< MAD  LIBS >>>>>>>>\n";
        cout<<"<<<<<<<< Main Menu >>>>>>>>\n";
        cout<<"===========================\n";
        cout<<"Please Select from the Following Options:\n";
        cout<<"1. Begin a New Adventure\n";
        cout<<"2. Read the Instructions\n";
        cout<<"3. Quit\n";
        int choice;
        cin>>choice;
        return choice;
    }
    void addWord(string input){
        Node *n=new Node();
        n->x=input;
        n->next=NULL;
        if(head==NULL){
            head = n;
        }
        else{
            Node *tmp = head;
            while(tmp->next!=NULL){
                tmp = tmp->next;
            }
            tmp->next = n;
        }

    }
    string popWord(){
        Node *n=head;
        string ret = n->x;
        head=head->next;
        delete n;
        return ret;
    }
    int adventureMenu(){
        cout<<endl;
        cout<<"<<<<<<<< Stories >>>>>>>>\n";
        cout<<"1. In the land of Bohemia\n";
        cout<<"2. Modern Infamy\n";

        int choice;
        cin>>choice;
        return choice;
    }
    void addNoun(){
        string input;
        cout<<"Please enter a noun."<<endl;
        getline(cin, input);
        addWord(input);
    }
    void addVerb(){
        string input;
        cout<<"Please enter a verb."<<endl;
        getline(cin, input);
        addWord(input);
    }
    void addAdj(){
        string input;
        cout<<"Please enter an adjective."<<endl;
        getline(cin, input);
        addWord(input);
    }
    void addStressEvent(){
      string input;
      cout<<"What is the most stressful thing you can imagine?"<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addPairBodyParts(){
      string input;
      cout<<"Name a pair of body parts."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addParent(){
      string input;
      cout<<"Please enter the first name of one of your parents."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addCelebrity(){
      string input;
      cout<<"Who is your favorite celebrity?"<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addBadBand(){
      string input;
      cout<<"Least favorite musical artist."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addBadSong(){
      string input;
      cout<<"Your least favorite musical artist's biggest hit."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addPastVerb(){
      string input;
      cout<<"Please enter a verb in the past tense."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addBadCelebrity(){
      string input;
      cout<<"Who is your least favorite celebrity?"<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addName(){
      string input;
      cout<<"Please enter your name."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addOccupation(){
      string input;
      cout<<"Please enter your dream job."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addAmount(){
      string input;
      cout<<"Please enter an adjective expressing an amount of something (I.e little, huge, very, scarsely)."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addIngVerb(){
      string input;
      cout<<"Please enter an 'ing' verb."<<endl;
      getline(cin, input);
      addWord(input);
    }
    void addRelation(){
      string input;
      cout<<"Please enter an adjective describing a relationship(i.e close, tight-knit, kickin-it)"<<endl;
      getline(cin, input);
      addWord(input);
    }

private:
    Node *head;
};

int main(){
    WordList List;
    int choice = 0;
    while(choice!=3)
    {
        choice = List.choiceMenu();
        switch(choice)
        {
            case 1:
            {
                int advChoice = List.adventureMenu();
                if(advChoice==1)
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    List.addNoun();List.addStressEvent();List.addVerb();
                    List.addPairBodyParts();List.addAdj();List.addAmount();
                    List.addCelebrity();List.addParent();
                    List.addBadBand();List.addAdj();List.addBadSong();
                    List.addPastVerb();List.addBadCelebrity();List.addVerb();
                    List.addVerb(); List.addOccupation();List.addName();
                    cout<<endl;
                    cout<<endl;

                    cout<<"Is this the real "<<List.popWord()<<"? Is this just fantasy?"<<endl;
                    cout<<"Caught in a "<<List.popWord()<<", no escape from reality"<<endl;
                    cout<<"Open your "<<List.popWord()<<", "<<List.popWord()<<" up to the skies and seeee"<<endl;
                    cout<<"I'm just a "<<List.popWord()<<" boy, I need no sympathy"<<endl;
                    cout<<"Because I'm easy come, easy go, "<<List.popWord()<<" high, little low"<<endl;
                    cout<<"Any way the wind blows doesn't really matter to "<<List.popWord() <<", to "<< List.popWord() <<"."<<endl;
                    cout<<"\t\t----------PIANO MUSIC---------\t\t"<<endl;
                    cout<< List.popWord() <<", just killed a man"<<endl;
                    cout<<"Put "<< List.popWord() <<" against his head, pulled my trigger, now he's "<< List.popWord() <<endl;
                    cout<<"Mama, life has just "<< List.popWord() <<"."<<endl;
                    cout<<"But now I've gone and thrown it all away"<<endl;
                    cout<< List.popWord() <<", ooh, didn't mean to make you cry!"<<endl;
                    cout<<"If I'm not back again this time tomorrow"<<endl;
                    cout<< List.popWord() <<" on, "<< List.popWord() <<" on as if nothing really matters"<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"Writen, and performed by: "<< List.popWord() <<". The greatest damn "<< List.popWord() <<" around."<<endl;
                }
                else{
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    List.addNoun();List.addNoun();List.addIngVerb();List.addRelation();List.addNoun();List.addIngVerb();List.addIngVerb();List.addNoun();
                    List.addAdj();List.addPastVerb();List.addVerb();List.addPastVerb();List.addNoun();List.addNoun();
                    cout<<""<<endl;
                    cout<<""<<endl;
                    cout<<""<<endl;
                    cout<<""<<endl;
                    cout<<"-------------------------------------------------"<<endl;
                    cout<<" December 10th, 2018 a date which will live in infamy."<<endl;
                    cout<<" The United States of America was suddenly and deliberately attacked"<<endl;
                    cout<<" by "<< List.popWord() <<" and "<< List.popWord() <<" forces of the Empire of Japan."<<endl;
                    cout<<" The United States was "<< List.popWord() <<" with that Nation and, at the "<< List.popWord() <<" of Japan"<<endl;
                    cout<<" was still in a "<< List.popWord() <<" competition with its Government and its Emperor looking toward the "<< List.popWord() <<" of peace in the Pacific."<<endl;
                    cout<<" Indeed, one hour after Japanese "<< List.popWord() <<" squadrons had commenced "<< List.popWord() <<" in the American Island of Oahu,"<<endl;
                    cout<<" the Japanese Ambassador to the United States and his colleague "<<endl;
                    cout<< List.popWord() <<" to our Secretary of State a "<< List.popWord() <<" reply to a recent American message."<<endl;
                    cout<<" And while this reply "<< List.popWord() <<" that it seemed useless to "<< List.popWord() <<"."<<endl;
                    cout<<" the existing diplomatic negotiations, it contained no "<< List.popWord() <<" or hint of "<< List.popWord() <<"."<<endl;
                    cout<<"-------------------------------------------------"<<endl;
                    cout<<""<<endl;
                    cout<<""<<endl;
                    cout<<""<<endl;
                    cout<<""<<endl;

                }
                break;
            }
            case 2:
            {
                //fileReader("readme.txt");
                cout<<"How to Play:\n";
                cout<<"-----------\n";
                cout<<"Simply fill in the blanks with the required information and enjoy the\n";
                cout<<"hilarious story that is created!\n";
                break;
            }
            case 3:
            {
                cout<<"\n<<<<<<<< GAME OVER >>>>>>>>\n";
                break;
            }
            default:
                cout<<"\nYou Made an Invalid Choice. Try Again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
