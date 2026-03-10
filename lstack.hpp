#include <list>
#include "empty_collection_exception.h"

template <typename T>
LStack<T>::LStack()
{
 list = new std::list<T>();
 count = 0;
}



template <typename T>
LStack<T>::~LStack()
{
  delete list;
}


template <typename T>
void LStack<T>::push(const T& data)
{
    list->push_front(data); // insert at top
    count++;               // list incremented for size
}


template <typename T>

T& LStack<T>:: top()
{
    if (empty()) // error check
    {
        throw empty_collection_exception(); // If the stack is empty, an empty_collection_exception is thrown
    }
    return list->front();
}

template <typename T>
T LStack<T>::pop()
{
    if (empty()) // error check
    {
        throw empty_collection_exception(); // If the stack is empty, an empty_collection_exception is thrown
    }

    T fElement = list->front(); // data set as the fron element
    list->pop_front();          // data removed from front
    count--;                   // size decreased
    return fElement;           // return the top element
}




template <typename T>
int LStack<T>::size() const
{
    return count;
}

template <typename T>

bool LStack<T>:: empty() const
{
    return count == 0;
}


