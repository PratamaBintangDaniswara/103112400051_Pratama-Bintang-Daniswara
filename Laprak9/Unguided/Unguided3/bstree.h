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

void printPreOrder(address root);
void printPostOrder(address root);

#endif
