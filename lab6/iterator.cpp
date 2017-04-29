#include "iterator.h" 

//------------------------------------------------
//OperatorIterator Class
//------------------------------------------------

OperatorIterator::OperatorIterator(Base* ptr) : Iterator(ptr) {};   //OperatorIterator constructor calls Iterator's constructor passing in ptr. Note can only do
                                                                    // : self_ptr(ptr) if self_ptr is a variable of OperatorIterator.  

void OperatorIterator::first()
{ 
    current_ptr = self_ptr->get_left(); 
    //cout << current_ptr->evaluate() << endl;   
}

void OperatorIterator::next() 
{ 
    if(current_ptr == self_ptr->get_left()) 
    {
        current_ptr = self_ptr->get_right(); 
    }
    else
    {
        current_ptr = NULL;
    } 
}

bool OperatorIterator::is_done()
{
    if(current_ptr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

Base* OperatorIterator::current()
{
    return this->current_ptr;  
}


//----------------------------------------
//UnaryIterator Class
//------------------------------------------

UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {}; 

void UnaryIterator::first() 
{
    current_ptr = self_ptr->get_left();  
}

void UnaryIterator::next()
{
    current_ptr = NULL; 
}

bool UnaryIterator::is_done()
{
    if(current_ptr == NULL)
    {
        return true; 
    }
    else
    {
        return false;
    }
}

Base* UnaryIterator::current()
{
    return this->current_ptr; 
}

//----------------------------------------------
//NullIterator Class
//-----------------------------------------------

NullIterator::NullIterator(Base* ptr) : Iterator(ptr) {}; 

void NullIterator::first() 
{
    return;    
}

void NullIterator::next()
{
    return;
}

bool NullIterator::is_done()
{
    return true;   
}

Base* NullIterator::current() 
{
    return NULL;    
}

//-------------------------------------
//PreOrderIterator Class
//----------------------------------------

PreOrderIterator::PreOrderIterator(Base* ptr) : Iterator(ptr) {}; 

void PreOrderIterator::first() 
{  
    Iterator* i = this->self_ptr->create_iterator();
    
    if(i)
    {
        i->first();
         
        for(unsigned j = 0; j < this->iterators.size(); j++)
        {
            this->iterators.pop(); 
        }
       
        this->iterators.push(i); 
    }
}

void PreOrderIterator::next()
{
    Iterator* i = this->iterators.top()->current()->create_iterator();
    
    i->first(); 
    this->iterators.push(i); 
    while(this->iterators.size() > 0 && this->iterators.top()->is_done())
     {
 
         this->iterators.pop(); 
         if(this->iterators.size() > 0) 
         {
            this->iterators.top()->next();
         }
      
     }
}

bool PreOrderIterator::is_done()
{
    if(this->iterators.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

Base* PreOrderIterator::current() 
{
    if(this->iterators.size() > 0) 
        {
            return this->iterators.top()->current();  
        }
        else
        {
            return NULL;
        }
}
