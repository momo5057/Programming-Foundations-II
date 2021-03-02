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
                  exp.merge(i-1);
                  s.erase(i, 2);
               }
      i++;
      }
   }
   exp.check();
}

void solve(string s)
{
   s = postfix(s);
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
               exp.solve(i-1);
//               exp.check();
               s.erase(i, 2);
            }
      i++;
   }

   }
   exp.check();

}
void prefix(string s)
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
                  exp.pre(i);
                  s.erase(i, 2);
               }
      i++;
      }
   }
   exp.check();
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
int i=0;
bool check = true;
while(check)
{
   if(input[i]!='0' && input[i]!='1' && input[i]!='2' && input[i]!='3' && input[i]!='4' && input[i]!='5' && input[i]!='6' && input[i]!='7' && input[i]!='8' &&
         input[i]!='9' && input[i]!='+' && input[i]!='-' && input[i]!='*' && input[i]!='/')
   {
      cout << "Invalid input. Input: ";
      cin >> input;
      while(input[input.length()-1]!=';')
      {
         cout << "Missing ; at end, try again. Input:";
         cin >> input;
      }
      i=0;
   }
   i++;
   if(i==input.length()-1)
      check = false;
}
check = true;
i = 0;
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
         cout << input << " = "  << endl;
         solve(input);
      }
      else if(user == '>')
      {
         prefix(input);
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
         cout << "This function does not work" << endl;
/*         cout << "input: ";
         cin >> temp;
         while(temp[temp.length()-1]!=';')
         {
            cout << "Missing ; at end, try again. Input:";
            cin >> temp;
         }
         input = input + temp;
         cout << input << endl;
*/      }
      else if(user == 's')
      {
         cout << "input: ";
         cin >> input;
         while(input[input.length()-1]!=';')
         {
            cout << "Missing ; at end, try again. Input:";
            cin >> input;
         }
         while(check)
         {
            if(input[i]!='0' && input[i]!='1' && input[i]!='2' && input[i]!='3' && input[i]!='4' && input[i]!='5' && input[i]!='6' && input[i]!='7' && input[i]!='8' &&
               input[i]!='9' && input[i]!='+' && input[i]!='-' && input[i]!='*' && input[i]!='/')
            {
               cout << "Invalid input. Input: ";
               cin >> input;
               while(input[input.length()-1]!=';')
               {
                  cout << "Missing ; at end, try again. Input:";
                  cin >> input;
               }
               i=0;
            }
            i++;
            if(i==input.length()-1)
               check = false;
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
