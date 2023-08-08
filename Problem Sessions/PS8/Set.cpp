#include<iostream>
#include"Set.h"
using namespace std;



template<class T>
Set<T>::Set()
{
    size=0;
    items = nullptr;
}
template<class T>
Set<T>::~Set()
{
    delete [] items;
}

template<class T>
void Set<T>::add(const T item)
{
    for (int i = 0; i < size; ++i) {
            if (items[i] == item) {
                return;
            }
        }

        // Allocate a new array with one more element
        T* new_items = new T[size + 1];

        // Copy the old items to the new array
        for (int i = 0; i < size; ++i) {
            new_items[i] = items[i];
        }

        // Add the new item to the end of the new array
        new_items[size] = item;

        // Free the old array and update the size and items pointer
        delete[] items;
        size++;
        items = new_items;
    
}
template<class T>
int Set<T>::getSize()
{
    return size;
}

template<class T>
T* Set<T>::getArray()
{
    T* array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = items[i];
        }
        return array;
}