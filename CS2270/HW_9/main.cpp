#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

#include "Graph.hpp"

using namespace std;


int main(int argc, char const *argv[])
{
    Graph g;
    ifstream inFile(argv[1]);
    string line, city, distance;
    vector<string> cities;
    getline(inFile, line);
    stringstream ss(line);
    getline(ss, city, ',');
    while(getline(ss, city, ','))
    {
        g.addVertex(city);
        cities.push_back(city);
    }
    while(getline(inFile, line))
    {
        stringstream ss(line);
        getline(ss, city, ',');
        int i=0;
        while(getline(ss, distance, ','))
        {
            if(stoi(distance)>0)
            {
                g.addEdge(city, cities[i], stoi(distance));
                cout<<" ... Reading in "<<city<<" -- "<<cities[i]<<" -- "<<distance<<endl;
            }
            i++;
        }
    }
    g.assignDistricts();
    g.displayEdges();

    return 0;
}
