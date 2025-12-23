#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left;
    Node *right;
};

extern Node *root;

bool isEmpty();
void createTree();
Node* newNode(string nama, float berat, string tier);
void insertNode(Node *baru);
void inOrder(Node *current);
Node* mostLeft();
Node* mostRight();
void searchByBeratBadan(float berat);

#endif
