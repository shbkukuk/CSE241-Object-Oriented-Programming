#include <iostream>
#include<cstdlib>
#include <ctime>
using namespace std;
int shootoran();
int shootbob();
int shootcharlie();
int main(){
    srand(time(0));
    bool aaronAlive = true, bobAlive = true, charlieAlive = true;
    int aaronWins = 0, bobWins = 0, charlieWins = 0;
    int numDuels = 0;
    while(numDuels!= 10000){
        if(aaronAlive&& bobAlive && charlieAlive){
            int shoot = shootoran();
            if (shoot == 1){
                charlieAlive = false;
                int shoot = shootbob();
                if (shoot = 1){
                    aaronAlive = false;
                    bobWins += 1;
                }
            }
            else {
                int shoot = shootbob();
                if (shoot == 1) {
                    charlieAlive = false;
                    int shoot = shootoran(); 
                    if (shoot ==1) {
                        bobAlive =false;
                        aaronWins += 1;
                    }
                    else {
                        int shoot = shootbob();
                        if (shoot  == 1){
                            aaronAlive = false;
                            bobWins = 1;
                        }
                    }
                }
            }

        }
        else {
            charlieWins += 1;
        }
        if (numDuels == 0){
            if (aaronWins == 1) {
                cout<< "Aaron win first game"<<endl;
            }
            if (charlieWins == 1) {
                cout<< "Charlie win first game"<<endl;
            }
            if (bobWins == 1) {
                cout<< "Bob win first game"<<endl;
            }
        }
        numDuels++;


    }
    double aaronProb = (double) aaronWins / numDuels;
    double bobProb = (double) bobWins / numDuels;
    double charlieProb = (double) charlieWins / numDuels;

    cout << "Probabilities of winning:" << endl;
    cout << "Aaron: " << aaronProb << endl;
    cout << "Bob: " << bobProb << endl;
    cout << "Charlie: " << charlieProb << endl;
    

}
int shootoran(){
    int random = rand() % 3 +1;
    if (random==1){
        return 1;
    }
    else {
        return 0;
    }
}
int shootbob(){
    int random = rand() % 2 + 1;
    if (random==1){
        return 1;
    }
    else {
        return 0;
    }
}
int shootcharlie(){
    return 1;
}