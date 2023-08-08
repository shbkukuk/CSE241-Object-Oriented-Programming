#include<iostream>
#include "pfarrayd.h"
using std::string;

OutOfRange::OutOfRange(string thisMessage,int thisIndex)
{
    this->message = thisMessage;
    this->index = thisIndex;
}

string OutOfRange::getMessage() const
{
    return message;
}

int OutOfRange::getIndex() const
{
    return index;
}

PFArrayD::PFArrayD()
{
    this->capacity=10;
    this->used = 0;
    a = new double[capacity];

}

PFArrayD::PFArrayD(int capacityValue)
{
    this->capacity = capacityValue;
    this->used = 0;
    a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD&pfaObject)
{
    this->capacity = pfaObject.getCapacity();
    this->used = pfaObject.getNumberUsed();
    if(capacity!=0)
    {
        a = new double[capacity];
        for(int i = 0; i<capacity;i++)
        {
            a[i]=pfaObject.a[i];
        }

    }
    
}

void PFArrayD::addElement(double element)
{
    if(element>=capacity)
    {
        throw(OutOfRange("OutOfRange",element));
    }
    used++;
    a[used]=element;
}
double& PFArrayD::operator[](int index)
{
    if(index>=capacity)
    {
        throw(OutOfRange("OutOfRange",index));
    }
    return a[index];
}



PFArrayD::~PFArrayD()
{
    this->capacity = 0;
    this->used = 0;
    delete [] a;
}