#include "Expression.h"
#include <string.h>

using namespace::std;

//default constructor
Expression::Expression()
{
   original=" ";
//   tokenized=0;
//   postfix=NULL;
   valid=false;
   type=illegal;
}

//special constructor
Expression::Expression(const string& s)
{
   original=s;
   char *tok=strtok(s, " ");
   int i=0;
//   while(tok != NULL)
//   {
//       tokenized[i++] = strtok(original, " ")
//   }
   valid=false;
   type=illegal;
}

//method name: set
//parameters:  reference string s, to be tokenized
//purpose:     tokenizes string and sets tokenized and original
//returns:     void
void Expression::set(const string& s)
{
   original=s;
//   char *tok=strtok(s, " ");
   int i=0;
//   while(tok != NULL)
//   {
//       tokenized[i++] = tok;
//      tok = strtok(NULL, " ");
//   }
   valid=false;
   type=illegal;
}

//method name: display
//parameters:  none
//purpose:     output values, for debugging
//returns:     void
void Expression::display() const
{
   cout << "original = " << original << endl;
   cout << "tokenized = ";
//   for(int i=0; i<tokenized.size(); i++)
//      cout << tokenized[i] << ";";
   cout << endl << "postfix =  " << endl;
   cout << "valid = 0" << endl;
   cout << "type = illegal" << endl;
}

//method name: get_original
//parameters:  none
//purpose:     getter for original string
//returns:     void
string Expression::get_original() const
{
   return original;
}

//method name: get_tokenized
//parameters:  none
//purpose:     getter for tokenized members
//returns:     none
vector<Token> Expression::get_tokenized() const
{
   return tokenized;
}
