void insertEnd(char key)
{
    Node* nn = new Node;
    nn->key = key;
    nn->next = NULL;

    if(head == NULL)
    {
        head =nn;
    }
    else{
        Node* temp = head;
        while(temp->next)
        {
            temp =  temp->next;
        }
        temp->next = nn;
    }
}

/**
This function is a modification of inorder traversal.
Since we need to search within a range I put those if conditioned
**/
void RangeSearch(TreeNode *node, char m, char n)
{
    if(node!=NULL)
    {
        if(node->key>m)// if value at the node is greater than lower bound then the left subtree may have something > lowerbound as well
            RangeSearch(node->left, m,  n);
        if(node->key>= m && node->key<=n) // if the value at the node is in the range put it at the linked list
            insertEnd(node->key);
        if(node->key<n)// if value at the node is less than upper bound then the right subtree may have something < upperbound as well
            RangeSearch(node->right, m,  n);
    }
}
