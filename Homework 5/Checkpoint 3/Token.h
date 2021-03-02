#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

using namespace::std;
enum Token_type {ID, INT, OP, EQ, OpenBrace, CloseBrace, INVALID};

class Token
{
   public:
      Token();
      Token(string s);
      void set(string s);
      int value() const;
      void display() const;
      Token_type get_type() const;
      string get_token() const;
      int get_priority() const;

   private:
      Token_type type;
      string token;
      int priority;

};

#endif /*TOKEN_H*/
