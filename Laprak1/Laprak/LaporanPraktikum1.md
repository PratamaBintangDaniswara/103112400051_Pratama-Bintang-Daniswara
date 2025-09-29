# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">PRATAMA BINTANG DANISWARA - 103112400051</p>

## Dasar Teori
Struktur data adalah cara menyimpan dan mengatur data di memori komputer agar dapat digunakan secara efisien dalam pemrograman C++. Struktur data sederhana meliputi array, yang menyimpan data sejenis secara berurutan dengan indeks, serta struct yang memungkinkan pengelompokan data berbeda tipe dalam satu wadah. Struktur data majemuk terbagi menjadi linier, seperti stack (LIFO), queue (FIFO), dan linked list, serta non-linier seperti tree dan graph. Selain itu, terdapat Abstract Data Type (ADT) yang tidak hanya menyimpan data tetapi juga mendefinisikan operasi yang dapat dilakukan terhadapnya, misalnya stack, queue, dan set. Pemilihan struktur data yang tepat membantu membuat program lebih efisien, terstruktur, dan mudah dikembangkan.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;
    cout << "Angka yang dimasukan " << angka << endl;
    return 0;
}
```
Program akan mengeluarkan angka yang sudah di inputkan oleh pengguna

### 2. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka 1: ";
    cin >> angka1;
    cout << "Masukkan angka 2: ";
    cin >> angka2;

    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pengurangan: " << angka1 - angka2 << endl;
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 / angka2 << endl;
    cout << "sisa bagi: " << angka1 % angka2 << endl;

    return 0;
}
```
Program ini akan mengeluarkan hasil dari penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi dari angka yang telah di inputkan oleh pengguna

### 3. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2 ;
    cout << "Masukkan angka 1: ";
    cin >> angka1;                      
    cout << "Masukkan angka 2: ";
    cin >> angka2;

    if (angka1 < angka2){
    cout << angka1 << "kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if(angka1 == angka2) {
        cout << angka1 << "sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;   
    cout << "masukan pilihan: " << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "penjumlahan: " << angka1 + angka2 << endl;
            cout << endl;
            break;
        case 2:
        cout << "pengurangan: " << angka1 - angka2 << endl;
            cout << endl;
            break;
            default:
            cout << "pilihan tidak tersedia" << endl;
    }
    return 0;
}
```
Program ini pertama membandingkan dua angka untuk melihat apakah nilainya lebih kecil, lebih besar, atau sama, lalu memberi pilihan menu sederhana agar pengguna bisa menjumlahkan atau mengurangkan kedua angka tersebut, dan hasilnya langsung ditampilkan

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;
int main(){
    float a, b;
    cout << "bil pertama : ";
    cin >> a;
    cout << "bil kedua : ";
    cin >> b;

    cout << "penjumlahan : " << a + b << endl;
    cout << "pengurangan : " << a - b << endl;
    cout << "perkalian : " << a * b << endl;
    cout << "pembagian : " << a / b << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak1/Laprak/OutputUnguided1.png)

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
using namespace std;
int main() {
    int n;
    string satuan[] = {"", "satu", "dua", "tiga", "empat",
                       "lima", "enam", "tujuh", "delapan", "sembilan"};
    string puluhan[] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh",
                        "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    cin >> n;

    cout << n << " : ";

    if (n == 0) {
        cout << "nol";
    }
    else if (n == 100) {
        cout << "seratus";
    }
    else if (n < 10) {
        cout << satuan[n];
    }
    else if (n < 20) {
        if (n == 10) cout << "sepuluh";
        else if (n == 11) cout << "sebelas";
        else cout << satuan[n % 10] << " belas";
    }
    else {
        int p = n / 10;
        int s = n % 10;
        cout << puluhan[p];
        if (s != 0) cout << " " << satuan[s];
    }

    cout << endl;
    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak1/Laprak/OutputUnguided2.png)

Program ini dipakai untuk mengubah angka 0 sampai 100 menjadi kata. Ada aturan khusus untuk angka tertentu seperti 0, 10, 11, dan 100, sedangkan angka lain dibagi sesuai kelompoknya: 1–9 langsung dari array satuan, 12–19 ditulis dengan tambahan “belas”, dan 20–99 dipecah jadi puluhan dan satuan lalu digabungkan jadi kata.

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main(){
    int n; //n=3
    int a = 1;
    cin >> n;

    for (int i = n; i >= 1; i--)  //3
    {
        //cetak 321
        for (int j = i; j >= 1; j--) // 3 2 1
        {
            cout << j;
        }
        
        cout << "*";
        //cetak 123
        for (int j = 1; j <= i; j++)
        {
            cout << j ;
        }

        cout << endl;
        //spasi 
        for (int j = 1; j <= a; j++) //2 //3
        {
           cout << " ";
        }
        a = a + 1;

    }
    cout << "*";

}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak1/Laprak/OutputUnguided3.png)

Program ini membuat pola angka yang dicetak menurun dari n sampai 1, lalu diberi tanda *, kemudian dilanjutkan angka naik dari 1 sampai n. Setelah satu baris selesai, hasil cetakan digeser ke kanan dengan menambah spasi, dan di bagian akhir program menampilkan satu tanda * lagi, dan output akan menunjukan hasil seperti piramida terbalik

## Kesimpulan
Dari praktikum ini saya belajar cara memakai CodeBlocks IDE sekaligus mengenal dasar bahasa C++ mulai dari input–output, operasi aritmatika, percabangan, sampai perulangan. Latihan yang dikerjakan juga membantu saya memahami bagaimana logika program bekerja, misalnya menghitung bilangan, mengubah angka ke kata, dan membuat pola sederhana. Semua ini jadi bekal awal yang penting sebelum masuk ke materi struktur data yang lebih rumit.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>...
