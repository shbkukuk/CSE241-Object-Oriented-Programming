#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); // Rastgele sayılar için zamanı kullanarak bir tohum oluşturun.
    int rastgeleSayi = rand() % 10 + 1; // 1-10 arasında rastgele bir sayı seçin.
    int tahmin; // Oyuncunun tahmin ettiği sayı.
    int tahminSayisi = 0; // Toplam tahmin sayısı.

    cout << "1-10 arasında bir sayı tahmin edin." << endl;

    do {
        cout << "Tahmininiz: ";
        cin >> tahmin;
        tahminSayisi++;

        if (tahmin < rastgeleSayi) {
            cout << "Daha yüksek bir sayı tahmin edin." << endl;
        } else if (tahmin > rastgeleSayi) {
            cout << "Daha düşük bir sayı tahmin edin." << endl;
        }
    } while (tahmin != rastgeleSayi);

    cout << "Tebrikler! " << tahminSayisi << " adımda doğru sayıyı tahmin ettiniz." << endl;

    return 0;
}