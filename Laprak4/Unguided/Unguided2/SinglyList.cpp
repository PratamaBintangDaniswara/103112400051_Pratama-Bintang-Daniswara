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

void deleteFirst(List &L) {
    if (L.first != NULL) {
        Node* P = L.first;
        L.first = P->next;
        delete P;
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            delete L.first;
            L.first = NULL;
        } else {
            Node* Q = L.first;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            delete Q->next;
            Q->next = NULL;
        }
    }
}

int nbList(List L) {
    int jumlah = 0;
    Node* P = L.first;
    while (P != NULL) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
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
