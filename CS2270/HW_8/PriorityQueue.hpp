#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include <string>

// a struct to store patient information
struct PatientNode
{
    std::string name;
    int injurySeverity;
    int treatmentTime;
};

class PriorityQueue
{
public:
    /*
    class constructor
    Purpose: perform all operations necessary to instantiate a class
    object
    Parameter queueSize: Maximum size of the priority queue
    return: none
    */
    PriorityQueue(int queueSize);
    /*
    class destructor
    Purpose: free all resources that the object has acquired
    Parameters: none
    return: none
    */
    ~PriorityQueue();
    /*
    Method Name: enqueue
    Purpose: enqueue new patient into priority queue; call other
    method(s) as required to maintain heap
    Parameter: _name - name of patient to be entered in priority queue
    Parameter: _injurySeverity - severity of injury
    Parameter: _treatmentTime - time required for doctor to treat patient
    injury
    returns void
    */

    void enqueue (std::string _name, int _injurySeverity, int _treatmentTime);
    /*
    Method Name: dequeue
    Purpose: remove the patient at the front of the priority queue from
    the queue, call other method(s) as required to maintain heap
    Parameters: none
    return: void
    */
    void dequeue();
    /*
    Method Name: peekName
    Purpose: get name of patient at front of priority queue while
    maintaining encapsulation
    Parameters: none
    return: name of patient at the front of the priority queue
    */
    std::string peekName();
    /*
    Method Name: peekInjurySeverity
    Purpose: get injury severity of patient at front of priority queue
    while maintaining encapsulation
    Parameters: none
    return: injury severity of patient at the front of the priority queue
    */
    int peekInjurySeverity();
    /*
    Method Name: peekTreatmentTime
    Purpose: get treatment time of patient at front of priority queue
    while maintaining encapsulation
    Parameters: none
    return: treatment time of patient at the front of the priority queue
    */
    int peekTreatmentTime();
    /*
    Method Name: isFull
    Purpose: indicate if priority queue is full
    Parameters: none
    return: true if queue is full, false otherwise
    */
    bool isFull();
    /*
    Method Name: isEmpty
    Purpose: indicate if priority queue is empty
    Parameters: none
    return: true if queue is empty, false otherwise
    */
    bool isEmpty();

private:
    /*
    Method Name: repairUpward
    Purpose: maintain heap properties by swapping node with parent if necessary
    Parameter nodeIndex - index of node that may violate heap properties
    return: void
    */
    void repairUpward(int nodeIndex);
    /*
    Method Name: repairDownward
    Purpose: maintain heap properties by swapping node with child if necessary
    Parameter: nodeIndex - index of node that may violate heap properties
    return: void
    */
    void repairDownward(int nodeIndex);
    PatientNode* priorityQueue; //pointer to the array used to implement priority queue
    int currentQueueSize; //number of patients currently in priority queue
    int maxQueueSize; //maximum capacity of priority queue
};
#endif
