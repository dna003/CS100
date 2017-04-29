#include "Container.h" 
#include "Sort.h"

void Container::set_sort_function(Sort* sortFunction) 
{
    sort_function = sortFunction; 
} 

void containerVec::sort() 
{
   sort_function->sort(this);      
}

void containerList::sort() 
{
   sort_function->sort(this);      
}
