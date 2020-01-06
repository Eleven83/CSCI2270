//Assignment 6 CPP File
//Ryan Hoffman
//CSCI 2270
//
//
#include "MovieTree.hpp"
#include <string>
#include <iostream>

using namespace std;

MovieTree::MovieTree()
{
    root=NULL;
}
MovieTree::~MovieTree()
{
    DeleteAll(root);
}
void MovieTree::printMovieInventory()
{
    printMovieInventory(root);
}
int MovieTree::countMovieNodes()
{
    countMovieNodes(root, 0);
}
void MovieTree::deleteMovieNode(std::string title)
{
    MovieNodeBST* delTree=root;
    delTree=searchBST(delTree, title);


}
void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{

}

void MovieTree::findMovie(std::string title)
{
    MovieNodeBST* temp=root;
    temp=searchBST(temp, title);
    if(temp==NULL)
    {
        cout<<"Movie not found."<<endl;
    }else{
        MovieNodeLL* foundMovie=searchLL(temp->head, title);
        while(foundMovie!=NULL && title!=foundMovie->title)
        {
            foundMovie=foundMovie->next;
        }
        if(foundMovie!=NULL)
        {
            cout<<"Movie Info:"<<endl;
            cout<<"==========="<<endl;
            cout<<"Ranking:"<<foundMovie->ranking<<endl;
            cout<<"Title:"<<foundMovie->title<<endl;
            cout<<"Year:"<<foundMovie->year<<endl;
            cout<<"Quantity:"<<foundMovie->quantity<<endl;
        }else
            cout<<"Movie not found."<<endl;
    }
}

void MovieTree::rentMovie(std::string title)
{

}
void MovieTree::DeleteAll(MovieNodeBST* node) //use this for the post-order traversal deletion of the tree
{

}
void MovieTree::printMovieInventory(MovieNodeBST* node)
{

}
void MovieTree::countMovieNodes(MovieNodeBST* node, int* c)
{

}
MovieNodeBST* MovieTree::searchBST(MovieNodeBST* node, string title)
{
    int compare;
    string titleLetter;
    string nodeLetter;
    titleLetter=title.substr(0,1);
    nodeLetter=string(1, node->letter);
    compare=nodeLetter.compare(titleLetter);
    if(compare<0)
    {
        if(node->rightChild!=NULL)
        {
            node=node->rightChild;
            return searchBST(node, title);
         }else
            return NULL;
    }else if(compare>0)
    {
        if(node->leftChild!=NULL)
        {
             node=node->leftChild;
             return searchBST(node, title);
         }else
            return NULL;
    }else if(compare==0)
    {
        return node;
    }
}
MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title)
{
    MovieNodeLL* tempLL=head;
    while(tempLL!=NULL && tempLL->title!=title)
    {
        tempLL=tempLL->next;
    }
}

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node)
{

}
