#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace::std;

class List
{
public:
   struct Node
   {
      string elem;
      struct Node* next;
   };
   Node *head;
   Node *tail;
   List();
   List(string);
   ~List(); //destructor to free nodes dynamically created to support the linklist
   void check() const;
   void merge(int i);
//   int when();
//   bool end();
};
#endif /*LINKEDLIST_H*/
