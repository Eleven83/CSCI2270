#include"BinaryTree.hpp"
#include <stack>

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  Implement this function
This function prints all the elements in a tree in a zigzag order
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/

void Tree::ZigZagTraverse(Node *root)
{
    //If null then return
    if(!root)
    {
        return;
    }
    //Declare a queue to hold the vertices at the current level
    //and a stack (LIFO) to hold vertices at next level
    queue<Node*> queue;
    stack<int> stack;
    //Push the root in to the queue
    queue.push(root);
    //Push a marker to indicate end of level
    queue.push(NULL);

    //Tells us if we need to print elements left to right or right to left
    bool lefttoright=true;
    //Check if stack is empty
    while(!queue.empty())
    {
        // Done with traversing all the levels, then break the loop
        if(queue.size()==1 && queue.front()==NULL)
        {
            break;
        }
        //pop out of queue
        Node *temp = queue.front();
        queue.pop();

        if(temp==NULL)
        {
            // Marker for next level
            queue.push(NULL);
            //Print the elements from the stack
            //Prints a level in right to left order
            if(!lefttoright)
            {
                // Print the contents of the stack and empty it
                //TODO
                while(!stack.empty())
                {
                    cout<<stack.top()<<endl;
                    stack.pop();
                }
            }
            //Invert the order for next level
            //TODO
            if(lefttoright==true)
            {
                lefttoright=false;
            }else if(lefttoright==false)
            {
                lefttoright=true;
            }
        }else{
            // Print the elements normally
            if(lefttoright)
            {
                cout<<temp->data<<endl;
            }else{
                // Push the elements into stack
                stack.push(temp->data);
            }
            // Add the node's children to the queue
            //TODO
            if(temp->left)
                queue.push(temp->left);
            if(temp->right)
                queue.push(temp->right);
        }
    }
}

/*
Main function that calls create tree, print Tree and the traversal function.
*/
int main()
{
    Tree t;
    t.createTree();
    //cout<<t.root->data<<endl;
    t.print2DUtil(t.root, 0);

    cout << "Zig Zag traversal of binary tree is \n";
    t.ZigZagTraverse(t.root);
    cout<<endl;

    return 0;
}
