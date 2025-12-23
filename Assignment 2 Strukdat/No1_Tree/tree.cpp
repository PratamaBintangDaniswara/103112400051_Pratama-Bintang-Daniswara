#include "tree.h"
#include<iostream>
using namespace std;

Node *root;

bool isEmpty() {
    return root == NULL;
}

void createTree() {
    root = NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node *baru = new Node;
    baru->namaMember = nama;
    baru->beratBadan = berat;
    baru->tierMember = tier;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

void insertNode(Node *baru) {
    if (isEmpty()) {
        root = baru;
    } else {
        Node *current = root;
        Node *parent = NULL;

        while (current != NULL) {
            parent = current;
            if (baru->beratBadan < current->beratBadan)
                current = current->left;
            else
                current = current->right;
        }

        if (baru->beratBadan < parent->beratBadan)
            parent->left = baru;
        else
            parent->right = baru;
    }
}

void inOrder(Node *current) {
    if (current != NULL) {
        inOrder(current->left);
        cout << current->beratBadan << " - ";
        inOrder(current->right);
    }
}

Node* mostLeft() {
    Node *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* mostRight() {
    Node *current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

void searchByBeratBadan(float berat) {
    Node *current = root;
    Node *parent = NULL;
    while (current != NULL && current->beratBadan != berat) {
        parent = current;
        if (berat < current->beratBadan)
            current = current->left;
        else
            current = current->right;
    }
    if (current == NULL) {
        cout << "Data tidak ditemukan di BST" << endl;
        return;
    }
    cout << "Data ditemukan" << endl;
    cout << "Nama  : " << current->namaMember << endl;
    cout << "Berat : " << current->beratBadan << endl;
    cout << "Tier  : " << current->tierMember << endl;
    if (parent != NULL) {
        cout << "Data Parent" << endl;
        cout << "Nama  : " << parent->namaMember << endl;
        cout << "Berat : " << parent->beratBadan << endl;
        cout << "Tier  : " << parent->tierMember << endl;
    }
    if (parent != NULL) {
        if ((parent->left == current && parent->right != NULL) ||
            (parent->right == current && parent->left != NULL)) {

            Node *sibling = (parent->left == current)
                            ? parent->right
                            : parent->left;

            cout << "Sibling Node" << endl;
            cout << "Nama  : " << sibling->namaMember << endl;
            cout << "Berat : " << sibling->beratBadan << endl;
            cout << "Tier  : " << sibling->tierMember << endl;
        } else {
            cout << "Tidak memiliki sibling" << endl;
        }
    }
    if (current->left != NULL) {
        cout << "Child Kiri" << endl;
        cout << "Nama  : " << current->left->namaMember << endl;
        cout << "Berat : " << current->left->beratBadan << endl;
        cout << "Tier  : " << current->left->tierMember << endl;
    }
    if (current->right != NULL) {
        cout << "Child Kanan" << endl;
        cout << "Nama  : " << current->right->namaMember << endl;
        cout << "Berat : " << current->right->beratBadan << endl;
        cout << "Tier  : " << current->right->tierMember << endl;
    }
}
