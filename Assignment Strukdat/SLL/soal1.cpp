#include<iostream>
using namespace std;
struct Node{
    string nama;
    Node* next;
};
Node* head = NULL;

void insertNamaAkhir(string nama){
    Node* baru = new Node{nama, NULL};
    if (head = NULL){
        head = baru;
    }else {
        Node* temp = head;
        while (temp->next != NULL)temp = temp->next;
        temp->next = baru; 
    }
    
}
void deleteNama(string tujuan){
    if (head = NULL) return;
    if (head->nama == tujuan){
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return; 
    }
}
void viewList(){
    Node* temp = head;
    while (temp != NULL){
        cout<<temp->nama<<" ";
        temp = temp->next;       
    }
    cout<<endl;
       
}
void hitungTampil(){
    Node* temp = head;
    int count = 0;
    cout<<"jumlah nama dengan huruf genap: ";
    while (temp != NULL){
        if (temp->nama.length()%2==0)
            count++;
        temp = temp->next;
    }
    cout<<count<<endl;
}
int main(){
    int pilih;
    string input;
    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nama: ";
            cin >> input;
            insertNamaAkhir(input);
        }
        else if (pilih == 2) {
            cout << "Masukkan nama untuk delete: ";
            cin >> input;
            deleteNama(input);
        }
        else if (pilih == 3) {
            viewList();
        }
        else if (pilih == 4) {
            hitungTampil();
        }

    } while (pilih != 0);
    return 0;
}