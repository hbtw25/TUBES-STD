#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED


#include <string>

using namespace std;

// ===================== DATA =====================

struct Player {
    string idPlayer;
    string nama;
    string role;      // Duelist, Controller, dsb.
    int credit;
};

struct Weapon {
    string idWeapon;
    string nama;
    string kategori;  // Rifle, Pistol, dsb.
    int harga;
};

// ===================== NODE & LIST =====================

// Parent : Single Linked List
struct NodeParent {
    Player info;
    NodeParent *next;
};

struct ListParent {
    NodeParent *first;
};

// Child : Double Linked List
struct NodeChild {
    Weapon info;
    NodeChild *next;
    NodeChild *prev;
};

struct ListChild {
    NodeChild *first;
    NodeChild *last;
};

// Relasi : Single Linked List
struct Relasi {
    NodeParent *pPlayer;
    NodeChild *pWeapon;
    int round;
};

struct NodeRelasi {
    Relasi info;
    NodeRelasi *next;
};

struct ListRelasi {
    NodeRelasi *first;
};

// ===================== FUNGSI ADT =====================

// Inisialisasi list
void createListParent(ListParent &LP);
void createListChild(ListChild &LC);
void createListRelasi(ListRelasi &LR);

// Alokasi node
NodeParent* alokasiParent(Player P);
NodeChild*  alokasiChild(Weapon W);
NodeRelasi* alokasiRelasi(NodeParent *P, NodeChild *C, int round);

// Insert
void insertLastParent(ListParent &LP, NodeParent *N);
void insertLastChild(ListChild &LC, NodeChild *N);
void insertFirstRelasi(ListRelasi &LR, NodeRelasi *N);

// Find
NodeParent* findParent(ListParent LP, string idPlayer);
NodeChild*  findChild(ListChild LC, string idWeapon);

// Show
void showParent(ListParent LP);
void showChild(ListChild LC);
void showRelasi(ListRelasi LR);
void showWeaponByPlayer(ListRelasi LR, string idPlayer);

// ========== TODO UNTUK PROGRESS 80% & FINAL (BELUM DIIMPLEMENTASI) ==========
// void deleteParent(...);
// void deleteChild(...);
// void deleteRelasi(...);
// void showPlayerByWeapon(...);
// int  countWeaponByPlayer(...);
// int  countPlayerByWeapon(...);
// dst...


#endif // MLL_H_INCLUDED
