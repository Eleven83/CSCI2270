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
Variables and functions for Tree ADT
*/
class Tree
{

  public:
    Node *root;
    Tree();
    void createTree();
    void preOrderTraverse(Node *root);
    void inOrderTraverse(Node *root);
    void postOrderTraverse(Node *root);
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
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
This function prints all the elements in a tree in a preorder fashion
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
void Tree::preOrderTraverse(Node *root)
{
  if(root!=NULL)
  {
      cout<<root->data<<endl;
      preOrderTraverse(root->left);
      preOrderTraverse(root->right);
  }
}

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
This function prints all the elements in a tree in inorder fashion
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
void Tree::inOrderTraverse(Node *root)
{
  if(root!=NULL)
  {
      inOrderTraverse(root->left);
      cout<<root->data<<endl;
      inOrderTraverse(root->right);
  }
}

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
This function prints all the elements in a tree in a post order fashion
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
void Tree::postOrderTraverse(Node *root)
{
  if(root!=NULL)
  {
      postOrderTraverse(root->left);
      postOrderTraverse(root->right);
      cout<<root->data<<endl;
  }
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


/*
 Main function that calls create tree, print Tree and all the traversal functions.
 */
int main()
{
  Tree t;
  t.createTree();
  //cout<<t.root->data<<endl;
  t.print2DUtil(t.root, 0);



  /**********************
    Uncomment this after implementation
  ***********************/


//   // 1, 2, 4, 5, 3, 6, 7
  cout << "\nPreorder traversal of binary tree is \n";
  t.preOrderTraverse(t.root);
  cout<<endl;

  // 4, 2, 5, 1, 6, 3, 7
  cout << "\nInorder traversal of binary tree is \n";
  t.inOrderTraverse(t.root);
  cout<<endl;

  // 4, 5, 2, 6, 7, 3, 1
  cout << "\nPostorder traversal of binary tree is \n";
  t.postOrderTraverse(t.root);
  cout<<endl;

  return 0;
}
