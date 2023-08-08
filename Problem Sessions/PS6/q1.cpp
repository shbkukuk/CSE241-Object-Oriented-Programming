#include <iostream>
using namespace std;

class DynamicStringArray


{   
    public :
        DynamicStringArray();
        int getSize();
        void addEntry(string newValue);
        bool deleteEntry(string value);
        string getEntry(int index);
        DynamicStringArray(const DynamicStringArray &c);
        ~DynamicStringArray();
        void growArray();
        void decreaseArray(int index);
        DynamicStringArray& operator=(const DynamicStringArray &other);
    
    private:
        string *dynamicArray;
        int size;
        

};

int main()
{
    DynamicStringArray names;// List of names
    names.addEntry("Frank");
    names.addEntry("Wiggum");
    names.addEntry("Nahasapeemapetilon");
    names.addEntry("Quimby");
    names.addEntry("Flanders");
    // Output list
    cout << "List of names:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    // Add and remove some names
    names.addEntry("Spuckler");
    cout << "After adding a name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Nahasapeemapetilon");
    cout << "After removing a name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Skinner");
    cout << "After removing a name that isn't on the list:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.addEntry("Muntz");
    cout << "After adding another name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    // Remove all of the names by repeatedly deleting the last one
        while(names.getSize() > 0) 
        {
            names.deleteEntry(names.getEntry(names.getSize() - 1));
        }
        cout << "After removing all of the names:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
        names.addEntry("Burns");
        cout << "After adding a name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    cout << "Testing copy constructor" << endl;
    DynamicStringArray names2(names);
    // Remove Burns from names
    names.deleteEntry("Burns");
    cout << "Copied names:" << endl;
    for(int i = 0; i < names2.getSize(); i++)
        cout << names2.getEntry(i) << endl;cout << endl;
    cout << "Testing assignment" << endl;
    DynamicStringArray names3 = names2;
    // Remove Burns from names2
    names2.deleteEntry("Burns");
    cout << "Copied names:" << endl;
    for(int i = 0; i < names3.getSize(); i++)
        cout << names3.getEntry(i) << endl;
    cout << endl;
    cout << "Enter a character to exit." << endl;
    char wait;cin >> wait;
    return 0;
}


DynamicStringArray::DynamicStringArray(){
    dynamicArray = NULL;
    size =0;

}

int DynamicStringArray::getSize()
{
    return this->size;
}

void DynamicStringArray::addEntry(string newValue)
{
    
    growArray();
    dynamicArray[size] = newValue;
    size++;
}

void DynamicStringArray::growArray(){
    string *temp = new string[size+1];

    if (size!=0)
    {
        for(int i=0; i<size;i++){
            temp[i] = dynamicArray[i];

        }
    }
    delete[] dynamicArray;
    dynamicArray = temp;
}

bool DynamicStringArray::deleteEntry(string value)
{
    for(int i=0; i<size;i++)
    {
        if(dynamicArray[i]== value)
        {
            decreaseArray(i);
            return true;
        }
        
    }
    return false;
}

void DynamicStringArray::decreaseArray(int index)
{
    string *temp = new string[size-1];

    for(int j=0;j<size;j++)
    {
        if(j!=index){
            if(j<index){
                temp[j]= dynamicArray[j];
            }
            else{
                temp[j-1]=dynamicArray[j];
            }

        }
    }
    size--;
    delete dynamicArray;
    dynamicArray = temp;
}

string DynamicStringArray::getEntry(int index)

{
    if (index>size)
    {
        return "";
    }
    else{
        return dynamicArray[index];
    }
}

DynamicStringArray& DynamicStringArray::operator =(const DynamicStringArray &other)
{
    if(this->dynamicArray != NULL )
    {
        delete[] dynamicArray;
    }
    if(other.size ==0)
    {
        this->size =0;
        this-> dynamicArray = NULL;
    }
    else
    {
        this->size = other.size;
        this->dynamicArray = new string[size];
        for (int i=0; i<size; i++)
        {
            dynamicArray[i] = other.dynamicArray[i];
        }

    }
    return *this;
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray& c)
{
    this->size = c.size;
    if(size==0)
    {
        this->dynamicArray = NULL;
    }
    else
    {
        this->dynamicArray = new string[this->size];
        for(int i=0; i<size; i++)
        {
            dynamicArray[i] = c.dynamicArray[i];
        }
    }
}

DynamicStringArray::~DynamicStringArray()
{
    if (dynamicArray != NULL)
    {
        delete[] dynamicArray;
    }
}


