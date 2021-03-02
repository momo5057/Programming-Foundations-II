#include "List.h"

List::List()
{
   head->elem = " ";
   head->next = NULL;
}
List::List(string s)
{
   head = NULL;
   Node* add = new Node();
   add->elem = s[s.length()];
   head = add;

   for(int i=s.length(); i>=0; i--)
   {
      add->elem = s[i];
      add->next = new Node();
      add = add->next;
   }

}
void List::check() const
{
   Node* current = head;
   if(current == NULL)
   {
      cout << "The list is empty" << endl;
   }
   while(current->next != NULL)
   {
      cout << current->elem << endl;
      current = current->next;
   }
}

void List::merge(int i)
{
   Node* current = head;
   for(int a = 0; a<=i; a++)
      current=current->next;
   current->elem = "(" + current->next->next->elem + current->elem + current->next->elem + ")";
   current->next = current->next->next->next;
}

List::~List()
{
   Node* current = new Node();
   current = head;
   while(current != NULL)
   {
      Node* next = current->next;
      delete current;
      current = next;
   }
   head = NULL;
   tail = NULL;
}
