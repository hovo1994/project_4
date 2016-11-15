// #include "heap_priority_queue.h"
#include <cstdlib>
template <typename T>
HeapPriorityQueue<T>::HeapPriorityQueue()
{}

template <typename T>
HeapPriorityQueue<T>::~HeapPriorityQueue()
{
    // _list->clear();
}
template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    //todo
    return _list->isEmpty();
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    // std::size_t i = _list->getLength();
    // std::cout<<"index: " << i <<std::endl;
    // _list->insert(i, item);
    // while(i != 0)
    // {
    //     std::cout<<"index:: " << i <<std::endl;
    //     //check last item with parent
    //     T currentItem = _list->getEntry(i);
    //     T parentItem = _list->getEntry(getParentIndex(i));
    //     std::cout<<"current:: " << currentItem <<std::endl;
    //     std::cout<<"parent:: " << parentItem <<std::endl;

    //     if(_list->getEntry(i) <= _list->getEntry(getParentIndex(i)))
    //     {
    //         i = getParentIndex(i);

    //     }
    //     else // if greater than, swap with parent
    //     {
    //         std::swap(_list[i], _list[getParentIndex(i)]);
    //         i = getParentIndex(i);
    //     }
    //     // if less than, set i to parentNodeIndex
    // }
    


}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    if(_list->isEmpty())
        throw std::logic_error("Attempted to remove from Empty Queue");

    _list->setEntry(0, _list->getEntry(_list->getLength()-1)); // remove top item from queue
    _list->remove(_list->getLength()-1);
    // call heap rebuild

}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    if(_list->isEmpty())
        throw std::logic_error("Attempted to peek at Empty Queue");

    return _list->getEntry(0);
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

// template <typename T>
// bool HeapPriorityQueue<T>::isLeaf(const int n)
// {
//     return (_list->getEntry(getLeftChildIndex(n)) == nullptr
//          && _list->getEntry(getRightChildIndex(n)) == nullptr);
// }

// template <typename T>
// bool HeapPriorityQueue<T>::isRoot(const int n)
// {
//     return (n == 0);
// }

// template <typename T>
// void HeapPriorityQueue<T>::heapify(int subTreeRootIndex)
// {return;
//     int li = getLeftChildIndex(subTreeRootIndex);
//     int ri = getRightChildIndex(subTreeRootIndex);


// }

// template <typename T>
// void HeapPriorityQueue<T>::insert(const T& item, uint priority)
// {
//     // create priority item element. 
//     HeapPriorityQueue<T>::qitem qi;
//     qi.data = item;
//     qi.priority = priority;
//     if (_list->getLength() == 0)
//     {
//         _list->insert(0, qi);
//     }
//     else
//     {
//         _list->insert(_list->getLength(), qi);
//         while
//     }
// }