#include "mll.h"
#include<iostream>
using namespace std;

int main() {
    ListParent LP;
    createListParent(LP);
    adrParent P;
    adrChild C;
    infotypeParent infoP;
    infotypeChild infoC;

    infoP = {"G004", "Romance"};
    P = alokasiNodeParent(infoP);
    insertFirstParent(LP, P);

        infoC = {"FR001", "Habibie & Ainun", 118, 2012, 7.6};
        C = alokasiNodeChild(infoC);
        insertLastChild(P->child, C);
        
        infoC = {"FR002", "Dilan 1990", 110, 2018, 6.6};
        C = alokasiNodeChild(infoC);
        insertLastChild(P->child, C);

    infoP = {"G003", "Horror"};
    P = alokasiNodeParent(infoP);
    insertFirstParent(LP, P);

        infoC = {"FH001", "Pengabdi Setan", 107, 2017, 8.4};
        C = alokasiNodeChild(infoC);
        insertLastChild(P->child, C);

    infoP = {"G002", "Comedy"};
    P = alokasiNodeParent(infoP);
    insertFirstParent(LP, P);

        infoC = {"FC001", "Agak Laen", 119, 2024, 8.0};
        C = alokasiNodeChild(infoC);
        insertLastChild(P->child, C);
        
        infoC = {"FC002", "My Stupid Boss", 108, 2016, 6.8};
        C = alokasiNodeChild(infoC);
        insertLastChild(P->child, C);

    infoP = {"G001", "Action"};
    P = alokasiNodeParent(infoP);
    insertFirstParent(LP, P);

        infoC = {"FA001", "The Raid", 101, 2011, 7.6};
        C = alokasiNodeChild(infoC);
        insertLastChild(P->child, C);
    printStrukturMLL(LP);
    searchFilmByRatingRange(LP, 8.0, 8.5);
    adrParent Prec = LP.first; 
    adrParent DeletedNode = NULL;
    deleteAfterParent(LP, Prec, DeletedNode);
    printStrukturMLL(LP);

    return 0;
}