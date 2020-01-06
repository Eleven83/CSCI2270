void Graph::findNodeWithMaximumAdjacent(int startVertex) {
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
	vertex* maxAv;
	int max = -1;
	cout << start->value << " ";
        //Students have to fill in this part
     while (!Q.empty())
     {
		vertex *node = Q.front();
		Q.pop();
		if((int)node->adj.size()>max)
		{
		    max = (int)node->adj.size();
		    maxAv = node;
		}
		for (int i = 0; i < (int)node->adj.size(); i++) {
			if(!node->adj[i].v->visited)
			{
			    Q.push(node->adj[i].v);
			    node->adj[i].v->visited =true;
			    cout<< node->adj[i].v->value<<" ";
			}

		}
	}
	cout<<endl<< maxAv->value;
}
