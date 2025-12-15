#include "mll.h"

int main() {
    listParent L;
    createListParent(L);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(L, P1);
    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(L, P2);
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(L, P3);

    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(L, P4);
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(L, P5);

    printMLLStructure(L);
    cout << endl;

    searchHewanByEkor(L, false);
    cout << endl;

    NodeParent temp = L.first;
    NodeParent targetPrev = NULL;
    
    while(temp != NULL){
        if(temp->isidata.idGolongan == "G003"){
            targetPrev = temp;
            break;
        }
        temp = temp->next;
    }

    if(targetPrev != NULL){
        deleteAfterParent(L, targetPrev); 
    }

    printMLLStructure(L);
    cout << endl;

    return 0;
}