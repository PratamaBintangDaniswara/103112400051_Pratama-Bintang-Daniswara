#include <iostream>
using namespace std;

struct Node { 
    int data;              // Menyimpan nilai data
    Node* next;            // Pointer ke node berikutnya
};

void append(Node*& head, int value) {   // Menambahkan node di akhir linked list
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void tampilList(Node* head) {           // Menampilkan seluruh elemen linked list
    Node* temp = head;
    cout << "Linked List yang dibuat: ";
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

Node* linearSearch(Node* head, int key) {   // Mencari nilai menggunakan linear search
    Node* current = head;
    int posisi = 1;
    cout << endl << "Mencari nilai: " << key << endl;
    cout << endl << "Proses Pencarian:" << endl;

    while (current) {
        cout << "Memeriksa node ke-" << posisi << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) -> DITEMUKAN!" << endl;
            cout << endl << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            if (current->next)
                cout << "Node berikutnya: " << current->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        current = current->next;
        posisi++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << endl << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;                            // Inisialisasi linked list kosong
    append(head, 10);                                // Menambahkan elemen ke linked list
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    tampilList(head);

    linearSearch(head, 30);                          // Pencarian pertama (data ditemukan)
    linearSearch(head, 25);                          // Pencarian kedua (data tidak ditemukan)

    return 0;
}
