#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertBelakang(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->prev = NULL;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void hapusBelakang() {
    if (head == NULL) {
        return;
    } 
    else if (head == tail) { 
        delete head;
        head = NULL;
        tail = NULL;
    }
    else {
        Node* hapus = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete hapus;
    }
}

void tampilDariDepan() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void balikList() {
    Node* temp = head;
    Node* bantu = NULL;

    while (temp != NULL) {
        bantu = temp->prev;
        temp->prev = temp->next;
        temp->next = bantu;
        temp = temp->prev;   
    }

    if (bantu != NULL) {
        head = bantu->prev;
    }
}

int main() {
    int menu, nilai;

    do {cout << "1. insert, 2. delete, 3. view depan, 4. reverse & view depan, 0. exit\n";
        cin >> menu;

        if (menu == 1) {
            cin >> nilai;
            insertBelakang(nilai);
        }
        else if (menu == 2) {
            hapusBelakang();
        }
        else if (menu == 3) {
            tampilDariDepan();
        }
        else if (menu == 4) {
            balikList();
            tampilDariDepan();
        }

    } while (menu != 0);

    return 0;
}
