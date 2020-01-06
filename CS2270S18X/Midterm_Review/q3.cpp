void Graph::findOddAdjacent(int startVertex) {
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
	cout << start->value << " ";
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
		for (int i = 0; i < (int)node->adj.size(); i++) {
		    if(!node->adj[i].v->visited)
		    {
		        Q.push(node->adj[i].v);
		        node->adj[i].v->visited = true;
		        if(node->adj[i].v->value%2!=0)
		            cout<< node->adj[i].v->value <<" ";
		    }
		}
	}
}
