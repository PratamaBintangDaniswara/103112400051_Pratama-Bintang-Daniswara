#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

Node* alokasi(int x) {
    Node* P = new Node;
    P->data = x;
    P->next = NULL;
    return P;
}

void insertFirst(List &L, Node* P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, Node* P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        Node* Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printList(List L) {
    Node* P = L.first;
    while (P != NULL) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}
