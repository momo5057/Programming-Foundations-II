#include <iostream>
#include "Token.h"
#include <vector>

using namespace::std;
enum Exp_type {assignment, arithmetic, illegal};

class Expression
{
   public:
      Expression();
      Expression(const string& s);
      void set(const string& s);
      void display() const;
      string get_original() const;
      vector<Token> get_tokenized() const;

   private:
      string original;
      vector<Token> tokenized;
      vector<Token> postfix;
      bool valid;
      Exp_type type;
};
