//Example 1: Build a binary search tree from the following integer keys:
//< 4, 2, 6, 9, 1, 3 >.

#include <iostream>

using namespace std;

struct Node
{
    id=-1;
    Node *parent=nullptr:
    Node *left=nullptr;
    Node *right=nullptr;
};

class BST
{
private:
    Node *root=nullptr;
    Node *createNode(int, Node*, Node*, Node*); //parent, left, right
public:
    BST();
    ~BST();
    bool addNode(int);
    bool removeNode(int);
    int findSmallestNode();
    int findLargestNode();

};
BST::BST()
{

}
BST::~BST()
{
    //clear all nodes

}
Node *BST::createNode(int itemToAdd, Node *parentNode, Node *leftChild, Node *rightChild)
{
    Node *newNode=new Node;
    newNode->id=itemToAdd;
    newNode->left=leftChild;
    newNode->right=rightChild;
    newNode->parent=parentNode;
}
int BST::findLargestNode()
{
    Node *tmpNode=root;
    while(tmpNode->right!=nullptr)
    {
        tmpNode=tmpNode->right;
    }
    return tmpNode->id;
}
int BST::findSmallestNode()
{
    Node *tmpNode=root;
    while(tmpNode->left!=nullptr)
    {
        tmpNode=tmpNode->left;
    }
    return tmpNode->id;
}


int main()
{

    return 0;
}
