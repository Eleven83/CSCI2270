#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* left, *right;
};

//A utility function to create a new BST node.
struct Node* newNode(int itemToAdd)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->key=itemToAdd;
    temp->left=temp->right=NULL;
    return temp;
};

class BSTclass{
private:
    /* data */
public:
    BSTclass()
    {
        cout<<"BSTclass constructor called."<<endl;
    }
    void inOrder(Node*);
    Node* insert(Node*, int);
    Node* minValueNode(Node*);
    Node* deleteNode(Node*, int);
};

//A utility function for in-order traversal of BST
void BSTclass::inOrder(Node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        cout<<root->key<<" ";
        inOrder(root->right);
    }
}

/*A utility function to insert a new Node with given key in BST */
Node* BSTclass::insert(Node *node, int key)
{
    //If the tree is empty, return a new Node.
    if(node==NULL)
        return newNode(key);
    //Otherwise, start recursing down the tree.
    if(key < node->key)
    {
        node->left = insert(node->left, key);
    }else
        node->right = insert(node->right, key);
    //Return the (unchanged) Node pointer.
    return node;
}
/*Given a non-empty BST, return the node with minimum key value found
in that tree. Note that the entire tree does not need to be searched.*/
Node* BSTclass::minValueNode(Node *node)
{
    Node *current=node;
    //Loop down to find left-most leaf node
    while(current->left!=NULL)
        current=current->left;
    return current;
}
/*Given a BST and a key, this function deletes the key and returns
the new root*/
Node* BSTclass::deleteNode(Node *root, int k)
{
    //Base case
    if(root==NULL)//empty tree
        return NULL;
    /*Recursive call for ancestors of the Node to be deleted. */
    if(k<root->key){
        root->left=deleteNode(root->left, k);
        return root;
    }else if(k>root->key){
        root->right=deleteNode(root->right, k);
        return root;
    }
    //Case 1: Node to delete is a leaf node (no children).
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        root=NULL;
        return root;
    }//Case 2: Node to delete has one child
    else if(root->left==NULL){ //Only has a right child
        Node *temp=root->right; //so point to the right
        delete root;
        return temp;
    }else if(root->right==NULL){ //Only has a left child
        Node *temp=root->left; //so point to the left
        delete root;
        return temp;
    }
    //Case 3: Node to delete has two children
    else{
        Node *succParent=root->right;
        Node *succ=root;
        while(succ->left!=NULL)
        {
            succParent=succ;
            succ=succ->left;
        }
        succParent->left=succ->right;
        //Copy successor data to root
        root->key=succ->key;
        //Delete successor and return root
        delete succ;
        return root;
    }
}

//Driver program to test above functions
int main()
{
    /*Let's create the following BST:
                  50
                /   \
             30      70
           /  \     /  \
         20   40   60  80   */

    BSTclass bst;
    Node *root=NULL;
    root=bst.insert(root, 50);
    root=bst.insert(root, 30);
    root=bst.insert(root, 20);
    root=bst.insert(root, 40);
    root=bst.insert(root, 70);
    root=bst.insert(root, 60);
    root=bst.insert(root, 80);

    cout<<"In-order traversal of the given tree: \n";
    bst.inOrder(root);

    cout<<"\nDelete 60\n";
    bst.deleteNode(root, 60);
    cout<<"In-order traversal of the modified tree: \n";
    bst.inOrder(root);

    cout<<"\nDelete 20\n";
    bst.deleteNode(root, 20);
    cout<<"In-order traversal of the modified tree: \n";
    bst.inOrder(root);

    cout<<"\nDelete 30\n";
    bst.deleteNode(root, 30);
    cout<<"In-order traversal of the modified tree: \n";
    bst.inOrder(root);

    cout<<"\nDelete 50\n";
    bst.deleteNode(root, 50);
    cout<<"In-order traversal of the modified tree: \n";
    bst.inOrder(root);

    cout<<endl;
    /*Another task:
        Implement a delete tree function.
        Pass the root to this function.
        Call this function from the destructor.*/


    return 0;
}
/*
CHALLENGE ALERT!!!
Submission Date and Time: Sunday, Oct 14th, 11:59PM
Email Subject: CSCI2270_CHALLENGE_1
The subject has to be exactly this...(above)
Send an email TO YOUR TA.

Implementation of the challenge will be like midterm FROM SCRATCH.

Submit programm as .cpp, explanation as .txt, and output as screenshot.
Also, explain the time complexity of your algorithm in the explanation
of the .txt (That means write the O(?) notation).

Challenge Problem:

Write a program to merge two BSTs in to one.
Try and make your program efficient.
*/
