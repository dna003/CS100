#include <iostream>   
#include "composite.h" 
#include "Container.h"
#include "Sort.h" 

using namespace std; 
   
int main()
{
    Base* a = new leaf(3); 
    Base* b = new leaf(4);
    Base* c = new leaf(7);
    Base* d = new leaf(11);      
    Base* add = new Add(a,b);  
    cout << add -> evaluate() << endl;
    Base* sub = new Sub(d,c);  
    cout << sub -> evaluate() << endl; 
    Base* mult = new Mult(a,b);  
    cout << mult -> evaluate() << endl; 
    Base* div = new Div(a,b);  
    cout << div -> evaluate() << endl; 
    Base* sqr = new Sqr(a);  
    cout << sqr -> evaluate() << endl; 
    
    Sort* select1 = new selectionSort();   
    Sort* bubble1 = new bubbleSort(); 
    Container* vector1 = new containerVec(); 
    Container* List1 = new containerList();  
   
    vector1->add_element(add); 
    vector1->add_element(sub); 
    vector1->add_element(mult); 
    
    cout << "Vector 1: "; 
    
    vector1->print();  
//--------------------------------------------------------------     
    vector1->set_sort_function(select1); 
      
    vector1->sort();  
    cout << "Sorted vector: "; 
    vector1->print(); 
//--------------------------------------------------------------------    
    List1->add_element(add); 
    List1->add_element(sub); 
    List1->add_element(mult); 
    
    cout << "List 1: ";
    List1->print();  
//-----------------------------------------------------------
    List1->set_sort_function(bubble1); 
    List1->sort(); 
    
    cout << "Sorted List: "; 
    List1->print();   
     
    return 0; 
} 
