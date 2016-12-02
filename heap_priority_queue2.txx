// #include "heap_priority_queue.h"
#include <cstdlib>
template <typename T>
HeapPriorityQueue<T>::HeapPriorityQueue()
{
    // _list.insert(0,T());
}

template <typename T>
HeapPriorityQueue<T>::~HeapPriorityQueue()
{
    // _list->clear();
}
template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    return _heapSize == 0;
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    if (isEmpty())
    {
        //std::cout<< "inserting" << std::endl;
        _list.insert(0, item);
        _heapSize++;

        return;
    }
    int i = _heapSize;
    _list.insert(i, item);
    _heapSize++;
    int pi = getParentIndex(i);

    while(i >= 0)
    {
        if (_list[i]>_list[pi])
        {
            T tempCurr = _list[i];
            T tempParent = _list[pi];

            _list.setEntry(i, tempParent);
            _list.setEntry(pi, tempCurr);
            i = pi;
            pi = getParentIndex(i);
            
        }
        else
        {
            break;
        }
        
    }

    
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    if (_heapSize == 1)
    {
        _heapSize--;
        _list.remove(0);
        return;
    }
    //make sure have a node to remove
    if(_heapSize > 1)
    {
        //swap last entry with root
        _list.setEntry(0,_list[_heapSize-1]);
        _list.remove(_heapSize-1);
        //now ensure that root at new node is where it should be
        _heapSize--;    
        heapRebuild(0);
        heapRebuild(0);
        heapRebuild(0);
        // heapRebuild(2);
        //update item count
    }
    else
    {
        throw std::logic_error("Attempted to remove from Empty Queue");
    }
    
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    if(isEmpty())
        throw std::logic_error("Attempted to peek at Empty Queue");

    return _list.getEntry(0);
}

template <typename T>
void HeapPriorityQueue<T>::heapRebuild(const int i)
{
    //have to check until node is a leaf: a node is not a leaf if it has at least a left child
    if(getLeftChildIndex(i) < _heapSize)
    {
        //find index of largest child of node we're trying to move
        int indChild = getLeftChildIndex(i); //assume left child is largest
        //see if right child exists and whether it is larger than left child
        if(getRightChildIndex(i) < _heapSize && _list[getRightChildIndex(i)] > _list[getLeftChildIndex(i)])
        {
            indChild = getRightChildIndex(i);
        }
        //swap with node with child, if necessary; if we do swap then we need to check new child
        if(_list[i] < _list[indChild])
        {
            //child is larger so swap parent and child
            T tempCurr = _list[i];
            T largerChild = _list[getLeftChildIndex(i)];
            
            _list.setEntry(i, largerChild);
            _list.setEntry(getLeftChildIndex(i), tempCurr);
            //now possibly parent to new children so check if we need to swap with them
            heapRebuild(indChild);
        }
    }
}

// indexing methods
template <typename T>
int HeapPriorityQueue<T>::getLeftChildIndex(const int n)
{
    return (n*2) + 1;
}

template <typename T>
int HeapPriorityQueue<T>::getRightChildIndex(const int n)
{
    return (n*2) + 2;
}

template <typename T>
int HeapPriorityQueue<T>::getParentIndex(const int n)
{
    return ((n-1)/2);
}// end indexing methods


template <typename T>
int HeapPriorityQueue<T>::getLargestChildIndex(const int n)
{
    // std::cout<<"getting Largest Child"<<std::endl;
    if (_list.getEntry(getRightChildIndex(n)) > _list.getEntry(getLeftChildIndex(n)))
    {
        return getRightChildIndex(n);
    }
    
    return getLeftChildIndex(n);
}



template <typename T>
bool HeapPriorityQueue<T>::isLeaf(const int n)
{
    if(getLeftChildIndex(n) < _heapSize)
    {
        return false;
    }
    if(getRightChildIndex(n) < _heapSize)
    {
        return false;
    }
    return true;
}


template <typename T>
void HeapPriorityQueue<T>::display()
{

    std::cout<<"Heap Size: "<<_heapSize<<std::endl;
    for (int i = 0; i < _list.getLength(); ++i)
    {
        std::cout<<_list.getEntry(i)<<std::endl;
    }
}

template <typename T>
void HeapPriorityQueue<T>::display(std::string callingPoint)
{

    std::cout<<callingPoint<<std::endl;
    std::cout<<"Heap Size: "<<_heapSize<<std::endl;
    for (int i = 0; i < _list.getLength(); ++i)
    {
        std::cout<<_list.getEntry(i)<<std::endl;
    }
}
