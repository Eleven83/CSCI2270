#include "HW5-MovieTree.hpp"
#include <iostream>

using namespace std;

MovieTree::MovieTree()
{
    root=NULL;
}
MovieTree::~MovieTree()
{
    delete root;
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
//Delete the tree and all nodes
// void deleteAll(MovieNode *node)
// {
//     if(node!=NULL)
//     {
//         deleteAll(node->leftChild);
//         deleteAll(node->rightChild);
//         delete node;
//         node=NULL;
//     }
// }
