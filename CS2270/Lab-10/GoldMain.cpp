#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[10];
bool visited[10];


/****************************
  Complete the DFS method
*****************************/
void dfs(int node)
{

  // Mark each node as visted as and when we visit them
  visited[node] = true;

  for(int i = 0;i < adj[node].size(); i++)
  {
      // TODO
      // If a node is not visited then call DFS recursively
  }
}


int main()
{
  int nodes, edges, x, y, connectedComponents = 0;
  nodes = 6;                       //Number of nodes
  edges = 4;                       //Number of edges


  // Edges stored in an adjacency list
  // Build a graph of 6 nodes and 4 vertices
  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[2].push_back(3);
  adj[3].push_back(2);

  adj[1].push_back(3);
  adj[3].push_back(1);
  adj[4].push_back(5);
  adj[5].push_back(4);


  //Initialize all nodes as not visited
  for(int i = 0; i < nodes; i++)
  {
    visited[i] = false;
  }

  for(int i = 1; i <= nodes; i++)
  {
    if(visited[i] == false)
    {
      dfs(i);

      // Total number of times DFS is restarted
      // is the number of connected components
      connectedComponents++;
    }
  }
  cout << "Number of connected components: " << connectedComponents << endl;
  return 0;
}
