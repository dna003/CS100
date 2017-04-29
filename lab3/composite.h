#ifndef composite_h
#define composite_h

#include <iostream>
#include <math.h>
#include <vector> 
#include <list>
#include <algorithm> 
using namespace std; 

class Base 
{
    public:
         Base() {};
         /* Pure Virtual Functions */
         virtual double evaluate() = 0; 
};

class leaf : public  Base
{
    public:
        double val;
        leaf(double x) : val(x) {}
        virtual double evaluate() {return val;}; 
}; 

class Sqr : public Base 
{
    public:
        Base* val;
        Sqr(Base* newval) {val = newval;} 
        double evaluate() {return val -> evaluate() * val -> evaluate();};
};

class Mult : public Base
{
  public:
       Base* val; 
       Base* val2; 
       Mult(Base* first, Base* second) : val(first), val2(second) {}
       virtual double evaluate() {return val -> evaluate() * val2 -> evaluate();};    
};  

class Add : public Base
{
    public:
        Base* val; 
        Base* val2; 
        Add(Base* first, Base* second) : val(first), val2(second) {} 
        virtual double evaluate() {return val -> evaluate() + val2 -> evaluate();};  
};

class Div : public Base 
{
    public: 
        Base* val; 
        Base* val2; 
        Div(Base* first, Base* second) : val(first), val2(second) {} 
        virtual double evaluate() {return val -> evaluate() / val2 -> evaluate();}; 
};

class Sub : public Base
{
    public: 
        Base* val; 
        Base* val2; 
        Sub(Base* first, Base* second) : val(first), val2(second) {} 
        virtual double evaluate() {return val -> evaluate() - val2 -> evaluate();};
};


#endif   
