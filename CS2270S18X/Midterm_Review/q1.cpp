
/** Question1**/
/**
given the name of the vertex and the vertices list it will find the index of the findVertexIndex
We need this indices so that we can retrive the corresponding distance from distance array
**/
int findVertexIndex(string kname, vector<vertex> vertices)
{
    for(int i=0;i<(int)vertices.size();i++)
    {
        if(vertices[i].name == kname)
            return i;
    }
    return -1;
}



void Graph::shortestPath(string source, string destination, string intermediate)
{
	vertex *start;
    int sIndex = findVertexIndex(source, vertices);

    start =   &vertices[sIndex];

    int* dist = new int[vertices.size()];

    for(int i=0;i<(int)vertices.size();i++)
        dist[i] = 99999;
	queue<vertex*> Q;
    dist[sIndex] =0;
    start->prev=NULL;
	Q.push(start);

	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
        int pIndex = findVertexIndex(node->name, vertices);
        node->visited = true;
        /*if destination is the current node then trace back to see presence of the intermediate node in the path*/
        if(node->name == destination)
        {
            vertex* temp = node;
            while(temp)
            {
                if(temp->name == intermediate )
                {
                    cout<<"Yes";
                    return;

                }
                temp = temp->prev;
            }
            cout<<"No";
            return;
        }
        /* Push adjacent in queue*/
        for(int i=0; i<(int) node->adj.size();i++)
        {
            if(!node->adj[i].v->visited)
            {
                vertex* nn = node->adj[i].v;
                int index = findVertexIndex(nn->name, vertices);
                Q.push(nn);
                /*Update the distance and the back pointer*/
                if(dist[index] > dist[pIndex]+1)
                {
                    dist[index]= dist[pIndex]+1;
                    nn->prev = node;
                }
            }
        }
	}

}
