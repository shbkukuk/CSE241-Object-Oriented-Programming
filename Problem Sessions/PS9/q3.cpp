#include<iostream>
#include"stack.h"
#include"stack.cpp"

using namespace std;

int main()
{
    Stack<int> a;
    try
    {
        cout<<a.pop()<<endl;
    }
    catch(PopEmptyStackException)
    {
            cout<< "Stack is empty, You can not arrive top of stack"<<endl;
            exit(1);
    }

    return 0;
    
}