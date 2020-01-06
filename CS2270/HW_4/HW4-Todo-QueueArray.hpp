#ifndef HW4_TODO_QUEUEARRAY
#define HW4_TODO_QUEUEARRAY
#include <string>

struct TodoItem
{
  std::string todo;
};

const int MAX_QUEUE_SIZE = 5;

class TodoQueueArray
{
public:
  TodoQueueArray();
  bool isEmpty();
  bool isFull();

  void enqueue(std::string todoItem);
  void dequeue();
  TodoItem peek();
  int getQueueFront() { return queueFront; }
  int getQueueEnd() { return queueEnd; }
  TodoItem* getQueue() { return queue; }
private:
  int queueFront; //the index in queue[] that will be dequeued next
  int queueEnd; //the index in queue[] that was most recently enqueued
  TodoItem queue[MAX_QUEUE_SIZE];
};
#endif
