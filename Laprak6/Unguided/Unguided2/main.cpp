#include "Doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;

    data = {"D001", "Hitam", 90};
    P = alokasi(data);
    insertLast(L, P);

    data = {"D002", "Putih", 70};
    P = alokasi(data);
    insertLast(L, P);

    data = {"D003", "Merah", 80};
    P = alokasi(data);
    insertLast(L, P);
    
    data = {"D004", "Kuning", 90};
    P = alokasi(data);
    insertLast(L, P);
    string nopolCari;
    cout << "Masukkan Nomor Polisi yang dicari : " ;
    cin >> nopolCari;    
    address hasilCari = findElm(L, nopolCari);
    if (hasilCari != Nil) {
        cout << endl << "Nomor Polisi : " << hasilCari->info.nopol << endl ;
        cout << "Warna        : " << hasilCari->info.warna << endl;
        cout << "Tahun        : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Nomor Polisi " << nopolCari << " tidak ditemukan." << endl;
    }   
    return 0;
}