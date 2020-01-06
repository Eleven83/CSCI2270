// #include "HW4-Todo-QueueArray.cpp"
// #include "HW4-Todo-StackArray.cpp"
// #include "HW4-Todo-StackLinkedList.cpp"
#include "HW4-Todo-QueueLinkedList.cpp"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // TodoQueueArray test;
    // cout<<test.getQueueFront()<<endl;
    // cout<<test.getQueueEnd()<<endl;
    // test.dequeue();
    // test.peek();
    // test.enqueue("testing the queue array");
    // cout<<test.getQueueFront()<<endl;
    // cout<<test.getQueueEnd()<<endl;
    // test.peek();
    // test.dequeue();
    // test.peek();

    TodoQueueLinkedList test;
    cout<<test.getQueueFront()<<" \n";
    cout<<test.getQueueEnd()<<" \n";
    test.enqueue("first");
    test.enqueue("in");
    test.enqueue("first");
    test.enqueue("out");
    test.peek();
    test.dequeue();
    test.peek();
    test.dequeue();
    test.peek();
    test.dequeue();
    test.peek();
    cout<<test.getQueueFront()<<" \n";
    cout<<test.getQueueEnd()<<" \n";
    //
    // TodoStackArray test;
    // test.getStackTop();
    // test.push("test1");
    // test.push("test2");
    // test.peek();
    // test.pop();
    // test.peek();

    return 0;
}
