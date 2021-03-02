#include <iostream>
#include <string>
//#include "Expression.h"
//#include "Token.h"
#include "List.h"
using namespace::std;

string postfix(string s)
{
   string eq;
   string num;
   string temp;
   for(int i=0; i<s.size()-1; i++)
   {
      if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
         eq+=s[i];
      else
         num+=s[i];
   }
   while(eq.size()!=0)
   {
      if(eq.size()==1 && num.size()==0)
      {
         temp+=eq[0];
         eq.clear();
      }
      else if(eq.size()==1 && num.size()==1)
      {
         temp+=num[0];
         num.clear();
         temp+=eq[0];
         eq.clear();
      }
      else if(eq.size()==1 && num.size()==2)
      {
         temp=temp+num[0]+num[1];
         num.clear();
         temp+=eq[0];
         eq.clear();
      }
      else if(eq.size()>=2 && num.size()==0)
      {
         if((eq[0]=='+' || eq[0]=='-') && (eq[1]=='/' || eq[1]=='*'))
         {
            temp+=eq[1];
            swap(eq[0], eq[1]);
            eq.erase(0, 1);
         }
         else
         {
            temp+=eq[0];
            eq.erase(0, 1);
         }
      }
      else if(eq.size()>=2 && num.size()==1)
      {
         temp+=num[0];
         num.clear();
         if((eq[0]=='+' || eq[0]=='-') && (eq[1]=='/' || eq[1]=='*'))
         {
            temp+=eq[1];
            swap(eq[0], eq[1]);
            eq.erase(0, 1);
         }
         else
         {
            temp+=eq[0];
            eq.erase(0, 1);
         }
      }
      else if(eq.size()>=2 && num.size()>=2)
      {
         if(num.size()==2)
         {
         temp=temp+num[0]+num[1];
         num.clear();
         }
         else
         {
            temp=temp+num[0]+num[1];
            num.erase(0, 2);
         }
         if((eq[0]=='+' || eq[0]=='-') && (eq[1]=='/' || eq[1]=='*'))
         {
            temp+=eq[1];
            swap(eq[0], eq[1]);
            eq.erase(0, 1);
         }
         else
         {
            temp+=eq[0];
            eq.erase(0, 1);
         }
      }
   }
   return temp;

}

void parenthesis(string s)
{
   s=postfix(s);
   s.erase(0, 0);
   List exp(s);
   for(int i=0; i<s.length()/2; i++)
      swap(s[i], s[s.length()-i-1]);
   int i=0;
   while(s.length()>1)
   {
   i=0;
      while(i<s.length())
      {
         if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            if(s[i+1]!='+' && s[i+1]!='-' && s[i+1]!='*' && s[i+1]!='/')
               if(s[i+2]!='+' && s[i+2]!='-' && s[i+2]!='*' && s[i+2]!='/')
               {
                  exp.merge(i);
                  s.erase(i, 2);
               }
      i++;
      }
   }
   exp.check();
}

string solve(string s)
{
   s = postfix(s);
   
}
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
         cout << "postfix: " << postfix(input) << endl;
      }
      else if(user == 'f')
      {
         parenthesis(input);
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
