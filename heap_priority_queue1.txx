// #include "heap_priority_queue.h"
#include <cstdlib>
template <typename T>
HeapPriorityQueue<T>::HeapPriorityQueue()
{
    _list.insert(0,T());
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
    // if list is empty initilaze list. 
    if (isEmpty())
    {
        //std::cout<< "inserting" << std::endl;
        _list.insert(1, item);
        ++_heapSize;

        return;
    }
    std::size_t i = ++_heapSize;
    //std::cout<<"index: " << i <<std::endl;
    _list.insert(i, item);

    while(i != 1)
    {
        // std::cout<<"index:: " << i <<std::endl;
        //check last item with parent
        // T currentItem = _list.getEntry(i);
        // T parentItem = _list.getEntry(getParentIndex(i));
        // std::cout<<"current:: " << currentItem <<std::endl;
        // std::cout<<"parent:: " << parentItem <<std::endl;
// 
        if(_list.getEntry(i) <= _list.getEntry(getParentIndex(i)))
        {
            i = getParentIndex(i);

        }
        else // if greater than, swap with parent
        {
            T tempCurr = _list[i];
            T tempParent = _list[getParentIndex(i)];

            _list.setEntry(i, tempParent);
            _list.setEntry(getParentIndex(i), tempCurr);

            i = getParentIndex(i);
        }

        // if less than, set i to parentNodeIndex
    }
    
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    if(isEmpty())
    {
        throw std::logic_error("Attempted to remove from Empty Queue");
    }
    else if (_heapSize == 1)
    {
        _list.remove(_heapSize--);
        
    }
    else 
    {
        _list.setEntry(1, _list.getEntry(_heapSize)); // remove top item from queue
        // do I have children? 
        
        _list.remove(_heapSize--);

        if (_heapSize==2 )
        {
            if ((_list.getEntry(1) < _list.getEntry(2)))
            {
                T tempCurr = _list[1];
                T largerChild = _list[2];
            
                _list.setEntry(1, largerChild);
                _list.setEntry(2, tempCurr);
            }
            else
            {
                display();
                return;
            }
    
        }
        else
        {
            int i = 1;
            bool notleaf = true;   
            while(notleaf)
            {
                
                if (_list[i] < _list[getLargestChildIndex(i)])
                {
                    //std::cout<<"Remove Index: "<<i<<std::endl;
                    T tempCurr = _list[i];
                    T largerChild = _list[getLargestChildIndex(i)];
        
                    _list.setEntry(i, largerChild);
                    _list.setEntry(getLargestChildIndex(i), tempCurr);
        
                    i = getLargestChildIndex(i);
                }
                else
                {
                    display();
                    return;
                }

                notleaf = !isLeaf(i);

                
                
            }
        }
    }
    // --_heapSize;
    display();
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    if(isEmpty())
        throw std::logic_error("Attempted to peek at Empty Queue");

    return _list.getEntry(1);
}


// indexing methods
template <typename T>
int HeapPriorityQueue<T>::getLeftChildIndex(const int n)
{
    return (n*2);
}

template <typename T>
int HeapPriorityQueue<T>::getRightChildIndex(const int n)
{
    return (n*2) + 1;
}

template <typename T>
int HeapPriorityQueue<T>::getParentIndex(const int n)
{
    return (n/2);
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
