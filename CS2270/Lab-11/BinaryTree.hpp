#include <iostream>
using namespace std;
#define COUNT 10
#include <queue>

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
Variables and functions for Tree ADT
*/
class Tree
{
public:
  Node *root;
  Tree();
  void createTree();
  void ZigZagTraverse(Node *root);
  void print2DUtil(Node *root, int space);
};

/*
Constructor for a Tree object
*/
Tree::Tree()
{
  this->root = NULL;
}

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void Tree::print2DUtil(Node *root, int space)
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

/*
Creates a tree of 7 elements
*/
void Tree::createTree()
{
  Node *root         = new Node(1);
  root->left         = new Node(2);
  root->right        = new Node(3);
  root->left->left   = new Node(4);
  root->left->right  = new Node(5);
  root->right->left  = new Node(6);
  root->right->right = new Node(7);
  this->root = root;
}
