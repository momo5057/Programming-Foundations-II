#include "Token.h"
#include <iostream>
#include <sstream>


using namespace::std;

//default constructor
Token::Token()
{
   type=INVALID;
   token=" ";
   priority=-1;
}

//special constructor
Token::Token(string s)
{
   type=get_type();
   token=get_token();
   priority=-1;
}

//method name: set
//parameters:  string s, to be treated as a token
//purpose:     sets the members based on the new token, leaving priority as -1
//returns:     void
void Token::set(string s)
{
   type=get_type();
   token=get_token();
   priority=-1;
}

//method name: value
//parmaeters:  none
//purpose:     if integer, string converted to int and returned. if identifier, return -1, else 
//             else, return -2.
//returns:     int based on definition above
int Token::value() const
{
   int v;
   stringstream s(get_token()); //used to convert int to string
   if(get_type()==1)
      s >> v;
   else if (get_type()==0)
      v=-1;
   else
      v=-2;
   return v;
}
//method name: display
//parameters:  none
//purpose:     to print out type, token, and priority
//returns:     void
void Token::display() const
{
   cout << "type = " << get_type() << endl;
   cout << "token = " << get_token() << endl;
   cout << "priority = " << get_priority() << endl;
}

//method name: get_type
//parameters:  none
//purpose:     getter for type
//returns:     Token_type type
Token_type Token::get_type() const
{
   if(get_token()==" ")
      return ID;
   else if(get_token()=="+" || get_token()=="-" || get_token()=="*" || get_token()=="/" || get_token()=="%")
      return OP;
   else if(get_token()=="0" || get_token()=="1" || get_token()=="2" || get_token()=="3" || get_token()=="4" || get_token()=="5" || get_token()=="6" || get_token()=="7" ||
           get_token()=="8" || get_token()=="9")
      return INT;
   else if(get_token()=="(")
      return OpenBrace;
   else if(get_token()==")")
      return CloseBrace;
   else
      return INVALID;
}

//method name: get_token
//parameters:  none
//purpose:     getter for token
//returns:     string token
string Token::get_token() const
{
   return token;
}

//method name: get_priority
//parameters:  none
//prupose:     getter for priority
//returns:     int priority
int Token::get_priority() const
{
   return value();
}
