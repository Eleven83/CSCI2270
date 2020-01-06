#include <iostream>

using namespace std;

//Definition of node for binary search tree
struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

//Function to create a new node
BSTNode* getNewNode(int data)
{
    BSTNode* newNode=new BSTNode();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
//Function to insert data in BST, returns address of root node
BSTNode* insert(BSTNode* root, int data)
{
    if(root==NULL)//empty tree
    {
        root=getNewNode(data);
    }
    //If data to be inserted is less than, insert in left subtree
    else if(data<=root->data)
    {
        root->left=insert(root->left, data);
    }
    //else, insert in the right subtree.
    else{
        root->right=insert(root->right, data);
    }
    return root;
}
void inOrder(BSTNode* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout<<root->data<<endl;
        inOrder(root->right);
    }
}

/*
delete() - to be implemented
Learn from the deleteBST program (lecture 16) and implement it.
Also, try to traverse it.
*/
void deleteBST(BSTNode* root)
{
    BSTNode* node = root;
    //To delete a BST we need to traverse all nodes and delete one by one
    //Post-order traversal is best because you delete children before parent.
    if(node==NULL)
        return;
    //First, delete both subtrees
    deleteBST(node->left);
    deleteBST(node->right);

    //Delete the node
    cout<<"Deleting node: "<<node->data<<endl;
    delete node;
}

//To search for an element in BST, returns true if element is found.
bool search(BSTNode* root, int data)
{
    if(root==NULL)
    {
        return false;
    }else if(root->data==data){
        return true;
    }else if(data<=root->data){
        return search(root->left, data);
    }else{
        return search(root->right, data);
    }
}

int main()
{
    /*Let's create the following BST:
                  15
                /   \
             10     20
           /  \    /  \
         8    12  16  25   */
    BSTNode* root=NULL;//Creating an empty tree.
    /*Code to test the logic.*/
    root=insert(root, 15);
    root=insert(root, 10);
    root=insert(root, 20);
    root=insert(root, 25);
    root=insert(root, 8);
    root=insert(root, 12);
    root=insert(root, 16);

    inOrder(root);
    
    bool reDo=false;
    while(!reDo)
    {
        //Ask user to enter a number to be searched.
        int numToSearch;
        cout<<"Please enter a number to search: "<<endl;
        cin>>numToSearch;
        //If number is found, print "Found".
        if(search(root, numToSearch)==true)
        {
            cout<<"Found "<<numToSearch<<" in the tree."<<endl;
            reDo=true;
        }else{
            cout<<"Could not locate "<<numToSearch<<" in the tree."<<endl;
            reDo=false;
        }
    }
    //Deleting the entire tree
    deleteBST(root);
    root=NULL;

    cout<<"Tree deleted."<<endl;

    return 0;
}
