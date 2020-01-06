#include <iostream>

//I need to stop relying on: using namespace std; and instead use something like:
//using std::cin;
//using std::cout;
//using std::endl;

struct Node
{
    int key;
    Node* left;
    Node* right;

    //parameterized constructor
    Node(int k)
    {
        this->key=k;
        this->left=this->right=NULL;
    }
};

void print(Node* n)
{
    if(n==NULL)
        return;
    std::cout<<n->key<<" ";
    print(n->left);
    print(n->right);
}

int main()
{
    Node* root=new Node(12);
    root->left=new Node(6);
    root->right=new Node(15);
    root->left->left=new Node(2);
    root->left->right=new Node(8);
    print(root);
}
