#include "mll.h"
#include <iostream>

using namespace std;

// ===================== CREATE LIST =====================

void createListParent(ListParent &LP) {
    LP.first = nullptr;
}

void createListChild(ListChild &LC) {
    LC.first = nullptr;
    LC.last  = nullptr;
}

void createListRelasi(ListRelasi &LR) {
    LR.first = nullptr;
}

// ===================== ALOKASI NODE =====================

NodeParent* alokasiParent(Player P) {
    NodeParent *N = new NodeParent;
    N->info = P;
    N->next = nullptr;
    return N;
}

NodeChild* alokasiChild(Weapon W) {
    NodeChild *N = new NodeChild;
    N->info = W;
    N->next = nullptr;
    N->prev = nullptr;
    return N;
}

NodeRelasi* alokasiRelasi(NodeParent *P, NodeChild *C, int round) {
    NodeRelasi *N = new NodeRelasi;
    N->info.pPlayer = P;
    N->info.pWeapon = C;
    N->info.round   = round;
    N->next = nullptr;
    return N;
}

// ===================== INSERT =====================

void insertLastParent(ListParent &LP, NodeParent *N) {
    if (LP.first == nullptr) {
        LP.first = N;
    } else {
        NodeParent *p = LP.first;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = N;
    }
}

void insertLastChild(ListChild &LC, NodeChild *N) {
    if (LC.first == nullptr) {
        LC.first = N;
        LC.last  = N;
    } else {
        N->prev      = LC.last;
        LC.last->next = N;
        LC.last      = N;
    }
}

void insertFirstRelasi(ListRelasi &LR, NodeRelasi *N) {
    if (LR.first == nullptr) {
        LR.first = N;
    } else {
        N->next  = LR.first;
        LR.first = N;
    }
}

// ===================== FIND =====================

NodeParent* findParent(ListParent LP, string idPlayer) {
    NodeParent *p = LP.first;
    while (p != nullptr) {
        if (p->info.idPlayer == idPlayer) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

NodeChild* findChild(ListChild LC, string idWeapon) {
    NodeChild *p = LC.first;
    while (p != nullptr) {
        if (p->info.idWeapon == idWeapon) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// ===================== SHOW =====================

void showParent(ListParent LP) {
    cout << "=== DATA PLAYER ===" << endl;
    if (LP.first == nullptr) {
        cout << "Belum ada player.\n\n";
        return;
    }
    NodeParent *p = LP.first;
    int i = 1;
    while (p != nullptr) {
        cout << i++ << ". "
             << p->info.idPlayer << " | "
             << p->info.nama << " | "
             << p->info.role << " | credit: "
             << p->info.credit << endl;
        p = p->next;
    }
    cout << endl;
}

void showChild(ListChild LC) {
    cout << "=== DATA WEAPON ===" << endl;
    if (LC.first == nullptr) {
        cout << "Belum ada weapon.\n\n";
        return;
    }
    NodeChild *p = LC.first;
    int i = 1;
    while (p != nullptr) {
        cout << i++ << ". "
             << p->info.idWeapon << " | "
             << p->info.nama << " | "
             << p->info.kategori << " | harga: "
             << p->info.harga << endl;
        p = p->next;
    }
    cout << endl;
}

void showRelasi(ListRelasi LR) {
    cout << "=== DATA PEMBELIAN (RELASI) ===" << endl;
    if (LR.first == nullptr) {
        cout << "Belum ada transaksi.\n\n";
        return;
    }
    NodeRelasi *p = LR.first;
    int i = 1;
    while (p != nullptr) {
        cout << i++ << ". "
             << p->info.pPlayer->info.nama
             << " membeli "
             << p->info.pWeapon->info.nama
             << " pada round ke-"
             << p->info.round << endl;
        p = p->next;
    }
    cout << endl;
}

void showWeaponByPlayer(ListRelasi LR, string idPlayer) {
    cout << "=== WEAPON YANG DIBELI PLAYER " << idPlayer << " ===" << endl;
    bool ada = false;
    NodeRelasi *p = LR.first;
    while (p != nullptr) {
        if (p->info.pPlayer->info.idPlayer == idPlayer) {
            ada = true;
            cout << "- "
                 << p->info.pWeapon->info.nama
                 << " (round " << p->info.round << ")\n";
        }
        p = p->next;
    }
    if (!ada) {
        cout << "Belum ada pembelian untuk player ini.\n";
    }
    cout << endl;
}

// ========== CATATAN ==========
// Fungsi delete(), count(), dan lain-lain belum dibuat.
// Fungsi-fungsi tersebut akan dikembangkan di Progress 80% & Final.
