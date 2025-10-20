#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(9));
    insertLast(L, alokasi(12));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(0));
    insertLast(L, alokasi(2));

    printList(L);

    return 0;
}
