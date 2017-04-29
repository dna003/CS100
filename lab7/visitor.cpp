#include "visitor.h" 
#include <sstream> 

PrintVisitor::PrintVisitor() : Visitor() {}; 

void PrintVisitor::rootNode()
{
    
}

void PrintVisitor::sqrNode() 
{
   output = output + "^2 ";   
}

void PrintVisitor::multNode()
{
    output = output + "* ";     
}

void PrintVisitor::subNode()
{
    output = output + "- ";    
}

void PrintVisitor::addNode()
{
   output = output + "+ ";  
} 

void PrintVisitor::opNode(Op* op) 
{
    //have to convert double to string
    
    ostringstream s; 
    s << op->evaluate();  

    output = output + s.str() + " ";    
}

void PrintVisitor::execute() 
{
    cout << output << endl;    
} 
