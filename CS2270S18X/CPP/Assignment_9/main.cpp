#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Assignment9.cpp"

using namespace std;

int printMenu(Graph g)
{
    int choice=0;
    string v1, v2;
    string startingCity;
    string endingCity;
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Print vertices"<<endl;
    cout<<"2. Find districts"<<endl;
    cout<<"3. Find shortest path"<<endl;
    cout<<"4. Find shortest weighted path"<<endl;
    cout<<"5. Quit"<<endl;
    cin>>choice;
    switch (choice) {
        case 1:
            g.displayEdges();
            break;
        case 2:
            //g.assignDistricts();
            break;
        case 3:
            cout<<"Enter a starting city: "<<endl;
            getline(cin, startingCity);
            cout<<"Enter an ending city: "<<endl;
            getline(cin, endingCity);
            g.shortestPath(startingCity, endingCity);
            break;
        case 4:
            cout<<"";
            break;
        case 5:
            cout<<"Goodbye!"<<endl;
            return 1;
            break;
        default:
            cout<<"Invalid Choice. Try again."<<endl;
    }
    return 0;
}

int main()
{
    Graph g;
    string line, word;
    char startChar='A';
    int x=0;
    int y=-1;
    vector<string> cities;
    ifstream inFile("zombieCities.txt");
    if(!inFile.is_open())
    {
        cout<<"Something Went Wrong."<<endl;
        return 0;
    }else{
        while(getline(inFile, line))
        {
            stringstream sso(line);
            getline(sso, word, ',');
            if(y==-1)
            {
                while(getline(sso, word, ','))
                {
                    g.addVertex(word);
                    cities.push_back(word);
                }
                y++;
            }else{
                x=0;
                while(getline(sso, word, ','))
                {
                    if(word!="0" && word!="-1")
                    {
                        g.addEdge(cities[x], cities[y], stoi(word));
                    }
                    x++;
                }
                y++;
            }
        }
    }
    int temp=0;
    while(temp!=1)
        temp=printMenu(g);

    return 0;
}
