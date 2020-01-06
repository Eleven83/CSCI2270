void Graph::findVerticesWithNoAdjacentVertices()
{
    int found=0;
    for(int i=0;i< (int)vertices.size();i++)
    {
        if((int)vertices[i].adj.size() == 0)
        {
            cout<< vertices[i].name<<" ";
            found++;
        }
    }
    if(found==0)
        cout<< "Not Found!";
}
