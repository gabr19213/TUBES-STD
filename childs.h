#ifndef CHILDS_H_INCLUDED
#define CHILDS_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elmBarang *adrBarang;
typedef struct infoBarang infotype;

struct infoBarang{
    string nama;
    string katagori;
    int stok;
};

struct elmBarang{
    infoBarang info;
    adrBarang next;
    bool statusKetersediaan;
};

struct listChild{
    adrBarang first;
};

adrBarang alokasiChild(infoBarang info);
bool isEmptyChild(listChild lc);
void insertFirstChild(listChild &lc, adrBarang B);
void inputBarang(listChild &lc, adrBarang &B);
void deleteFirstChild(listChild &lc, adrBarang &B);
void deleteAfterChild(listChild &lc, adrBarang &B, adrBarang prec);
void deleteLastChild(listChild &lc, adrBarang &B);
adrBarang searchBarang(listChild lc, string p);

#endif // CHILDS_H_INCLUDED
