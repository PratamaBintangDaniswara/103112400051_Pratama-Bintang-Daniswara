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

