#include <iostream>
#include <vector>
#include "Graph.cpp"

using namespace std;


int main()
{
    Graph g;
    g.addVertex("Boulder");
    g.addVertex("Denver");
    g.addVertex("Texas");

    g.addEdge("Boulder", "Denver", 30);
    g.addEdge("Denver", "Texas", 300);
    g.addEdge("Boulder", "Texas", 330);
    g.displayEdges();

    return 0;
}
