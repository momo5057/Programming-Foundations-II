/*
 * File:   mystring.cpp
 * Author: wingning
 *
 * mystring class implementation:
 * methods whose implementations are provided:
 * default constructor
 * a constructor taking c-style string
 * the destructor
 * size, length, capacity, max_size
 * << operator for cout
 * c_str
 *
 * methods to be implemented:
 * a copy constructor
 * ...
 */

#include "Mystring.h"

// default constructor
Mystring::Mystring() 
{
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s) 
{
    len        = strlen(s);
    buf_size   = len;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);

}

// copy constructor to be implemented
Mystring::Mystring(const Mystring& orig) 
{
    len = orig.length();
    ptr_buffer = new char[len];
    buf_size = len+1;
    ptr_buffer=orig.ptr_buffer;
}

// one of the over loaded assignment operator if you have time
Mystring& Mystring::operator=(const Mystring& orig)
{
     if(this!=&orig)
     {
         this->ptr_buffer=NULL;
        this-> len = orig.length();
        this-> ptr_buffer = new char[len];
         this->buf_size = len+1;
         this->ptr_buffer=orig.ptr_buffer;
     }
     return *this;
}
Mystring& Mystring::operator=(const char * orig)
{
//     if(this!=orig.ptr_buffer)

         this->ptr_buffer=NULL;
         this->len = strlen(orig);
         this->ptr_buffer = new char[buf_size];
         this->buf_size = len+1;
         strcpy(ptr_buffer, orig);
     return *this;
}
// some simple methods implemented for you
 Mystring::size_type Mystring::size() const 
 {
     return len;
 }
 
 Mystring::size_type Mystring::length() const
 {
     return len;
 }
 
 Mystring::size_type Mystring::capacity() const
 {
       return buf_size;
 }
 
 Mystring::size_type Mystring::max_size() const
 {
       return (int)pow(2,30) -4 ;
 }

//additional functions for homework3



//Requests change is capacity use pushback

void Mystring::reserve(size_type n)

{

    for(int i=0; i<n; i++)

        push_back(' ');

}

//Checks if string is empty or not

bool Mystring::empty() const

{

    if(len==0)

        return true;

    else

        return false;

}

//get character of string

char Mystring::operator[](size_type pos) const

{

    if(pos<0 || pos>=len)

        return NULL;

    return ptr_buffer[pos];

}
char& Mystring::operator[](size_type pos)

{

  //  if(pos<0 || pos>=len)

//        return ' ';

    return ptr_buffer[pos];

}
//append to string

Mystring& Mystring::operator+=(const Mystring& str)

{

    int i=0;

    while(ptr_buffer[i]!='\0')      //finds end of char

        i++;

    for(int i=0; i<str.length(); i++)    //creates space for new char

        push_back('c');

    for(int a=0; a<str.length(); a++, i++)

        ptr_buffer[i]=str[a];

    return *this;

}
Mystring& Mystring::operator+=(const char * str)

{

    int i=0;

    while(ptr_buffer[i]!='\0')      //finds end of char

        i++;

    for(int i=0; i<strlen(str); i++)    //creates space for new char

        push_back('c');

    for(int a=0; a<strlen(str); a++, i++)

        ptr_buffer[i]=str[a];

    return *this;

}
//append to string

Mystring& Mystring::append(const Mystring& str)

{

    int i=0;

    while(ptr_buffer[i]!='\0')      //finds end of char

        i++;

    for(int i=0; i<str.length(); i++)    //creates space for new char

        push_back('c');

    for(int a=0; a<str.length(); a++, i++)

        ptr_buffer[i]=str[a];

    return *this;

}
Mystring& Mystring::append(const char * str)

{

    int i=0;

    while(ptr_buffer[i]!='\0')      //finds end of char

        i++;

    for(int i=0; i<strlen(str); i++)    //creates space for new char

        push_back('c');

    for(int a=0; a<strlen(str); a++, i++)

        ptr_buffer[i]=str[a];

    return *this;

}
//insert into string, keep everything else

Mystring& Mystring::insert(size_type pos, const Mystring& str)

{

    int i=0;

    for(i=str.length(); i<pos; i--)    //creates space for new char

    {

        push_back('c');

        ptr_buffer[i+pos]=ptr_buffer[i];

    }

    for(int a=0; a<str.length(); a++, i++)

        ptr_buffer[i]=str[a];

    return *this;

}
Mystring& Mystring::insert(size_type pos, const char * str)

{

    int i=0;

    for(i=strlen(str); i<pos; i--)    //creates space for new char

    {

        push_back('c');

        ptr_buffer[i+pos]=ptr_buffer[i];

    }

    for(int a=0; a<strlen(str); a++, i++)

        ptr_buffer[i]=str[a];

    return *this;

}
//replace portion on string

Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str)

{

    for(int i=start; i<span; i++)

        ptr_buffer[i]=str[i];

    return *this;

}
Mystring& Mystring::replace(size_type start, size_type span, const char * str)

{

    for(int i=start; i<span; i++)

        ptr_buffer[i]=str[i];

    return *this;

}
//gets cstring equivalent

////////////not started

char Mystring::*c_str()

{
    return NULL;
}

//finds first palce a char exists

//s is list of chars to search for

//pos is where to start searching

//n is length of s

//returns position where character found, or Null

Mystring::size_type Mystring::find_first_of(const char* s, size_type pos, size_type n) const

{

    while(ptr_buffer[pos]!='\0')
    {
        for(int i=pos; i<=len; i++)
        {
            for(int a=0; a<=n; a++)
            {
                if(s[a]==ptr_buffer[pos])
                    return i;
             }
            pos++;
        }   
    }
    return -1;
}

//find non-matching character in string from the end

Mystring::size_type Mystring::find_last_not_of(const char* s, size_type pos) const

{

   int temp=0;
    while(ptr_buffer[pos]!='\0')
    {

        if(s[0]==ptr_buffer[pos])

            temp=pos;

        pos++;

    }

    return temp;

}

//clear string

void Mystring::clear()

{

    *ptr_buffer='\0';

    len=0;

    buf_size=1;

}

//append character to string

void Mystring::push_back(char c)

{

    char * p=new char;

    p=ptr_buffer;

    len+=1;

    p[len+1]=ptr_buffer[len+1];

    ptr_buffer = p;

}
/*bool Mystring::operator==(const Mystring& s1, const Mystring& s2)
{
   if(s1.length()==s2.length())
      for(int i=0; 0<s1.length(); i++)
         if(s1[i]==s2[i])
            return true;
   else
      return false;
}

Mystring Mystring::operator+(const Mystring& s1, const Mystring& s2)
{
   this->ptr_buffer=s1+s2;
   return *this;
}
*/
// Destructor
Mystring::~Mystring() 
{
    delete [] ptr_buffer;
}

// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str) 
{
    out << str.c_str();
    return out;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const 
{
    return ptr_buffer;
}
