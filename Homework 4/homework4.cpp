/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tingyan
 *
 * Created on October 30, 2018, 1:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include "Linkedlist.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Linkedlist oper(5);
    cout  << "1. ---Testing constructor and check function \n";  
    Linkedlist list(4);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  
    
    cout  << "2. ---Testing push front 7 \n";  
    cout << "before push front: " << endl;
    list.check();
    list.push_front(7);
    list.check();
    cout << endl;
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  
    
    cout  << "3. ---Testing push back  -1 \n";  
    cout << "before push back: " << endl;
    list.check();
    list.push_back(-1);
    list.check();
    cout << endl;
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  
    
    cout  << "4. ---Testing insert 5 at position 2 \n"; 
    cout << "before insert: " << endl;
    list.check();
    list.insert(2, 5);
    list.check();
    cout << endl;
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  
    
    cout  << "5. ---Testing front \n";    
    cout << list.front() << endl << endl;
    cout << "--------------------------------------\n\n" ;  
    
    cout  << "6. ---Testing back \n";  
     cout << list.back() << endl << endl;
    cout << "--------------------------------------\n\n" ;  
    
    cout  << "7. ---Testing sort \n";  
    cout << "before sort: " << endl;
    list.check();
    cout << endl;
    list.sort();
    list.check();
    cout << endl;
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  

    cout  << "8. ---Testing erase position 2 \n"; 
    cout << "before erase: " << endl;
    list.check();
    list.erase(2);
    list.check();
    cout << endl;
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  
   
    cout  << "9. ---Testing pop_back \n"; 
    cout << "before insert: " << endl;
    list.check();
    list.pop_back();
    list.check();
    cout << endl;
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  

    cout  << "10. ---Testing pop_front \n"; 
    cout << "before insert: " << endl;
    list.check();
    list.pop_front();
    list.check();
    cout << endl;
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  

    cout  << "11. ---Testing clear and empty \n"; 
    cout << "before clear: " << endl;
    if(list.empty())
       cout << "List is empty" <<endl;
    else
       cout << "List is not empty" << endl;
    cout << "after clear: " << endl;
    cout << endl;
    list.clear();
    if(list.empty())
       cout << "List is empty"<<endl;
    else
       cout << "List is not empty"<<endl;
    cout << "--------------------------------------\n\n" ;  
    
    cout  << "12. ---Testing assignment operator \n"; 
    cout << "original before operator: " << endl;
    list.check();
    list.rcheck();
    cout << "new before operatior: " <<endl;
    oper.check();
    oper.check();
    cout << "after operator: " <<endl;
    list=oper;
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;  
    return 0;
}
