#ifndef SORT_H 
#define SORT_H

#include "Container.h"
#include <algorithm>
#include <math.h>

using namespace std; 
  

class Sort
{
    public: 
        Sort(){};  

        /* Pure Virtual Functions */ 
        virtual void sort(Container* container) = 0;
};

class bubbleSort : public Sort
{
    public:  
        void sort(Container* container) 
        {
            int contSize = container->size();
            for(int i = 0; i < contSize; i++)
            {
                for(int j = 0; j < contSize - i - 1; j++)
                {
                    if(container->at(j+1)->evaluate() > container->at(j)->evaluate())
                    {
                        container->swap(j,j+1); 
                    }
                }
            }
        }
};


class selectionSort : public Sort
{
    public:  
        void sort(Container* container) 
        { 
            int min = 0; 
            int contSize = container->size(); 
            for(int i = contSize-1; i > 0; i--)
            { 
                min = 0; 
                for(int j = 1; j <= i; j++)
                { 
                    if(container->at(j)->evaluate() < container->at(min)->evaluate())
                    {
                        min = j; 
                    }
                }              
                container->swap(i, min); 
            }
        }        
};

#endif
