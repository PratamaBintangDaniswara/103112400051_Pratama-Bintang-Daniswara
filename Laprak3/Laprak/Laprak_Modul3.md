# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Pratama Bintang Daniswara - 103112400051</p>

## Dasar Teori
Abstrak Data Type (ADT) merupakan tipe data yang didefinisikan oleh pengguna dan dapat digunakan layaknya tipe data bawaan sistem, namun dengan struktur internal yang tidak terlihat oleh pengguna. Melalui konsep ini, data dapat dimanipulasi menggunakan operasi tertentu tanpa perlu mengetahui cara penyimpanan atau representasi internalnya [1]. ADT umumnya memiliki dua model utama, yaitu public functions yang dapat diakses dari luar dan private functions yang hanya digunakan di dalam strukturnya sendiri. Model ini menjadi dasar dalam pembentukan berbagai struktur data seperti list, queue, dan stack yang berperan penting dalam pengelolaan data pada suatu program [2]. 

## Guided
### 1. modular

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi tipe (struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

//deklarasi primitif(fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
```C++
#include<iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

 return 0;
}
```
Program ini dibuat secara terstruktur dengan konsep modular untuk mengelola data mahasiswa serta melakukan input dan perhitungan nilai 

### 2. non modular
```C++
#include <iostream>
using namespace std;
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

 return 0;
}
```
Program ini digunakan untuk menyimpan data mahasiswa berupa NIM dan dua nilai, kemudian menghitung serta menampilkan hasil rata-rata dari kedua nilai tersebut

## Unguided 
### 1. Program Menyimpan Data Mahasiswa

```C++
#include<iostream>
using namespace std;
struct Mhs{
    string nama, nim;
    float uts, uas, tugas, nilaiA;
};
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return(0.3*uts)+(0.4*uas)+(0.3*tugas);
}
int main() {
    Mhs mahasiswa[10];
    int a;
    cin >> a;

    for (int i = 0; i < a; i++){
        cout << "Data Mahasiswa ke " << i + 1 << endl;
        cout << "Nama :";
        cin >> mahasiswa[i].nama;
        cout << "Nim  :";
        cin >> mahasiswa[i].nim;
        cout << "Nilai Uts :";
        cin >> mahasiswa[i].uts;
        cout << "Nilai Uas :";
        cin >> mahasiswa[i].uas;
        cout << "Nilai Tugas :";
        cin >> mahasiswa[i].tugas;
        mahasiswa[i].nilaiA = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }
    cout << " Daftar Nilai Mahasiswa" << endl;
    cout << "No  Nama           Nim             UTS  UAS Tugas Nilai Akhir" << endl;
    for (int i = 0; i < a; i++) {
        cout << (i + 1) << "   "
             << mahasiswa[i].nama << "      "
             << mahasiswa[i].nim << "       "
             << mahasiswa[i].uts << "   "
             << mahasiswa[i].uas << "   "
             << mahasiswa[i].tugas << "   "
             << mahasiswa[i].nilaiA << endl;
    }
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![output_unguided1](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak3/Laprak/OutputUnguided1.png)

Program ini dipakai untuk input data sampai 10 mahasiswa, termasuk nama, NIM, dan nilai UTS, UAS, serta tugas. Setelah itu program menghitung nilai akhirnya dan menampilkan hasilnya dalam daftar

### 2. ADT
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran p);

#endif
```

```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}

void tampil_pelajaran(pelajaran p) {
    cout << "nama pelajaran : " << p.namaMapel << endl;
    cout << "nilai : " << p.kodeMapel << endl;
}

```

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![output_unguided2](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak3/Laprak/OutputUnguided2.png)

Program ini dipakai untuk nyimpan dan nampilin data pelajaran, kayak nama mata pelajaran dan kodenya, lewat fungsi buat data dan fungsi buat nampilin hasilnya


### 3.Program tukar Array dengan Pointer
```C++
#include <iostream>
using namespace std;

void tampil(int a[3][3], string n){
    cout<<n<<":"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void tukarArr(int a[3][3],int b[3][3],int r,int c){
    int t=a[r][c];
    a[r][c]=b[r][c];
    b[r][c]=t;
}

void tukarPtr(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}

int main(){
    int A[3][3],B[3][3];
    cout<<"Array A:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>A[i][j];
        }
    }
    cout<<"Array B:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>B[i][j];
        }
    }

    tampil(A,"A");
    tampil(B,"B");

    int r,c;
    cout<<"baris kolom: ";
    cin>>r>>c;
    tukarArr(A,B,r,c);

    tampil(A,"A");
    tampil(B,"B");

    int x,y;
    cout<<"x y: ";
    cin>>x>>y;
    tukarPtr(&x,&y);
    cout<<x<<" "<<y;
}
```
### Output Unguided 3 :

##### Output 1
![output_unguided3](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak3/Laprak/OutputUnguided3.png)

Program ini digunakan untuk menukar elemen pada dua array 3x3 berdasarkan posisi baris dan kolom yang dimasukkan, lalu juga menukar dua nilai menggunakan pointerarray B


## Kesimpulan
Pada praktikum modul 3 ini saya belajar tentang konsep Abstract Data Type (ADT) dan penerapannya dalam pemrograman modular menggunakan bahasa C++. Dari percobaan yang dilakukan, saya bisa memahami bagaimana cara membuat struktur data sendiri, memisahkan fungsi ke dalam file yang berbeda, serta mengelola data menggunakan pointer dan fungsi agar program jadi lebih efisien. Dengan menerapkan konsep modular, program menjadi lebih terstruktur, mudah dipahami, dan lebih gampang dikembangkan atau diperbaiki di kemudian hari

## Referensi
<br>[1] https://www.sciencedirect.com/topics/computer-science/abstract-data-type
<br>[2] https://www.scholarhat.com/tutorial/datastructures/abstract-data-type
