#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
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
   void solve(int i);
   int convert(string c);
   void pre(int i);
};
#endif /*LINKEDLIST_H*/
