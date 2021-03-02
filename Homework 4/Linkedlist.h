#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
using namespace std;

class Linkedlist
{
   public:
      typedef int& reference;
      typedef const int& const_reference;

      Linkedlist(); //default constructor for empty list
      ~Linkedlist(); //destructor to free nodes dynamically created to support the linklist

      bool empty();
      void clear();
      reference back();
      const_reference back() const;
      reference front();
      const_reference front() const;

      Linkedlist& operator=(const Linkedlist& l);

      void pop_back ( );
      void pop_front ( );
      void push_back ( const int& x );
      void push_front ( const int& x );
      //no new node, no copying
      void sort ( );
      // constructor that initializes the linked list with n nodes,
      // with elem value from 0 to n-1
      // print the linked list in the forward direction,
      // similar to the show function of lab6
      void check() const;
      // print the linked list in the backward direction,
      // similar to the reverse_show function of lab7
      void rcheck() const;
      // insert a node with value specified by x after the node
      // specified by pos. The first node has position 0.
      // if the number of nodes in the linked list is less than
      // pos, the node is inserted at the end.
      void insert(unsigned int pos, const int& x);
      // remove the node specified by pos.
      // if the number of nodes in the linked list is less than
      // pos, the node at the end if any is removed.
      void erase(unsigned int pos);
   private:
      struct Node
      {
          int elem;  // Data
          struct Node * next;        // Pointer to the next node in the chain
          struct Node * prev;        // Pointer to the previous node in the chain
      };
      Node *head;
      Node *tail;
      int size;

};

#endif /*LINKEDLIST_H*/
