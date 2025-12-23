#include "tree.h"
#include<iostream>
using namespace std;

int main() {
    createTree();

    insertNode(newNode("Rizkina Azizah", 60, "Basic"));
    insertNode(newNode("Hakan Ismail", 50, "Bronze"));
    insertNode(newNode("Olivia Seavali", 65, "Silver"));
    insertNode(newNode("Felix Pedrosa", 47, "Gold"));
    insertNode(newNode("Gamel Al Ghifari", 56, "Platinum"));
    insertNode(newNode("Mutia Fauziah", 52, "Bronze"));
    insertNode(newNode("Hanif Al Faiz", 70, "Basic"));
    insertNode(newNode("Davi Ilyas", 68, "Silver"));
    insertNode(newNode("Abdad Mubarok", 81, "Gold"));

    cout << "Hasil Traversal InOrder" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Node dengan Berat Terkecil : "
         << mostLeft()->beratBadan << endl;

    cout << "Node dengan Berat Terbesar : "
         << mostRight()->beratBadan << endl << endl;

    searchByBeratBadan(70);

    return 0;
}
