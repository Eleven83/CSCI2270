#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Graph.cpp"

using namespace std;

int main()
{
    Graph g;
    string line, word;
    int x=0;
    int y=-1;
    vector<string> cities;
    ifstream inFile("mat.txt");
    if(!inFile.is_open())
    {
        cout<<"File Not Open!"<<endl;
        return 0;
    }else{
        while(getline(inFile, line))
        {
            stringstream sso(line);
            getline(sso, word, ' '); //discard first part "dest/source"
            if(y==-1)
            {
                while(getline(sso, word, ' '))
                {
                    g.addVertex(word);
                    cities.push_back(word);
                }
                y++;
            }else{
                x=0;
                while(getline(sso, word, ' '))
                {
                    g.addEdge(cities[x], cities[y], stoi(word));
                    x++;
                }
                y++;
            }
        }
    }
    g.displayEdges();
    return 0;
}
