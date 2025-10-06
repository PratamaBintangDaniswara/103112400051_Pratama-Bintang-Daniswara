#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5, luas = 0, keliling = 0;
    int *ptrPanjang = &panjang, *ptrLebar = &lebar;

    cout << " Nilai Awal " << endl;
    cout << "Panjang: " << *ptrPanjang << endl;
    cout << "Lebar: " << *ptrLebar << endl << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));
    cout << " Hasil Perhitungan " << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));
    cout << " Nilai Setelah Diubah Melalui Pointer " << endl;
    cout << "Panjang Baru: " << *ptrPanjang << endl;
    cout << "Lebar Baru: " << *ptrLebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}
