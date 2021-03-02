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
   valid = false;
   type = illegal;
   original = s;
   postfix = postfix;
//   tokenized
}
void Expression::set(const string& s)
{
   valid = false;
   type = illegal;
   original = s;
   postfix = postfix;
//   tokenized
}
void Expression::display() const
{
   cout << "original = " << original << endl;
   cout << "tokenized = ";
//   for(int i=0; i<tokenized.size(); i++)
//      cout << tokenized[i] << endl;
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
