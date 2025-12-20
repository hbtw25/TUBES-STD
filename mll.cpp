#include "mll.h"
#include <iostream>

using namespace std;

// ===================== CREATE LIST =====================
void createListParent(ListParent &LP) { 
    LP.first = nullptr; 
}

void createListChild(ListChild &LC) { 
    LC.first = nullptr; 
    LC.last = nullptr; 
}

void createListRelasi(ListRelasi &LR) { 
    LR.first = nullptr; 
}

// ===================== ALOKASI =====================
addressParent alokasiParent(infotypeParent P) {
    addressParent N = new NodeParent;
    N->info = P; 
    N->next = nullptr;
    return N;
}

addressChild alokasiChild(infotypeChild W) {
    addressChild N = new NodeChild;
    N->info = W; 
    N->next = nullptr; 
    N->prev = nullptr;
    return N;
}

addressRelasi alokasiRelasi(addressParent P, addressChild C, int round) {
    addressRelasi N = new NodeRelasi;
    N->info.pPlayer = P;
    N->info.pWeapon = C;
    N->info.round = round;
    N->next = nullptr;
    return N;
}

// ===================== DEALOKASI =====================
void dealokasiParent(addressParent P) {
    delete P;
}

void dealokasiChild(addressChild P) {
    delete P;
}

void dealokasiRelasi(addressRelasi P) {
    delete P;
}

// ===================== INSERT =====================
void insertLastParent(ListParent &LP, addressParent N) {
    if (LP.first == nullptr) {
        LP.first = N;
    } else {
        addressParent P = LP.first;
        while (P->next != nullptr) {
            P = P->next;
        }
        P->next = N;
    }
}

void insertLastChild(ListChild &LC, addressChild N) {
    if (LC.first == nullptr) { 
        LC.first = N; 
        LC.last = N; 
    } else {
        N->prev = LC.last;
        LC.last->next = N;
        LC.last = N;
    }
}

void insertFirstRelasi(ListRelasi &LR, addressRelasi N) {
    N->next = LR.first;
    LR.first = N;
}

// ===================== FIND =====================
addressParent findParent(ListParent LP, string idPlayer) {
    addressParent P = LP.first;
    while (P != nullptr) {
        if (P->info.idPlayer == idPlayer) return P;
        P = P->next;
    }
    return nullptr;
}

addressChild findChild(ListChild LC, string idWeapon) {
    addressChild P = LC.first;
    while (P != nullptr) {
        if (P->info.idWeapon == idWeapon) return P;
        P = P->next;
    }
    return nullptr;
}

// ===================== SHOW BASIC =====================
void showParent(ListParent LP) {
    cout << "=== DATA PLAYER ===\n";
    if (LP.first == nullptr) { cout << "Belum ada player.\n\n"; return; }
    int i = 1;
    addressParent P = LP.first;
    while (P != nullptr) {
        cout << i++ << ". " << P->info.idPlayer << " | " << P->info.nama
             << " | " << P->info.role << " | credit: " << P->info.credit << "\n";
        P = P->next;
    }
    cout << "\n";
}

void showChild(ListChild LC) {
    cout << "=== DATA WEAPON ===\n";
    if (LC.first == nullptr) { cout << "Belum ada weapon.\n\n"; return; }
    int i = 1;
    addressChild P = LC.first;
    while (P != nullptr) {
        cout << i++ << ". " << P->info.idWeapon << " | " << P->info.nama
             << " | " << P->info.kategori << " | harga: " << P->info.harga << "\n";
        P = P->next;
    }
    cout << "\n";
}

void showRelasi(ListRelasi LR) {
    cout << "=== DATA RELASI (PEMBELIAN) ===\n";
    if (LR.first == nullptr) { cout << "Belum ada transaksi.\n\n"; return; }
    int i = 1;
    addressRelasi R = LR.first;
    while (R != nullptr) {
        cout << i++ << ". " << R->info.pPlayer->info.nama
             << " membeli " << R->info.pWeapon->info.nama
             << " (round " << R->info.round << ")\n";
        R = R->next;
    }
    cout << "\n";
}

// ===================== RELASI FEATURES =====================
bool cekRelasi(ListRelasi LR, string idPlayer, string idWeapon) {
    addressRelasi R = LR.first;
    while (R != nullptr) {
        if (R->info.pPlayer->info.idPlayer == idPlayer &&
            R->info.pWeapon->info.idWeapon == idWeapon) return true;
        R = R->next;
    }
    return false;
}

void tampilWeaponPerPlayer(ListRelasi LR, string idPlayer) {
    cout << "=== WEAPON YANG DIBELI PLAYER " << idPlayer << " ===\n";
    bool ada = false;
    addressRelasi R = LR.first;
    while (R != nullptr) {
        if (R->info.pPlayer->info.idPlayer == idPlayer) {
            ada = true;
            cout << "- " << R->info.pWeapon->info.nama
                 << " (round " << R->info.round << ")\n";
        }
        R = R->next;
    }
    if (!ada) cout << "Belum ada pembelian.\n";
    cout << "\n";
}

void tampilPlayerPerWeapon(ListRelasi LR, string idWeapon) {
    cout << "=== PLAYER YANG MEMBELI WEAPON " << idWeapon << " ===\n";
    bool ada = false;
    addressRelasi R = LR.first;
    while (R != nullptr) {
        if (R->info.pWeapon->info.idWeapon == idWeapon) {
            ada = true;
            cout << "- " << R->info.pPlayer->info.nama
                 << " (round " << R->info.round << ")\n";
        }
        R = R->next;
    }
    if (!ada) cout << "Belum ada yang membeli weapon ini.\n";
    cout << "\n";
}

void tampilSemuaPlayerDanWeapon(ListParent LP, ListRelasi LR) {
    cout << "=== SETIAP PLAYER BESERTA WEAPON YANG DIBELI (DENGAN ROUND) ===\n";
    if (LP.first == nullptr) { cout << "Belum ada player.\n\n"; return; }

    addressParent P = LP.first;
    while (P != nullptr) {
        cout << P->info.idPlayer << " | " << P->info.nama << ":\n";
        bool ada = false;
        
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->info.pPlayer == P) {
                ada = true;
                cout << "  - " << R->info.pWeapon->info.nama
                     << " (round " << R->info.round << ")\n";
            }
            R = R->next;
        }
        if (!ada) cout << "  (belum membeli)\n";
        P = P->next;
    }
    cout << "\n";
}

void tampilSemuaWeaponDanPlayer(ListChild LC, ListRelasi LR) {
    cout << "=== SETIAP WEAPON BESERTA PLAYER YANG MEMBELI (DENGAN ROUND) ===\n";
    if (LC.first == nullptr) { cout << "Belum ada weapon.\n\n"; return; }

    addressChild W = LC.first;
    while (W != nullptr) {
        cout << W->info.idWeapon << " | " << W->info.nama << ":\n";
        bool ada = false;
        
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->info.pWeapon == W) {
                ada = true;
                cout << "  - " << R->info.pPlayer->info.nama
                     << " (round " << R->info.round << ")\n";
            }
            R = R->next;
        }
        if (!ada) cout << "  (belum pernah dibeli)\n";
        W = W->next;
    }
    cout << "\n";
}

// ===================== COUNT =====================
int hitungTotalWeaponPlayer(ListRelasi LR, string idPlayer) {
    int cnt = 0;
    addressRelasi R = LR.first;
    while (R != nullptr) {
        if (R->info.pPlayer->info.idPlayer == idPlayer) cnt++;
        R = R->next;
    }
    return cnt;
}

int hitungTotalPlayerWeapon(ListRelasi LR, string idWeapon) {
    int cnt = 0;
    addressRelasi R = LR.first;
    while (R != nullptr) {
        if (R->info.pWeapon->info.idWeapon == idWeapon) cnt++;
        R = R->next;
    }
    return cnt;
}

int hitungWeaponTidakTerbeli(ListChild LC, ListRelasi LR) {
    int cnt = 0;
    addressChild W = LC.first;
    while (W != nullptr) {
        bool pernah = false;
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->info.pWeapon == W) { pernah = true; break; }
            R = R->next;
        }
        if (!pernah) cnt++;
        W = W->next;
    }
    return cnt;
}

int hitungPlayerTidakMembeli(ListParent LP, ListRelasi LR) {
    int cnt = 0;
    addressParent P = LP.first;
    while (P != nullptr) {
        bool pernah = false;
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->info.pPlayer == P) { pernah = true; break; }
            R = R->next;
        }
        if (!pernah) cnt++;
        P = P->next;
    }
    return cnt;
}

// ===================== DELETE RELASI =====================
bool deleteRelasi(ListRelasi &LR, string idPlayer, string idWeapon, int round) {
    if (LR.first == nullptr) return false;

    addressRelasi prevNode = nullptr;
    addressRelasi cur = LR.first;

    while (cur != nullptr) {
        bool match = (cur->info.pPlayer->info.idPlayer == idPlayer &&
                      cur->info.pWeapon->info.idWeapon == idWeapon &&
                      cur->info.round == round);
        if (match) {
            if (prevNode == nullptr) LR.first = cur->next;
            else prevNode->next = cur->next;

            dealokasiRelasi(cur); // GANTI delete cur
            return true;
        }
        prevNode = cur;
        cur = cur->next;
    }
    return false;
}

// helper: hapus semua relasi yg menunjuk player tertentu
static void deleteRelasiByPlayerPtr(ListRelasi &LR, addressParent pTarget) {
    addressRelasi prevNode = nullptr;
    addressRelasi cur = LR.first;
    while (cur != nullptr) {
        if (cur->info.pPlayer == pTarget) {
            addressRelasi del = cur;
            if (prevNode == nullptr) LR.first = cur->next;
            else prevNode->next = cur->next;
            cur = cur->next;
            dealokasiRelasi(del); // GANTI delete del
        } else {
            prevNode = cur;
            cur = cur->next;
        }
    }
}

// helper: hapus semua relasi yg menunjuk weapon tertentu
static void deleteRelasiByWeaponPtr(ListRelasi &LR, addressChild wTarget) {
    addressRelasi prevNode = nullptr;
    addressRelasi cur = LR.first;
    while (cur != nullptr) {
        if (cur->info.pWeapon == wTarget) {
            addressRelasi del = cur;
            if (prevNode == nullptr) LR.first = cur->next;
            else prevNode->next = cur->next;
            cur = cur->next;
            dealokasiRelasi(del); // GANTI delete del
        } else {
            prevNode = cur;
            cur = cur->next;
        }
    }
}

// ===================== DELETE PARENT =====================
bool deleteParent(ListParent &LP, ListRelasi &LR, string idPlayer) {
    if (LP.first == nullptr) return false;

    addressParent prevNode = nullptr;
    addressParent cur = LP.first;

    while (cur != nullptr) {
        if (cur->info.idPlayer == idPlayer) {
            // hapus relasi yang terkait
            deleteRelasiByPlayerPtr(LR, cur);

            // hapus node parent
            if (prevNode == nullptr) LP.first = cur->next;
            else prevNode->next = cur->next;

            dealokasiParent(cur); // GANTI delete cur
            return true;
        }
        prevNode = cur;
        cur = cur->next;
    }
    return false;
}

// ===================== DELETE CHILD =====================
bool deleteChild(ListChild &LC, ListRelasi &LR, string idWeapon) {
    if (LC.first == nullptr) return false;

    addressChild cur = LC.first;
    while (cur != nullptr) {
        if (cur->info.idWeapon == idWeapon) {
            // hapus relasi terkait weapon
            deleteRelasiByWeaponPtr(LR, cur);

            // lepas dari DLL
            if (cur->prev != nullptr) cur->prev->next = cur->next;
            else LC.first = cur->next; // cur adalah first

            if (cur->next != nullptr) cur->next->prev = cur->prev;
            else LC.last = cur->prev;  // cur adalah last

            dealokasiChild(cur); // GANTI delete cur
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// ===================== EDIT RELASI =====================
bool editRelasiGantiWeapon(ListRelasi &LR, ListChild LC,
                            string idPlayer, string idWeaponLama, int round,
                            string idWeaponBaru) {
    addressChild wBaru = findChild(LC, idWeaponBaru);
    if (wBaru == nullptr) return false;

    addressRelasi R = LR.first;
    while (R != nullptr) {
        if (R->info.pPlayer->info.idPlayer == idPlayer &&
            R->info.pWeapon->info.idWeapon == idWeaponLama &&
            R->info.round == round) {
            R->info.pWeapon = wBaru;
            return true;
        }
        R = R->next;
    }
    return false;
}

bool editRelasiGantiPlayer(ListRelasi &LR, ListParent LP,
                            string idPlayerLama, string idWeapon, int round,
                            string idPlayerBaru) {
    addressParent pBaru = findParent(LP, idPlayerBaru);
    if (pBaru == nullptr) return false;

    addressRelasi R = LR.first;
    while (R != nullptr) {
        if (R->info.pPlayer->info.idPlayer == idPlayerLama &&
            R->info.pWeapon->info.idWeapon == idWeapon &&
            R->info.round == round) {
            R->info.pPlayer = pBaru;
            return true;
        }
        R = R->next;
    }
    return false;
}
