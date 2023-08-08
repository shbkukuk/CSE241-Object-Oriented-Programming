#include <iostream>
#include <cmath>
using namespace std; 

class MyInteger{
    private : 
        int x;
    public :
    // define methods
        void Set(int x);
        int Get();
        int operator[](int x); //define overload function as member of class 
        MyInteger(int X);
};


int main(){
    MyInteger num(12046);
    cout << num[1] << " " << num[2] << " " << num[3] << endl;
    cout << num[4] << endl;cout << num[5] << endl;
    return 0;

}
MyInteger::MyInteger(int X){ // define class initalize
    x = X;

}

void MyInteger::Set(int x){ // set value x as member of MyInteger
    this->x = x;
}
int MyInteger::Get(){ // get value x 
    return x;
}

int MyInteger::operator[](int index){
    if (index < 0) return -1; // if index lower than zero return -1
    int digit = 0;
    int temp = x;
    while (temp > 0 && digit <= index) {
        if (digit == index) return temp % 10;//first index must be equal to units digit so if index equal to zero return mod 10 of value.
        temp /= 10;//i reassign temp number without units digits 
        digit++;// i increase
    }
    return -1;
}