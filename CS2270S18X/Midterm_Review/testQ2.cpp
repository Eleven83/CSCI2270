#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    std::string name;
    bool visited;
    int distance;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2);
        void addVertex(std::string name);
	bool ifPathExistsLessThanDist(string vertex1, string vertex2, int dist);
    protected:
    private:
        std::vector<vertex> vertices;

};

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2){

    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < (int)vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
		v.visited = false;
        vertices.push_back(v);

    }
}

bool Graph::ifPathExistsLessThanDist(string vertex1, string vertex2, int dist)
{
    vertex* start;
    vertex* end;
    int pathSize=0;
    queue<vertex*> Q;
    for(unsigned int i=0; i<vertices.size(); i++)
    {
        if(vertex1==vertices[i].name)
        {
            start=&vertices[i];
            start->visited=true;
            start->distance = 0;
            Q.push(start);
        }
        if(vertex2==vertices[i].name)
        {
            end=&vertices[i];

        }
    }
    while(!Q.empty())
    {
        start=Q.front();
        Q.pop();

        for(unsigned int j=0; j<start->adj.size(); j++)
        {

            if(start->adj[j].v->visited!=true)
            {
                Q.push(start->adj[j].v);
                start->adj[j].v->visited=true;
                start->adj[j].v->distance = start->distance+1;
            }
        }
    }
    if(end->distance < dist)
    {
        return true;
    }
    return false;
//    return(end->distance < dist)
}

int main() {
    Graph g;

    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addVertex("d");
    g.addVertex("e");

    g.addEdge("a", "b");
    g.addEdge("a", "d");
    g.addEdge("c", "d");
    g.addEdge("b", "c");
    g.addEdge("d", "e");
    g.addEdge("c", "e");

    cout << g.ifPathExistsLessThanDist("c", "b", 1) << endl;;

    return 0;
}


//
void replaceMaxWithMin(TreeNode *root)
{
    TreeNode* min=NULL;
    TreeNode* max=NULL;
    TreeNode* temp = root;
    if(root!=NULL)
    {
        while(temp->leftChild != NULL){
            temp=temp->leftChild;
        }
        min = temp;
        temp = root;
        while(temp->rightChild!=NULL)
        {
            temp=temp->rightChild;
        }
        max = temp;
        min=max->parent->rightChild;
        if(max->leftChild!=NULL)
        {
            max->leftChild->parent = min;
            min->leftChild = max->leftChild;
        }
        min->parent->leftChild = NULL;
        min->parent=max->parent;
    }
}
