#include <iostream>
#include "Token.h"
#include "Expression.h"

using namespace::std;

int main()
{
   Token T;
   Expression E;

   T.set("hello");
   cout << "Token value = " << T.value();
   T.display();
   E.set("Hello");
   E.display();

   return 0;
}
