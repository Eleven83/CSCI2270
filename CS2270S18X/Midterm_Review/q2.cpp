void Graph::printMislabeledParents(int startVertex) {
	vertex *start;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].value == startVertex) {
			start = &vertices[i];
		}
	}

	queue<vertex*> Q;
	Q.push(start);
	start->visited = true;
	//cout << start->value << end;
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
		if(node->value == start->value)
		    cout<< node->value <<endl;
		for(int i=0;i< (int)node->adj.size();i++)
		{
		    if(!node->adj[i].v->visited)
		    {
		        Q.push(node->adj[i].v);
		        node->adj[i].v->visited = true;
		        if(node->adj[i].v->parentID != node->value)
		            cout<< node->adj[i].v->value <<endl;
		    }
		}
	}
}
