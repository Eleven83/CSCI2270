#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <queue>
#include "Graph.cpp" //bad practice, but it's compiling easier for the exam
#include "BST.cpp"

using namespace std;
int main() {
	//build the graph
    Graph g;
    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addVertex("d");
    g.addVertex("e");
    g.addVertex("g");

    g.addEdge("a", "b");
    g.addEdge("a", "d");
    g.addEdge("c", "d");
    g.addEdge("b", "c");
    g.addEdge("d", "e");
    g.addEdge("c", "e");
	g.addEdge("e", "g");

    g.displayEdges();

    //test cases for your code will be given on test day
    //cout<<g.studentFunction("a", "c")<<endl;

    //build the BST
    int a[] = {60, 30, 20, 90, 45, 78, 11, 34, 40, 100, 120, 12, 35, 16, 21, 22, 65, 70, 73, 80};
    BST bst;
    bst.build(a, 20);
    bst.inOrderTraversal();

    //test cases for your code will be given on test day

}
