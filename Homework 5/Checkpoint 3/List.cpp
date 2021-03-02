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

   for(int i=s.length()-1; i>=0; i--)
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
int List::convert(string s)
{
   int len = s.length();
   int answer = 0;
   int temp;
   int count = 1;
   for(int i = 0; i<s.length(); i++)
   {
      if(s[i]=='0')
         temp = 0;
      if(s[s.length()-1-i]=='1')
         temp = 1;
      if(s[s.length()-1-i]=='2')
         temp = 2;
      if(s[s.length()-1-i]=='3')
         temp = 3;
      if(s[i]=='4')
         temp = 4;
      if(s[i]=='5')
         temp = 5;
      if(s[i]=='6')
         temp = 6;
      if(s[i]=='7')
         temp = 7;
      if(s[i]=='8')
         temp = 8;
      if(s[i]=='9')
         temp = 9;
      answer += temp * count;
      count = count * 10;

   }
   return answer;
}

void List::solve(int i)
{
   Node* current = head;
   for(int a = 0; a<=i; a++)
      current=current->next;
   string cur;
   int curn;
   int curnn;
   curn = convert(current->next->elem);
   curnn = convert(current->next->next->elem);
   cur = current->elem;
   int temp;
   if(cur[0]=='+')
      temp = (curnn + curn);
   else if(cur[0]=='-')
      temp = (curnn - curn);
   else if(cur[0]=='*')
      temp = (curnn * curn);
   else if(cur[0]=='/')
      temp = (curnn / curn);

   ostringstream str1;
   str1 << temp;
   current->elem = str1.str();
   current->next = current->next->next->next;
}
void List::pre(int i)
{
   Node* current = head;
   for(int a = 0; a<i; a++)
   {
      current = current->next;
   }
   current->elem = current->elem + current->next->next->elem + current->next->elem;
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
