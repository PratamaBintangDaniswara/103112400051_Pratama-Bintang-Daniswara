#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } else if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    } else {
        int kiri = hitungJumlahNode(root->left);
        int kanan = hitungJumlahNode(root->right);
        int total = 1 + kiri + kanan;
        return total;
    }
}

int hitungTotalInfo(address root, int start) {
    if (root == NULL) {
        return 0;
    } else {
        int kiri = hitungTotalInfo(root->left, start);
        int kanan = hitungTotalInfo(root->right, start);
        int total = root->info + kiri + kanan;
        return total;
    }
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) {
        return start;
    }

    int kiri  = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    if (kiri > kanan) {
        return kiri;
    } else {
        return kanan;
    }
} 

void printPreorder(address root) {
    if (root != NULL) {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root) {
    if (root != NULL) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}