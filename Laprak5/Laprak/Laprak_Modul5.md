# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua) </h1>
<p align="center">Pratama Bintang Daniswara - 103112400051</p>

## Dasar Teori
Linked list merupakan salah satu struktur data dinamis yang terdiri dari simpul-simpul (node) yang saling terhubung secara sekuensial melalui pointer, di mana setiap simpul menyimpan data dan alamat simpul berikutnya. Struktur ini memungkinkan pengelolaan data secara fleksibel, seperti penambahan, penghapusan, dan pencarian elemen tanpa harus menggunakan indeks seperti pada array. Dalam penerapannya, dikenal beberapa jenis linked list, yaitu singly linked list, doubly linked list, singly circular linked list, dan doubly circular linked list, yang masing-masing memiliki karakteristik hubungan antar simpul yang berbeda. Selain itu, terdapat berbagai operasi penting seperti insert, delete, update, dan retrieve untuk memanipulasi data di dalamnya. Dalam konteks pencarian data (searching), metode yang umum digunakan adalah sequential search dan binary search, di mana sequential search melakukan pencarian secara berurutan dari awal hingga akhir data, sedangkan binary search membagi ruang pencarian menjadi dua bagian secara berulang, namun hanya dapat diterapkan pada data yang telah terurut. Konsep-konsep tersebut menjadi dasar penting dalam pemahaman struktur data dan algoritma, sebagaimana dijelaskan dalam beberapa referensi seperti modul Struktur Data Universitas Negeri Malang [1], serta artikel dari STKIP Persada Khatulistiwa dan Medium [2][3]

## Guided
### 1. Linked list dengan operasi insert dan update 

### main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;
}   
```

### listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}
void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
### listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H

#define Nil NULL
#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

// ==== DEKLARASI / PROTOTYPE ====
bool isEmpty(linkedlist List);
void createList(linkedlist &List);

address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void printList(linkedlist List);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// === Fungsi update data ===
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address nodePrev);

#endif
```
Program ini dibuat untuk mengelola data buah dengan menggunakan struktur data Singly Linked List, yaitu kumpulan simpul (node) yang saling terhubung satu sama lain secara berurutan. Setiap simpul menyimpan informasi nama, jumlah, dan harga buah. Program ini bisa menambahkan data baru ke dalam list, mengubah data yang sudah ada, serta menghapus data tertentu tanpa harus memindahkan elemen lain seperti pada array biasa. Selain itu, program juga bisa menampilkan seluruh isi list dan menghitung berapa banyak data yang tersimpan di dalamnya. Secara keseluruhan, program ini memperlihatkan cara kerja linked list dalam menyimpan dan memanipulasi data secara dinamis dan efisien

### 2. Linked List linear dan binary

### binary.cpp
```C++
#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi binary search untuk linked list (data harus terurut)
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* binarySearch(Node* head, int key) {
    int length = getLength(head);      // Hitung panjang list
    int left = 0;
    int right = length - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Cari posisi tengah
        
        // Traverse ke posisi mid
        Node* temp = head;
        for(int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        
        if(temp->data == key) {           // Jika ditemukan
            return temp;
        }
        else if(temp->data < key) {       // Cari di bagian kanan
            left = mid + 1;
        }
        else {                            // Cari di bagian kiri
            right = mid - 1;
        }
    }
    return nullptr;                       // Tidak ditemukan
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan elemen terurut ke linked list (penting untuk binary search!)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    int key = 30;  // Nilai yang dicari
    Node* result = binarySearch(head, key); // Panggil fungsi binary search

    if(result != nullptr) {
        cout << "Nilai " << key << " ditemukan dalam linked list." << endl;
    } else {
        cout << "Nilai " << key << " tidak ditemukan dalam linked list." << endl;
    }

    return 0;
}
```

### linear.cpp
```C++
#include <iostream>
using namespace std;

struct Node { 
    int data;
    Node* next;
};

Node *linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Kedua program ini sama-sama menggunakan linked list untuk mencari data, tapi dengan cara yang berbeda. Program linear search mencari data satu per satu dari awal sampai akhir list, sedangkan binary search mencari dengan cara membagi dua bagian pencarian secara berulang, namun hanya bisa digunakan jika datanya sudah terurut. Linear search lebih mudah diterapkan, sementara binary search sebenarnya lebih cepat, tapi pada linked list tetap butuh waktu karena harus menelusuri simpul satu per satu untuk menemukan posisi tengah

## Unguided 

### 1.Binary Search

```C++
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
```

### Output Unguided 1 :

##### Output 1
![op1](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak5/Laprak/OutputUnguided1.png)

Program ini memakai linked list yang tersusun rapi dan menggunakan metode binary search untuk mencari nilai tertentu. Selama proses pencarian, program menampilkan langkah-langkahnya seperti posisi tengah, nilai yang dicek, dan alamat node yang ditemukan agar pengguna bisa lebih mudah memahami jalannya pencarian

### 2. Linear search

```C++
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
```
### Output Unguided 2 :

##### Output 1
![op2](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak5/Laprak/OutputUnguided2.png)

Program ini menggunakan metode Linear Search pada Linked List untuk mencari nilai tertentu dengan memeriksa setiap node satu per satu dari awal hingga akhir. Jika data yang dicari ditemukan, program menampilkan alamat memori, nilai data, dan node setelahnya. Namun, jika tidak ditemukan, program akan memberi tahu bahwa data tersebut tidak ada dalam daftar

## Kesimpulan
Melalui praktikum ini kita bisa memahami bagaimana Linked List bekerja sebagai struktur data yang dinamis untuk menyimpan dan mengelola data. Berbagai operasi seperti menambah, menghapus, dan memperbarui data dapat dilakukan dengan mudah tanpa perlu indeks seperti pada array. Selain itu, percobaan juga menunjukkan perbedaan antara Linear Search yang mencari data satu per satu dan Binary Search yang mencari dengan membagi dua bagian secara berulang. Dari sini bisa disimpulkan bahwa setiap metode pencarian memiliki kelebihan masing-masing tergantung pada kondisi data yang digunakan

## Referensi
<br>[1] https://elektro.um.ac.id/wp-content/uploads/2016/04/ASD-Modul-6-Linked-List.pdf
<br>[2] https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pdf
<br>[2] https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[3] https://daismabali.medium.com/metode-searching-dalam-struktur-data-dan-implementasi-pemrogramannya-d97582084866
