#include<iostream>
#include"Set.h"
#include"Set.cpp"
using namespace std;

int main()
{
    
    Set<int>s1;
    Set<string>s2;
    int* intArray=NULL;
    string* stringArray=NULL;
    int i;
    //Addsomesampleintegerstotheset
    s1.add(10);
    s1.add(20);
    s1.add(15);
    s1.add(20);
    intArray = s1.getArray();
    cout<<"Set one has"<<s1.getSize()
    <<"items Here they are:"<<endl;
    for(i=0;i<s1.getSize();i++)
    {
    cout<<intArray[i]<<endl;
    }
    if(intArray!=NULL)delete[]intArray;
    //Addsomesamplestringstotheset
    s2.add("butter");
    s2.add("hamburgers");
    s2.add("pizza");
    s2.add("hotdogs");
    s2.add("pizza");
    stringArray=s2.getArray();
    cout<<"Settwohas"<<s2.getSize()
    <<"items.Heretheyare:"
    <<endl;
    for(i=0;i<s2.getSize();i++)
    {
        cout <<stringArray[i]<<endl ;
    }
    if(stringArray!=NULL) delete [ ] stringArray;
    return 0 ;

}