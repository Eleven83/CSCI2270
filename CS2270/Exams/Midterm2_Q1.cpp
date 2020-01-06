#include <iostream>

using namespace std;

//Binary Tree Node
struct Node
{
    int key;
    Node *left, *right;
};

/* utility that allocates a new Node
   with the given key */
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

int findMaximum(Node *root)
{
    if(root == NULL)
        return 0;
    int max=root->key;
    int lMax=findMaximum(root->left);
    int rMax=findMaximum(root->right);
    if(lMax > max)
        max=lMax;
    if(rMax > max)
        max=rMax;
    return max;
}

// Driver Code
int main()
{
    // Binary Tree is:
    //        7
    //      /  \
    //     8    11
    //         / \
    //        2   9
    Node* newRoot=NULL;
    Node* root = newNode(7);
    root->left = newNode(8);
    root->right = newNode(11);
    root->right->left=newNode(2);
    root->right->right=newNode(9);

    int max = findMaximum(root);
    cout << "Maximum of all the nodes is: "
         << max << endl;

    return 0;
}
