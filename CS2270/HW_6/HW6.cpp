#include "MovieTree.hpp"
#include <iostream>

using namespace std;
//Delete the tree and all nodes
void deleteAll(MovieNode *node)
{
    if(node!=NULL)
    {
        deleteAll(node->leftChild);
        deleteAll(node->rightChild);
        delete node;
        node=NULL;
    }
}
MovieTree::MovieTree()
{
    root=NULL;
}
MovieTree::~MovieTree()
{
    deleteAll(root);
    root=NULL;
}
//Function to traverse in-order
void inOrderTraverse(MovieNode* root)
{
    if(root!=NULL)
    {
        inOrderTraverse(root->leftChild);
        cout<<"Movie: "<<root->title<<" "<<root->quantity<<endl;
        inOrderTraverse(root->rightChild);
    }
}
//Function to traverse and print the list of movies
void MovieTree::printMovieInventory()
{
    //inOrderTraverse
    if(root!=NULL)
    {
        inOrderTraverse(root);
    }
}
//Forms a BST by inserting nodes. Maintains BST properties.
void MovieTree::addMovieNode(int r, string t, int y, int q)
{
    MovieNode *temp=new MovieNode(r, t, y, q);
    if(root==NULL)
    {
        root=temp;
        return;
    }else{
        MovieNode* temp2=root;
        MovieNode* temp3;
        while(temp2!=NULL)
        {
            temp3=temp2;
            if(temp->title<=temp2->title)
                temp2=temp2->leftChild;
            else
                temp2=temp2->rightChild;
        }
        temp->parent=temp3;
        if(temp3->title<=temp->title)
            temp3->rightChild=temp;
        else
            temp3->leftChild=temp;
    }
}
//Function to find a movie from the list
void MovieTree::findMovie(string title)
{
    MovieNode* temp=root;
    temp=search(title);
    if(temp!=NULL)
    {
        cout<<"Movie Info:"<<endl;
        cout<<"==========="<<endl;
        cout<<"Ranking:"<<temp->ranking<<endl;
        cout<<"Title:"<<temp->title<<endl;
        cout<<"Year:"<<temp->year<<endl;
        cout<<"Quantity:"<<temp->quantity<<endl;
    }else
        cout<<"Movie not found."<<endl;
}
//Function to rent a movie
void MovieTree::rentMovie(string title)
{
    MovieNode *rental=root;
    rental=search(title);
    if(rental==NULL)
    {
        cout<<"Movie not found."<<endl;
    }else if(rental->quantity==0){
        cout<<"Movie out of stock."<<endl;
    }else{
        rental->quantity--;
        cout<<"Movie has been rented."<<endl;
        cout<<"Movie Info:"<<endl;
        cout<<"==========="<<endl;
        cout<<"Ranking:"<<rental->ranking<<endl;
        cout<<"Title:"<<rental->title<<endl;
        cout<<"Year:"<<rental->year<<endl;
        cout<<"Quantity:"<<rental->quantity<<endl;
    }
}
//Search function need to find the specific node
MovieNode* MovieTree::search(string title)
{
    bool found=false;
    MovieNode* temp=root;
    while(temp && !found)
    {
        if(title==temp->title)
        {
            found=true;
        }else if(title<temp->title){
            temp=temp->leftChild;
        }else{
            temp=temp->rightChild;
        }
    }
    return temp;
}
int countHelper(MovieNode *node)
{
    MovieNode *temp=node;
    int count=1;
    if(temp->leftChild!=NULL)
    {
        count+=countHelper(temp->leftChild);
    }
    if(temp->rightChild!=NULL)
    {
        count+=countHelper(temp->rightChild);
    }
    return count;
}

void MovieTree::countMovies()
{
    int Count=0;
    if(root!=NULL)
    {
        Count+=countHelper(root);
    }
    cout<<"Count = "<<Count<<endl;
}
MovieNode* deleteNode(MovieNode *root, string title)
{
    if(root==NULL)
    {
        return NULL;
    }
    // If value to be deleted is less than the root
    // Then we need to search in the left subtree
    else if(title < root->title){
        root->leftChild = deleteNode(root->leftChild, title);
    }
    // If value to be deleted is greater than the root
    // Then we need to search in the right subtree
    else if(title > root->title){
        root->rightChild = deleteNode(root->rightChild, title);
    }
    //We found the node with the value to be deleted.
    else{
        //Case 1
        // Leaf node
        if(root->leftChild == NULL && root->rightChild == NULL)
        {
            delete root;
            root = NULL;
        }
        /*************************
        Case 2 - Node with one child
        Has a right child
        Complete this function
        *************************/
        else if(root->leftChild == NULL){
            MovieNode* temp=root->rightChild;
            delete root;
            temp=root;
        }
        /*************************
        Case 2 - Node with one child
        Has a left child
        Complete this function
        *************************/
        else if(root->rightChild == NULL){
            MovieNode* temp=root->leftChild;
            delete root;
            temp=root;
        }
        /*************************
        Case 3 - Node with two children
        Complete this function
        *************************/
        else{
            MovieNode* current=root;
            while(current->leftChild!=NULL)
            {
                current=current->leftChild;
            }
            MovieNode* temp=current;
            current->title=temp->title;
            current->rightChild=deleteNode(root->rightChild, temp->title);
            root=temp;
        }
    }
    return root;
}
void MovieTree::deleteMovie(string title)
{
    MovieNode* current=root;
    current=search(title);
    if(current!=NULL)
    {
        root=deleteNode(root, title);
    }else{
        cout<<"Movie not found."<<endl;
    }
}
