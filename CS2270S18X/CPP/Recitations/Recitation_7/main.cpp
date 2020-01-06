#include <iostream>
#include "BST.cpp"

using namespace std;

int main()
{
    BST tree(4);
    tree.insertNode(1);
    tree.insertNode(0);
    tree.insertNode(3);
    tree.insertNode(6);
    tree.insertNode(8);
    tree.insertNode(7);
    tree.insertNode(5);
    tree.insertNode(9);

    tree.printTree();
    if(tree.searchKey(5))
        cout<<"find 5"<<endl;
    else
        cout<<" not found 5"<<endl;

    if(!tree.searchKey(99))
        cout<<"not found"<<endl;

    return 0;
}
