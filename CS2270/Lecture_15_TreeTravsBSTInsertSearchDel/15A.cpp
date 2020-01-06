#include <iostream>

using namespace std;

//Simple functions to traverse a tree.
//Make these functions a part of your cheat sheet.

//Happy Coding!

/*A binary tree node has data, pointer to left child and
pointer to right child.*/
struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};

/*Given a binary tree, print its nodes according to the
"bottom-up" post-order traversal.*/
void printPostorder(struct Node* node)
{
    if(node==NULL)
        return;
    //First recursive call on left subtree.
    printPostorder(node->left);
    //Then recursive call on the right subtree.
    printPostorder(node->right);
    //Now deal with the node.
    cout<<node->data<<" ";
}
/*Given a binary tree, print its nodes in order.*/
void printInorder(struct Node* node)
{
    //Base case.
    if(node==NULL)
        return;
    /*First recursive call on the left subtree.*/
    printInorder(node->left);
    /*Then handle the node.*/
    cout<<node->data<<" ";
    /*Now recursive call on the right subtree.*/
    printInorder(node->right);
}
/*Given a binary tree, print its nodes in pre-order.*/
void printPreorder(struct Node* node)
{
    if(node==NULL)
        return;
    /*First print the node data.*/
    cout<<node->data<<" ";
    /*Then recursive call on the left subtree.*/
    printPreorder(node->left);
    /*Now recursive call on the right subtree.*/
    printPreorder(node->right);
}

/*Driver program to test the above programs.*/
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<endl<<"Pre-order traversal of the binary tree is "<<endl;
    printPreorder(root);
    cout<<endl<<"In-order traversal of the binary tree is "<<endl;
    printInorder(root);
    cout<<endl<<"Post-order traversal of the binary tree is "<<endl;
    printPostorder(root);
    cout<<endl;

    return 0;
}
