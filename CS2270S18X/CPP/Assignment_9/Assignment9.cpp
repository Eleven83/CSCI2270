#include "Graph.h"
#include <queue>

using namespace std;

Graph::Graph()
{

}
Graph::~Graph()
{

}
void Graph::addEdge(std::string v1, std::string v2, int weight)
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
                    av.weight=weight; //assign the weight to the weight member of the adjVertex struct.
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
void Graph::addVertex(std::string name)
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
        v.districtID=-1;
        vertices.push_back(v);
    }
}
void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices
    for(int i=0; i<vertices.size(); i++)
    {
        cout<<vertices[i].districtID<<":"<<vertices[i].name<<"-->";
        for(int j=0; j<vertices[i].adj.size(); j++)
        {
            cout<<vertices[i].adj[j].v->name;
            if(j!=vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}
// void Graph::assignDistricts()
// {
//     unsigned int ID=-1;
//     queue <vertex*> Q;
//     vertex* v;
//     for(unsigned int i=0; i<vertices[i].size(); i++)
//     {
//         if(!vertices[i].visited)
//         {
//             v=&vertices[i];
//             ID++;
//             Q.push(v);
//             vertices[i].visited=true;
//         }
//         while(!Q,empty())
//         {
//             v=Q.front();
//             Q.pop();
//             v->ID=ID;
//             for(unsigned int j=0; j<v->adj.size(); j++)
//             {
//                 if(!v->adj[j].v->visited)
//                 {
//                     Q.push(v->adj[j].v);
//                     v->adj[j].v->visited=true;
//                     v-adj[j].v->districtID=ID;
//                 }
//             }
//         }
//     }
// }
// void Graph::DFSLabel(std::string startingCity, int distID)
// {
//
// }
// // Breadth First Search
void Graph::shortestPath(std::string startingCity, std::string endingCity)
{
    queue<vertex*> Q;
    vertex* startV;
    vertex* endV;
    for(unsigned int i=0; i<vertices.size(); i++)
    {
        if(startingCity==vertices[i].name)
        {
            startV=&vertices[i];
            Q.push(startV);
            vertices[i].visited=true;
        }
        while(!Q.empty())
        {
            startV=Q.front();
            Q.pop();
            if(!startV->adj[i].v->visited)
            {
                startV->adj[i].v->visited=true;
                Q.push(startV->adj[i].v);
                if(startV->adj[i].v->name==startingCity)
                {
                    startV=startV->adj[i].v;
                }
                if(startV->adj[i].v->name==endingCity)
                {
                    endV=startV->adj[i].v;
                }
                if(startV->districtID==endV->districtID)
                {
                    cout<<","<<startV->adj[i].v->name;
                    cout<<endl;
                }
                if((startV->districtID==-1) && (endV->districtID==-1))
                {
                    cout<<"Please identify the districts before checking distances"<<endl;
                    break;
                }
                if(startV->districtID!=endV->districtID)
                {
                    cout<<"No safe path between cities"<<endl;
                    break;
                }else{
                    cout<<"One or more cities doesn't exist"<<endl;
                    break;
                }
            }
        }
    }
}
// // Dijkstras
// void Graph::shortestWeightedPath(std::string startingCity, std::string endingCity)
// {
//
// }
