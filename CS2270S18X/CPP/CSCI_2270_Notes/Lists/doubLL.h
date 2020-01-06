#include "Node.h"

using namespace std;

class List {
private:
    Node *head, *tail;

public:
    List ();
    ~List();
    bool createNode(string, int, int, float);
    void display();
};
