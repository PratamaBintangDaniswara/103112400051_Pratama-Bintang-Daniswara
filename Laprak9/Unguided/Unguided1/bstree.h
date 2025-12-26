#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;

typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
} Node;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif
