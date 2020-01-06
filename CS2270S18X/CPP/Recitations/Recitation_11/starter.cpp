#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct vertex;

struct adjVertex {
	vertex* v;
	int weight;
};

struct vertex {
	string key;
	vector<adjVertex> adjacent;
	bool visited = false;
};

class Graph {
	private:
		//vertices
		vector<vertex> vertices;
		vertex* findVertex(string);
	public:
		//methods for accessing graphs
		Graph();
		~Graph();
		void insertVertex(string);	//identifier of the vertex
		void insertEdge(string,string,int);	//start, end, weight
		void printGraph();
		void DFSpath(string, string);
		void findNodeWithMaximumAdjacent(string);

};

Graph::Graph() {}

Graph::~Graph() {}

void Graph::insertVertex(string value) {
	bool found = false;
	int i=0;
	while (i<vertices.size() && !found) {
		if (vertices[i].key == value) {
			found = true;
		}
		i++;
	}
	if (!found) {
		vertex v;
		v.key = value;
		vertices.push_back(v);
	}
	else {
		cout << "There is already a vertex " << value << " in this graph" << endl;
	}
}

vertex* Graph::findVertex(string value) {
	int i=0;
	while (i<vertices.size()) {
		if (vertices[i].key == value) {
			return &vertices[i];
		}
		i++;
	}
	return nullptr;
}



void Graph::insertEdge(string v1, string v2, int weight) {
	vertex *vStart = findVertex(v1);
	vertex *vEnd = findVertex(v2);
	if (vStart!=nullptr && vEnd!=nullptr) {
		//this code assumes that an edge doesn't exist
		//write some error checking to handle when it does
		adjVertex v1v2Edge;
		v1v2Edge.weight = weight;
		v1v2Edge.v = vEnd;
		vStart->adjacent.push_back(v1v2Edge);
	}
	else {
		if (vStart == nullptr) {
			cout << "no vertex with name " << v1 << " in this graph" << endl;
		}
		if (vEnd == nullptr) {
			cout << "no vertex with name " << v2 << " in this graph" << endl;
		}
	}
}

void Graph::findNodeWithMaximumAdjacent(string start)
{
	vertex* startV; //initialize a pointer to a vertex struct
	for(int i=0; i<vertices.size(); i++) //Other: i<(int)vertices.size() works also...
	{
		vertices[i].visited=false;
		if(vertices[i].key==start)
		{
			startV=&vertices[i];
		}
	}
	queue<vertex*> Q;
	Q.push(startV);
	startV->visited=true;
	cout<<startV->key<<" ";
	vector<vertex*> maxNode; //create a vector of vertex to store the node(s) with the most adjacent nodes
	int maxAdjSize=start.size(); //initialize to the size of the vector
	maxNode.push_back(startV);
	while(!Q.empty())
	{
		vertex* node=Q.front();
		Q.pop();
		for(int i=0; i<(int)node->adjacent.size(); i++)
		{
			if(!node->adjacent[i].v->visited)
			{
				node->adjacent[i].v->visited=true;
				cout<<node->adjacent[i].v->key<<" ";
				Q.push(node->adjacent[i].v);
				if(node->adjacent[i].v->adjacent.size()>maxAdjSize)
				{
					maxAdjSize=node->adjacent[i].v->adjacent.size();
					maxNode.clear();
					maxNode.push_back(node->adjacent[i].v);
				}else if(node->adjacent[i].v->adjacent.size()==maxAdjSize){
					maxNode.push_back(node->adjacent[i].v);
				}
			}
		}
	}
	cout<<"\n";
	for(int j=0; j<maxNode.size(); j++)
		cout<<maxNode[j]->key;
}

void Graph::DFSpath(string src, string dst)
{

}


int main() {

	Graph myGraph;

	myGraph.insertVertex("A");
	myGraph.insertVertex("B");
	myGraph.insertVertex("C");
	myGraph.insertVertex("D");
	myGraph.insertVertex("E");
	myGraph.insertVertex("F");
	myGraph.insertVertex("G");

	myGraph.insertEdge("A", "B", 0); myGraph.insertEdge("B", "A", 0);
	myGraph.insertEdge("A", "C", 0); myGraph.insertEdge("C", "A", 0);
	myGraph.insertEdge("B", "D", 0); myGraph.insertEdge("D", "B", 0);
	myGraph.insertEdge("C", "D", 0); myGraph.insertEdge("D", "C", 0);
	myGraph.insertEdge("E", "D", 0); myGraph.insertEdge("D", "E", 0);
	myGraph.insertEdge("E", "B", 0); myGraph.insertEdge("B", "E", 0);
	myGraph.insertEdge("E", "G", 0); myGraph.insertEdge("G", "E", 0);
	myGraph.insertEdge("F", "G", 0); myGraph.insertEdge("G", "F", 0);

	myGraph.findNodeWithMaximumAdjacent("A");

	return 0;

}
