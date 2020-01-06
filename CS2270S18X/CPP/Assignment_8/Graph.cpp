#include "Graph.h"

using namespace std;

void Graph::addEdge(string v1, string v2, int distance)//Method to add edge between two cities
{
    for(int i=0; i<vertices.size(); i++) //loop thru the entire vertices vector
    {
        if(vertices[i].name==v1)//if the name of the city stored at pos 'i' is the same as the first city name, loop thru vertices again
        {
            for(int j=0; j<vertices.size(); j++)//loop thru the entire vertices vector
            {
                if(vertices[j].name==v2 && i!=j)//if the name at pos 'j' is the same as the second city name AND the two cities are different
                {
                    adjVertex av; //initialize a new adjVertex.
                    av.v=&vertices[j]; //assign the address of the pos 'j' to the vertex struct via the 'v' pointer in the adjVertex struct.
                    av.weight=distance; //assign the weight/"distance" to the weight member of the adjVertex struct.
                    vertices[i].adj.push_back(av); //add the new struct and its' info to the adj vector in the vertex struct of the first city 
                    //another vertex for edge in other direction
                    // adjVertex av2;
                    // av2.v = &vertices[i];
                    // av2.weight = weight;
                    // vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string name)
{
    bool found=false;
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].name==name)
        {
            found=true;
            cout<<vertices[i].name<<" already in the graph."<<endl;
        }
    }
    if(found==false)
    {
        vertex v;
        v.name=name;
        vertices.push_back(v);
    }
}
int Graph::isAdjacent(string v1, string v2)
{
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].name==v1)
        {
            for(int j=0; j<vertices[i].adj.size(); j++)
            {
                if(vertices[i].adj[j].v->name==v2)
                    return 1;
            }
        }
    }
    return 0;
}
void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices
    for(int i=0; i<vertices.size(); i++)
    {
        cout<<vertices[i].name<<"-->";
        for(int j=0; j<vertices[i].adj.size(); j++)
        {
            cout<<vertices[i].adj[j].v->name;
            if(j!=vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}
