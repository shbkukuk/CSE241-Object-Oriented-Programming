#include <iostream>
using namespace std;

class HotDogStand{
    public:
        int ID;
        int sold;
        static int totalOfSold;
        HotDogStand(int IDnumber, int soldNumber);
        void JustSold();
        int numberOfSold();
        static int getTotalOfSold();
        

};
int HotDogStand::totalOfSold = 0;
HotDogStand::HotDogStand(){
    ID = 0;
    sold = 0;
}
HotDogStand::HotDogStand(int IDnumber, int soldNumber){
            ID = IDnumber;
            sold = soldNumber;

        }

int main(){
    int soldStand1=0,soldStand2=0,soldStand3=0;
    HotDogStand stand1(1,0);
    HotDogStand stand2(2,0);
    HotDogStand stand3(3,0);
    for(int i=0; i<10;i++){
        stand1.JustSold();
        soldStand1 = stand1.numberOfSold();
        
        
        cout<<"Stand 1 sold "<<soldStand1<<"number of sold total is"<<soldStand1+soldStand2+soldStand3<<endl;

        stand2.JustSold();
        soldStand2 = stand2.numberOfSold();
        
        cout<<"Stand 2 sold "<<soldStand2<<"number of sold total is"<<soldStand1+soldStand2+soldStand3<<endl;

        stand3.JustSold();
        soldStand3 = stand3.numberOfSold();
        
        cout<<"Stand 3 sold "<<soldStand3<<"number of sold total is"<<soldStand1+soldStand2+soldStand3<<endl;
    }

    return 0;
    
}

void HotDogStand::JustSold(){
    sold++;
}
int HotDogStand::numberOfSold(){
    return sold;
}
int HotDogStand::getTotalOfSold(){
    return totalOfSold;
}