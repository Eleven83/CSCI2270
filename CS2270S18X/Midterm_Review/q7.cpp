void Graph::colorVertices(string sourceVertex){
	vertex *start;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].name == sourceVertex) {
			start = &vertices[i];
		}
	}

	queue<vertex*> Q;
	Q.push(start);
	start->visited = true;
	start->color = "Red";
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();

		for (int i = 0; i < (int)node->adj.size(); i++) {
		    if(!node->adj[i].v->visited)
		    {
		        Q.push(node->adj[i].v);
		        node->adj[i].v->visited = true;
		        if(node->color == "Red")
		            node->adj[i].v->color = "Black";
		        else
		            node->adj[i].v->color = "Red";

		    }
		}
	}
}
