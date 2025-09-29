#include <iostream>
using namespace std;

int main() {
    int angka1, angka2 ;
    cout << "Masukkan angka 1: ";
    cin >> angka1;                      
    cout << "Masukkan angka 2: ";
    cin >> angka2;

    if (angka1 < angka2){
    cout << angka1 << "kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if(angka1 == angka2) {
        cout << angka1 << "sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;   
    cout << "masukan pilihan: " << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "penjumlahan: " << angka1 + angka2 << endl;
            cout << endl;
            break;
        case 2:
        cout << "pengurangan: " << angka1 - angka2 << endl;
            cout << endl;
            break;
            default:
            cout << "pilihan tidak tersedia" << endl;
    }
    return 0;
}