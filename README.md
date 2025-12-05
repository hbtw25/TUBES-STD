Berikut **README.md Progress 40%** yang *rapi, sederhana, akademis*, dan **siap dimasukkan ke LMS**.

Kamu tinggal copy–paste ke file `README.md` di dalam folder project.

---

# 📘 **Tugas Besar Struktur Data – Progress 40%**

## **Sistem Manajemen Pembelian Senjata Buy Phase Valorant**

### **Multi Linked List Tipe B (Parent: SLL, Child: DLL)**

### **Kelompok 3 – Kelas 3B S1 Teknologi Informasi**

**Anggota Kelompok:**

| NIM              | Nama                              | List yang Dikerjakan  |
| ---------------- | --------------------------------- | --------------------- |
| **103032430021** | **Harsya Brahmantyo Wibowo**      | Parent (Player) – SLL |
| **103032400011** | **Raditya Vihandika Bari Jabran** | Child (Weapon) – DLL  |

---

# 📌 **1. Deskripsi Singkat Program**

Program ini merupakan implementasi **Multi Linked List (MLL) Tipe B**, di mana terdapat:

1. **List Parent (Single Linked List – SLL):**
   Menyimpan data **Player** pada game Valorant.
2. **List Child (Double Linked List – DLL):**
   Menyimpan data **Weapon/Equipment** yang tersedia pada Buy Phase.
3. **List Relasi (SLL):**
   Menghubungkan Player dengan Weapon yang dibeli pada sebuah round.

Hubungan bersifat **Many-to-Many (M ke N)**:

* 1 Player dapat membeli banyak Weapon.
* 1 Weapon dapat dibeli oleh banyak Player (pada transaksi berbeda).

Program dibuat sederhana agar mudah dipresentasikan pada level mahasiswa semester 3.

---

# 📌 **2. Struktur Data (Progress 40%)**

### ✔ **Struct yang sudah dibuat**

* `Player`
* `Weapon`
* `Relasi`
* `NodeParent` (SLL)
* `NodeChild` (DLL)
* `NodeRelasi` (SLL)
* `ListParent`, `ListChild`, `ListRelasi`

### ✔ **Fungsi-fungsi ADT yang sudah dibuat**

#### **Parent – SLL**

* `createListParent()`
* `alokasiParent()`
* `insertLastParent()`
* `findParent()`
* `showParent()`

#### **Child – DLL**

* `createListChild()`
* `alokasiChild()`
* `insertLastChild()`
* `findChild()`
* `showChild()`

#### **Relasi – SLL**

* `createListRelasi()`
* `alokasiRelasi()`
* `insertFirstRelasi()`
* `showRelasi()`
* `showWeaponByPlayer()` *(versi sederhana)*

---

# 📌 **3. Fitur yang Berhasil Diimplementasikan (40%)**

### ✔ Input data Player

### ✔ Input data Weapon

### ✔ Membuat transaksi pembelian (relasi)

### ✔ Menampilkan:

* Semua Player
* Semua Weapon
* Semua transaksi pembelian
* Semua weapon yang dibeli oleh 1 player

### ✔ Program sudah terpisah menjadi 3 file:

* `mll.h` → ADT / deklarasi
* `mll.cpp` → implementasi fungsi
* `main.cpp` → menu utama dan interaksi pengguna

---

# 📌 **4. Fitur yang Belum Dibuat (Akan Diselesaikan pada 80% & 100%)**

Sesuai spesifikasi MLL Tipe B, berikut fitur yang masih **TODO**:

### ❌ Delete Data

* Hapus Player
* Hapus Weapon
* Hapus Relasi

### ❌ Validasi & Pencarian Lanjutan

* Mengecek apakah player membeli weapon tertentu
* Menampilkan semua player yang membeli satu weapon
* Menampilkan semua player beserta daftar pembeliannya
* Menampilkan semua weapon beserta pembelinya

### ❌ Perhitungan (Counting)

* Jumlah weapon yang dibeli player tertentu
* Jumlah player yang membeli weapon tertentu
* Jumlah weapon yang belum dibeli
* Jumlah player yang belum membeli

### ❌ Edit Relasi

* Mengganti weapon dalam pembelian
* Mengganti player dalam pembelian

---

# 📌 **5. Cara Menjalankan Program (Code::Blocks)**

1. Buat project baru **Console Application C++**.
2. Tambahkan file berikut:

   * `mll.h`
   * `mll.cpp`
   * `main.cpp`
3. Pastikan ketiganya ada dalam project.
4. Klik **Build & Run**.

---

# 📌 **6. Catatan Presentasi**

* Setiap anggota menjelaskan **list yang menjadi bagiannya**:

  * **Harsya → Parent (SLL)**
  * **Raditya → Child (DLL)**
* Relasi dijelaskan **bersama-sama**, karena menjadi penghubung.
* Program sengaja dibuat sederhana agar lebih fokus pada:

  * pemahaman pointer,
  * bentuk linked list,
  * relasi antar list.

---

# 📌 **7. Status Progress**

**Progress ADT & kode mencapai ±40% dari total spesifikasi Tugas Besar.**

---

