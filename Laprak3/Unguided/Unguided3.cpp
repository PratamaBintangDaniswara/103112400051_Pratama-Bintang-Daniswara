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