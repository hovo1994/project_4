/** A class of nodes for a link-based binary tree */
#ifndef _BINARY_NODE
#define _BINARY_NODE

#include <iostream>

template<typename T>
class BinaryNode
{
 public:
  //constructors
  BinaryNode();
  BinaryNode(const T& anItem);
  BinaryNode(const T& anItem, BinaryNode<T>* itemL, BinaryNode<T>* itemR);

  void setItem(const T& anItem);
  T getItem() const;
  bool isLeaf() const;
  BinaryNode<T>* getL() const;
  BinaryNode<T>* getR() const;
  void setL(BinaryNode<T>* L);
  void setR(BinaryNode<T>* R);

 private:
  T item;
  BinaryNode<T>* ptrL;
  BinaryNode<T>* ptrR; // Pointer to right child
}; // end BinaryNode

#include "BinaryNode.cpp" 
#endif
