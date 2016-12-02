#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList(): _data(nullptr), _capacity(0), _size(0)
{}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
    _capacity = x._capacity;
    _size = x._size;
    // if _capacity is 0 then point _data to nullptr
    //otherwise create new array of type T[_capacity]
    _data = _capacity ? new T[_capacity] : nullptr;
    std::copy(x._data, x._data + _capacity, _data);
  
  
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  if(_data != nullptr) delete[] _data;
  _size = 0;
  _capacity = 0;
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  if (&x == this)
    {
        return *this;
    }
    swap(*this, x);
    return *this; 
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& x, DynamicArrayList<T>& y)
{
   std::swap(x._capacity, y._capacity);
   std::swap(x._size, y._size);
   std::swap(x._data, y._data);
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  return _size == 0;
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  return _size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{ // enforce 0 indexing
  if((position >= 0) && (position <= _size))
  {
    if (_size == _capacity)
    { // grow array
      T * oldData  = _data; //get addr of _data array

      _data = new T[(_capacity*2)+1]; //doesn't overwrite old array

      for(int i = 0; i < _capacity; i++)
        _data[i] = oldData[i];
      
      if(oldData != nullptr)
        delete [] oldData;
      _capacity = (_capacity*2) +1;
    }
    // check for shifting positions of items
    if (position != _size)
    {// shift items
      for (int i = _size; i > position; i--)
      {
        _data[i] = _data[i - 1];
      }
    }
    ++_size;
    // insert new item into array using 1 indexing
    _data[position] = item;
  }
  else
  {
     throw std::range_error("Invalid insert into array list");
  }
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  // check for items in list or if it's empty
  if (_size == 0 || position >= _size)
  {
    throw std::range_error("Invalid Remove from list");
  }
  else
  {
    for (int i = position; i < _size; i++)
    {
      _data[i] = _data[i+1];
    }
    --_size;
  }
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  _size = 0;
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
    // is it a valid position?
   if ((position >= 0) && (position < _size))
      return _data[position];
   else 
   { // throw error if invalid error
      //std::cout<<position<<std::endl;
      //std::cout<<_size<<std::endl;
      throw std::range_error("getEntry() called at invalid position or with empty list"); 
   }  // end if
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{

   if ((position >= 0) && (position < _size))
      _data[position] = newValue;
   else
   {
      throw std::range_error("setEntry() called with an empty list or invalid position"); 
   } 
}

template <typename T>
T DynamicArrayList<T>::operator[](std::size_t index) const
{
  if(index >= 0 && index <= _size-1)
    return _data[index];
  else
  {
    throw std::range_error("Entry reference greater than list length.");
  }
}
