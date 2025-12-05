// TUGAS BESAR STRUKTUR DATA
// Manajemen Pembelian Senjata pada Buy Phase Game Valorant
// Tipe MLL : B (Parent SLL, Child DLL)

// Kelompok 3 :
// 103032430021 - Harsya Brahmantyo Wibowo
// 103032400011 - Raditya Vihandika Bari Jabran

#include <iostream>
#include "mll.h"

using namespace std;

void menu() {
    cout << "==============================\n";
    cout << "  BUY PHASE VALORANT (MLL B)  \n";
    cout << "==============================\n";
    cout << "1. Tambah Player\n";
    cout << "2. Tambah Weapon\n";
    cout << "3. Tampilkan Player\n";
    cout << "4. Tampilkan Weapon\n";
    cout << "5. Tambah Transaksi Pembelian\n";
    cout << "6. Tampilkan Semua Transaksi\n";
    cout << "7. Tampilkan Weapon yang dibeli 1 Player\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

int main() {
    ListParent LP;
    ListChild  LC;
    ListRelasi LR;

    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);

    int pilih;
    do {
        menu();
        cin >> pilih;
        cin.ignore();   // buang newline setelah input angka

        if (pilih == 1) {
            Player P;
            cout << "ID Player   : ";
            getline(cin, P.idPlayer);
            cout << "Nama        : ";
            getline(cin, P.nama);
            cout << "Role        : ";
            getline(cin, P.role);
            cout << "Credit      : ";
            cin >> P.credit;
            cin.ignore();

            NodeParent *N = alokasiParent(P);
            insertLastParent(LP, N);
            cout << "Player ditambahkan.\n\n";

        } else if (pilih == 2) {
            Weapon W;
            cout << "ID Weapon   : ";
            getline(cin, W.idWeapon);
            cout << "Nama        : ";
            getline(cin, W.nama);
            cout << "Kategori    : ";
            getline(cin, W.kategori);
            cout << "Harga       : ";
            cin >> W.harga;
            cin.ignore();

            NodeChild *N = alokasiChild(W);
            insertLastChild(LC, N);
            cout << "Weapon ditambahkan.\n\n";

        } else if (pilih == 3) {
            showParent(LP);

        } else if (pilih == 4) {
            showChild(LC);

        } else if (pilih == 5) {
            string idP, idW;
            int round;
            cout << "ID Player : ";
            getline(cin, idP);
            cout << "ID Weapon : ";
            getline(cin, idW);
            cout << "Round ke : ";
            cin >> round;
            cin.ignore();

            NodeParent *p = findParent(LP, idP);
            NodeChild  *c = findChild(LC, idW);

            if (p == nullptr) {
                cout << "Player tidak ditemukan.\n\n";
            } else if (c == nullptr) {
                cout << "Weapon tidak ditemukan.\n\n";
            } else {
                NodeRelasi *r = alokasiRelasi(p, c, round);
                insertFirstRelasi(LR, r);
                cout << "Transaksi dicatat.\n\n";
            }

        } else if (pilih == 6) {
            showRelasi(LR);

        } else if (pilih == 7) {
            string idP;
            cout << "Masukkan ID Player: ";
            getline(cin, idP);
            showWeaponByPlayer(LR, idP);
        }

    } while (pilih != 0);

    cout << "Program selesai.\n";
    return 0;
}
