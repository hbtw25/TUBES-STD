#ifndef MLL_VALORANT_H
#define MLL_VALORANT_H

#include <iostream>
#include <string>

using namespace std;

// ===================== INFOTYPE DEFINITIONS =====================
struct Player {
    string idPlayer;
    string nama;
    string role;
    int credit;
};

struct Weapon {
    string idWeapon;
    string nama;
    string kategori;
    int harga;
};

typedef Player infotypeParent;
typedef Weapon infotypeChild;

// ===================== TYPEDEF POINTERS =====================
typedef struct NodeParent *addressParent;
typedef struct NodeChild *addressChild;
typedef struct NodeRelasi *addressRelasi;

// ===================== NODE & LIST DEFINITIONS =====================

// --- Parent (Single Linked List) ---
struct NodeParent {
    infotypeParent info;
    addressParent next;
};

struct ListParent {
    addressParent first;
};

// --- Child (Doubly Linked List) ---
struct NodeChild {
    infotypeChild info;
    addressChild next;
    addressChild prev;
};

struct ListChild {
    addressChild first;
    addressChild last;
};

// --- Relasi (Single Linked List) ---
// Relasi holds pointers to Parent and Child, plus extra data (round)
struct RelasiData {
    addressParent pPlayer;
    addressChild  pWeapon;
    int round;
};

struct NodeRelasi {
    RelasiData info;
    addressRelasi next;
};

struct ListRelasi {
    addressRelasi first;
};

// ===================== ADT PRIMITIVES =====================

// --- CREATE LIST ---
// IS: Sembarang
// FS: Terbentuk ListParent kosong (first = nullptr)
void createListParent(ListParent &LP);

// IS: Sembarang
// FS: Terbentuk ListChild kosong (first = nullptr, last = nullptr)
void createListChild(ListChild &LC);

// IS: Sembarang
// FS: Terbentuk ListRelasi kosong (first = nullptr)
void createListRelasi(ListRelasi &LR);

// --- ALLOCATION ---
// IS: Data Player P terdefinisi
// FS: Mengembalikan addressParent yang berisi info P, next = nullptr
addressParent alokasiParent(infotypeParent P);

// IS: Data Weapon W terdefinisi
// FS: Mengembalikan addressChild yang berisi info W, next = nullptr, prev = nullptr
addressChild alokasiChild(infotypeChild W);

// IS: Address Player P, Address Child C, dan round terdefinisi
// FS: Mengembalikan addressRelasi yang menghubungkan P dan C
addressRelasi alokasiRelasi(addressParent P, addressChild C, int round);

// --- DEALOCATION ---
// IS: P terdefinisi
// FS: Memori P dikembalikan ke sistem
void dealokasiParent(addressParent P);

// IS: P terdefinisi
// FS: Memori P dikembalikan ke sistem
void dealokasiChild(addressChild P);

// IS: P terdefinisi
// FS: Memori P dikembalikan ke sistem
void dealokasiRelasi(addressRelasi P);

// --- INSERT ---
// IS: ListParent LP mungkin kosong, P adalah elemen baru
// FS: P menjadi elemen terakhir list parent
void insertLastParent(ListParent &LP, addressParent P);

// IS: ListChild LC mungkin kosong, P adalah elemen baru
// FS: P menjadi elemen terakhir list child
void insertLastChild(ListChild &LC, addressChild P);

// IS: ListRelasi LR mungkin kosong, P adalah elemen baru
// FS: P menjadi elemen pertama list relasi
void insertFirstRelasi(ListRelasi &LR, addressRelasi P);

// --- FIND ---
// IS: ListParent LP terdefinisi, idPlayer yang dicari
// FS: Mengembalikan address node jika ditemukan, nullptr jika tidak
addressParent findParent(ListParent LP, string idPlayer);

// IS: ListChild LC terdefinisi, idWeapon yang dicari
// FS: Mengembalikan address node jika ditemukan, nullptr jika tidak
addressChild findChild(ListChild LC, string idWeapon);

// --- SHOW / VIEW ---
// IS: ListParent LP terdefinisi
// FS: Menampilkan seluruh data player ke layar
void showParent(ListParent LP);

// IS: ListChild LC terdefinisi
// FS: Menampilkan seluruh data weapon ke layar
void showChild(ListChild LC);

// IS: ListRelasi LR terdefinisi
// FS: Menampilkan seluruh data transaksi ke layar
void showRelasi(ListRelasi LR);

// ===================== BUSINESS LOGIC / FEATURES =====================

// IS: ListRelasi LR terdefinisi
// FS: Mengembalikan true jika ada relasi antara player dan weapon tsb, false jika tidak
bool cekRelasi(ListRelasi LR, string idPlayer, string idWeapon);

// IS: ListRelasi LR terdefinisi
// FS: Menampilkan daftar weapon yang dibeli oleh idPlayer
void tampilWeaponPerPlayer(ListRelasi LR, string idPlayer);

// IS: ListRelasi LR terdefinisi
// FS: Menampilkan daftar player yang membeli idWeapon
void tampilPlayerPerWeapon(ListRelasi LR, string idWeapon);

// IS: ListParent dan ListRelasi terdefinisi
// FS: Menampilkan setiap player beserta daftar weapon yang mereka beli
void tampilSemuaPlayerDanWeapon(ListParent LP, ListRelasi LR);

// IS: ListChild dan ListRelasi terdefinisi
// FS: Menampilkan setiap weapon beserta daftar player yang membelinya
void tampilSemuaWeaponDanPlayer(ListChild LC, ListRelasi LR);

// IS: ListRelasi terdefinisi
// FS: Mengembalikan jumlah weapon yang dibeli idPlayer
int hitungTotalWeaponPlayer(ListRelasi LR, string idPlayer);

// IS: ListRelasi terdefinisi
// FS: Mengembalikan jumlah player yang membeli idWeapon
int hitungTotalPlayerWeapon(ListRelasi LR, string idWeapon);

// IS: ListChild dan ListRelasi terdefinisi
// FS: Mengembalikan jumlah weapon yang tidak ada di tabel relasi (tidak pernah dibeli)
int hitungWeaponTidakTerbeli(ListChild LC, ListRelasi LR);

// IS: ListParent dan ListRelasi terdefinisi
// FS: Mengembalikan jumlah player yang tidak ada di tabel relasi (tidak pernah belanja)
int hitungPlayerTidakMembeli(ListParent LP, ListRelasi LR);

// --- DELETE OPERATIONS ---
// IS: ListRelasi terdefinisi
// FS: Jika ditemukan relasi (player+weapon+round) sesuai input, elemen dihapus dan return true
bool deleteRelasi(ListRelasi &LR, string idPlayer, string idWeapon, int round);

// IS: ListParent dan ListRelasi terdefinisi
// FS: Data player dihapus dari ListParent, dan semua relasinya di ListRelasi ikut terhapus
bool deleteParent(ListParent &LP, ListRelasi &LR, string idPlayer);

// IS: ListChild dan ListRelasi terdefinisi
// FS: Data weapon dihapus dari ListChild, dan semua relasinya di ListRelasi ikut terhapus
bool deleteChild(ListChild &LC, ListRelasi &LR, string idWeapon);

// --- EDIT OPERATIONS ---
// IS: ListRelasi dan ListChild terdefinisi
// FS: Relasi lama diubah weapon-nya menjadi weapon baru. Return true jika sukses.
bool editRelasiGantiWeapon(ListRelasi &LR, ListChild LC,
                            string idPlayer, string idWeaponLama, int round,
                            string idWeaponBaru);

// IS: ListRelasi dan ListParent terdefinisi
// FS: Relasi lama diubah player-nya menjadi player baru. Return true jika sukses.
bool editRelasiGantiPlayer(ListRelasi &LR, ListParent LP,
                            string idPlayerLama, string idWeapon, int round,
                            string idPlayerBaru);

#endif
