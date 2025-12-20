# 📘 **Tugas Besar Struktur Data – Final Release (100%)**

## **Sistem Manajemen Pembelian Senjata Buy Phase Valorant**

### **Multi Linked List Tipe B (Parent: SLL, Child: DLL)**

### **Kelompok 3 – Kelas 3B S1 Teknologi Informasi**

**Anggota Kelompok:**

| NIM              | Nama                              | Peran / Fokus         |
| ---------------- | --------------------------------- | --------------------- |
| **103032430021** | **Harsya Brahmantyo Wibowo**      | Parent (Player) – SLL |
| **103032400011** | **Raditya Vihandika Bari Jabran** | Child (Weapon) – DLL  |

---

# 📌 **1. Deskripsi Program**

Program ini adalah implementasi **Multi Linked List (MLL) Tipe B** untuk mensimulasikan sistem pembelian senjata pada game Valorant.
Sistem ini menangani relasi **Many-to-Many** antara **Player** dan **Weapon**, di mana:
*   Satu Player bisa membeli banyak Weapon.
*   Satu Weapon bisa dibeli oleh banyak Player.

Relasi antar data direpresentasikan menggunakan **Linked List Relasi**, bukan pointer langsung.

---

# 📌 **2. Spesifikasi Struktur Data**

Codingan ini mengikuti standar **Classic ADT** (Sesuai Modul Lab/Kuliah):
1.  **Typedef Pointer**: Menggunakan `addressParent`, `addressChild`, `addressRelasi` (bukan `Node*` langsung).
2.  **Explicit Arrow Syntax**: Menggunakan akses `P->info`, `P->next` untuk kejelasan logika pointer.
3.  **Nullptr**: Menggunakan standar modern C++11 `nullptr`.
4.  **Memory Management**: Menggunakan `alokasi` dan `dealokasi` terpisah.

**Jenis List:**
*   **List Parent** (Player): **Single Linked List (SLL)**
*   **List Child** (Weapon): **Doubly Linked List (DLL)**
*   **List Relasi** (Transaksi): **Single Linked List (SLL)**

---

# 📌 **3. Status Fitur (100% Completed)**

Berikut adalah daftar fitur yang telah berhasil diimplementasikan sepenuhnya:

### ✅ **A. Manajemen Data Dasar (CRUD)**
| Fitur | Status | Keterangan |
| :--- | :--- | :--- |
| **Insert Player** | ✔ DONE | `insertLastParent` |
| **Insert Weapon** | ✔ DONE | `insertLastChild` |
| **Insert Transaksi** | ✔ DONE | `insertFirstRelasi` |
| **Delete Player** | ✔ DONE | `deleteParent` (Cascading + `dealokasiParent`) |
| **Delete Weapon** | ✔ DONE | `deleteChild` (Cascading + `dealokasiChild`) |
| **Delete Transaksi** | ✔ DONE | `deleteRelasi` (+ `dealokasiRelasi`) |
| **Find Player** | ✔ DONE | `findParent` |
| **Find Weapon** | ✔ DONE | `findChild` |

### ✅ **B. Pelaporan & View (Show)**
| Fitur | Status | Keterangan |
| :--- | :--- | :--- |
| **Show All Player** | ✔ DONE | Menampilkan daftar player |
| **Show All Weapon** | ✔ DONE | Menampilkan daftar weapon |
| **Show All Transaksi** | ✔ DONE | Menampilkan riwayat pembelian |
| **Show Weapon per Player** | ✔ DONE | Menampilkan belanjaan player X |
| **Show Player per Weapon** | ✔ DONE | Menampilkan pembeli weapon Y |
| **Show All Detail** | ✔ DONE | Nested view: Player -> List Belanjaan |

### ✅ **C. Statistik (Counting)**
| Fitur | Status | Keterangan |
| :--- | :--- | :--- |
| **Count Weapon per Player** | ✔ DONE | Berapa senjata yang dibeli si X? |
| **Count Pembeli per Weapon** | ✔ DONE | Berapa orang yang beli senjata Y? |
| **Count Weapon Tak Terbeli** | ✔ DONE | Weapon yang belum laku sama sekali |
| **Count Player Tak Membeli** | ✔ DONE | Player hemat yang belum belanja |

### ✅ **D. Fitur Tambahan**
| Fitur | Status | Keterangan |
| :--- | :--- | :--- |
| **Edit Transaksi** | ✔ DONE | Ganti senjata (`editRelasiGantiWeapon`) |
| **Edit Transaksi** | ✔ DONE | Ganti pembeli (`editRelasiGantiPlayer`) |
| **Cek Relasi** | ✔ DONE | Apakah Player A beli Weapon B? |

---

# 📌 **4. Cara Menjalankan Program**

1.  Pastikan compiler mendukung C++11 (bawaan GCC/MinGW modern sudah support).
2.  File sumber kode (source code):
    *   `mll.h` (Header ADT)
    *   `mll.cpp` (Implementasi Fungsi)
    *   `main.cpp` (Menu Utama)
3.  **Compile & Run**.

Jika menggunakan Code::Blocks / Dev-C++:
1.  Buat **Console Project**.
2.  Masukkan ketiga file tersebut ke dalam project.
3.  Tekan **F9** (Build & Run).

---

# 📌 **5. Catatan Penting (Untuk Asisten/Dosen)**

*   **Dealokasi**: Kami telah mengimplementasikan prosedur `dealokasi` secara eksplisit untuk mencegah *memory leak* saat penghapusan (delete) data Parent, Child, maupun Relasi.
*   **Cascading Delete**: Jika Parent dihapus, semua data Relasi yang terkait dengannya juga ikut terhapus otomatis. Begitu juga dengan Child.
*   **Formal Naming**: Penamaan fungsi menggunakan Bahasa Indonesia baku (`Tidak` bukan `Tak`) agar formal.