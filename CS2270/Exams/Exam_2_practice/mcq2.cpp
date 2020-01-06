#include <iostream>

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(int k)
    {
        this->key = k;
        this->right = this->left = NULL;
    }
};
void print(Node* n, int k)
{
    if (n == NULL)
        return;
    if ( n->key %2 == 0)
    {
        std::cout << n->key <<" ";
    }
    print(n->left, k);
    print(n->right, k);
}
int main()
{
    Node* root = new Node(12);
    root->left = new Node(6);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->right->right = new Node(8);
    print(root, 0);
}
