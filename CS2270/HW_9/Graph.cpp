#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

#include "Graph.hpp"

using namespace std;

Graph::Graph()
{

}
Graph::~Graph()
{

}
//Method to create an edge between two vertices
void Graph::addEdge(std::string v1, std::string v2, int distance)
{
    for(int i=0; i<vertices.size(); i++) //loop thru the entire vertices vector
    {
        if(vertices[i].name==v1)//if the name of the city stored at pos 'i' is the same as the first city name, loop thru vertices again
        {
            for(int j=0; j<vertices.size(); j++)//loop thru the entire vertices vector
            {
                if(vertices[j].name==v2 && i!=j)//if the name at pos 'j' is the same as the second city name AND the two cities are different
                {
                    Edge adjVertex; //initialize a new adjacent vertex.
                    adjVertex.v=&vertices[j]; //assign the address of pos 'j' to the vertex struct via the 'v' pointer in the Edge struct.
                    adjVertex.distance=distance; //assign the distance to the adjacent vertex.
                    vertices[i].Edges.push_back(adjVertex); //add the new struct and its' info to the adj vector in the vertex struct of the first city
                }
            }
        }
    }
}

//Method to create a vertex, takes city name as parameter
void Graph::addVertex(std::string name)
{
    bool isVertex=false;
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].name==name)
        {
            isVertex=true;
        }
    }
    if(isVertex==false)
    {
        vertex v;
        v.name=name;
        v.district=-1;
        vertices.push_back(v);
    }
}
//Method to print all the edges in the graph
void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices
    for(int i=0; i<vertices.size(); i++)
    {
        cout<<vertices[i].district<<":"<<vertices[i].name<<"-->";
        for(int j=0; j<vertices[i].Edges.size(); j++)
        {
            cout<<vertices[i].Edges[j].v->name<<" ("<<vertices[i].Edges[j].distance<<" miles)";
            if(j!=vertices[i].Edges.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}
//Method to iterate through the vertices, perform BFT to find connected
//components, and assign to district
void Graph::assignDistricts()
{
    int districtID=1;
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].district==-1)
        {
            BFTraversalLabel(vertices[i].name, districtID);
            districtID++;
        }
    }
}
//Method to iterate through the vertices, perform DFS by calling the
//DFTraversal function
void Graph::printDFS()
{
    setAllVerticesUnvisited();
    for(int i=0; i<vertices.size(); i++)
    {
        if(!vertices[i].visited)
        {
            DFTraversal(&vertices[i]);
        }
    }

}
//Method to iterate through the vertices, mark them unvisited.
//This function is called prior to calling DFS after BFS has been performed
//so that the nodes can revisited again when DFS is called.
void Graph::setAllVerticesUnvisited()
{
    for(int i=0; i<vertices.size(); i++)
    {
        vertices[i].visited=false;
    }
}
//Method to find and return the vertex of the specified city
vertex* Graph::findVertex(std::string name)
{
    for(int i=0; i<(int)vertices.size(); i++)
    {
        if(vertices[i].name==name)
        {
            return &vertices[i];
        }
    }
    return NULL;
}
// Call BFTraversalLabel from within assignDistricts to label the districts.
// This method should implement a breadth first traversal from the startingCity
// and assign all cities encountered the distID value
void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
    vertex* startV=findVertex(startingCity);
    queue<vertex*> vQueue;
    startV->visited=true;
    vQueue.push(startV);
    if(startV!=NULL)
    {
        while(!vQueue.empty())
        {
            startV->district=distID;
            vertex* assign=vQueue.front();
            vQueue.pop();
            for(int i=0; i<assign->Edges.size(); i++)
            {
                if(!assign->Edges[i].v->visited)
                {
                    assign->Edges[i].v->visited=true;
                    assign->Edges[i].v->district=distID;
                    vQueue.push(assign->Edges[i].v);
                }
            }
        }
    }
}
//Method to traverse depth first
void Graph::DFTraversal(vertex *v)
{
    v->visited=true;
    cout<<v->name<<endl;
    for(int i=0; i<v->Edges.size(); i++)
    {
        if(!v->Edges[i].v->visited)
        {
            DFTraversal(v->Edges[i].v);
        }
    }
}
