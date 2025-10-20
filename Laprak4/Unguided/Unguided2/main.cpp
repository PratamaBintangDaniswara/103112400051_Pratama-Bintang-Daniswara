#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi(2));
    insertLast(L, alokasi(9));
    insertLast(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertLast(L, alokasi(0));

    deleteFirst(L);
    deleteLast(L);
    deleteFirst(L);

    createList(L);
    insertLast(L, alokasi(12));
    insertLast(L, alokasi(0));

    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
