#include <iostream>
#include <limits> // for numeric_limits
#include <cstdlib> // for system("cls")
#include "mll.h"

using namespace std;

// IS: Sembarang
// FS: Layar konsol bersih (kosong)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// IS: Sembarang
// FS: Program berhenti sejenak menunggu input Enter dari user
void pauseFunc() {
    cout << "\n[!] Tekan Enter untuk kembali ke menu...";
    cin.get(); 
    // Handle potential leftover newline
}

// IS: Sembarang
// FS: Menampilkan judul program dan identitas kelompok
void header() {
    clearScreen();
    cout << "==============================================\n";
    cout << "   VALORANT WEAPON STORE MANAGER (MLL TIPE B) \n";
    cout << "==============================================\n";
    cout << "   [ Kelompok 3 - S1 Teknologi Informasi ]    \n";
    cout << "==============================================\n\n";
}

// IS: Label (string) terdefinisi
// FS: Mengembalikan integer valid yang diinputkan user. Jika input bukan angka, diminta ulang.
int inputAngka(string label) {
    int val;
    cout << label;
    while (!(cin >> val)) {
        cout << "   [ERROR] Input harus berupa angka!\n";
        cout << "   Ulangi " << label;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer setelah input berhasil
    return val;
}

// IS: Sembarang
// FS: Menampilkan daftar menu utama ke layar
void showMenu() {
    header();
    cout << "=== MANAJEMEN DATA ===\n";
    cout << "1.  [Insert] Tambah Player Baru\n";
    cout << "2.  [Insert] Tambah Weapon Baru\n";
    cout << "3.  [Insert] Beli Senjata (Transaksi Baru)\n";
    cout << "\n=== VIEW DATA ===\n";
    cout << "4.  [Show] Semua Player\n";
    cout << "5.  [Show] Semua Weapon\n";
    cout << "6.  [Show] Semua Transaksi (Relasi)\n";
    cout << "\n=== PENCARIAN & FILTER ===\n";
    cout << "7.  [Search] Lihat Weapon milik Player tertentu\n";
    cout << "8.  [Search] Lihat Player pemilik Weapon tertentu\n";
    cout << "9.  [View]  Semua Player beserta Belanjaannya\n";
    cout << "10. [View]  Semua Weapon beserta Pembelinya\n";
    cout << "11. [Check] Cek Status Relasi (Apakah A beli B?)\n";
    cout << "\n=== STATISTIK (COUNT) ===\n";
    cout << "12. [Count] Jumlah Senjata per Player\n";
    cout << "13. [Count] Jumlah Pembeli per Weapon\n";
    cout << "14. [Count] Weapon tak laku (Belum dibeli)\n";
    cout << "15. [Count] Player hemat (Belum belanja)\n";
    cout << "\n=== HAPUS & EDIT ===\n";
    cout << "16. [Delete] Hapus Transaksi Spesifik\n";
    cout << "17. [Delete] Hapus Player (Cascading)\n";
    cout << "18. [Delete] Hapus Weapon (Cascading)\n";
    cout << "19. [Edit]   Ganti Senjata pada Transaksi\n";
    cout << "20. [Edit]   Ganti Pembeli pada Transaksi\n";
    cout << "0.  Keluar\n";
    cout << "==============================================\n";
    cout << ">> Pilih Menu: ";
}

int main() {
    ListParent LP; ListChild LC; ListRelasi LR;
    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);

    int pilih;
    do {
        showMenu();
        if (!(cin >> pilih)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilih = -1; // force invalid
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "\n----------------------------------------------\n";

        switch(pilih) {
        case 1: {
            infotypeParent P;
            cout << "Input Data Player Baru\n";
            cout << "ID Player : "; getline(cin, P.idPlayer);
            cout << "Nama      : "; getline(cin, P.nama);
            cout << "Role      : "; getline(cin, P.role);
            P.credit = inputAngka("Credit    : ");

            if (findParent(LP, P.idPlayer) != nullptr) {
                cout << "\n[GAGAL] ID Player '" << P.idPlayer << "' sudah ada!\n";
            } else {
                insertLastParent(LP, alokasiParent(P));
                cout << "\n[BERHASIL] Player berhasil ditambahkan.\n";
            }
            break;
        }
        case 2: {
            infotypeChild W;
            cout << "Input Data Weapon Baru\n";
            cout << "ID Weapon : "; getline(cin, W.idWeapon);
            cout << "Nama      : "; getline(cin, W.nama);
            cout << "Kategori  : "; getline(cin, W.kategori);
            W.harga = inputAngka("Harga     : ");

            if (findChild(LC, W.idWeapon) != nullptr) {
                cout << "\n[GAGAL] ID Weapon '" << W.idWeapon << "' sudah ada!\n";
            } else {
                insertLastChild(LC, alokasiChild(W));
                cout << "\n[BERHASIL] Weapon berhasil ditambahkan.\n";
            }
            break;
        }
        case 3: {
            string idP, idW; 
            cout << "Tambah Transaksi Pembelian\n";
            cout << "ID Player : "; getline(cin, idP);
            cout << "ID Weapon : "; getline(cin, idW);
            int round = inputAngka("Round ke  : ");

            addressParent p = findParent(LP, idP);
            addressChild  w = findChild(LC, idW);

            if (p == nullptr) cout << "\n[GAGAL] Player tidak ditemukan.\n";
            else if (w == nullptr) cout << "\n[GAGAL] Weapon tidak ditemukan.\n";
            else {
                insertFirstRelasi(LR, alokasiRelasi(p, w, round));
                cout << "\n[BERHASIL] Transaksi berhasil dicatat.\n";
            }
            break;
        }
        case 4: showParent(LP); break;
        case 5: showChild(LC); break;
        case 6: showRelasi(LR); break;
        case 7: {
            string idP; cout << "Lihat Belanjaan Player\nID Player: "; getline(cin, idP);
            tampilWeaponPerPlayer(LR, idP);
            break;
        }
        case 8: {
            string idW; cout << "Lihat Pembeli Weapon\nID Weapon: "; getline(cin, idW);
            tampilPlayerPerWeapon(LR, idW);
            break;
        }
        case 9: tampilSemuaPlayerDanWeapon(LP, LR); break;
        case 10: tampilSemuaWeaponDanPlayer(LC, LR); break;
        case 11: {
            string idP, idW;
            cout << "Cek Relasi\n";
            cout << "ID Player: "; getline(cin, idP);
            cout << "ID Weapon: "; getline(cin, idW);
            if (cekRelasi(LR, idP, idW)) cout << "\n[YA] Ada transaksi antara mereka.\n";
            else cout << "\n[TIDAK] Tidak ada transaksi.\n";
            break;
        }
        case 12: {
            string idP; cout << "Count Weapon by Player\nID Player: "; getline(cin, idP);
            cout << ">> Total Beli: " << hitungTotalWeaponPlayer(LR, idP) << " item.\n";
            break;
        }
        case 13: {
            string idW; cout << "Count Player by Weapon\nID Weapon: "; getline(cin, idW);
            cout << ">> Total Pembeli: " << hitungTotalPlayerWeapon(LR, idW) << " orang.\n";
            break;
        }
        case 14: cout << ">> Weapon tak laku: " << hitungWeaponTidakTerbeli(LC, LR) << "\n"; break;
        case 15: cout << ">> Player hemat: " << hitungPlayerTidakMembeli(LP, LR) << "\n"; break;
        case 16: {
            string idP, idW;
            cout << "Hapus Transaksi\n";
            cout << "ID Player : "; getline(cin, idP);
            cout << "ID Weapon : "; getline(cin, idW);
            int round = inputAngka("Round ke  : ");
            if (deleteRelasi(LR, idP, idW, round)) cout << "\n[BERHASIL] Relasi dihapus.\n";
            else cout << "\n[GAGAL] Relasi tidak ditemukan.\n";
            break;
        }
        case 17: {
            string idP; cout << "Hapus Player (Cascading)\nID Player: "; getline(cin, idP);
            if (deleteParent(LP, LR, idP)) cout << "\n[BERHASIL] Player & history belanjanya dihapus.\n";
            else cout << "\n[GAGAL] Player tidak ditemukan.\n";
            break;
        }
        case 18: {
            string idW; cout << "Hapus Weapon (Cascading)\nID Weapon: "; getline(cin, idW);
            if (deleteChild(LC, LR, idW)) cout << "\n[BERHASIL] Weapon & history penjualannya dihapus.\n";
            else cout << "\n[GAGAL] Weapon tidak ditemukan.\n";
            break;
        }
        case 19: {
            string idP, idLama, idBaru;
            cout << "Edit Transaksi (Ganti Senjata)\n";
            cout << "ID Player      : "; getline(cin, idP);
            cout << "ID Weapon Lama : "; getline(cin, idLama);
            int round = inputAngka("Round ke       : ");
            cout << "ID Weapon Baru : "; getline(cin, idBaru);
            if (editRelasiGantiWeapon(LR, LC, idP, idLama, round, idBaru))
                cout << "\n[BERHASIL] Data transaksi diperbarui.\n";
            else cout << "\n[GAGAL] Gagal edit (Data tidak valid).\n";
            break;
        }
        case 20: {
            string idP, idW, idBaru;
            cout << "Edit Transaksi (Ganti Pembeli)\n";
            cout << "ID Player Lama : "; getline(cin, idP);
            cout << "ID Weapon      : "; getline(cin, idW);
            int round = inputAngka("Round ke       : ");
            cout << "ID Player Baru : "; getline(cin, idBaru);
            if (editRelasiGantiPlayer(LR, LP, idP, idW, round, idBaru))
                cout << "\n[BERHASIL] Data transaksi diperbarui.\n";
            else cout << "\n[GAGAL] Gagal edit (Data tidak valid).\n";
            break;
        }
        case 0: cout << "Keluar dari program...\n"; break;
        default: cout << "[!] Menu tidak tersedia.\n"; break;
        }

        if (pilih != 0) pauseFunc();

    } while (pilih != 0);

    return 0;
}
