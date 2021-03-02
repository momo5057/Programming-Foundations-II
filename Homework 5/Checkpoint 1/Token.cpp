#include "Token.h"
#include <iostream>
#include <string>
#include <stdlib.h>
Token::Token()
{
   type = INVALID;
   token=" ";
   priority=-1;
}
Token::Token(string s)
{
   if(s[0]= ' ')
      type = ID;
   else if(s[0]='0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9')
      type = INT;
   else if(s[0] = '+' || '-' || '*' || '/' || '%')
      type = OP;
   else if(s[0]='=')
      type = EQ;
   else if(s[0]='(')
      type = OpenBrace;
   else if(s[0] = ')')
      type = CloseBrace;
   else
      type = INVALID;
   token=s;
   priority=-1;
}
int Token::value() const
{
   if(type==INT)
   {
      int val = stoi(token, NULL, 0);
      return val;
   }
   else if(type==ID)
      return -1;
   else
      return -2;
}
void Token::display() const
{
   cout << "type = " << get_type() << endl;
   cout << "token = " << get_token() << endl;
   cout << "priority = " << get_priority() << endl;
}
Token_type Token::get_type() const
{
   return type;
}
string Token::get_token() const
{
   return token;
}
int Token::get_priority() const
{
   return value();
}

