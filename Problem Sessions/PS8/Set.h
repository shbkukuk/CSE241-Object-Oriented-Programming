#ifndef SET_H
#define SET_H
#include <iostream>

using namespace std;


template<class T>
class Set
{   
    public:
        Set();
        ~Set();
        void add(const T item);
        int getSize();
        T* getArray();

    private:
        int size;
        T* items;

};

#endif