#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype data;
    address P;
    string nopolInput;

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        if (findElm(L, data.nopol) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(data);
            insertLast(L, P);
        }
        cout << endl;
    }

    printInfo(L);
    return 0;
}
