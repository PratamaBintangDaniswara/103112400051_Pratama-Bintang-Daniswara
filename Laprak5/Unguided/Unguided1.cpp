#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi Binary Search untuk Linked List (data harus terurut)
Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1;
    int step = 1;

    cout << endl << "Proses pencarian nilai " << key << ":" << endl;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Menelusuri node ke posisi tengah
        Node* temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        cout << "Iterasi " << step++ << ": posisi tengah = " << mid 
             << ", data = " << temp->data;

        if (temp->data == key) {
            cout << " -> Ditemukan!" << endl;
            cout << "Alamat node: " << temp << endl;
            cout << "Data node : " << temp->data << endl;
            if (temp->next != nullptr)
                cout << "Node berikutnya: " << temp->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return temp;
        } 
        else if (temp->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        } 
        else {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
    }

    cout << "Data " << key << " tidak ditemukan dalam linked list." << endl;
    return nullptr;
}

// Fungsi menampilkan seluruh isi linked list
void tampilList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Membuat linked list terurut
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    tampilList(head);

    // Pencarian pertama (data ada)
    int cari1 = 40;
    binarySearch(head, cari1);

    // Pencarian kedua (data tidak ada)
    int cari2 = 25;
    binarySearch(head, cari2);

    return 0;
}