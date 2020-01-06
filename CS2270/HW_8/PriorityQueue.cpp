#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include "PriorityQueue.hpp"

using namespace std;

//Create the class object
PriorityQueue::PriorityQueue(int queueSize)
{
    currentQueueSize=0;
    maxQueueSize=queueSize;
    priorityQueue=new PatientNode[maxQueueSize+1];
}

//Free all resources created by the object
PriorityQueue::~PriorityQueue()
{
    delete [] priorityQueue;
}

//Private method to maintain heap properties. Swap w/ parent if necessary.
void PriorityQueue::repairUpward(int nodeIndex)
{
    if(nodeIndex!=1)
    {
        int parent=nodeIndex/2;
        if(priorityQueue[parent].injurySeverity < priorityQueue[nodeIndex].injurySeverity ||
            (priorityQueue[parent].injurySeverity==priorityQueue[nodeIndex].injurySeverity &&
                priorityQueue[parent].treatmentTime > priorityQueue[nodeIndex].treatmentTime))
        {
            PatientNode temp=priorityQueue[parent];
            priorityQueue[parent]=priorityQueue[nodeIndex];
            priorityQueue[nodeIndex]=temp;
            repairUpward(parent);
        }
    }
    return;
}

//Private method to maintain heap properties. Swap w/ child if necessary.
// void PriorityQueue::repairDownward(int nodeIndex)
// {
//     if(nodeIndex < currentQueueSize)
//     {
//         int leftChild=nodeIndex*2;
//         int rightChild=nodeIndex*2+1;
//         int biggerChild;
//         if(leftChild < currentQueueSize)
//         {
//             if(rightChild < currentQueueSize)
//             {
//                 if(priorityQueue[leftChild].injurySeverity > priorityQueue[rightChild].injurySeverity ||
//                     (priorityQueue[leftChild].injurySeverity == priorityQueue[rightChild].injurySeverity &&
//                         priorityQueue[leftChild].treatmentTime < priorityQueue[rightChild].treatmentTime))
//                 {
//                     biggerChild=leftChild;
//                 }else
//                     biggerChild=rightChild;
//             }else
//                 biggerChild=leftChild;
//             if(priorityQueue[biggerChild].injurySeverity > priorityQueue[nodeIndex].injurySeverity ||
//                 (priorityQueue[biggerChild].injurySeverity == priorityQueue[nodeIndex].injurySeverity &&
//                     priorityQueue[biggerChild].treatmentTime < priorityQueue[nodeIndex].treatmentTime))
//             {
//                 PatientNode temp=priorityQueue[nodeIndex];
//                 priorityQueue[nodeIndex]=priorityQueue[biggerChild];
//                 priorityQueue[biggerChild]=temp;
//                 repairDownward(biggerChild);
//             }
//         }
//     }
//     return;
// }

//Function to re-order the tree after a node has been removed at index nodeIndex
void PriorityQueue::repairDownward(int nodeIndex)
{
    
    return;
}
//Add a patient node to the priority queue
void PriorityQueue::enqueue (std::string _name, int _injurySeverity, int _treatmentTime)
{
    if(isFull())
    {
        //If queue is full, output queue full message
        cout<<"Priority Queue full. Send Patient to another hospital."<<endl;
        return;
    }else{
        currentQueueSize++;
        priorityQueue[currentQueueSize].name=_name;
        priorityQueue[currentQueueSize].injurySeverity=_injurySeverity;
        priorityQueue[currentQueueSize].treatmentTime=_treatmentTime;

        //Call repairUpward to maintain properties
        repairUpward(currentQueueSize);
    }
}

//Remove a patient node from the priority queue
void PriorityQueue::dequeue()
{
    // if(isEmpty())
    // {
    //     //If queue is empty, print the following:
    //     cout<<"Queue empty."<<endl;
    // }else{
    priorityQueue[1]=priorityQueue[currentQueueSize];
    repairDownward(1);
    currentQueueSize--;

}

//Find out who is next in the queue
string PriorityQueue::peekName()
{
    return priorityQueue[1].name;
}

int PriorityQueue::peekInjurySeverity()
{
    return priorityQueue[1].injurySeverity;
}

int PriorityQueue::peekTreatmentTime()
{
    return priorityQueue[1].treatmentTime;
}

bool PriorityQueue::isFull()
{
    if(currentQueueSize>=maxQueueSize)
        return true;
    else
        return false;
}

bool PriorityQueue::isEmpty()
{
    if(currentQueueSize==0)
        return true;
    else
        return false;
}
