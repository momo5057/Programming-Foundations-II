#include "mystrok.h"
#include <iostream>
#include <cstring>

mystrok M;
using namespace::std;

//constructor
mystrok::mystrok()
{
}

//copy constructor
mystrok::mystrok(mystrok& other)
{
}

//destructor
mystrok::~mystrok()
{
}

//method name: mystrok
//parameters: a char pointer for the string and a const char pointer for the deliminator
//purpose: returning a pointer to a char from a given string
//returns: char pointer
char *mystrtok(char *str, const char *delim)
{
   char *strCopy;
   char *ptr;
   int count=0;
   if(str!=NULL)
   {
      strCopy = M.find_first_non_in_the_set(str, delim); //Gets location of non deliminating
      str = M.find_first_in_the_set(strCopy, delim);  //Gets location of deliminating
      if(str-strCopy)
      {
         int i;
         for(i=0; i<(str-strCopy); i++)
            ptr[i] = strCopy[i];   //Goes through to tokenize
         ptr[i] = '\0';   //Ends token
         strCopy = str;   //saves pointer for next time
         return ptr;
      }
   }
   else
      return NULL;
}

//method name: find_first_non_in_the_set
//parameters: a char pointer for the string and a const char pointer as a place holder
//purpose: to return the address of the first character in str so the character doesent show up in
//         the set paramater, else return NULL ptr value
//returns: char ptr
char *find_first_non_in_the_set(char *str, const char *set)
{
   int count = 0;
   while(*str)
   {
      for(int i = 0; i<strlen(set); i++)
      {
         if(*str==*(set+i))  //checks if char is non deliminating
         {
            str++;
            break;  //if true, break 
         }
         else
            count++;  //else go on to next char
      }
      if(count==strlen(set))
         break;   //checks to see if gone through
      else
         str=NULL;
   }
   return str;
}

//method name: find_first_in_the_set
//parameters: a char pointer for the string and a const char pointer as a place holder
//purpose: return address of first character in str such that this character does show up in set
//         paramater. else return Null ptr value
//returns: char ptr
char *find_first_in_the_set(char *str, const char *set)
{
   int count = 0;
   while(*str)
   {
      for(int i = 0; i<strlen(set); i++)
      {
         if(*(set+i)==*str)  //finds first character of str
         {
            count=1;
            break;
         }
      }
      if(count=1)
         break;   //checks to see if gone through
      else
         str=NULL;
   }
   return str;
}
