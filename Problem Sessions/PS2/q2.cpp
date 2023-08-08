#include<iostream>
#include <cstring> 
using namespace std;

const int MAX_DIGITS = 20;
bool worker = true;

void readChar(int num[], int& size);
int chartoArr(char c);
void reverseArr(int arr[], int size);
void sumArr(int num1[], int size1, int num2[], int size2, int sum[], int& sizeSum);
void printNumbers(int num[], int size);
string answer;


int main(){
    while (worker){}
    {
        int num1[MAX_DIGITS], size1;
        int num2[MAX_DIGITS], size2;
        int sum[MAX_DIGITS + 1], sizeSum;

      
        cout << "Enter first number: ";
        readChar(num1, size1);

      
        cout << "Enter second number: ";
        readChar(num2, size2);

        
        sumArr(num1, size1, num2, size2, sum, sizeSum);

        cout << "The sum is: ";
        printNumber(sum, sizeSum);

        cout<<"do you want to calculate again ? "<<endl;
        cin>> answer;
        if (answer=='no'){
            worker = false;
            return 0;
        }

    }
    return 0;
    

}
int chartoArr(char c) {
    return c - '0';
}


void reverseArr(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}


void readChar(int num[], int& size) {
    char digits[MAX_DIGITS + 1];

    size = strlen(digits);
    if (size>20){
        cout<<"You should max 20 digit so please give numbers again"<<endl;
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        num[i] = chartoArr(digits[size - i - 1]);
    }
}


void printNumbers(int num[], int size) {
    if (size>20){
        cout<<"The sum of numbers overflow. Please give numbers again"<<endl;
        exit(1);
    }
    for (int i = size - 1; i >= 0; i--) {
        cout << num[i];
    }
    cout << endl;
}


void sumArr(int num1[], int size1, int num2[], int size2, int sum[], int& sizeSum) {
    
    memset(sum, 0, sizeof(sum));

    
    int carry = 0;
    int i = 0;
    while (i < size1 || i < size2 || carry != 0) {
        int digit1 = (i < size1) ? num1[i] : 0;
        int digit2 = (i < size2) ? num2[i] : 0;
        int digitSum = digit1 + digit2 + carry;
        sum[i] = digitSum % 10;
        carry = digitSum / 10;
        i++;
    }

    sizeSum = i;

    
    reverseArr(sum, sizeSum);
}