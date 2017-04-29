#ifndef VISITOR_H
#define VISITOR_H
#include "composite.h" 
#include <string> 

using namespace std; 

class Base; 
class Op; 

class Visitor
{
    public:
        Visitor(){}; 
        virtual void rootNode() = 0; 
        virtual void sqrNode() = 0;
        virtual void multNode() = 0; 
        virtual void subNode() = 0; 
        virtual void addNode() = 0; 
        virtual void opNode(Op* op) = 0;
        virtual void execute() = 0;   
}; 

class PrintVisitor : public Visitor 
{
    private: 
        string output;
        
    public: 
        PrintVisitor(); 
        
        void rootNode(); 
        void sqrNode(); 
        void multNode(); 
        void subNode(); 
        void addNode(); 
        void opNode(Op* op);
         
        void execute();
        
};        
#endif
