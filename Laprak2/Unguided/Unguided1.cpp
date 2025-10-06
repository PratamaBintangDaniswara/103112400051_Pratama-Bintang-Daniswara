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
