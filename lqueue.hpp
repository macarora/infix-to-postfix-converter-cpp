#include <list>
#include "empty_collection_exception.h"

template <typename T>
LQueue<T>::LQueue() // constructor
{
   list = new std::list<T>(); 
   count = 0;

}

template <typename T>
LQueue<T>::~LQueue() // destructor
{
   delete list; 
}

template <typename T>
void LQueue<T>::enqueue(const T &data)
{
    list->push_back(data); // data is inserted at the rear of the queue
    count++;              // list incremented for size
}

template <typename T>
T LQueue<T>::dequeue()
{
    if (empty()) // error check for empty list
    {
        throw empty_collection_exception(); // exception thrown if list is empty
    }

    T fElement = list->front(); // get front element
    list->pop_front();          // remove front element
    count--;                   // decrease the count

    return fElement;
}

template <typename T>
T &LQueue<T>::front()
{
    if (empty()) // error check for empty list
    {
        throw empty_collection_exception(); // exception thrown if list is empty
    }

    return list->front(); // Returns a reference to the front element on the queue
}
template <typename T>
int LQueue<T>::size() const
{
    return count;
}
template <typename T>
bool LQueue<T>::empty() const
{
    return count == 0;
}
