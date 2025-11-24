# <h1 align="center">Laporan Praktikum Modul 8 - Queue </h1>
<p align="center">Pratama Bintang Daniswara - 103112400051</p>

## Dasar Teori
Queue adalah struktur data linear yang bekerja dengan prinsip FIFO (First-In, First-Out), di mana elemen yang pertama masuk akan menjadi elemen pertama yang diproses. Operasi utamanya terdiri dari enqueue yang menambahkan data di bagian rear dan dequeue yang menghapus data dari front. Struktur ini dapat diimplementasikan menggunakan Array maupun Linked List. Implementasi Array bersifat statis sehingga kapasitasnya terbatas dan berpotensi menimbulkan overflow atau ruang kosong yang tidak termanfaatkan jika tidak menggunakan mekanisme circular. Sementara itu, implementasi dengan Linked List bersifat dinamis dan memungkinkan penyesuaian ukuran secara fleksibel, sekaligus membuat operasi enqueue dan dequeue berlangsung efisien dengan waktu akses konstan O. Pendekatan dinamis ini lebih sesuai untuk sistem yang memerlukan pengelolaan antrian secara berkelanjutan.
## Guided

### 1. Guided1
## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
} ;

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchQueue(queue Q, int data);

#endif
```
## Queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchQueue(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
## main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah updateQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchQueue(Q, 4);
    searchQueue(Q, 9);

    return 0;
}
```
Program ini membuat Queue dinamis dengan Linked List, menambah data di tail, menghapus dari head, dan memanipulasi pointer untuk menjalankan operasi antrian sesuai prinsip FIFO.

### 2. Guided2
## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
## Queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
## main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Program ini membangun queue statis berbasis array yang menambah data dari bagian belakang dan mengambil data dari bagian depan dengan teknik circular, sehingga pemakaian ruang lebih efisien.

## Unguided 

### 1. Alternatif 1 (head diam, tail bergerak)

## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
## Queue.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "---------------------------------" << endl;
    cout << " H - T \t : Queue Info" << endl;
    cout << "---------------------------------" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
## main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "---------------------------------" << endl;
    cout << " H - T \t : Queue Info" << endl;
    cout << "---------------------------------" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak8/Laprak/OutputUnguided1.png)

Program ini membuat queue berukuran lima elemen dan menjalankan operasi dasar seperti tambah, hapus, dan tampil, lalu menunjukkan perubahan head, tail, dan isi antrian setelah setiap langkah.

### 2. Alternatif 2 (head bergerak, tail bergerak)
## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif 
```
## Queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue Empty" << endl;
    } else {
        val = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++; 
        }
    }
    return val;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " \t : ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
## main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "---------------------------------" << endl;
    cout << " H - T \t : Queue Info" << endl;
    cout << "---------------------------------" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak8/Laprak/OutputUnguided2.png)

Program ini mengimplementasikan ADT Queue berbasis array dengan pergerakan head dan tail yang diatur otomatis oleh program sesuai operasi tambah, hapus, dan tampil, sehingga perubahan isi antrian bisa terlihat setelah setiap langkah dijalankan.

### 3. Alternatif 3 (head dan tail berputar)
## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
## Queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % 5;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue Empty" << endl;
    } else {
        val = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head = (Q.head + 1) % 5;
        }
    }
    return val;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " \t : ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) {
                break; 
            }
            i = (i + 1) % 5;
        }
    }
    cout << endl;
}
```
## main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "---------------------------------" << endl;
    cout << " H - T \t : Queue Info" << endl;
    cout << "---------------------------------" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak8/Laprak/OutputUnguided3.png)

Program ini mengimplementasikan ADT Queue menggunakan array dengan mekanisme circular, di mana head dan tail bergerak melingkar menggunakan operasi modulo sehingga indeks kembali ke awal saat mencapai batas, dan seluruh proses enqueue, dequeue, serta penampilan isi antrian mengikuti pergerakan melingkar tersebut.

## Kesimpulan
Praktikum ini menyimpulkan bahwa struktur data Queue bekerja dengan prinsip FIFO, di mana elemen pertama yang masuk menjadi elemen pertama yang keluar. Implementasi Queue menggunakan Linked List memberikan fleksibilitas dan efisiensi karena hanya membutuhkan manipulasi pointer tanpa batasan ukuran. Sementara itu, implementasi berbasis Array menunjukkan perbedaan performa yang signifikan; metode kepala tetap kurang efisien karena membutuhkan pergeseran elemen, sedangkan Circular Queue jauh lebih optimal karena memungkinkan head dan tail bergerak secara melingkar tanpa shifting. Secara keseluruhan, praktikum ini menegaskan bahwa pemilihan metode implementasi Queue sangat memengaruhi efisiensi operasi enqueue dan dequeue.

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006
