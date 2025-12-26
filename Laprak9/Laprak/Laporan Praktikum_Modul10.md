# <h1 align="center">Laporan Praktikum Modul 10 - Tree </h1>
<p align="center">Pratama Bintang Daniswara - 103112400051</p>

## Dasar Teori
Struktur data Tree merupakan struktur data non-linear yang digunakan untuk menyusun data secara hierarkis, berbeda dengan Array, Linked List, dan antrian yang menyimpan data secara linear dalam satu urutan [1], [2]. Pada Tree, terdapat satu simpul utama yang disebut root yang menjadi titik awal, kemudian data berkembang ke simpul-simpul turunan sehingga membentuk cabang. Implementasi Tree memanfaatkan alokasi memori dinamis seperti pada Linked List, sehingga ukurannya dapat bertambah sesuai kebutuhan dan tidak terikat batas tetap seperti Array yang berpotensi mengalami overflow [3]. Setiap simpul pada Tree dapat memiliki lebih dari satu pointer untuk menghubungkan ke simpul anak, yang memungkinkan pembentukan struktur bertingkat. Salah satu bentuk Tree yang umum digunakan adalah Binary Search Tree (BST), yang menerapkan aturan pengurutan khusus sehingga proses pencarian data dapat dilakukan secara lebih efisien, dengan kompleksitas waktu ideal O(log n), dibandingkan pencarian pada struktur data linear yang membutuhkan waktu O(n) [1].

## Guided

### 1. Guided1
## Rekursif_pangkat2.cpp
```C++
#include<iostream>
using namespace std;

int pangkat_2(int x) {//adalah pengkatnya
    if(x == 0) {//basis
        return 1;
    } else if (x > 0) {//rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukkan nilai x: "; 
    cin >> x;
    cout << endl;
    cout << " pangkat 2 dari " << x << " adalah : " << pangkat_2(x) ;

    return 0;
}
```
Program ini mengimplementasikan konsep rekursi untuk menghitung pangkat 2, di mana perhitungan dilakukan dengan memanggil fungsi secara berulang hingga mencapai kondisi dasar.

### 2. Guided2
## BST1.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data interger
typedef struct Node* address; //alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan(integer)
    address left; // pointer left
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam BST

//traversal
void preOrder(address root); //function traversal tree secara pre-order (tengah - kiri - kanan atau root - childkiri - childkanan)
void inOrder(address root); //function traversal tree secara in-order (kiri - tengah - kanan atau childkiri - root - childkanan)
void postOrder(address root); //function traversal tree secara post-order (kiri - kanan - tengah atau childkiri - childkanan - root)

//utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

#endif
```
## BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
## main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program ini mengimplementasikan Binary Search Tree (BST) yang mendukung proses insert data, traversal tree, serta perhitungan jumlah node dan kedalaman tree.

### 3. Guided3
## BST2.h
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>

using namespace std;

typedef int infotype;//alias infotype untuk data integer
typedef struct Node *address;//alias address untuk pointer ke struct Node (*Node)
typedef struct Node {
    infotype info;//data integer yang disimpan
    address left;//pointer ke anak kiri
    address right;//pointer ke anak kanan
} Node;

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah tree kosong
void createTree(address &root); //function untuk membuat tree kosong

//alokasi &insertBST
address newNode(infotype x); //function untuk memasukkan data(infotype) ke dalam node baru
address insertNode(address root, infotype x); //function untuk memasukkan node baru ke dalam BST

//Traversal
void preOrder(address root); //function traversal tree secara preOrder (tengah -> kiri -> kanan atau root -> child kiri -> child kanan)
void inOrder(address root); //function traversal tree secara inOrder (kiri -> tengah -> kanan atau child kiri -> root -> child kanan)
void postOrder(address root); //function traversal tree secara postOrder (kiri -> kanan -> tengah atau child kiri -> child kanan -> root)

//Utility
int countNodes(address root); //function untuk menghitung size atau ukurun atau jumlah node yang ada pada tree
int treeDepth(address root); //function untuk menghitung depth atau kedalaman atau level tree

//FUNCTION & Prosedur Baru
//searching
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

// Mostleft & Mostright
address mostLeft(address root); //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
address mostRight(address root); //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
void deleteTree(address &root); //prosedur untuk menghapus seluruh node yang ada didalam BST



#endif
```
## BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
## main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }
    return 0;
}
```
Program ini mengelola Binary Search Tree (BST) secara lebih lengkap, mulai dari menambahkan data, menampilkan isi tree, mencari data tertentu, mengetahui nilai terkecil dan terbesar, hingga menghapus node maupun seluruh isi tree dengan cara yang terstruktur dan mudah dipahami.

## Unguided 

### 1. Unguided 1 :

## bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;

typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
} Node;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif
```
## bstree.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } else if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
```
## main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    address root = NULL;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    printInorder(root);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak9/Laprak/OutputUnguided1.png)

Program ini digunakan untuk menyimpan dan mengelola data dalam bentuk Binary Search Tree (BST), di mana data dimasukkan secara terurut, bisa dicari kembali, dan ditampilkan dari nilai terkecil ke terbesar menggunakan traversal InOrder.

### 2. Unguided 2 :
## bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;
typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
} Node;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif

```
## bstree.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } else if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    } else {
        int kiri = hitungJumlahNode(root->left);
        int kanan = hitungJumlahNode(root->right);
        int total = 1 + kiri + kanan;
        return total;
    }
}

int hitungTotalInfo(address root, int start) {
    if (root == NULL) {
        return 0;
    } else {
        int kiri = hitungTotalInfo(root->left, start);
        int kanan = hitungTotalInfo(root->right, start);
        int total = root->info + kiri + kanan;
        return total;
    }
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) {
        return start;
    }

    int kiri  = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    if (kiri > kanan) {
        return kiri;
    } else {
        return kanan;
    }
}
```
## main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    address root = NULL;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    printInorder(root);
    cout << "\n";
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak9/Laprak/OutputUnguided2.png)

Program ini dipakai untuk menyimpan dan mengatur data angka dalam bentuk Binary Search Tree (BST). Data dimasukkan secara otomatis mengikuti aturan BST, lalu bisa ditampilkan berurutan, dihitung jumlah datanya, dijumlahkan seluruh nilainya, dan diketahui seberapa dalam struktur tree yang terbentuk.

### 3. Unguided 3 :

## bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;
typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
} Node;

address alokasi(infotype x);
void insertNode(address &root, infotype x);

void printPreOrder(address root);
void printPostOrder(address root);

#endif 
```
## bstree.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void printPreOrder(address root) {
    if (root != NULL) {
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}
```
## main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = NULL;
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "PreOrder  : ";
    printPreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    printPostOrder(root);
    cout << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak9/Laprak/OutputUnguided3.png)

Program ini membuat Binary Search Tree sederhana untuk menyimpan angka. Setiap angka dimasukkan ke posisi yang benar. Setelah itu, isi tree ditampilkan dengan dua cara, yaitu PreOrder untuk melihat urutan dari root dulu, dan PostOrder untuk melihat urutan dari child dulu baru ke root.

## Kesimpulan
Praktikum ini nunjukin kalau Binary Search Tree (BST) itu cara yang rapi dan efisien buat nyimpen data. Kita bisa masukin data, nyari, nampilin (preorder, inorder, postorder), sampai ngitung jumlah node dan kedalaman tree dengan logika yang jelas. Jadi, BST bikin pengolahan data jadi lebih terstruktur dan gampang dipahami dibanding struktur data biasa.

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006
