#include "mll.h"
#include<iostream>
using namespace std;

void createListParent(ListParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

void createListChild(ListChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}

adrParent alokasiNodeParent(infotypeParent x) {
    adrParent P = new NodeParent;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->child);
    return P;
}

adrChild alokasiNodeChild(infotypeChild x) {
    adrChild P = new NodeChild;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasiNodeParent(adrParent P) {
    delete P;
}

void dealokasiNodeChild(adrChild P) {
    delete P;
}

void insertFirstParent(ListParent &LP, adrParent P) {
    if (LP.first == NULL) {
        LP.first = P;
        LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(ListChild &LC, adrChild P) {
    if (LC.first == NULL) {
        LC.first = P;
        LC.last = P;
    } else {
        P->prev = LC.last;
        LC.last->next = P;
        LC.last = P;
    }
}

void hapusListChild(ListChild &LC) {
    adrChild P = LC.first;
    while (P != NULL) {
        adrChild temp = P;
        P = P->next;
        dealokasiNodeChild(temp);
    }
    LC.first = NULL;
    LC.last = NULL;
}

void deleteAfterParent(ListParent &LP, adrParent Prec, adrParent &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        
        hapusListChild(P->child);

        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        } else {
            LP.last = Prec; 
        }
        
        P->next = NULL;
        P->prev = NULL;
        dealokasiNodeParent(P);
    } else {
        cout << "Gagal hapus" << endl;
    }
}

void searchFilmByRatingRange(ListParent LP, float minRating, float maxRating) {
    adrParent P = LP.first;
    int idxP = 1;

    while (P != NULL) {
        adrChild C = P->child.first;
        int idxC = 1;

        while (C != NULL) {
            if (C->info.ratingFilm >= minRating &&
                C->info.ratingFilm <= maxRating) {

                cout << "Data Film ditemukan pada list child dari node parent "
                     << P->info.namaGenre
                     << " pada posisi ke " << idxC << endl << endl;

                cout << "Data Film (Child)" << endl;
                cout << "Judul Film : " << C->info.judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke " << idxC << endl;
                cout << "ID Film : " << C->info.IDFilm << endl;
                cout << "Durasi Film : " << C->info.durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->info.tahunTayang << endl;
                cout << "Rating Film : " << C->info.ratingFilm << endl << endl;

                cout << "Data Genre (Parent)" << endl;
                cout << "ID Genre : " << P->info.IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke " << idxP << endl;
                cout << "Nama Genre : " << P->info.namaGenre << endl << endl;
            }

            C = C->next;
            idxC++;
        }

        P = P->next;
        idxP++;
    }
}

void printStrukturMLL(ListParent LP) {
    adrParent P = LP.first;
    int idxP = 1;

    while (P != NULL) {
        cout << "Parent " << idxP << endl;
        cout << "ID Genre : " << P->info.IDGenre << endl;
        cout << "Nama Genre : " << P->info.namaGenre << endl;

        adrChild C = P->child.first;
        int idxC = 1;

        while (C != NULL) {
            cout << "- Child " << idxC << " :" << endl;
            cout << "  ID Film : " << C->info.IDFilm << endl;
            cout << "  Judul Film : " << C->info.judulFilm << endl;
            cout << "  Durasi Film : " << C->info.durasiFilm << " menit" << endl;
            cout << "  Tahun Tayang : " << C->info.tahunTayang << endl;
            cout << "  Rating Film : " << C->info.ratingFilm << endl;

            C = C->next;
            idxC++;
        }

        cout << endl;
        P = P->next;
        idxP++;
    }
}