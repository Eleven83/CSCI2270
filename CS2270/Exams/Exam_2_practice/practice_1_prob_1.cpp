// Program to print product of all
// the nodes of a binary tree
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

// Function to find product of
// all the nodes
int calculateProduct(Node* root)
{
    if(root == NULL)
        return 1;
    return(root->key * calculateProduct(root->left) * calculateProduct(root->right));
}

// Driver Code
int main()
{
    // Binary Tree is:
    //       3
    //      /  \
    //     6    2
    //    / \  / \
    //   2   4
    Node* root = newNode(3);
    root->left = newNode(6);
    root->right = newNode(2);
    root->left->left = newNode(2);
    root->left->right = newNode(4);

    int prod = calculateProduct(root);
    cout << "Product of all the nodes is: "
         << prod << endl;

    return 0;
}

/*
// C++ program to print all even node of BST

using namespace std;
// create Tree
struct Node {
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node
   with given key in BST */
/*Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
/*    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
/*    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
/*    return node;
}

// Function to print all even nodes
void evenNode(Node* root)
{
    if (root != NULL) {
        evenNode(root->left);
        // if node is even then print it
        if (root->key % 2 == 0)
            printf("%d ", root->key);
        evenNode(root->right);
    }
}

// Driver Code
int main()
{
    /* Let us create following BST
       5
      / \
     3     7
    / \ / \
    2 4 6 8 */
/*    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);

    evenNode(root);

    return 0;
}
*/
