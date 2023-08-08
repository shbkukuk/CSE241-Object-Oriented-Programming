#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of suitors: ";
    cin >> n;

    vector<int> suitors(n);
    for (int i = 0; i < n; i++) {
        suitors[i] = i + 1;
    }

    
    int current = 0;
    while (suitors.size() > 1) {
        
        current = (current + 2) % suitors.size();
        suitors.erase(suitors.begin() + current);

        if (current == suitors.size()) {
            current = 0;
        }
    }

    cout << "The lucky winner is suitor number " << suitors[0] << endl;

    return 0;
}