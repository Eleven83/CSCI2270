#include <iostream>
using namespace std;
#define COUNT 10

/*
Each node in the tree has this structure
*/
struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/*
Class variables and methods for a BST
*/
class BST
{
  public:
    Node *root;
    BST();
    Node* insertIntoBST(Node *root, int value);
    Node* deleteNode(Node *root, int value);
    Node* maxValueNode(Node* node);
    void inOrderTraverse(Node *root);
    bool isValidBST(Node *root);
    void print2DUtil(Node *root, int space);
};

/*
Constructor for a BST object
*/
BST::BST()
{
  this->root = NULL;
}

/*
This function prints all the elements in a tree in inorder fashion
*/
void BST::inOrderTraverse(Node *root)
{
  if(root != NULL)
  {
    inOrderTraverse(root->left);
    cout<< root->data<<" ";
    inOrderTraverse(root->right);
  }
}

/*
Forms a binary tree by inserting nodes. It make sures that
the insertion retains the property of a BST.
 */
Node* BST::insertIntoBST(Node *node, int value)
{
  if(this->root == NULL)
  {
    this->root = new Node(value);
  }
  if(!node)
  {
     Node *newNode = new Node(value);
     return newNode;
  }
  else
  {
    if(value < node->data)
    {
        node->left = insertIntoBST(node->left, value);
    }
    else
    {
      node->right = insertIntoBST(node->right, value);
    }
  }
  return node;
}

/*
Returns the maximum node value from a given BST.
*/
Node* BST::maxValueNode(Node* node)
{
    Node *current = node;

    /* loop down to find the rightmost leaf */
    while (current->right != NULL)
        current = current->right;

    return current;
}

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}
