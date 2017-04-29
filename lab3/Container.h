#ifndef CONTAINER_H
#define CONTAINER_H
 
#include "composite.h"
#include <vector> 
#include <list> 

using namespace std;

class Sort;   

class Container
{
    protected:
        Sort* sort_function; 
        
    public:
        Container() : sort_function(NULL) {}; 
        Container(Sort* function) : sort_function(function) {}; 
        
        void set_sort_function(Sort* sort_function); 
        
        virtual void add_element(Base* element) = 0; 
        virtual void print() = 0; 
        virtual void sort() = 0; 
        virtual void swap(int i, int j) = 0; 
        virtual Base* at(int i) = 0; 
        virtual int size() = 0;  
};

class containerVec : public Container
{
   public:
       vector<Base* > vec; 
         
       containerVec() : Container() {} 

       containerVec(Sort* function) : Container(function) {}           // we don't need these b/c inherited. 
      
      // void set_sort_function(Sort* sortFunction) 
      // {
          // sort_function = sortFunction; 
      // } 

       void add_element(Base* data) 
       {
           vec.push_back(data); 
       } 

       void print() 
       {
           for( unsigned i = 0; i < vec.size(); i++)
           {
               cout << vec.at(i)->evaluate() << " ";
           }
           cout << endl;
       }

       void sort();

       void swap(int i, int j) 
       {
           Base* temp = vec.at(i);  
           vec.at(i) = vec.at(j); 
           vec.at(j) = temp;  

       } 

       Base* at(int i) 

      {
          return vec.at(i); 
      }

      int size() 
      {
          return vec.size(); 
      }

}; 


class containerList : public Container 
{
    public:
        list<Base* > baseList; 

        containerList() : Container() {}; 

        containerList(Sort* function) : Container(function) {}; 

       // void set_sort_function(Sort* sortFunction)
       // {
           // sort_function = sortFunction;
       // }

        void add_element(Base* data)
        {
            baseList.push_back(data);
        }

        void print()
        {
            list<Base* >::iterator itr = baseList.begin(); 

            while(itr != baseList.end())
            {
                cout << (*itr)->evaluate() << " ";
                itr++; 
            }
            cout << endl; 

        }

        void sort();

        void swap(int i, int j) 
        {
            list<Base* >::iterator itr = baseList.begin(); 

            for(int x = 0; x < i; x++)
            {
                itr++; 
            }

            list<Base* >::iterator itr1 = baseList.begin(); 

            for(int x = 0; x < j; x++)
            {
                itr1++; 
            }

            iter_swap(itr, itr1); 
        }

        Base* at(int i)
        {
            unsigned y = i; 
            if(y > baseList.size())
            {
                cout << "Error!" << endl;
                 
            }
            else
            {
                list<Base* >::iterator itr = baseList.begin(); 

                for(int x = 0; x < i; x++)
                {
                    itr++; 
                }
                return *itr; 
           }
        }

        int size()
        {
            return baseList.size();
        }
};



#endif
