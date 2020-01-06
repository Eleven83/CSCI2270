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

//Question 1
    //Here

//Question 2
// In the graph provided, each vertex in the graph contains a parent ID, which is
// the ID of the parent vertex in a BFS. Some of the vertices have an incorrect parent ID assigned.
// Write a C++ method that prints all vertices that have a mis-labeled parent ID.
// You do not need to check the parentID for the starting node. You need to fill
// appropriate code in the following function which has already been defined for you.
// void Graph::printMislabeledParents(int startVertex);
// The function should print the starting vertex and the vertices with mis-labeled
// parent IDs in the order in which they are visited. The vertex structure includes
// a "visited" variable, set to false by default. You can use this variable in the findAdjacentWithSmallerValue function.

struct adjVertex{
    vertex *v;
};
struct vertex{
    int value;
    int parentID
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
	void printMislabeledParents(int startVertex);
    private:
        std::vector<vertex> vertices;
};
void Graph::printMislabeledParents(int startVertex)
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
	cout<<start->value<<endl;
	while(!Q.empty())
    {
		vertex* node=Q.front();
		Q.pop();

	}
}


//Question 7
// Write a c++ function to color vertices based on distance from the source. The function takes one
// parameter: starting vertex. Color the source node as "Red".
// Color all its neighbors(1 hop away from source) as "Black". Color all vertices that are 2 hops away
// from source as "Red", 3 hops away as "Black" and so on. Use the built-in C++ queue data structure to
// implement the queue.
struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
	bool visited;
	string color;
    std::vector<adjVertex> adj;
};
class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayVertices();
		void colorVertices(string sourceVertex);
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

void Graph::colorVertices(string sourceVertex)
{
    //Start with a standard breadthFirstTraverse
    //Since we aren't given a search function, we need to implement one.
    vertex* startV;
    for(unsigned int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].name==sourceVertex)
        {
            startV=&vertices[i];
        }
    }
    cout<<startV->name;
    //Now, after above BFT search finds the starting vertex, continue with BFT algorithm
    startV->visited=true;
    startV->color="Red";
    queue<vertex*> Q;
    Q.push(startV);
    vertex* n;
    //Now we can scan the queue.
    while(!Q.empty())
    {
        n=Q.front(); //dequeue part 1
        Q.pop(); //dequeue part 2
        //scan the list of each element in Q
        for(unsigned int i=0; i<n->adj.size(); i++)
        {
            if(!n->adj[i].v->visited)
            {
                n->adj[i].v->visited=true;
                //Delete later for coderunner
                cout<<n->adj[i].v->name;
                Q.push(n->adj[i].v);
                //Check the n node color and set adj to the opposite
                if(n->color=="Red")
                {
                    n->adj[i].v->color="Black";
                }else
                    n->adj[i].v->color="Red";
            }
        }
    }
}
void Graph::addEdge(string v1, string v2, int weight){

    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
		v.visited = false;
		v.color = "";
        vertices.push_back(v);

    }
}

void Graph::displayVertices(){
    //loop through all vertices and adjacent vertices
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<":"<<vertices[i].color;
        cout<<endl;
    }

}

int main() {
	Graph g;

    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addVertex("d");
    g.addVertex("e");

    g.addEdge("a", "b", 2);
    g.addEdge("a", "d", 2);
    g.addEdge("c", "d", 2);
    g.addEdge("b", "c", 2);
    g.addEdge("d", "e", 2);
    g.addEdge("c", "e", 2);

    g.colorVertices("a");
	// g.displayVertices();
	return 0;
}

//NOTE:
9.3 BST Complexity
The runtime for the search(), insert(), and delete() algorithms on a BST depends on how the tree is built.
For example, the following sequence of integers:
< 15, 8, 4, 18, 10, 17, 20, 9, 11 >
generates the BST shown in Figure 18.
Figure 18. Example of a balanced BST. The left and right child positions are occupied at
all levels except the last and there is only a one-level difference in the left and right sub-trees of the root.
The BST is balanced; the left and right child positions for all nodes in the tree are occupied at all levels except
the last level, and there is only a one-level difference in the left and right sub-trees of the root.

However, a BST built from a sorted sequence of data:
<4, 8, 9, 10, 11, 15, 17, 18, 20>
Figure 19. Example of a BST built from sorted data. The BST is effectively a
linked list and operations on this BST will have O(n) behavior.

Definitions:
1. Leaf node - A leaf node is a node in a tree that does not have any children.
2. Height of a tree - The height of a tree is the number of edges between the root to the deepest leaf node.
3. Definition of balanced tree - A balanced binary search tree has the minimum possible maximum height.
For each node x, the heights of the left and right sub-trees of x differ by at most 1.

In a BST, basic operations to search, insert, and delete run in O(h) time,
where h is the height of the tree. When n = h, where n is the number of nodes,
these operations are O(n) and the BST has the same runtime properties as a linked list.
When the tree is balanced, as in Figure 18, the distance from the root to any leaf node
at the bottom of the tree, is log2(n), where n is the number of nodes in the tree.
In a BST with 9 nodes, there are 3-4 levels, and in the worst case, there would be 4 comparisons
to find a node in the tree. Calculating log2(9) ≈ 3.16 shows that log(n) is a good approximation.

10 Recursion
Recursion is the process of a function calling itself, and it is frequently used to evaluate
structures that can be defined by self-similarity, such as trees. A recursive call to a function
evaluates a smaller and smaller instance of the structure until the smallest case is reached.

10.1 Rules for recursive algorithms
There are two rules that define the structure of any recursive algorithm.
The algorithm needs to include:
• A base case. This is the smallest unit of the problem that can be defined.
Once the base case is reached, the algorithm should return without additional recursive calls.
• A set of rules that can reduce all cases down to the base case. The base case
is the exit strategy for a recursive algorithm. If the algorithm never reaches the base case, then it will never exit.

In a BST, the base case is an individual node with no children. Smaller and smaller
sub-trees can be evaluated until a sub-tree is reached that is a single node.

10.2 Tree traversal algorithms
Recursion is often used in tree traversal algorithms. Just as the contents of an
array can be traversed, so can the nodes in a tree to determine the values in the tree.
With any tree traversal algorithm, the objective is to evaluate every node in the tree exactly once,
and the algorithm used determines the order in which the nodes are visited.

There are three orderings to consider for tree traversals:
• In-order - Nodes are visited in the order left child - parent - right child, which can generate a sorted output in a binary search tree (BST).
• Pre-order - Nodes are visited in the order parent - left child - right child.
• Post-order - Nodes are visited left child - right child - parent.

11 Tree Balancing
Binary search trees (BST) provide an efficient structure for storing and retrieving data.
When the BST is balanced with a height of O(log n), the complexity of insert, search, and delete operations is also O(log n),
where n is the number of nodes in the tree. However, in an unbalanced tree, the complexity of these operations can be O(n) in the worst case.

Tree-balancing algorithms are applied to BSTs to ensure that, as nodes are added to the tree,
the tree remains balanced with an O(log2 n) height and the complexity of operations on the tree is also O(log2n).

11.1 Red-black trees
One common approach to tree balancing is to build the BST as a red-black tree.
In the red-black tree algorithm, each node in the BST is assigned a color, either red or black,
and the nodes in the tree are ordered such that no path from the root to a leaf can be
more than twice as long as any other path. This coloring results in red-black trees having a
height of O(log n), which guarantees a worst-case runtime of O(log n) on search, insert, and delete operations.

11.1.1 Red-black node properties
Each node in a red-black tree has at least the following properties:
• color
• key
• left child
• right child
• parent
The only red-black property not found in a regular BST is the color, which is added to the nodes to create the structure in the tree.

PROPERTIES:
Property 1: A node is either red or black.
Property 2: The root node is black.
Property 3: Every leaf (NULL) node is black.
Property 4: If a node is red, then both of its children must be black.
Property 5: For each node in the tree, all paths from that node to the leaf nodes contain the same number of black nodes.

Another difference between a regular BST and a red-black tree is how the leaf nodes are represented.
In a red-black tree, the leaf nodes are external sentinel nodes with all of the same properties as a
regular node, but they are effectively empty nodes. The leaf nodes are black to satisfy Property 3 of a red-black tree.

11.1.3 Red-black tree balancing
When nodes are added or deleted from a red-black tree, the operation can destroy the red-black properties
of the tree. For example, deleting the 4 from the red-black tree in Figure 2 potentially creates
a configuration where the 2, which is red, has a red child. This configuration violates Property 4,
which states that children of a red node must be black. To resolve this violation, the tree can be
balanced using rotation and recoloring to restore the red-black properties. The particular balancing
algorithm needed depends on the operation and the violation.

11.1.4 Left and right rotations
Rotations are local operations on nodes that reorder the nodes in the tree in a way that
preserves the BST properties and set the tree up for recoloring to restore the red-black properties.
Rotations are used in red-black trees as well as in most other tree-balancing algorithms.

There are two types of rotations: a left rotation and a right rotation. Figure 3 shows
the tree that results from both a left and a right rotation. These rotations are
inverses of each other: a tree rooted at x, shown in the right-side image in Figure 3,
that undergoes a left rotation produces the tree shown in the left-side image in Figure 3.
Performing a right rotation on that same tree, rooted at y, returns the tree to its original state.

12 Graphs
The map of the Midwestern United States in Figure 1 shows the major cities between Denver and
Kansas City and the roads that connect them. Anyone interested in travelling between any two
cities on the map, would first identify the two cities and then identify the roads between them.

Graphs provide a structure for representing connections between people, places, or things that
captures the essence of the connections. A person wanting to between Denver and Kansas City
would likely due so using major highways. They would want to identify the path between the two cities,
including the distance and if the path goes through other locations along the way. They would be
less interested in the smaller roads that connect the two places.

12.1 Adjacency Matrix
An adjacency matrix is a structure for representing direct connections between entities in a graph, such as locations.
In a 2D matrix, these entities are listed on both the horizontal and vertical axis.
If there is a direct connection between two entities, it means they are adjacent and
there is a 1 at that location in the matrix. If there isn’t a direct connection,
they are not adjacent and there is a 0 at that location in the matrix.

Example 1: Generate an adjacency matrix for the cities shown in Figure 1 - Denver,
Colorado Springs, Pueblo, Fort Collins, Lincoln, Omaha, Kansas City, Lawrence, and
Wichita - showing which locations are directly connected by a major highway.
Steps:
1. Generate a blank 2D matrix that lists the locations on both axes.
The vertical axis is the starting location and the horizontal axis is the destination (Figure 2).
Figure 2. Empty adjacency matrix with the starting location on the vertical axis and the destination location on the horizontal axis.
2. Add a 1 to the matrix if two locations have a road between them and add a 0 to
the matrix if they don’t. The roads generate the adjacency matrix shown in Figure 3.

12.2 Graph Representation
The information in an adjacency matrix can be represented as a graph, where a graph structure is
defined as G = (V, E); graph G has a set of V vertices connected by a set of E edges.
If the adjacency matrix has a 1 in a cell, then the graph has an edge between those two vertices.

12.3 Adjacency-list Representation
Another method for storing graph data is to use an adjacency list instead of an adjacency matrix.
In this approach, the vertices in the graph are stored in an array, and each vertex
in the array contains a pointer to a list of its adjacent vertices. For example, an array of
vertices for the road map would each contain a list of the vertices that each vertex connects to,
as shown in the adjacency list in Figure 6. This list contains the same data shown in the
adjacency matrix in Figure 3 and the graph in Figure 5. For example, the Denver vertex has
five adjacent vertices - Colorado Springs, Ft. Collins, Lawrence, Lincoln, and Wichita stored in a list.
The Colorado Springs vertex only has one adjacent vertex - Denver.

///////////////////

13 Hash tables
A hash table, also known as a hash map, is a data structure that stores data using
a parameter in the data, called a key, to map the data to an index in an array.
The data is also called a record, and the array where records are stored is called a hash table.

There are two necessary components to a hash table:
the array where the records are stored and
a hash function that generates the mapping to an array index.

For example, imagine the hash table is used to store records of movies.
Each movie record contains the Title, Ranking, and Year of the movie.
The movie could be defined with a struct as follows:
struct movie{
string Title;
int Ranking;
int Year;
}
Figure 1 shows the process of how individual movie records are stored in a hash table.
Each movie is a record that contains the properties of the movie. The key for the record,
which in this case is the title, is input to a hash function, shown in Figure 1 as h(Title).
The hash function uses the ASCII characters in the title, generates a unique integer value for that title.
That integer value is the index in the hash table array where the movie record is then stored.
For example, if the hash function returned a value of 2, then the movie would be stored at index = 2 in the hash table array.

13.3 Collisions
If every key always mapped to a unique index in a hash table, then hash tables would be used for everything.
There would be no reason to store data in any other data structure because hash tables
would be the faster than any other data structure available.
However, in any large data set, the reality is that multiple records often have the same hash value,
and therefore, need to be stored in the same index in a hash table.
When this happens, it’s called a collision, which is when two or more keys hash to the same index.

Formally, given a hash function h, a collision occurs when:
h(k1) = h(k2), k1 != k2, where k1 and k2 are keys.
