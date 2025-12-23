#ifndef MLL_H
#define MLL_H
#include <iostream>
using namespace std;

struct infotypeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
};

// Info untuk Parent (Genre)
struct infotypeParent {
    string IDGenre;
    string namaGenre;
};

// Pointer Declarations
typedef struct NodeChild *adrChild;
typedef struct NodeParent *adrParent;

// Struktur Node Child (Double Linked List)
struct NodeChild {
    infotypeChild info;
    adrChild next;
    adrChild prev;
};

// Struktur List Child (Punya First dan Last)
struct ListChild {
    adrChild first;
    adrChild last;
};

// Struktur Node Parent (Double Linked List)
struct NodeParent {
    infotypeParent info;
    NodeParent *next;
    NodeParent *prev;
    ListChild child; // Setiap parent punya 1 List Child
};

// Struktur List Parent (Punya First dan Last)
struct ListParent {
    adrParent first;
    adrParent last;
};

void createListParent(ListParent &LP);
void createListChild(ListChild &LC);

adrParent alokasiNodeParent(infotypeParent x);
adrChild alokasiNodeChild(infotypeChild x);

void dealokasiNodeParent(adrParent P);
void dealokasiNodeChild(adrChild P);

void insertFirstParent(ListParent &LP, adrParent P);
void insertLastChild(ListChild &LC, adrChild P);

void hapusListChild(ListChild &LC);
void deleteAfterParent(ListParent &LP, adrParent Prec, adrParent &P);

void searchFilmByRatingRange(ListParent LP, float minRating, float maxRating);
void printStrukturMLL(ListParent LP);


#endif
