#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Friday 1-19-2018

    *Arrays
    *Structs
    *Functions
    *File I/O
    *Array of Structs

*/

/*
EX: fileIOarray.cpp
Program reads in SIDs from .txt, stores in array, then
passes array to display
*/
/*
void disArray(int arr[], int n);

int main()
{
    int sidArrayLength = 10;
    int sidArray[sidArrayLength];
    ifstream inStream;
    inStream.open("sampleNum.txt");
    for(int i=0; i<10; i++)
    {
        inStream>>sidArray[i];
    }
    disArray(sidArray, sidArrayLength);
    inStream.close();

    return 0;
}
//Prints out each element of the array
void disArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}
*/
/*
//Moving on to a new data type called a STRUCT
//struct type definition
struct Student //struct named student
{
    //members of the struct
    int sidNumber;
    string name;
    string dept;
}; //always end with semicolon

//now in main we use file i/o to get data and store that data in as a struct in each element of the array
int main()
{
    string line;
    ifstream inFile;
    Student studentStructArray[10];  //Create an instance of the Student struct which is an array of 10 structs
    inFile.open("csvListSample.txt");   //open the file
    if(!inFile.is_open()) //check
        cout<<"Error opening file"<<endl;
    //loop line by line through the file
    for(int i=0; i<10; i++)
    {
        getline(inFile, line, ','); //from the file, store in 'line' until a ',' is reached
        studentStructArray[i].sidNumber=stoi(line);//use the dot operator to access the sidNumber member of the struct
                                                   //and assign it the first value from line, which is an int
        inFile>>ws;
        getline(inFile, studentStructArray[i].name, ','); //stores the second value in the line in the name member of the struct
        inFile>>ws;
        getline(inFile, studentStructArray[i].dept, '\n'); //stores the third value of line in the dept member of the struct

        cout<<"Student ID Number: "<<studentStructArray[i].sidNumber<<endl;
        cout<<"Name: "<<studentStructArray[i].name<<endl;
        cout<<"Department: "<<studentStructArray[i].dept<<'\n'<<endl;
    }
    inFile.close(); //close the file
    return 0;
}
*/
/*
Monday, 1-22-2018

    *Continued
        *File I/O
        *Arrays
        *Structs
        *Array of Structs
    *New Material
        *Command line arguments
        *Complexity

*/
/*
//Complexity.cpp
int main()
{
    int arr[]={2,9,7,0}; //creating an array of 4 elements
    //demonstrating an n^2 algorithm
    int count=0;
    int arrLength=4;

    //scan the array once for each element
    int temp;
    for(int j=0; j<arrLength; j++)
    {
        temp=arr[j];
        for(int i=0; i<arrLength; i++)
        {
            if(arr[j]==arr[i])
                cout<<"Element "<<j<<" is equal to element "<<i<<endl;
            count++;
        }
    }
    cout<<"The total number of array operations is: "<<count<<endl; //count will be 4^2 which is 16

    return 0;
}
*/

/*
Wednesday, 1-24-2018
*Algorithm Complexity
    -Big-O notation
    -Number Systems
*Intro to Pointers
    *Pass-by-value
    *Pass-by-reference
    *Pass-by-pointer
*/
/*
Algorithms:
    Pre and Post conditions
        -Precondition = input specs (i.e sqrt(n), n>0 where n>0 is the precondition)
        -Postcondition = expected output
    Correctness
        -algorithm returns the correct result every time
    Cost
        - If Precondition, Postcondition, and Correctness are true:
        - Memory usage and runtime
    Big-O
        - Worst case algorithm performance
        - Theoretical upper bound for the algorithm
        - SEE REF. http://bigocheatsheet.com/
    Number Systems
        - Binary, Decimal, Hexadecimal
        - 8 bits in one byte
        - Hex is 0 thru 9 then A thru F
    Pointers
        - Variable of Memory address
*/

/*
//pointers.cpp

int main()
{
    int jenny = 5;
    int *jennyPtr; // Pointer is a special kind of variable that contains a memory address

    jennyPtr=&jenny; //address operator
    cout<<"jenny = "<<jenny<<endl;
    cout<<"&jenny = "<<&jenny<<endl;
    cout<<"jennyPtr = "<<jennyPtr<<endl;
    cout<<"*jennyPtr = "<<*jennyPtr<<endl; // dereferencing a pointer


    return 0;
}
*/

/*
Friday 1-26-2018
    *Pointers(cont)
        *non-native types
        *the '->' operator
    *Functions
        *Pass-by-value
        *Pass-by-reference
        *Pass-by-pointer
        *Pass-by-array
    *Dynamic Variables
*/
/*
Pass-by-value
    void passByValue(int a) //when called, it's given a copy of the value
    Ex:
        void pBV(int a)//local variable
        {
            a++;
        }
        int main()
        {
                int x=3;
                pBV(x) //copy
                cout<<x<<endl;
        }
Pass-by-reference
    Ex:
    void pBR(int &a)//reference/address of a variable
    {
        ++a;
    }
    int main()
    {
        int x=3;
        pBR(x); //
    }
Pass-by-Pointer
    Ex:
    void pBP(int *a) //address, but pointer type
    {
        *a++;
    }
    int main()
    {
        int *myptr;
        pBP(myptr);
    }
Pass-by-array
    Ex:
    void pBA(int arr[], int n) //tells compiler that the function takes an array, which is an address, pointer to 1st element
    {
        //code here
    }
*/
/*
void passByValue(int a)
{
    ++a;
}
void passByRef(int &a)
{
    ++a;
}
void passByPtr(int *a)
{
    *a=*a+1;
}
void passByArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        arr[i]=i;
}
int main()
{
    int billy=2, jimmy=2, jenny=2;
    //int *jennyPtr=&jenny;
    cout<<"Before function calls: billy: "<<billy<<endl;
    passByValue(billy);
    cout<<"After function calls: billy: "<<billy<<endl;
    //
    cout<<"Before function calls: jimmy: "<<jimmy<<endl;
    passByRef(jimmy);
    cout<<"After function calls: jimmy: "<<jimmy<<endl;
    //
    cout<<"Before function calls: jenny: "<<jenny<<endl;
    passByPtr(&jenny);
    cout<<"After function calls: jenny: "<<jenny<<endl;
    //
    int n=10;
    int arr[n];
    passByArray(arr, n);
    for(int i=0;i<n; i++)
        cout<<arr[i]<<endl;
                                    //array=ptr; //illegal
    return 0;
}
*/

/*
Monday 1-29-2018

    *Pointers to user defined types(structs)
    *Dynamic Memory
        *Array doubling
    *Working toward linked lists
        *the node
*/
/*
Pointers (cont)
    *Pointer defined by what type it points to: (data_type *ptr_name;)
    *Pointers to fundamental data types(bool, int, char, etc..) OR user defined types(i.e. structs, classes, etc..)
        Ex: defined struct:
            struct Amigo
            {
                string name;
                int age;
            };
            int main()
            {
                Amigo jose; //instance of Amigo
                Amigo *josePtr; //pointer of Amigo type
                josePtr=&jose; //assigns the reference

                //syntax for accessing members of the struct via pointer
                (*josePtr).name="Mourinho";
                (*josePtr).age=55;

                //ALTERNATE SYNTAX
                josePtr->name="Mourinho";
                josePtr->age=55;
            }
    Ex:
        struct ListNode
        {
            string userName;
            ListNode *next; //"Circular Definition", pointer to itself
        };

Dynamically Allocated Memory
    *Automatic variables get allocated on the stack.
     Whereas Dynamically allocated variables get allocated at run-time(on the fly) and use the heap.
    *Two operators used: "new" and "delete".
        Ex: int *p1;
            p1=new int; //nameless variable
            delete p1; //frees up the memory of the p1 pointer on the heap
            *p1=5; //BAD, Don't do it! (It's possible that the free memory may have already taken a new variable or value)
    Array Example:
        //dynamic array with user input length
            int n;
            int *numPtr;
            cin>>n;
            numPtr=new int[n]; //new array of length n
            delete [] numPtr;

    Ex: Create Dynamic Array of length n and fill with user inputs, then double the length of the Array
        and keep first n values unchanged:
            int n=5;
            int *a;
            a=new int[n]; //dynamic array length n
            for(int i=0; i<n; i++)
            {
                cin>>a[i];
            }
            //double the array length
            int *tmp;
            tmp=new int[2*n];
            for(int i=0; i<n; i++)
            {
                tmp[i]=a[i];
            }
            delete [] a; //deallocationg the memory that a is pointing to
            a=tmp; //assign temp to a
            tmp=nullptr; //Good practice!

*/
/*
Wednesday 1-31-2018
    *Pointers and dynamic memory to create a node
    *Use nodes to create a linked list

*/
/*
Recap:
    Pointers:
        -Allow keeping track of data in memory space.
        -Needed for dynamic memory.
        -Can point to user defined types (i.e. structs, classes)
    Dynamic Memory:
        -Let's us create variables on the fly
        -Uses Heap(instead of stack)
        -Allows for greater program flexability/usability
        -Can write a program that works on various size files
*/
/*
Nodes and Lists
    *Why?
        -Arrays use "Contiguous" space in memory, but inserting an element
            requires shifting the elements(copy each one and move it)
        -Alternatively:
            -Allocate space Dynamically //create a new node
            -Link the elements via pointers //next
            -Use a node for each element (node stores an element and a pointer that points to the next node)
            -Singly linked list (dynamic)
    *How:
        struct Node //Circular Definition
        {
            string item;
            Node *next;
        };
        -each instance of this struct will be one node of the Linked List
        Ex:
        //copy the elements from an array[4] to a linked list.(4 nodes)
        string a[]={"uno", "dos", "tres", "cuatro"};
        ListNode *head, *tmp, *current;
        head=new Node; //allocate
        head->item=a[0]; //assign data
        head->next=nullptr; //make the next pointer null
        current=head; //assign head to current node
        int i=1;
        while(i<4)
        {
            tmp=new Node;
            tmp->item=a[i];
            tmp->next=nullptr;
            current->next=tmp; //ensures last element is null
            current=tmp;
            i++;
        }
        //How would you retrieve the data of a specific node?
        //Traversing the Linked list
        current=head;
        while(current!=nullptr) //while current is not at the end of the list
        {
            cout<<current->item<<endl;
            current=current->next; //go to the next node
        }

*/
/*
Friday 2-2-2018
    *Recap
        -singly linked list
        -Traversing the list
    *Linked Lists
        -search
        -insert
        -delete
    *linkedlist2.cpp is on the shared drive

*/
/*
RECAP:
    *Constructing a LL:
        -use 3 struct pointers of the node struct
        -(head, tmp, current)
        -begin allocating space for each node, one at a time
        -set head pointing to first node
        -use current to point to the most recently created node(prvevious node)
        -use tmp to create new nodes
            -always initialize the tmp node pointing to null
        -loop thru until desired number of nodes created
    *Traversing
        -have current point to head
            ie  current=head; //Both are pointers
                while(current!=nullptr)
                {
                    cout<<"Blah";
                    current=current->next;
                }
*/
/*
    *Search
        -EX: Find a node that contains a certain string: "tres". Return its address,
            if not found, return NULL.
            while(current!=NULL)
            {
                if(current->item=target)
                {
                    return current;
                }
            }
            return NULL;
        //Take a look at link.cpp in my notes folder

    *Inserting a New Node
        -3 scenarios:
            A)At beginning
            B)In the middle(after a given node)
            C)At the end
            __________________________________
                A)Inserting at the beginning //basically replacing the head
                    1)Create a new node
                        -use tmp to point to the new node
                    2)Link the new node with the old head
                        tmp->next head
                    3)Make head point to new node
                    4)set tmp to NULL
            __________________________________
                B)In the middle(After a given node)
                    1)Create a new node
                        -use tmp to point to new node
                    2)Link new node with next node
                    3)Link prvevious with new node
            __________________________________
                C)At the end/tail
                    1)
                    2)
                    3)

*/
/*
Monday 2-5-2018
    *Finish up with struct based LL approach
        -Deleting a node
    *Classes/Objects Intro

//linkedList3.cpp in the drive

*/
/*
    *Deleting a node from existing LL
        -Ex_1: Delete specified node
            (imagine a LL with 4 elements)
            1. find the node preceding the specified node
            2. link prvevious with new next node
            3. deallocate memory for the deleted node
        -Ex_2: if specified node is the head node
            1. update head to point to head->next
            2. free specified node

    *Classes
        -Given a struct
            struct Time
            {
                int hour;
                int minutes;
                string meridian; //am vs pm
            };
            int main()
            {
                Time t;
                t.hour=13; //PROBLEM! compromised data integrity. Prone to error because a 12 hour clock
                //if only we had a way to embed data validation within the struct...
            }
        -Classes and Objects
        -Class is a complex type similar to struct.
        -Instance of a class is an object.
        -Features:
            1. has members
            2. can define member functions
                -> these are called methods
                -> they control access to member variables
            3. Members can be private or public
                -> public = accessible outside of the class
                -> private = accessible only from within the class //can't access a private member in main()
            4. Constructors
                -> public methods used to initialize objects
                -> they get the same name as the class
        EXAMPLE FROM ABOVE:
            Ex: Create a class called Time12 for storing time in a 12 hour format
                1. 3 private members: int hour, int minute, string mer
                2. constructor - takes 3 arguments
                3. public method to display the time
            //see classIntro.cpp

*/
/*
Wednesday 2-7-2018
    *Recap Class/Object Intro
    *Create a singly linked list class
        -Define a constructor
        -Define grow-list method
        -Display list method
        -Define destructor

*/
/*
RECAP Class/Object:
        -Object is instance of a class
        -Similar to struct but have public as well as private members
        -Have member functions called methods that control access to the data
        -Constructors(public method) used to initialize objects of a given class
        -Constructors are given the same name as the class
        EX: class ClassName
            {
                ClassName();//constructor
            };

*/
/*
    *Create a Linked List class
        -Use a node struct
            -struct Node
             {
                string item;
                Node *next;
             };
        -Introduce an approach to constructing a LL that lends itself
            well to a class-based
        1) 2 private members:
            head and tail Pointers
        2) Public:
            A) A constructor that initializes both pointers to null
            B) A "grow" method for allocating nodes Dynamically(and also fill the node payload)
                -If the LL is empty:
                    1) Allocate node and point head to it.
                    2) Point tail to the same node
                    3) Write contents to the node member
                    4) Write null to head->next (or tail->next)
                -Else (LL not empty)
                    1) Use tmp pointer and allocate new node
                    2) Write contents to the node member
                    3) tmp->next point to null
                    4) Write tail->next points to tmp
                    5) Have tail pointer point to last node
            C) A destructor - gets called automatically when object goes out of scope
                - Deallocate dynamic memory
            D) Maybe have a display funtion that traverses and cout

*/
/*
Friday 2-9-2018
    *Finish Singly LL Class
        -Show multiple file compilation
        -add destructor
    *Doubly Linked List

*/
/*
    Single file approach
    EX:
        struct
        {
            //
        }
        class
        {
            //
        }
        int main()
        {
            //
        }
    But with MULTI-FILE approach:
        EX: For a singly linked class
            -.h file
            #ifndef SLL_H
            #define SLL_H
            //put declarations in the header file
            struct
            {

            }
            class SSL
            {
            private:
                Node *head, *tail;
            public:
                List;
                ~List;
                void growList(string, newItem)
            }

            #endif

        //Then in your .cpp file:
            #include <iostream>
            #include <whatever>
            #include "SSL.h"

            using namespace std;
            //Definitions go here
            SLL::SLL()
            {
                //constructor definition
            }
            SSL::~SSL()
            {
                //destructor definition
            }
            //Followed by any other method definitions
            void SSL::growList(string newItem)
            {
                //code
            }
        //Finally have a test cpp file
            SLL_test.cpp
            #include <iostream>
            #include "SLL.h"

            int main()
            {
                SLL l;
                l.displayList();
                return 0;
            }
        //END EXAMPLE

    *Destructor
        -Method for "clean-up". Gets called automatically when function goes out of scope.
        -Default generated if none explicitly defined
        - Need to define explicitly when working with dynamically allocated memory
        //EX: Destructor for SLL class:
            SSL::~SSL()
            {
                current=head;
                while(current!=NULL)
                {
                    temp=current->next;
                    delete current;
                    current=temp;
                }
            }

*/
/*
    *Doubly Linked List
        -Similar to singly LL except in each node 2 pointers instead of 1
        -To keep track of the whole list, keep head and tail
        -The advantage is the ability to traverse in both directions
        -Also, the delete operation is more efficient (faster).
            ...Given a target node there's no need to traverse the list
            EX: Given address of node to be deleted:

*/

/*
Monday 2-12-2018
    *MIDTERM 1: Friday, 2-23-2018, @5pm?
    *This week:
        -Stacks and Queues
    *Today:
        -Stacks
            -Linked list implementation
            -Array implementation

*/
/*
    *Stack - data struct that allows a specific order in which operations
            on its data can be performed.
            -Push & Pop
                -Push adds to the top
                -Pop removes from the top
            -Can have limit on max number of elements
            -Usage:
                Ex: Call stack during program execution
                    -currently active subroutines
                Ex: Stack overflow
                    -too many functions on call stack (seg fault)
    Stack Abstract Data Type
        EX:
            private:
                top //keeps track of 'top'
                maxSize //depends on implementation
                count //depends on implementation
            public:
                initialize() //constructor
                isFull()
                isEmpty()
                push()
                pop()
                display()

    Singly Linked list Stack Implementation
        - a special case of SLL
        - don't have to set maxSize (but can)
        - 'top' is a pointer to 'Node' type
        - stack is empty if 'top' is NULL
        - 'push' adds new nodes to LL
        - 'pop' removes node from 'top' and returns the node (could be defined differently)



*/

/*
Wednesday 2-14-2018
    *Stack
        -Finish SLL implementation
        -Recap ADP
        -Array implementation
    *Queues
        -high level
        -ADP
        -Skip LL
        -Array
            -two approaches

*/
/*
Recap ADP(Abstract Data Type):
EX:
    private:
        top //keeps track of 'top'
        maxSize //keep track
    public:
        initialize() //constructor
        isFull()
        isEmpty()
        push()
        pop()
        display()

    Array implementation:
        array of strings up to maxSize-1
    private:
        int top, count;
        string a[maxSize];
    public:
        constructor()
        {
            top=0;
            count=0;
        }
        bool isFull()
        {
            check if top==maxSize
        }
        bool isEmpty()
        {
            if top==0, then stack is empty.
        }
        void push(string newItem)
        {
            if !isfull,
                a[top]=newItem;
            top++;
        }else{
            cout<<"Stack overflow"<<endl;
        }
        string pop()
        {
            string out="";
            if (!isEmpty())
            {
                out=a[top];
                top--;
            }else
                cout<<"Stack is empty"<<endll;
            return out;
*/
/*
Queues
    -similar to stack
    -allows for specific order of operations
    -enqueue: add new element
        -always at the tail
    -dequeue: remove an element
        -always from head
    FIFO.
    EXAMPLE:
        -Read and write commands get queued up in very fast but small DRAM


*/
/*
Friday 2-16-2018
    *Destructor for SLL Stack
    *Recap: Stacks vs Queues
    *Queue: the array approach
        -linear vs circular


*/
/*
Stacks vs Queues:
    -Both are complex data structures that allow for specific order
    in which operations on their data can be performed
    Stack:
        -can only add/remove to/from top(push/pop)
        -LIFO
    Queue:
        -can only add at tail(enqueue)
        -can only remove from head(dequeue)
        -FIFO
    -Either one can be implemented using an array or linked list
        -Array: linear or circular

*/
/*
Queue
    -Linear array implementation:
        -simplest
        -head stays fixed
        -tail tracks end of Queue
        -dequeue is inefficient (worst case, when queue is full O(n))

    -Circular Array Queue:
        -allows head and tail to move when dequeue and enqueue
        -EX:
            maxQsize=4;
            //when start, head=0 and tail=0;

            q.enqueue(A) //head=0 and tail=1
            q.enqueue(B) //head=0 and tail=2
            q.enqueue(C) //head=0 and tail=3
            q.dequeue()  //head=1 and tail=3
            q.enqueue(D) //head=1 and tail=0
            q.enqueue(E) //head=1 and tail=1
        if head and tail are equal, how do you tell if the queue is full or empty?
        A: keep count of the queue size. Check if maxQsize==current queue size.

    -Queue ADP Implementation:
        private:
            head
            tail
            queSize
            data //count
        public:
            init //constructor
            isEmpty()
            isFull()
            enqueue(newItem)
            item dequeue
            disp()
        IMPLEMENTATION Circular Array:
            #define MAX_SIZE 5
            class QueueArrCir
            {
            private:
                int head, tail, queSize;
                string a[MAX_SIZE]; //data
            public:
                QueueArrCir //constructor
                {
                    head=0;
                    tail=0;
                    queSize=0;
                }
            bool isEmpty()
            {
                if queSize==0;
                return true;
                else return false;
            }
            bool isFull()
            {
                if queSize==MAX_SIZE
                 return true
                 else
                 return false
            }
            void enqueue(string item)
            {
                //when enqueueing we only deal with the tail
                if(!isFull())
                {
                    a[tail]=item;
                    if(tail==MAX_SIZE-1)
                        tail=0;
                    else
                        tail++;
                }else
                    cout<<"Queue is full"<<endl;
            }

            }


*/
/*
Monday 2-19-2018
    *SUBSTITUTE Professor
    *Trees

*/
/*
*Trees:
*Binary Tree:
    -One root, many branches
    -See chapter 8
    -Pointers in a Binary Tree:
        • parent
        • left child
        • right child
    -The next and previous pointers of a doubly linked list are replaced with
        parent and left and right child pointers in binary trees
    -Parent node and Root node
        -Each node in the tree is a parent node for at most two children, a left and a right child.
        -The topmost node in the tree is called the root. The parent of the root is NULL.
    -A binary search tree (BST) is a special case of a binary tree where the data in the tree is ordered.
        -nodes in the left sub-tree of that node all have a value less than the node value,
        -nodes in the right sub-tree of that node all have a value greater than or equal to the node value
    -See BST.cpp

*/
/*
Wednesday 2-21-2018
    *Recap Binary Trees
    *Recursion
    *BST

*/
/*
Binary Tree:
    -Like with LL, pointers point to nodes of same type
    -Each node has two "next" pointers, one "previous" pointer and a "key" value
    -Each node has 0, 1, or 2 children
    -except for "root" node, every node has a parent node
    -This is called a hierarchical data structure as opposed to linear (Linked list)
        ---------------
        |   parent    |
        ---------------
        |    key      |
        ---------------
        |*left | *right|
        |child | child |
        ---------------
    -Subtrees:
        -The whole tree is defined by its subtrees.
        -EX:
            Root of the tree is A, A has 2 children, B & C. C is the root of the subtree
            and has two children, D & E. Then E is the root of the smaller subtree.
        -Self-similarity: the thing is similar to a part of itself.
        -Why this is important:
            -We can examine smaller and smaller subtrees starting at the root
            until the whole tree is traversed.

*/
/*
Recursion:
    Recursive Structure:
        -A struct defined in terms of itself.
        EX: A tree defined by smaller and smaller trees
    Recursive Algorithm:
        -Algorithm that calls itself. Each call the input gets smaller until a "base case"
        is reached.
    EX: Recursively traverse tree and print all key values.

                    ----
                   | A |
                   ----
                |         |
              ----       ----
             | B |      | E |
             ----       ----
           |      |
         ----     ----
        | C |    | D |
        ----     ----

        void rt(node *n)
        {
            print key
            if(n->leftChild!=NULL)
                rt(n->leftChild)
            if(n->rightChild!=NULL)
                rt(n->rightChild)
        };
        Display: A B C D E

*/
/*
Binary Search Tree (BST) contd.
    -For any node in the tree, nodes in the left branch have smaller values than
    the node value.
    -Nodes in the right have values greater than or equal to the
    node value.
    EX: {4,3,1,2,7,5,8}
                4
               / \
              3   7
             /   / \
            1   5   8
             \
              2

    -BST ADT(class sample):
        private:
            root
            searchRecursive
        public:
            init() //constructor
            insert(value) //build the tree
            search(value)
            display() //e.g. recursive traverse
            delete(value)
            deleteTree()


        struct node
        {
            int key;
            node* parent;
            node* leftChild;
            node* rightChild;
        };

*/
/*
Monday 2-26-2018
    *Inserting a node in BST
    *First search, then modify the tree to add the node
    *9.2.1 in eBook

*/
/*
Wednesday 2-28-2018
    *3 traversal options
    *BST delete-node function

*/
/*
    Traversing a tree:
        - 3 conventions:
            -Pre-order: root, left, right
            -In-order: left, root, right
            -Post-order: left, right, root
        -Algorithms:
            displayPreOrder(n)
            {
                cout<<n->key<<endl;
                if(n->leftChild!=NULL)
                    displayPreOrder(n->leftChild);
                if(n->rightChild!=NULL)
                    displayPreOrder(n->rightChild);
            }
            displayInOrder(n)
            {
                if(n->leftChild!=NULL)
                    displayInOrder(n->leftChild);
                cout<<n->key<<endl;
                if(n->rightChild!=NULL)
                    displayInOrder(n->rightChild);
            }
            displayPostOrder(n)
            {
                if(n->leftChild!=NULL)
                    displayInOrder(n->leftChild);
                if(n->rightChild!=NULL)
                    displayInOrder(n->rightChild);
                cout<<n->key<<endl;
            }

*/
/*
delete() method - algorithm for removing a node with a specified value from the tree

There are three cases to consider when deleting a node. Exactly one of the following conditions is true about the deleted node:
1. The node has no children.
2. The node has one child.
3. The node has two children.

    Steps:
        1. Find node
            //Returns pointer to the node with a key that matches the search
            //value or NULL if the key does not exist in the tree.
            searchRecursive(node, searchKey)
            {
                if (node!=NULL)
                    if(node->key == searchKey)
                        return node
                    else if(node.key > searchKey)
                        return searchRecursive(node->left, searchKey)
                    else
                        return searchRecursive(node->right, searchKey)
                else
                  return NULL
            }

        2. Check for children
        case 1: Node has no children (Not the root) & (both pointers are null)
            if(node->leftChild==NULL && node->rightChild==NULL)
            {
                if(node==node->parent->leftChild)
                    node->parent->leftChild=NULL; //deleted the node
                else
                    node->parent->rightChild=NULL; //deleted the node
            }
        case 2: Node has 1 child
                else if()
                {
                    //
                }
        case 3: Node has 2 children
            else if(node->leftChild!=NULL && node->rightChild!=NULL)
            {
                //leftChild (relationship to parent)
                //find the min node in right branch(below deleted node) and use it to replace the deleted node
                *min=getMin(node);
                if(min==node->rightChild)
            }

*/
/*
Friday 3-2-2018
    *Function Overloading
    *Assignment: a few words about it
    *Delete() Node

*/
/*
Function Overloading:
    -A function can have multiple definitions based on the arguments being passed
    -The compiler will automatically invoke the appropriate definition based on
        the arguments being called with the function.
*** Ex: void foo(int x)
        {
            cout<<"called with one argument"<<endl;
        }
        void foo(int x, int y)
        {
            cout<<"called with two arguments"<<endl;
        }
        int main()
        {
            foo(1);
            foo(1,2);
        }
////////See date.cpp, date.h, and dateTest.cpp in notes folder
Overloading constructors is typical and the compiler can detect the # of arguments
as well as type of arguments

*/
/*
Assignment 6 Notes:
    -Create a BST and do stuff with it
    -Based on a text file of movies
    -Insert, find, rent, print inventory, delete, count movies in the tree, quit
    -USE Post-order traversal for the delete
*/
/*
Delete Node:
    Is it root{
        A)not Root
            children?
            1)No children
                relationship to parent
                a)Node is leftChild
                b)Node is rightChild
            2)Two children
                relationship to Parent
                a)Node is leftChild
                    -find min node in right branch
                    -use it to replace node being deleted
                    -update parent pointer
                b)Node is rightChild
                    -find min node in right branch
                    -
            3)One child
                relationship to parent
                a)Node is leftChild
                    i)is leftChild
                   ii)is rightChild
    }           b)Node is rightChild
                    i)is leftChild
                   ii)is rightChild
        B) is Root
            1)No children
            2)Has two children
            3)Has one child
*/
/*
Monday 3-5-2018
    *Tree Complexity
        -balanced vs unbalanced
    *Tree Balancing
    *Red-Black Trees

*/
/*
Complexity:
    -Balanced vs unbalanced (Section 9.3)
        -Number of tree nodes:
            N=1+2(or 2^1)+3(or 2^2)+7(2^3).....+ 2^h where h is height of the tree.
            N=2^(h+1)-1
            h~O((log2)N) is much better than O(n) worst case.
        -This is only true when tree is balanced.
        -The most unbalanced tree you can have: see section 9.3
    When the tree is balanced, as in Figure 18, the distance from the root
    to any leaf node at the bottom of the tree, is log2(n), where n is the number of nodes in the tree.

    Tree Balancing:
        Various algorithms, e.g. AVL, red-black, work by having nodes with additional
        information (properties)...

*/

/*
Red-Black Trees:(Section 11)
    Special case of BST
        Each node in a red-black tree has at least the following properties:
            • color //only property not found in regular BST...
            • key
            • left child
            • right child
            • parent
    NOTE:The 5 Properties:
        Property 1: A node is either red or black.
        Property 2: The root node is black.
        Property 3: Every leaf (NULL) node is black.
        Property 4: If a node is red, then both of its children must be black.
        Property 5: For each node in the tree, all paths from that node to
                    the leaf nodes contain the same number of black nodes.
    NOTE:
    In a red-black tree, the leaf nodes are external sentinel nodes with all
    of the same properties as a regular node, but they are effectively empty nodes.
    The leaf nodes are black to satisfy Property 3 of a red-black tree.

    Operations:
        In order for the tree to self balance, certain operations are needed.
        The particular balancing algorithm needed depends on the operation and the violation.
        Recolor- change node color. red to black or black to red.
        Rotate- Rotations are local operations on nodes that reorder the nodes
                in the tree in a way that preserves the BST properties and
                set the tree up for recoloring to restore the red-black properties.
            2 Types of Rotate(inverses of eachother):
                Left- see section 11.1
                Right-see section 11.1

        Inserting a Node in to a R-B Tree:
            Nodes are added to red-black trees in the same way they are added to a regular BST.
            However, there are three changes to the BST insert operation needed.
            1. Replace all instances of NULL in the BST insert() algorithm with
                the sentinel node nullNode. This change sets the parent of the root
                to nullNode and the left and right children of a new node to nullNode.
            2. Set the color of the new node to red.
            3. Resolve any violation of the red-black properties using tree balancing.

        Examples: Building a R-B Tree:
            insert(10) to an empty tree:
                Rule:New node is red.
                Violation: parent node of tree must be black
                Fix: recolor node to black
                10 is inserted as red, then to fix, we make it black and add 2 null
                leaf nodes.
            Add 5 to tree:
                Rule: New node is red.
                Violation: None
                Fix:

*/
/*
Wednesday 3-7-2018
    *Review last lecture
    *Leaf Nodes (different approach than a BST)
    *Return to insert example
        -conceptual
        -algorithm
*/
/*
Tree Balancing Review:
    -Red Black tree algorithm
    -Recap: all same properties as BST plus built-in self-balancing mechanism
    -Nodes have additional binary color choice (Red or Black)
    -Need to have rotation mechanism
*/
/*
Leaf Nodes:
    -regular BST                    -Red-Black Tree
        *parent                        *parent
          key(stores data)                key(unused)
        *LC|*RC                          color=black
                                        *LC|*RC

    Leaf nodes don't store data.
    Key is unused
*/
/*
Insertion (contd):
    In a red-black tree:
    1. Replace all instances of NULL in the BST insert() algorithm (Algorithm 9.3)
        with the sentinel node nullNode. This change sets the parent of the root
        to nullNode and the left and right children of a new node to nullNode.
    2. Set the color of the new node to red.
    3. Resolve any violation of the red-black properties using tree balancing.

Example:
        Building a RB Tree:
        insert(10) in empty tree.
        Rule: new node is red
        Violation: Root node is black.
        Fix: Re-color
        Now, add 5 to the tree.
        insert(5)
        No violations.
        Add 4 to the tree.
        insert(4)
        Violation: 5 is still red and it needs to be black but a rotation is Needed
        Fix: Rotate right so now 5 is root, 4 is leftChild of 5 and 10 is rightChild of 5
             then re-color 5 to black.

    Insert algorithm
    ________________
        1st insert a node just like in a BST
        next, identify the "uncle" node.
    6 Possible Scenarios:
        A)Parent of new node is leftChild
            1. uncle is Red
            2. uncle is black and new node is rightChild
            3. uncle node is black and new node is leftChild
        B)Parent of new node is rightChild
            1.----|
            2.----| symmetrical equivalents of above
            3.----|

        A)Case 1: uncle is RED
            violation: red node must have black children nodes
            Fix:
                1. re-color x.parent and x.parent.parent.rightChild (uncle) to black
                2. x.parent.parent to red
                3. set x=x.parent.parent (move 2 levels up)
                4. repeat until x is root OR x.parent is black. Ensure root is black

*/
/*
Friday 3-9-2018
    *Delete node from RB Tree

*/
/*
Recap delete() from BST:
    -No children
        -delete the node
    -1 children
        -replace with remaining child
    -2 children
        -replace with min node from right branch
---------------------------------------------------------/
Now, for a RB Tree:
    EXAMPLE: delete(10)
            after replacing the 10 with its min in the right branch, 12,
            we then need to fix the properties that we violated.
            In this case, P5.


*/
/*
Monday 3-12-2018
    *Pick up with RB node Insertion
        -rbInsert()
        -rbBalance() //subroutine of insert

*/
/*
rbInsert:
    EX: rbInsert(root, x)
        -modified version of BST insert()
        -traverse the tree checking < or >= at each node until the correct spot
        is found for new node (preserving BST)
        -need to color the new node(red)
        -instead of null pointers we have the "null node"
        -BST
        -call rbBalance(root, newMode)
    rbBalance(root, newNode)
    while(newNode.color==red)
    {
        if(parent of newNode is leftChild)
        {
            //check the uncle
            uncle=newNode->parent->parent->rightChild;
            //then figure out which of the 3 cases applies
            case 1)if uncle is red
                   else if uncle is black
            case 2)if newNode is rightChild
                case 3)newNode is leftChild
        }else //parent of newNode is rightChild
            //same as above with "right" and "left" switched
    }
    root.color=black;

EXAMPLE: given a tree:
             11
            / \
           2   14
         /  \    \
        1    7    15
       /\   / \   / \
      N  N  5  8  N  N
           /\  /\
          N N N N

    insert(4)
    4 gets inserted leftChild of 5
    violating Property 4.
    Now we would call rbBalance()
    What color is uncle? Red.
    So that leads us to case 1.
    1)re-color parent and uncle to black
        and parent->parent to red
    2) set x=parent->parent
                 11
                / \
               2   14
             /  \    \
            1    7    15
                / \
               5  8
              /
             4
    Moving our way up the tree checking uncle
    we end up with case 2 after that:
        1)set x=x->Parent
        2)Rotate left around x(now pointing to the 2)
                         11
                        / \
                       7   14
                     /  \    \
                    2    8    15
                   /\
                  1  5
                    /
                   4
        finished case 2. Now, since case 2 ALWAYS leads to case 3:
        //check uncle node = black
        x is rightChild
        we have case 3:
            1)set x->parent to black (7)
              set x->parent->parent to red (11)
            2) right rotate on x->parent->parent (11)
                         7
                        / \
                       2   11
                     / \   / \
                    1  5  8  14
                      /       \
                     4        15

        then after a while loop we're done
*/
/*
Wednesday 3-14-2018
*CONTINUE FROM MONDAY
*/
//NOTE: Insert based on uncle, delete based on siblings.
/*
NOTE: Re-balancing is only needed if deleted node is black.
Red Black Delete algorithm:
    -4 cases
        case 1: x's sibling w is red.
        case 2: x's sibling w is black AND both of w's children are black.
        case 3: w is black. w's leftChild is red and rightChild is black.
        case 4: w is black. w's rightChild is red and leftChild is black.
    EXAMPLE: delete(root, value)
                z=search(value);
                y=z;
                yOGcolor=y.color;
                if(z.left=nullNode)
                    x=z.right;
                    rbTransplant(root, z, z.right)NOTE
                else if(z.right=nullNode)
                //replace z with z.right
                    .
                    .
                    .
                else
                //find min of right branch
                if(yOGcolor==black)
                    rbDeleteBalance(T, x)//T is rbTransplant
                }
                rbTransplant(root, u, v)
                    if u.parent==nullptr
                        root=v;
                    else if u=u.parent.left
                        u.parent.left=v;
                    else
                        u.parent.right=v;
                    v.parent=u.parent;//nullNode.parent=z.parent
                }
                //now we have property violated
                //since the color of the original node was black, we call rbDeleteBalance(T, x)
                rbDeleteBalance(T, x)
                    while(x!=root && x.color==black)
                    {
                        if x==x.parent.left
                            w=x.parent.right //find x's sibling and call it 'w'
                            if w.color==red
                                case 1
                            if w.left.color==black && w.right.color==black
                                case 2
                            else if w.right.color==black
                                case 3
                                w.left.color=black
                                w.color=red
                                rightRotate(w)
                                w=x.parent.right;
                                //leads to case 4
                                w.color=x.parent.color
                                x.parent.color=black
                                w.right.color=black
                                leftRotate(x.parent)
                                x=root;
                            else
                                x=x.parent.right
                                //replace "right" with "left"
                                while x.color=black
                                //the new tree is made


*/
/*
Monday 3-19-2018
    *Graphs
        ADT - undirected, weighted
        insertVertex()
        insertEdge()
        print()
        search()

*/
/*
    ADT //suggested minimum functionality
    private:
        vertices
    public:
        init()
        insertVertex(value)
        insertEdge(startVal, endVal, weight)
        deleteVertex(value)
        deleteEdge(startVal, endVal)
        printGraph()
        search(value)
    struct Vertex
    {
        string key;
        vector<adjVertex> adjacent;
    };
    struct adjVertex  //NOTE:The adjVertex struct only stores the destination vertex in v because the origin vertex is stored in the vertices vector.
    {
        Vertex *v;
        int weight;
    };

    insertVertex(value)
    {
        bool found=false;
        for(loop over the entire vector of vertices)
        {
            if(matching value found at vertex)
                found=true
                break
                can't have repeat values
            if(!found)
                vertex.key=value
                vertices.add(vertex)
        }

    }
    insertEdge(v1, v2, weight) //adds an edge in one direction only
    {
        for(int x = 0; x < vertices.size(); x++) //he vertices vector is checked for a key value that matches v1
        {
            if(vertices[x].key == v1)
            {
                for(int y = 0; y < vertices.size(); y++) //if it is found the vertices vector is checked again for v2.
                {
                    if(vertices[y].key == v2 && x != y) //the destination vertex vertices[y] is added to the adjacency list for the source vertex v1.
                        adjVertex av;
                        av.v = &vertices[y]; //The adjVertex struct stores a pointer to the vertex, which is why the address of vertices[y] is used
                        av.weight = weight;
                        vertices[x].adjacent.push_back(av); //If the key isn't found in vertices, it is added to vertices using the vector push_back() method.
                }
            }
        }

    }
    printGraph()
    {
        for(x=0 to end)
        {
            print(vertices[x].key)
            for(y=0 to vertices[x].adjacent.end)
            {
                print(vertices[x].adjacent[y].vertex.key)
            }
        }
    }
    NOTE: See coding example folder Graphs.

*/
/*
Wednesday 3-21-2018
    *Graphs continued
        -Traversal
            -Graph as a tree
            -Breadth first
        -Breadth first search
            -shortest distance

*/
/*
    You can traverse in the print() method but it only prints vertices based on the order that the vector
    was populated.
    ???What if we want to know more info about a particular vertex. How the vertex relates to the rest of the graph? How many degrees
    of separation between 2 vertices? Shortest path?
    EX: Given a graph:
                        f
                      /
                     b
                    / \
                   a   c
                    \ / \
                    d - e
        How does 'a' relate to all other vertices?(separation wise)
        Re-draw as a tree with 'a' as the root.
                1a
               / \
             2b  3d
             / \   \
           4c  5f  6e
 Update vertex struct to keep track of visited nodes.
    struct vertex
    {
        string key;
        vector<adjVertex> adj;
        bool visited;
    }
    breadthFirstTraverse(value)
    {
        vertex=search(value);
        visited=true;
        queue.enqueue(vertex);
        while(!queue.is_empty())
        {
            n=queue.dequeue();
            for(x=0 to n.adjacent.end)
            {
                if(!n.adjacent[x].visited)
                {
                    n.adjacent[x].visited=true;
                    print(n.adjacent[x].v.key);
                    queue.enqueue(n.adjacent[x].v);
                }
            }
        }
    }

*/
/*Notes
Monday 04-02-2018
	Welcome Back!
	Last time...
		*Breadth First Seach
		*Graph Traversal
	Today:
		-Breadth First Search
		-Depth First
			-Traverse
			-Search

*/
/*
RECAP:
	What is Breadth First?
        *Evaluating the vertices at the same level of a graph before evaluating
            nodes at deeper levels is a breadth-first evaluation.

        *The root in this tree is the starting vertex in a graph.
*/
/*
Goal of breadthFirstTraverse is to traverse and maybe print the entire graph
    in a BF order
Goal of breadthFirstSearch is to find a vertex via shortest path

*Differences in Algorithms:
    -BFT takes value as only parameter
    -BFS takes start and search as 2 parameters
    -add "distance" to the vertex struct
    -some way to increment and keep track of distance as each layer is traversed
    -return vertex if/when found
        -distance from starting vertex will be encoded in the returned vertex
    update the vertex struct:
        struct Vertex
        {
            string key;
            vector <adjVertex> adj;
            bool visited;
            int distance; //to store number of edges
        };
    NOTE:
    BFS Algorithm: //Calculates the distance between the startValue and searchValue vertices, and returns the searchValue vertex.
    EXAMPLE: What is the shortest distance between vertices A and G in the graph in Figure 17 using Algorithm 12.6?
    vertex breadthFirstSearch(startValue, searchValue){
        vertex=search(startValue); //Identify the starting vertex using search().
        vertex.visited=true;c//Mark the vertex visited.
        vertex.distance=0; //Initialize the distance to the starting vertex to 0.
        queue.enqueue(vertex); //Enqueue the starting vertex A
        while(!queue.isEmpty()) //
        {
            n=queue.dequeue(); //Dequeue the starting vertex A. //SECOND PASS:Dequeue vertex B. The only vertex adjacent to B that hasn’t been visited is G, which is also the value being searched for.
            //Examine the vertices adjacent to A, which are B and F. If visited is false for any vertex, mark it visited and add it to the queue.
            for(int i=0; i<n.adjacent.end; i++)
            {
                if(!n.adjacent[i].v.visited) //Check if vertex B has been visited.
                {
                    n.adjacent[x].v.distance=n.distance+1; //Store the distance to vertex B as the (distance to A)+1.
                                                            //The distance to A is 0, so the distance to B is 1.
                                                            //SECOND PASS:Calculate the distance to G, which is (distance to B) + 1, which makes the distance 2.
                    if(n.adjacent[x].v.key==searchValue) //Check if vertex B is the search value, which it is not.
                                                         //SECOND PASS:Check if G is the value being searched for, and since it is, the vertex is returned on Line 11.
                        return n.adjacent[x].v
                    else
                        n.adjacent[x].v.visited=true //Mark vertex B as visited and add it to the queue.
                        queue.enqueue(n.adjacent[x].v)
                }
                //Repeat lines 1763-1770 for vertex F.
            }
        }
        return NULL;
    }
*/
/*
    Depth First:
        -resursive
        -nonrecursive
    DepthFirstTraversal(vertex)
    {
        vertex.visited=true;
        for(int i=o; i<vertex.adjacent.end; i++) //scan the adjacency list
        {
            if(!vertex.adjacent[i].v.visited)
            {
                print(vertex.adjacent[i].v.key);
                DepthFirstTraversal(vertex.adjacent[i].v)
            }
        }
    }

*/

/*
Wednesday 04-04-2018
More DFS and BFS

*/
/*
    NOTE: BFS finds shortest path in unweighted graph.
          Whereas In a weighted graph, the path with the shortest distance
          between two vertices is the path with the lowest cumulative edge weight

 Dijkstra’s algorithm:
    NOTE: The shortest distance in weighted graph, where the edge weights are
            strictly positive, can be found using Dijkstra's algorithm
            chooses the lowest cumulative weight to any adjacent vertex that
            hasn’t yet been solved. The shortest path overall is found from these
            individual lowest weight decisions.

            Example:
                struct vertex{
                    string key;
                    vector<adjVertex> adjacent;
                    bool solved;
                    int distance;
                    vertex* parent;
                };
                vertex Dijkstra(startValue, endValue)
                {
                    startV=search(start);
                    endV=search(end);
                    startV.solved=true;
                    solved={startV}; //list of solved vertices

                    while(!endV.solved)
                    {
                        minDist=INT_MAX //should be a built-in system value that is max allowed
                        solvedV=NULL:
                        for(each v in solved list)
                        {
                            s=solved[x];
                            for(each a in v.adjacent) // a = adjacent vertex
                            {
                                if(!s.adjacent[a].v.solved) //
                                {
                                    dist=s.distance + s.adjacent[a].weight;
                                    if(dist<minDist)
                                    {
                                        solvedV=s.adjacent[a].v;
                                        minDist=dist;
                                        parent = s;
                                    }
                                }
                            }
                        }
                        solvedV.distance=minDist;
                        solvedV.parent=parent;
                        solvedV.solved=true;
                        solved.add(solvedV);
                    }
                    return endV;
                }

        NOTE: "Distance" member is now sum of edge weights NOT number of edges.
        NOTE: "solved" is like "visited", except not true unless it is the minDist vertex



*/
/*
Friday 4-6-2018
    *Hash Tables/hash map
    -data structure that stores data using a parameter in the data, called a key,
    to map the data to an index in an array. The data is also called a record,
    and the array where records are stored is called a hash table.
    -two necessary components to a hash table: the array where the records are
        stored and a hash function that generates the mapping to an array index.

*/

/*
Monday 4-9-2018
    NOTE: Friday lecture is optional due to exam and Wednesday is a Review.
    *Hash Tables contd
    *Hash functions
*/
/*
    -Hash Tables:
        -multiplication method
        -collision resolution
            -open addressing
            -chaining
        -ADT
        -Complexity

*/
/*
    Example: Say, we want to store some student ID numbers for 100 students that
                conveniently happen to be sequential...
            105608900
                  901
                  902
                  903...etc...
        x = SID % 100 Thus 0 <= x <= 99
        student 0 to student 99. Perfect hash function/table: All records assigned
        to the table w/o collision or wasted space.
        NOTE: Difficult to predict what the data will look like in the real world
                so most hash functions will be imperfect
        So, instead of trying to design a perfect hash function we will use collision
        resolution algorithms.
        EX: If using hashSum() function, figure out the potential range:
            -key is 5 chars
            -ASCII chars are all caps A-Z

                        QEVIS
                        XSOLM
                        Smallest value would be AAAAA=65*5=325
                        Largest value would be ZZZZZ=90*5=450
                        Range = 125
                        Say, we used a hash table size 500, where m=500
                        Thus, percent used = (125/500) = 25%
            -Takeaway: Increasing table size does NOT decrease collisions.
            -Instead, we look for a different hash function (e.g. universal hashing),
             or have a collision resolution mechanism built-in. That's what we will
             look at.
        -Multiplication Method:
            1.Calculate the sum of the ASCII values in the key (k).
            2.Multiply k by a constant (A), where A is between 0 and 1. Call kA.
            3.Keep the fractional of kA.
            4.Scale kA fractional by table size (m).
            5.Take the floor (round down) of the result.
                EXAMPLE:
                    AAAAA given A(m)=13/32, m=1024
                    1. k=325
                    2. kA=325(13/32) = 132.0312
                    3. fractional = 0.0312
                    4. floor(fractional*m)=32  //output of h of K, index used for hashing

                Code: Q: How would you get the fractional portion of a value?
                      A: fractional(v)
                            integer=floor(v)
                            return(v-integer)
                Advantages of multiplication over division method (hashSum()):
                    -modulo is more expensive than multiplication
                    -choosing m is less critical



*/
/*
Wednesday 4-18-2018
    - Make up exam Info
        - Only if you participated in the piazza poll.
        - Tomorrow(Thursday) 5pm.
        - No coderunner will be used.
        - Format will be:
            - on laptop
            - given a file to compile
            - the given problem will require code to be written & submitted with the file.
        - This replaces the first grade.
    - Project
        - Due MAY 6th
        - Write-up on moodle
        - Write an essay with results
        - Priority Queues
            - Implementation
            - Run a given data set through it
            - 3 different ways to approach the same task (Real World Example)
            - E.R. setting. Pregnant women flooding the hospital and need to prioritize treatment (TRIAGE)
    - No more assignments
    - HW make-up:
        - get interview for one homework for FULL POINTS !!!
        - has to pass all test cases!

*/
/*
Priority Queue:
    -It's a queue where:
        - new elements get added in the order they are received
        - when a single element gets requested, the highest priority element gets returned
        - priority is defined by me. It's indicated by some "comparable".
        EX: Highest number indicates highest priority.
NOTE:
    RECAP: Stack vs Queue vs P.Q.
    Stack = FILO
    Queue = FIFO
    Priority Queue = Highest Priority is output first (Think of a bag of scrabble letters)

    - Can define our priority queue many ways:
        - highest number = highest priority
        - lowest number = highest priority
        - ETC..
    - Real World Applications:
        - job scheduling in operating system
        - E.R. TRIAGE order
        - Load balancing on a server (moodle - lol)
        - Dijkstra's: i.e. shortest route gets highest priority

    - Implementations:
        - Arrays, Linked Lists, and Heaps.
            - Most use cases for queues, we eventually remove everything we added.
            When we choose an implementation, we need to consider the cost of add and delete.
        EXAMPLE: Array (unsorted)  / 2 / 7 / 0 /  /
                    add: just append to the end. -> O(1) Complexity
                    deQ: need to traverse array to find specific element. -> O(n) Complexity
            Now say:
                Array (sorted)   / 0 / 2 / 7 /  /
                enQ: have to do a search -> O(n)
                deQ: just grab first element. -> O(1)
            Both of these cost O(n).
            -Same is true for Linked List:
                - Best is O(n).
        - A data structure called binary heap that is most often used for P.Q. implementations.
        - Heap:
            - stored in a complete binary tree:
                - difference in height between two branches is no more than one.
            - NOT a binary search tree!!!
            - relationship defined between parent and children nodes.
        - Min-heap:
            - root always has the minimum value. O(1).
        - If structure is needed to remove an element with highest priority,
            heap is a good choice.

    - Building a heap:
        - We can store a complete binary tree in an array by storing the root in the
            first index pos(0), and the remaining elements in a heirarchical order.
            A special kind of array...
        EXAMPLE:
        Have some values in a binary tree:     R
                                              /  \
                                            W     T
                                           / \   /
                                          Q   E  Y
        Element at index x has leftChild
            child at index 2x + 1
        rightChild at index 2x + 2
        what about parent of x?
        floor((x-1)/2)
        R x=0
        W x(Lc) = 2x + 1=1
          x(Rc) =

*/
/*
Friday 4-20-2018
    - Priority Queues recap
    - heap
        - storing a complete binary tree in an array
        - ADT (min-heap)
        - push()
        - pop()
        - heapify()
*/
/*
Recap:
    - Like a regular queue, in that user does not get to specify which element to
        extract (pop()). However, pop() in PQ returns element with highest priority.
    - Implementation:
        - what's the complexity? sorted array?, unsorted array?, LL? O(n).
        - binary heap O(log n) complexity is better performance.
    - Heap:
        - min-heap and max-heap
        - min-heap where root is min node,
            and parent-child relationship where parent less than child
            has to be a complete binary tree. i.e. height between 2 branches<=1
        - Storing a tree in an array:
            array ---->  / A / B / C / D / E / F /
            For any element at index x:
            LC index = 2x+1
            RC index = 2x+2
            Parent index = floor((x-1)/2)
        - min-heap ADT:
            public:
                minHeap();
                push(value);
                int pop();
                int peek();
                void printHeap();
            private:
                int* heap //pointer to array of heap elements
                int capacity //max heap size
                int currentSize // keep track of # of elements
                void minHeapify(index) //recursive method to fix heap after each pop()
                int parent(index) {return((i-1)/2)}
                int leftC(index) {return(2*i + 1)}
                int rightC(index) {return(2*i + 2)}
                void swap(int *x, int *y)
            constructor
                minHeap(int cap)
                    currentSize = 0;
                    capacity = cap;
                    heap - new int[capacity];
                push(value)
                {
                1.  if currentSize==capacity
                2       print "Q full"
                3   else
                4       currentSize++;
                5       i = currentSize - 1;
                6       heap[i] = value; //enqueue new key at the back
                7   while((i != 0) && (heap[parent[i]] > heap[i]))
                    {
                8       swap(&heap[i], &heap[parent[i]]);
                9       i = parent[i];
                    }
                }
                example: push(6); push(3);
                        1 false
                        3,4 currentSize = 1
                        5 i = 0
                        6 heap[0] = 6
                        7 i = 0, so false, no while loop
                            done with push(6)
                        //push(3)
                        1 false
                        3,4 currentSize = 2
                        5 i = 1
                        6 heap[i] = 3
                        7 heap[parent[i]] > heap[i] is true (heap[parent[i]] = 6 and heap[i] = 3)
                        8 swap(heap[i], heap[parent[i]])
                        9 i = 0
                        7 false
                            done push(3)

                example:
                pop()
                {
                    if(currentSize <= 0)
                        return error;
                    else
                        return heap[0];
                    int poppedValue = heap[0]; //always the first element
                    heap[0] = heap[currentSize - 1]; //overwrite it with the last element in the array
                    currentSize--;
                    minHeapify(0);
                    return poppedValue;
                }
*/
/*
P.Q. My Notes:
Use for:
First-In First-Out operations where priority overrides arrival time
Ex: CPU scheduling (smallest job first, system/user priority)
Ex: Medical emergencies (gunshot wound vs. broken arm)
Notes:
Often implemented as a std::vector
--------------------------------------------------------------------------------
    Example Code
    std::priority_queue<int> p;

    //---------------------------------
    // General Operations
    //---------------------------------

    // Insert
    p.push(value);

    // Access
    int top = p.top();  // 'Top' element

    // Size
    unsigned int size = p.size();

    // Remove
    p.pop();
--------------------------------------------------------------------------------
Heap priority_queue
Notes:
A heap is essentially an instance of a priority queue
A min heap is structured with the root node as the smallest and each child subsequently smaller than its parent
A max heap is structured with the root node as the largest and each child subsequently larger than its parent
A min heap could be used for Smallest Job First CPU Scheduling
A max heap could be used for Priority CPU Scheduling
Max Heap Example (using a binary tree):
                100
               /   \
             19     36
            /  \   /  \
          17    3 25   1
         /  \
        2    7

*/
/*
Monday 4-23-2018
    -Continue with heap implementation
        - recap:
        - push() (i.e. enqueue, add, insert, etc..)
        - pop() (i.e dequeue, delete, remove, etc..)
            - heapify(): recursive function to fix heap after pop()

*/
/*
Example:
    void MinHeap::push(int k)
    {
        if(currentSize==capacity)
        {
            cout<<"At capacity, cannot insert key.";
        }else{
            currentSize++; //update size
            int i=currentSize-1;
            heap[i]=k; //append to end of heap array (leaf node)
            //Fix the min heap property if it's violated
            while(i!=0 && heap[parent(i)] > heap[i])
            {
                swap(&head[i], &heap[parent(i)]);
                i=parent(i);
            }
        }
    }
    NOTE: Because heap is a partially ordered tree, simple insertion will preserve properties
    Complexity of of push() here:
        - worst case (as above) added node will have to percolate up to root of tree
        - if tree has height of h, the operation will require h comparisons. h = log(n). Big-O: O(log n).
pop():
    - getting the highest priority item (in PQ application) is trivial, you just take the root.
    - resorting the heap property requires some complexity though...
    - General Algorithm:
        1. Check the currentSize of the heap
            - if empty then there's nothing to return
            - if size == 1, return that one element
        2. Store the root value, (i.e. heap[0]) in local variable (will be returned later).

        3. Swap the root with the last value in the tree.

        4. Recursively move the largest element in to position.
Example:
    int MinHeap::pop()
    {
        if(currentSize <= 0)
            return -1;
        if(currentSize==1)
        {
            currentSize--;
            return heap[0];
        }
        int poppedVal = heap[0];
        heap[0]=heap[currentSize-1];
        currentSize--;
        MinHeapify(0);

        return poppedVal;
    }
    void MinHeap::MinHeapify(int i)
    {
        int leftChild=left(i);
        int rightChild=right(i);
        int smallest=i;
        if(leftChild < currentSize && heap[leftChild] < heap[i])
            smallest=leftChild;
        if(rightChild < currentSize && heap[rightChild] < heap[smallest])
            smallest=rightChild;
        if(smallest != i)
        {
            swap(&heap[i], &heap[smallest]);
            MinHeapify(smallest);
        }
    }

    So... What's the complexity of pop()?
        - Note that the data structure traversal is based on the rightChild(), leftChild(), and parent() methods.
        Which means that not every element in the heap has to be visited.
        - O(log n).

    Binary heap is a good structure for storing a PQ. What else is it good for?
        -

*/
/*
Wednesday 4-25-2018
    - Heap --> Heapsort
        - Big O
    - Simple sort algorithm
        - bubble sort
        - Big O
    - Performance timing

*/
/*
- Heap and Heapsort:
    "Sifting"
    - Given an array of comperable elements, add all elements to a heap.
        1. A={8,4,10,3} --> min-heap
        2. pop() x array.length
            gives a sorted array A={3,4,8,10}
    Complexity of Heapsort?
        - Building a heap is O(n)
        - heapify worse case is O(log n)
        - Therefore, total time is O(n log n)

- BubbleSort:
    - Given some unsorted array, A={8,4,10,3}
        1st pass: Start with first pair of elements, if first > second, swap them .
- Performance Timing:
    .........

*/
/*
Friday 4-27-2018
    - Final Exam May 6th 1:30pm
        - Will replace lowest exam score
        - Similar format as other exams. No coderunner.
    - Next Week:
        - Monday - finish up performance, STL PQ
        - Wednesday - possibly no class (Check email regularly)
    - Final Project due May 6th by 5pm
    - Today:
        - Finish up performance timing:
            -BubbleSort vs Heapsort
        - Priority Queue from STL library
            - 3 parameters
            - Overloading the operator()

*/
/*
- Comparing sorting algorithms for performance:


*/
/*
Monday 4-30-2018
    * Final Exam Optional
        - May 6th 1:30 pm - HLMS 201
        - Must get 65% average on exams
        - Final exam score replaces lowest exam score
        - Similar format (No coderunner)
    * Today (Last Lecture)
        - Finish up performance, STL and PQ
        - NO CLASS Wednesday
    *Final Project Due May 6th by 5pm
        - Mandatory interview grading
        - Schedule with TA
    * Today:
        - BubbleSort vs Heapsort
        - Priority queue from STL

*/
/*
STL Priority Queue:
    priority_queue<int> pq;
    - At least one parameter is required, the other two :
        - container: vector is default.
        - compare: "less-than" is default.
    Ex: priority_queue<int, vector<int>, compare> pq2;
        compare will return true if a is considered priority over b
        compare(a, b). By default, a<b is applied.
        ex: push(3)            3
            push(5)           /
                             5
            a<b = true.

        struct compare
        {
            bool operator() (const int &a, const int &b)
            {
                return a>b;
            }
        }

*/
