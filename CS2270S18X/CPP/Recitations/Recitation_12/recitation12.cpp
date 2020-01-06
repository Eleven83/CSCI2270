#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    int value;
    bool visited;
    std::vector<adjVertex> adj;
};

class Graph
{
     public:
        Graph();
        ~Graph();
        void addEdge(int v1, int v2);
        void addVertex(int name);
        void displayEdges();
		void findAdjacentDivisibleByParentVertex(int startVertex);
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
void Graph::addEdge(int v1, int v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].value == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].value == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    /*adjVertex av2;
                    av2.v = &vertices[i];
                    vertices[j].adj.push_back(av2);*/
                }
            }
        }
    }
}
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].value == n){
            found = true;
            cout<<vertices[i].value<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.value = n;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].value<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->value<<"***";
        }
        cout<<endl;
    }

}

void Graph::findAdjacentDivisibleByParentVertex(int startVertex)
{
	vertex* start;
	for(int i=0; i<(int)vertices.size(); i++)
    {
		vertices[i].visited=false;
		if(vertices[i].value==startVertex)
        {
			start=&vertices[i];
		}
	}
	queue<vertex*> Q;
	Q.push(start);
	start->visited=true;
    cout<<start->value<<" ";
	while(!Q.empty())
    {
		vertex* node=Q.front();
		Q.pop();
		for(int i=0; i<(int)node->adj.size(); i++)
        {
            if(node->adj[i].v->visited!=true)
            {
                Q.push(node->adj[i].v);
                node->adj[i].v->visited=true;
                if(((node->adj[i].v->value) % (start->value))==0)
                {
                    cout<<node->adj[i].v->value<<" ";
                }
            }
		}
	}
}

int main() {

	Graph myGraph;

	myGraph.addVertex(10);
	myGraph.addVertex(20);
	myGraph.addVertex(30);
	myGraph.addVertex(40);

	myGraph.addEdge(10, 20); myGraph.addEdge(20, 10);
	myGraph.addEdge(10, 30); myGraph.addEdge(30, 10);
	myGraph.addEdge(10, 40); myGraph.addEdge(40, 10);
	myGraph.addEdge(20, 30); myGraph.addEdge(30, 20);
	myGraph.addEdge(20, 40); myGraph.addEdge(40, 20);

	myGraph.findAdjacentDivisibleByParentVertex(10);
	myGraph.findAdjacentDivisibleByParentVertex(20);

    return 0;
}
