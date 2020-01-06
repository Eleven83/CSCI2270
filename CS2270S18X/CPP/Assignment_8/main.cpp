#include <iostream>
#include <sstream>
#include <fstream>
#include "Graph.cpp"

using namespace std;

int printMenu(Graph g)
{
    int choice=0;
    string v1, v2;
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Print vertices"<<endl;
    cout<<"2. Vertex adjacent"<<endl;
    cout<<"3. Quit"<<endl;
    cin>>choice;
    switch (choice) {
        case 1:
            g.displayEdges();
            break;
        case 2:
            cin.ignore(); //eat the newline char to handle the getline(cin, variable)
            cout<<"Enter first city:"<<endl;
            getline(cin, v1);
            cout<<"Enter second city:"<<endl;
            getline(cin, v2);
            if(g.isAdjacent(v1, v2)==1)
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
            break;
        case 3:
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
            std::cout << line << '\n';
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
