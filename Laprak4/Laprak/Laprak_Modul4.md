# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama) </h1>
<p align="center">Pratama Bintang Daniswara - 103112400051</p>

## Dasar Teori
Linked list merupakan salah satu bentuk struktur data dinamis yang terdiri atas sejumlah simpul (node) yang saling terhubung secara berurutan melalui pointer. Setiap simpul memiliki dua bagian utama, yaitu data yang menyimpan nilai dan pointer yang menunjuk ke simpul berikutnya. Dengan struktur seperti ini, proses penambahan maupun penghapusan data dapat dilakukan lebih fleksibel tanpa harus menggeser elemen lain di dalam memori. Beberapa operasi dasar pada linked list meliputi penambahan data baru (insert), pengecekan apakah list kosong (isEmpty), pencarian elemen pertama maupun berikutnya (find first dan find next), pengambilan isi simpul tertentu (retrieve), pembaruan nilai (update), serta penghapusan simpul (delete now, delete head, dan clear). Berdasarkan arah keterhubungannya, linked list terbagi menjadi beberapa jenis, yaitu singly linked list yang setiap simpulnya hanya memiliki satu arah ke simpul berikut, doubly linked list yang memiliki dua pointer untuk bergerak maju dan mundur, singly circular linked list di mana simpul terakhir kembali menunjuk ke simpul pertama, serta doubly circular linked list yang memiliki hubungan dua arah dan melingkar antar simpul [1][2]

## Guided
### 1. Insert Operations

### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

### list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
Program ini dibuat untuk menampilkan cara kerja singly linked list dalam menyimpan dan mengelola data mahasiswa secara terhubung dan terstruktur.

### 2. Linked List Insert and Delete Operations
### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
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

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
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
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
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
    cout << "List sudah terhapus!" << endl;
}


```

### list.h
```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

```
Program ini menunjukkan cara kerja singly linked list dalam menambah dan menghapus data, sekaligus menghitung jumlah node dan mengosongkan seluruh list.

## Unguided 
### 1. ADT Singly Linked List

### main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi(2));
    insertLast(L, alokasi(9));
    insertLast(L, alokasi(8));
    insertFirst(L, alokasi(12));

    cout << "List awal: ";
    printList(L);

    return 0;
}

```

### singlylist.cpp
``` C++
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
```

### singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* P);
void insertLast(List &L, Node* P);
void printList(List L);

#endif
```


### Output Unguided 1 :

##### Output 1
![soal 1](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak4/Laprak/OutputUnguided1.png)

Pada bagian ini program membuat sebuah singly linked list dengan menambahkan data menggunakan fungsi insertFirst() dan insertLast(), lalu menampilkannya lewat printList(). Hasil akhirnya menunjukkan data 12, 2, 9, dan 8 berhasil tersusun dalam list


### 2. Penghapusan node

### main.cpp
```C++
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
```

### singlylist.cpp
```C++
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
```

### singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* P);
void insertLast(List &L, Node* P);
void deleteFirst(List &L);
void deleteLast(List &L);
int nbList(List L);
void deleteList(List &L);
void printList(List L);

#endif
```
### Output Unguided 2 :

##### Output 1
![soal 2](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak4/Laprak/OutputUnguided2.png)

Pada bagian ini program melakukan penghapusan data pada list menggunakan deleteFirst(), deleteLast(), dan deleteList(), kemudian menghitung jumlah node dengan nbList(). Hasil akhirnya memperlihatkan bahwa list berhasil diperbarui dan semua data telah terhapus.





## Kesimpulan
Dari praktikum ini saya belajar bagaimana singly linked list bekerja dan bagaimana cara mengelola data secara dinamis menggunakan pointer. Saya jadi paham bahwa setiap data dihubungkan melalui simpul (node) yang saling terhubung, sehingga proses menambah atau menghapus data bisa dilakukan dengan mudah tanpa harus memindahkan seluruh elemen seperti pada array. Selain itu, saya juga mempelajari berbagai operasi dasar seperti menambah data (insert), menghapus data (delete), menghitung jumlah node, dan mengosongkan seluruh list. Melalui praktik ini, saya jadi lebih mengerti cara kerja memori dinamis di C++ dan pentingnya ketelitian dalam menggunakan pointer agar program berjalan dengan benar. Secara keseluruhan, praktikum ini membantu saya memahami konsep dasar struktur data dinamis dan penerapannya dalam pemrograman nyata.

## Referensi
<br>[1] https://elektro.um.ac.id/wp-content/uploads/2016/04/ASD-Modul-6-Linked-List.pdf
<br>[2] https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pdf
<br>[2] https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
