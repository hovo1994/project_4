#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue : public AbstractPriorityQueue<T>

{
public:
    HeapPriorityQueue();
    ~HeapPriorityQueue();

    // return true if the priority queue is empty
    bool isEmpty();

    // insert item into the queue
    // may throw on allocation failure
    void add(const T& item);

    // remove highest priority item from the queue
    // throws std::logic_error if queue is empty
    void remove();

    // get the item with the highest priority from the queue
    // throws std::logic_error if queue is empty
    T peek();

    // void display();
    // void display(std::string callingPoint);

    
private:
    int getRightChildIndex(const int n);
    int getLeftChildIndex(const int n);
    int getParentIndex(const int n);
    bool isLeaf(const int n);
    int getLargestChildIndex(const int n);
    void heapRebuild(const int i);
    DynamicArrayList<T> _list;

    int _heapSize = 0;


 

  // // Heap Interface Methods
  // bool isEmpty() const;
  // int getNumberOfNodes();
  // int getHeight();
  // T peekTop() const; // throw exception on empty
  // bool add(const T& newData);
  // bool remove();
  // void clear();


};
#include "heap_priority_queue.txx"
#endif
