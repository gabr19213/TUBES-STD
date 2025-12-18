#include "childs.h"

adrBarang alokasiChild(infoBarang info){
    adrBarang B = new elmBarang;
    B->info = info;
    B->next = nullptr;
    B->statusKetersediaan false;
    return B;
}
bool isEmptyChild(listChild lc){
    return lc.first = nullptr;
}
void insertFirstChild(listChild &lc, adrBarang B){
    if(isEmptyChild(lc)){
        lc.first = B;
    }else{
        B->next = lc.first;
        lc.first = B;
    }
}
void inputBarang(listChild &lc, adrBarang &B){
    infotype b;
    adrBarang find;
    cout << "Masukkan nama barang: ('-' untuk berhenti) :";
    cin >> b.nama;
    while (b.nama != "-"){
        find = searchBarang(lc, b.nama);
        if (find == nullptr){
            cout << "Masukkan kategori barang: ";
            cin >> b.katagori;
            B = alokasiChild(b);
            insertFirstChild(lc, B);
        }else{
            cout << "Barang sudah ada dalam inventori." << endl;
        }
        cout << "Masukkan nama barang: ('-' untuk berhenti) :";
        cin >> b.nama;
    }
}
void deleteFirstChild(listChild &lc, adrBarang &B){
    if(isEmptyChild(lc)){
        B = nullptr;
    }else if (lc.first->next == nullptr){
        B = lc.first;
        lc.first = nullptr;
    }else{
        B = lc.first;
        lc.first = lc.first->next;
        B->next = nullptr;
    }
}
void deleteAfterChild(listChild &lc, adrBarang &B, adrBarang prec){
    if(isEmptyChild(lc)){
        B = nullptr;
    }else if(prec->next == nullptr){
        B = nullptr;
    }else{
        B = prec->next;
        prec->next = B->next;
        B->next = nullptr;
    }
}
void deleteLastChild(listChild &lc, adrBarang &B){
    adrBarang prev = lc.first;
    if (isEmptyChild(lc)){
        B = nullptr;
    }else if (lc.first->next == nullptr){
        B = lc.first;
        lc.first = nullptr;
    }else{
        while (prev->next->next != nullptr){
            prev = prev->next;
        }
        B = prev->next;
        prev->next = nullptr;
    }
}
adrBarang searchBarang(listChild lc, string p){
    adrBarang b, find;
    b = lc.first;
    find = nullptr;
    while (b != nullptr){
        if (b->info.nama == p){
            find = b;
        }
        b = b->next;
    }
    return find;
}
