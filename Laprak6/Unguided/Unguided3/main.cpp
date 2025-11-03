#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;
    string hapusNopol; 

    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);

    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol; 

    deleteByNopol(L, hapusNopol);

    cout << endl << "DATA LIST 1" << endl;
    printInfo(L); 

    return 0;
}