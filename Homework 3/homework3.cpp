/*
 * File:   main.cpp
 * Author: wingning
 *
 * Created on October 1, 2010, 11:04 AM
 * Modified on January 18, 2016
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Mystring.h"

#define string Mystring

using namespace std;



/*

 * Check function from the previous lab

 */

void check (const string s, const string name)

{

    cout << "checking " << name << endl;

    cout << name << " contains " << s << endl;

    cout << name << " capacity() is " << s.capacity() << endl;

    cout << name << " length() is " << s.length() << endl;

    cout << name << " size() is " << s.size() << endl;

    cout << name << " max_size() is " << s.max_size() << endl;

    if(s.empty()==true)

        cout << name << " is empty." << endl;

    else

        cout << name << " is not empty." << endl;

    

    cout << endl;

}



int main()

{

    string s1="Hello World";

    string s1name("s1");

   

    cout << "---Testing assignment operator---\n\n";

    string s2;

    s2=s1;

    string s2name("s2");

    check(s2,s2name);

    

    cout << "---Testing reserve---\n\n";

    string s3="Hello!";

    string s3name("s3");

    s3.reserve(3);

    check(s3, s3name);

    

    cout << "---Testing [] operator---\n\n";

    cout << s1[2] << endl << endl;

    cout << "---Testing += operator---\n\n";

    s1+=s2;

    check(s1, s1name);

    cout << "---Testing append---\n\n";

    string s4=" Hi!";

    s3.append(s4);

    check(s3, s3name);

    cout << "---Testing insert---\n\n";

    string s5="Hello World!";

    s5.insert(5, "Mom!");

    check(s5, "s5");



    cout << "---Testing replace---\n\n";

    string s6="Hello World!";

    s6.replace(6, 11, "Mom!");

    check(s6, "s6");

    cout << "---Testing *c_str---\n\n";

    cout << "Not implemented yet\n\n";

    cout << "---Testing find_first_of---\n\n";

    cout << s3.find_first_of("l", 0, 0) << endl << endl;

    cout << "---Testing find_last_not_of---\n\n";

    cout << s3.find_last_not_of("l", 0) << endl << endl;

    cout << "---Testing clear---\n\n";

    s1.clear();

    check(s1, s1name);


    return 0;

}


