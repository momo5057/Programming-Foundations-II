#include <iostream>
#include "Expression.h"
#include "Token.h"

using namespace::std;

void menu()
{
   cout << "=== expression evaluation program starts ===" << endl;
   char user;
   string temp;
   string input;
   cout << "input: ";
   cin >> input;
   while(input[input.length()-1]!=';')
   {
      cout << "Missing ; at end, try again. Input:";
      cin >> input;
   }
   while(user != 'q')
   {
      cout << "action:";
      cin >> user;
      while(user != '=' && user != '>' && user != '<' && user != 'f' && user != 'q' && user != 'c' && user != 's')
      {
         cout << "Invalid input. Input:";
         cin >> user;
      }
      if(user == '=')
      {
         cout << "evaluate expression\n";
      }
      else if(user == '>')
      {
         cout << "print prefix\n";
      }
      else if(user == '<')
      {
         cout << "print postfix\n";
      }
      else if(user == 'f')
      {
         cout << "equivalent with parenthesize\n";
      }
      else if(user == 'c')
      {
         cout << "input: ";
         cin >> temp;
         while(temp[temp.length()-1]!=';')
         {
            cout << "Missing ; at end, try again. Input:";
            cin >> temp;
         }
         input = input + temp;
         cout << input << endl;
      }
      else if(user == 's')
      {
         cout << "input: ";
         cin >> input;
         while(input[input.length()-1]!=';')
         {
            cout << "Missing ; at end, try again. Input:";
            cin >> input;
         }
         cout << input << endl;
      }
   }
}

int main()
{
   menu();
   return 0;
}
