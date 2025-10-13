#include<iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m){
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "input Nilai1: ";
    cin >> m.nilai1;
    cout << "input Nilai2: ";
    cin >> m.nilai2;
}

//Relasi dari Fungsi rata2
float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2)/2;
}