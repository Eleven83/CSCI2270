/*
Add a method to the BST class that deletes a given value from the BST. The method
takes one argument, the value of the node to be deleted. Replace the node to be
deleted with its right child. Move the left subtree of the deleted node to the
appropriate position in the replacement node’s right subtree, only if the
replacement has a right subtree, to maintain the BST properties.
Use the following function header:
void BST::studentFunction(int value)

Test cases
Test your code using the following cases
bst.studentFunction(78);
inOrderTraversal();
should print 11 12 16 20 21 22 30 34 35 40 45 60 65 70 73 80 90 100 120
bst.studentFunction(30);
inOrderTraversal();
should print 11 12 16 20 21 22 34 35 40 45 60 65 70 73 80 90 100 120
bst.studentFunction(60);
inOrderTraversal();
should print 11 12 16 20 21 22 34 35 40 45 65 70 73 80 90 100 120

*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Node{
    int key;
    Node *parent;
    Node *left;
    Node *right;
    Node(Node *p, Node *l, Node *r){
        parent = p;
        left = l;
        right = r;
    }
};

class BST{
public:
    void build(int a[], int size);
    void inOrderTraversal();
    void studentFunction(int); //write me
    BST();
private:
    Node *root;
    void inOrderTraversal(Node *node);
    Node *search(int k);
};

BST::BST(){
    root = NULL;
}

void BST::inOrderTraversal(Node *node){
    if(node)
    {
        inOrderTraversal(node->left);
        cout<<node->key<<" ";
        inOrderTraversal(node->right);
    }
}

void BST::inOrderTraversal(){
    inOrderTraversal(root);
}

void BST::build(int a[], int size){
    root = NULL;
    Node *parent;
    Node *tmp;
    for(int i = 0; i < size; i++){
        parent = NULL;
        tmp = root;
        while(tmp != NULL){ //checks for placement of the new node
            parent = tmp;
            if(tmp->key > a[i]){
                //go left
                tmp = tmp->left;
            }else if(tmp->key < a[i]){
                //go right
                tmp = tmp->right;
            }
        }
        if(parent == NULL){              //this section builds the tree
            root = new Node(NULL, NULL, NULL);
            root->key = a[i];
            cout<<"root: "<<root->key<<" parent: "<<parent<<endl;

        }else if(parent->key < a[i]){
            Node *n = new Node(parent, NULL, NULL);
            parent->right = n;
            n->key = a[i];
            cout<<"node: "<<n->key<<" right child of: "<<parent->key<<endl;

        }else{
            Node *n = new Node(parent, NULL, NULL);
            parent->left = n;
            n->key = a[i];
            cout<<"node: "<<n->key<<" left child of: "<<parent->key<<endl;

        }
    }

}
Node* BST::search(int k){
    if (root == NULL){
        cout<<"tree is empty"<<endl;
        return NULL;
    }
    else{
        Node *tmp = root;
        while(tmp != NULL){
            if(tmp->key > k){
                //go left
                tmp = tmp->left;
            }else if(tmp->key < k){
                //go right
                tmp = tmp->right;
            }else{
                return tmp;
            }
        }

    }
    cout<<"value not found in tree"<<endl;
    return NULL;
}

void BST::studentFunction(int value)
{
    //code here
}
