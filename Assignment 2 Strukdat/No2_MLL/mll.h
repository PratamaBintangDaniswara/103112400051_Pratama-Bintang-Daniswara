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

struct infotypeParent {
    string IDGenre;
    string namaGenre;
};

typedef struct NodeChild *adrChild;
typedef struct NodeParent *adrParent;

struct NodeChild {
    infotypeChild info;
    adrChild next;
    adrChild prev;
};

struct ListChild {
    adrChild first;
    adrChild last;
};

struct NodeParent {
    infotypeParent info;
    NodeParent *next;
    NodeParent *prev;
    ListChild child;
};

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

