#include<iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Declariton values
string mod;
string secretNumber;
int digit;
string inputNumber;
int exact;
int misplaced;
// Declaraiton constant Values 
const int MAX_DIGIT = 9;
const int TRY_NUM = 100;

// Define methods  
string randNumber(int digitNumber);
//Generate random number respect to digit value
//return string number 
bool checkUnique(string secretNumber);
//Check number is unique 
//return boolen if number is unique true ,else false.
void E1(string number, int digit);
//Check error define in the assigment rules as E1
void E2(string number);
//Check error define in the assigment rules as E2
void E0(string mod,int digit,string secretNumber);
//Check error define in the assigment rules as E0

//Run code
int main(int argc, char** argv){
    srand(time(0)); // set valur for random numbers
    mod = string(argv[1]); // set mode from user input
    if (mod==string("-r")){
         digit = stoi(string(argv[2])); // set digit of number
         secretNumber = randNumber(digit); // create random number respect to digit
     }
     else if(mod==string("-u")){
        secretNumber = string(argv[2]); // set secret number from user
        digit = secretNumber.length(); // get digit from secretNumber for check it is valid
     }
     E0(mod,digit,secretNumber); // check E0 errors.
     E1(secretNumber,digit);// check E1 errors.
     E2(secretNumber);//check E2 errors. 
     
     int counter = 0; // set count 
     while(counter<TRY_NUM){
        exact =0; // set exact count number represent value that  check match in place of the secret number
        misplaced =0; // set misplaced count number represent value that  do exist in the secret number but are not in place
        cin>>inputNumber;
        E1(inputNumber,digit);// check E1 errors.
        E2(inputNumber);//check E2 errors. 

        for (int i=0;i<digit;i++){
            for(int j=0;j<digit;j++){
                if(secretNumber[i]==inputNumber[j]&& i == j){ //each digit number checks exact location in input number
                    exact++;
                }
                else if (secretNumber[i]==inputNumber[j]&& i != j){//each digit number checks in the input number but different location in input number
                    misplaced++;
                }

            }
        }
        counter++;
        if(exact==secretNumber.length()&&misplaced==0){
            //if User found number then program  exit and show user found in how many steps
            cout<<"User found number in "<<counter<<" iteration"<<endl;
            exit(1);

        }
        cout<<exact<<" "<<misplaced<<endl;
        // print exact and misplaced numbers

     }

    cout<<"FAILED"<<endl;
    // if user not found while iterations will be equal to TRY_NUM
    // print failed and exit. 
    return 0;

}

string randNumber(int digitNumber){
     // Generate a vector of digits 1 to 9
    vector<int> digits;
    for (int i = 1; i <= 9; i++) {
        digits.push_back(i);//assign item to vector 
    }
    // Shuffle the vector of digits randomly
    random_shuffle(digits.begin(), digits.end());//The function swaps the value of each element with that of some other randomly picked element

    // Choose the high-most digit from the shuffled vector, making sure it's not 0
    int first_digit = 0;
    while (first_digit == 0) {
        first_digit = digits.back();
        digits.pop_back();
    }
    // Add the remaining shuffled digits to the number
    first_digit = rand() % 9 + 1;
    int number = first_digit * pow(10, digitNumber-1);
    for (int i = 1; i < digitNumber; i++) {
        number += digits[i-1]* pow(10, digitNumber-1-i);
    }
    string screetNumber = to_string(number);
    return screetNumber;

}

bool checkUnique(string secretNumber){
    // check secret number is unique 
    int digit = secretNumber.length(); // declaration lenght of secret numbet to digit number
    for (int i=0;i<digit-1;i++){
        for(int j=i+1;j<digit;j++){
            if(secretNumber[i]==secretNumber[j]){//check there is any repeating number  12343563
                return true;//there has repeating number return true
            }

        }
    }

    return false;// there has not repeating number return false

}
void E0(string mod,int digit,string secretNumber){
    bool unique = checkUnique(secretNumber);// declaration unique boolen and assign result of checkUnique result
    if((mod!=string("-r")&&mod!=string("-u"))||(digit<=0||digit>9)||unique){//check errors 
        cout<<"E0"<<endl; // print Error type
        exit(1);// finish program
    }

}

void E1(string number,int digit){
    if (number.length()!=digit){ //check digit is equal to input number 
        cout<<"E1"<<endl; //print Error type
        exit(1);// finish program.
    }

}

void E2(string number){
    int numbers[] = {0,1,2,3,4,5,6,7,8,9}; // create int numbers array
    int digit = number.length();// declaration digit number and assign lenght of number
    for(int i = 0; i < digit ;i++){
        bool nonfound = true;// declaration nonfound param and assign true
        for(int num:numbers){
            if((int(number[i])-48)==num){//check number values is real number[0-9] 
                nonfound = false;
            }

        }
        if(nonfound){
            cout<<"E2"<<endl;//print Error type
            exit(1);// finish program
        }
    }
}