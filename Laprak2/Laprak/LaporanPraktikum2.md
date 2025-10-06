# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++  (Bagian Kedua)</h1>
<p align="center">Pratama Bintang Daniswara - 103112400051</p>

## Dasar Teori
Array adalah variabel yang digunakan untuk menyimpan sekumpulan data dengan tipe yang sama, sehingga memungkinkan kita mengelompokkan banyak nilai dalam satu nama variabel. Setiap nilai di dalam array disimpan secara berurutan pada lokasi memori yang berbeda dan disebut sebagai elemen array [1]. Dalam bahasa C++, terdapat pula konsep penting bernama pointer, yaitu variabel yang menyimpan alamat memori dari suatu nilai atau objek. Dengan pointer, kita dapat mengakses dan memanipulasi nilai atau objek tersebut secara lebih efisien karena bekerja langsung melalui alamat memori [3]. Array sendiri memiliki beberapa jenis yang dapat digunakan sesuai kebutuhan.

### A. Array 1 dimensi <br/>
Array 1 dimensi adalah array yang terdiri atas sejumlah kolom yang disusun secara berurutan, di mana setiap elemen di dalamnya dapat diakses menggunakan indeks yang menunjukkan posisi elemen tersebut [1].

``` C++
 tipe_data  nama_array  [jumlah_elemen];
```

### B. Array 2 dimensi 
Dalam C++, kita dapat menginisialisasi array 2 dimensi sekaligus saat mendeklarasikannya, dan cara yang paling umum adalah dengan menggunakan kurung kurawal ({}) untuk menetapkan nilai pada setiap baris [2].

``` C++ 
int arr[4][2] = {
    {1234, 56},
    {1212, 33},
    {1434, 80},
    {1312, 78}
} ;
```
atau dapat juga seperti berikut 
``` C++
int arr[4][2] = {1234, 56, 1212, 33, 1434, 80, 1312, 78};
```

### C. Arrnpointer 
Di dalam bahasa pemrograman C++, setiap tipe data memiliki pointer yang sesuai, sehingga kita dapat membuat pointer untuk tipe data dasar seperti int, float, atau char. Pointer ini berfungsi untuk menunjuk ke lokasi memori tempat nilai dari tipe data tersebut disimpan. Sebagai contoh, pointer dengan tipe int akan menunjuk ke alamat memori yang menyimpan nilai bilangan bulat. Deklarasi dan inisialisasi pointer dalam C++ dapat dilakukan untuk berbagai tipe data sesuai kebutuhan [3].

``` C++
int angka = 42; int *ptr = &angka; // Inisialisasi pointer dengan alamat variabel angka
```



## Guided 

### 1. Array 1 dimensi

```c++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5) {
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program ini meminta pengguna memasukkan 5 nilai ke dalam array arr[5] menggunakan perulangan for, lalu menampilkan kembali setiap nilai beserta indeksnya melalui perulangan while. Program ini menunjukkan cara input dan output data menggunakan array sederhana di C++.

### 2. Array 2 dimensi 

```c++ 
#include<iostream>
using namespace std;

void tampilkanhasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };  
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};
    
    // Penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
    
    cout<<"Hasil Penjumlahan: "<<endl;
    tampilkanhasil(arrC);

    cout<<endl;

    // Perkalian matriks 2x2
    for (int i = 0; i < 2; i++){            //Perulangan baris 
        for (int j = 0; j < 2; j++){        //Perulangan kolom  
            for (int k = 0; k < 2; k++){    //Perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout<<"Hasil Perkalian: "<<endl;
    tampilkanhasil(arrD);

    return 0;
}
```
Program ini menjumlahkan dan mengalikan dua matriks 2×2. Hasil penjumlahan disimpan di arrC, sedangkan hasil perkalian di arrD. Fungsi tampilkanhasil digunakan untuk menampilkan hasil kedua operasi tersebut ke layar.

### 3. Arrnpointer

```c++ 
#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int*ptr=arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++){
        cout<<"elemen array ke-"<< i+1<<" menggunakan pointer: "<<*(ptr+i)<<endl;
    }

    //mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){
        cout<<"Elemen array ke-"<< i+1 <<" menggunakan indeks: "<<arr[i]<<endl;
    }
    return 0;
}
```
Program ini menunjukkan cara menampilkan isi array dengan dua cara: pertama menggunakan pointer *(ptr+i) dan kedua menggunakan indeks biasa arr[i], sehingga terlihat bahwa pointer bisa digunakan seperti indeks untuk membaca elemen array.
### 4. Fungsi prosedur 

```c++ 
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
 }
```
Program ini meminta input angka, lalu mencetak deret dengan tiga cara: for dari 0 hingga sebelum angka input, while dari 10 turun hingga lebih besar dari input, dan do-while yang mencetak 10 sekali.


## Unguided 

### 1. Matriks 3x3

```C++
#include <iostream>
using namespace std;

const int N = 3;

void printMatriks(int M[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

void penjumlahanMatriks(int A[N][N], int B[N][N], int C[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void penguranganMatriks(int A[N][N], int B[N][N], int C[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalianMatriks(int A[N][N], int B[N][N], int C[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            C[i][j] = 0;
            for(int k=0;k<N;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    int A[N][N] = {{7,12,22},
                   {31,6,41},
                   {15,19,36}};

    int B[N][N] = {{11,34,7},
                   {3,25,41},
                   {5,18,33}};

    int C[N][N];
    int pilih;

    do{
        cout<<" Menu Program Matriks " << endl;
        cout<<"1. Penjumlahan matriks" << endl;
        cout<<"2. Pengurangan matriks" << endl;
        cout<<"3. Perkalian matriks" << endl;
        cout<<"4. Keluar" << endl;
        cout<<"Pilih: ";
        cin>>pilih;

        switch(pilih){
            case 1:
                penjumlahanMatriks(A,B,C);
                cout<<"Hasil penjumlahan:" << endl;
                printMatriks(C);
                break;
            case 2:
                penguranganMatriks(A,B,C);
                cout<<"Hasil pengurangan:" << endl;
                printMatriks(C);
                break;
            case 3:
                perkalianMatriks(A,B,C);
                cout<<"Hasil perkalian:" << endl;
                printMatriks(C);
                break;
            case 4:
                cout<<"Program selesai." << endl;
                break;
            default:
                cout<<"Pilihan tidak ada." << endl;
        }
    }while(pilih!=4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![output unguided1_1.png](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak2/Laprak/OutputUnguided1.png)

Program ini punya dua matriks 3×3 (A dan B). Kita bisa pilih mau tambah, kurang, atau kali kedua matriks itu lewat menu. Hasilnya disimpan di matriks C dan langsung ditampilkan. Program bakal terus jalan sampai kita pilih keluar


### 2. Hitung luas dan keliling persegi 

```C++ 
#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5, luas = 0, keliling = 0;
    int *ptrPanjang = &panjang, *ptrLebar = &lebar;

    cout << " Nilai Awal " << endl;
    cout << "Panjang: " << *ptrPanjang << endl;
    cout << "Lebar: " << *ptrLebar << endl << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));
    cout << " Hasil Perhitungan " << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));
    cout << " Nilai Setelah Diubah Melalui Pointer " << endl;
    cout << "Panjang Baru: " << *ptrPanjang << endl;
    cout << "Lebar Baru: " << *ptrLebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![output unguided2.png](https://github.com/PratamaBintangDaniswara/103112400051_Pratama-Bintang-Daniswara/blob/main/Laprak2/Laprak/OutputUnguided2.png)


Program ini menghitung luas dan keliling persegi panjang. Awalnya menampilkan ukuran panjang dan lebar, lalu menghitung luas dan keliling. Setelah itu, ukuran diubah lewat pointer, dan hasil perhitungannya ditampilkan lagi dengan nilai baru


## Kesimpulan
Kesimpulannya, dari praktikum ini kita belajar cara menggunakan array dan pointer di C++. Kita jadi paham bagaimana array bisa menyimpan banyak data sekaligus, sedangkan pointer membantu kita mengakses dan mengubah data langsung dari memori. Kedua konsep ini penting sebagai dasar untuk membuat program dan algoritma yang lebih kompleks di C++

## Referensi
[1] https://www.materidosen.com/2017/06/array-satu-dimensi-c-lengkap-contoh.html
<br> [2] https://www.digitalocean.com/community/tutorials/two-dimensional-array-in-c-plus-plus
<br>  [3] https://www.domainesia.com/berita/pointer-adalah/

