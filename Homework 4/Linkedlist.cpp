

#include "Linkedlist.h"

Linkedlist::Linkedlist()
{
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}
Linkedlist::~Linkedlist()
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
bool Linkedlist::empty()
{
   return(head==NULL);
}
void Linkedlist::clear()
{
   head=NULL;
   tail=head;
}


Linkedlist::reference Linkedlist::back()
{
//cant return null
int obj;
   if(empty())
   {
      cout << "List is empty;";
      return obj;
   }
   return tail->elem;
}
Linkedlist::const_reference Linkedlist::back() const
{
   return tail->elem;
}
Linkedlist::reference Linkedlist::front()
{
   int obj;
   if(empty())
   {
      cout << "List is empty;";
      return obj;
   }
   return head->elem;
}
Linkedlist::const_reference Linkedlist::front() const
{
   return head->elem;
}
Linkedlist& Linkedlist::operator=(const Linkedlist& l)
{
   clear();
/*   if(&l != this)
   {
      Node *temp = head;
      while(head)
      {
         temp = head->next;
         delete head;
         head = temp;
      }
      temp = l->head;
      while(temp)
      {
         push_back(temp->elem);
         temp=temp->next;
      }
   }
   return *this;

   Node* obj = new Node();
   Node* current = new Node();
   obj=this->head;
   while (obj->next!=NULL)
      obj->next=this->obj->next;
*/
}

void Linkedlist::pop_back()
{
    Node * five = new Node();
    five = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    delete five;
   size--;
}
void Linkedlist::pop_front()
{
    Node * four = new Node();
    four = head;
    head = head -> next;
    head -> prev = NULL;
    delete four;
   size--;
}
void Linkedlist::push_back(const int& x)
{
   Node* add = new Node();
   add->elem=x;
   if(head==NULL)
   {
       add->prev=NULL;
       head=add;
       tail=head;
       tail->next=NULL;
    }
else
{
   add->prev = tail;
   add->next = NULL;
   tail->next = add;
   tail=add;

}
   size++;
}
void Linkedlist::push_front(const int& x)
{
   Node* add = new Node();
   add->elem=x;
   if(head==NULL)
   {
       add->prev=NULL;
       head=add;
       head->next=tail;
    }
else
{
   add->next = head;
   add->prev = NULL;
   head->prev = add;
   head=add;

}
   size++;

}
void Linkedlist::sort()
{
   Node* check1 = head;
   Node* current;
   int smallest=head->elem;
   int temp;
   int i;
   int a=0;
   int rem;
   int hold;
   while(check1->next!=NULL)
   {
      temp=check1->elem;
      i=a;
      smallest=check1->elem;
      current=check1->next;
      while(current!=NULL)
      {
         temp=current->elem;
         if(temp<smallest)
         {
            smallest=temp;
            rem=i;
         }
         current=current->next;
         i++;
      }
if(check1->elem!=smallest)
{
   current=head;
   for(int b=0; b<rem; b++)
      current=current->next;
   current=current->next;
   hold=check1->elem;
   check1->elem=smallest;
   current->elem=hold;
}
   check1=check1->next;
   a++;
   }
}

Linkedlist::Linkedlist(unsigned int n)
{
   int size = n;
   head=NULL;
   tail=NULL;
   for(int i=0; i<n; i++)
   {
      push_back(i);
   }
}
void Linkedlist::check() const
{
    Node* current = head;
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    int i = 0;
    while (current != NULL)
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
}
void Linkedlist::rcheck() const
{
    Node* current = tail;
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    int i = 0;
    while (current != NULL)
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
}
void Linkedlist::insert(unsigned int pos, const int& x)
{

   Node* add = new Node();
   add->elem=x;
   Node* before=new Node();
   before=head;
   Node* after=new Node();
   if(pos>size)
      pos=size;
   for(int i=0; i<pos; i++)
      before = before->next;
   after=before->next;
   before->next=add;
   after->prev=add;
   add->prev=before;
   add->next=after;
size++;
}
void Linkedlist::erase(unsigned int pos)
{
   if(pos>size)
      pos=size;
    Node * temp=new Node();
    temp = head;
    for(int i=0; i < pos; i++)
        temp = temp -> next;
    Node * above=new Node();
    above = temp -> next;
    Node * behind=new Node();
    behind = temp -> prev;
    above -> prev = temp -> prev;
    behind -> next = temp -> next;
    delete temp;
size--;
}
