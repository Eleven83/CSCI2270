/*
1. Write a method in the Graph class to determine if two vertices share an
adjacent vertex, but are not connected to each other.
Your method should be called studentFunction, and take two string
arguments, and return a bool:
bool Graph::studentFunction(string v1, string v2)
The input arguments are the key values for the vertices, and then function
returns true if the vertices share an adjacent vertex and false otherwise.
In the code provided, there is a graph already built. Use that graph to verify
that your code passes the following test cases:
    //returns false since a adjacent to b
    cout << g.studentFunction("a", "b") << endl;

    //returns true since a-d-c in graph, a and c both adjacent to d
    cout << g.studentFunction("a", "c") << endl;

    //returns false since a-d-e-g in graph is path a - g
    cout << g.studentFunction("a", "g") << endl;

    //returns false since start and end vertex are the same
    cout<<g.studentFunction(“a”,”a”)<<endl;

    //returns false because a adjacent to d, even though a-e-d is
    //also a path where they share an adjacent vertex
    cout<<g.studentFunction(“a”, ”d”)<<endl;
*/
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
		bool studentFunction(string, string); //write me
        void displayEdges();
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

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        //vertices[i].adj is a vector and we can call size() to get number of elements
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
            //if we wanted to show weight, vertices[i].adj[j].weight - don't need dereference

        }
        cout<<endl;
    }

}

bool Graph::studentFunction(string v1, string v2)
{
    //code here.
}
