#include "Expression.h"

using namespace::std;

Expression::Expression()
{
   valid = false;
   type = illegal;
   tokenized = tokenized;
   original = ' ';
   postfix = postfix;
}
Expression::Expression(const string& s)
{
//   valid = false;
//   type = illegal;
//   original = s;
//   postfix = postfix;
//   tokenized
   set(s);
}
void Expression::set(const string& s)
{
   valid = false;
   type = illegal;
   original = s;
   postfix = postfix;
   int len= s.length();
   string copy = s;
   for(int i=0; i<copy.length(); i++)
   {
      if((copy.at(i)=='+')||(copy.at(i)=='-')||(copy.at(i)=='*')||(copy.at(i)=='/')||(copy.at(i)=='%')||(copy.at(i)=='='))
      {
         copy.insert(i, " ");
         copy.insert(i+2, " ");
         i = i+2;
      }
   }
   char *cc = new char[copy.length()];
   strcpy(cc, copy.c_str());

   char * pch;
   pch = strtok(cc, " ");
   while(pch!=NULL)
   {
      Token t(pch);
      tokenized.push_back(t);
      pch = strtok(NULL, " ");
   }
}
void Expression::display() const
{
   cout << "original = " << original << endl;
   cout << "tokenized = ";
   for(int i=0; i<tokenized.size(); i++)
   {
      cout << tokenized[i] << " ";
   }
   cout << "postfix = " /*<< postfix*/ << endl;
   cout << "valid = " << valid << endl;
   cout << "type = " << illegal << endl;
}
string Expression::get_original() const
{
   return original;
}
vector<Token> Expression::get_tokenized() const
{
   return tokenized;
}
