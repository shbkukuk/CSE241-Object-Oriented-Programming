#include<iostream>
#include "pfarrayd.h"
using std::cin;
using std::cout;
using std::endl;

void testPFArrayD();
//ConductsonetestoftheclassPFArrayD.
int main()
{
    cout<<"This program tests the classPFArrayD.\n";
    char ans;
    do
    {
        testPFArrayD();
        cout<<"Testagain?(y/n)";
        cin>>ans;
    }while((ans=='y')||(ans=='Y'));
    return 0;
}
void testPFArrayD()
{
    int cap;
    cout<<"Entercapacityofthissuperarray:";
    cin>>cap;
    PFArrayD temp(cap);
    cout<<"Enterupto"<<cap<<"nonnegativenumbers.\n";
    cout<<"Placeanegativenumberattheend.\n";
    double next;
    cin>>next;
    while((next>=0)&&(!temp.full()))
    {
        try{
            temp.addElement(next);
            cin>>next;
        }
        catch(OutOfRange e)
        {
            cout<<e.getMessage()<<" "<<e.getIndex()<<"\n";
            exit(0);
        }

        
    }
    cout<<"Youenteredthefollowing"
    <<temp.getNumberUsed()<<"numbers:\n";
    int index;
    int count=temp.getNumberUsed();
    for(index=0;index<count;index++)
    {
        try
        {
            cout<<temp[index]<<"";
            cout<<endl;
            cout<<"(plusasentinelvalue.)\n";
        }
        catch(OutOfRange e)
        {
            cout<<e.getMessage()<<" "<<e.getIndex()<<"\n";
            exit(0);
        }
        
        
    }
    //Testindexoutofrange
    try
    {
        cout<<temp[-1];//2∗count];
    }
    catch(OutOfRange e)
    {
        cout<<e.getMessage()<<" "<<e.getIndex()<<"\n";
        exit(0);
    }
    
    
    //Testinsertbeyonddeclaredsize
    try
    {
        temp.addElement(99999);
    }
    catch(OutOfRange e)
    {
        cout<<e.getMessage()<<" "<<e.getIndex()<<"\n";
        exit(0);
    }
    
    
};
