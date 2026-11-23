# 📚 Modul Panduan Belajar C++ & PBO - Sistem ATM Bank Nyahu

> **Dokumen Khusus:** Dibuat untuk memandu anggota tim yang masih awam dengan C++ dan Pemrograman Berorientasi Objek (PBO) agar dapat memahami alur program dan mengerjakan tugas masing-masing dengan mudah.

---

## 🎯 DAFTAR URUTAN BELAJAR

1. [Modul 1: Gambaran Besar & Analogi Dunia Nyata](#modul-1-gambaran-besar--analogi-dunia-nyata)
2. [Modul 2: Struktur File C++ (Kenapa Ada .h dan .cpp?)](#modul-2-struktur-file-c-kenapa-ada-h-dan-cpp)
3. [Modul 3: Konsep PBO dari Nol (Class, Object, Method, Attribute)](#modul-3-konsep-pbo-dari-nol)
4. [Modul 4: Memahami Pointer (\*), Reference (&), dan Tanda Panah (->)](#modul-4-memahami-pointer-reference-dan-tanda-panah--)
5. [Modul 5: Menyimpan Banyak Data dengan Vector (std::vector)](#modul-5-menyimpan-banyak-data-dengan-vector)
6. [Modul 6: Kodingan Praktek Sederhana (Studi Kasus Dompet Digital)](#modul-6-kodingan-praktek-sederhana-studi-kasus-dompet-digital)
7. [Modul 7: Menelusuri Alur Program Saat Dijalankan](#modul-7-menelusuri-alur-program-saat-dijalankan)
8. [Modul 8: Contekan Kode (Cheat Sheet) untuk Tugas Setiap Anggota](#modul-8-contekan-kode-cheat-sheet-untuk-tugas-setiap-anggota)
9. [Modul 9: Troubleshooting Error Umum di C++](#modul-9-troubleshooting-error-umum-di-c)

---

## Modul 1: Gambaran Besar & Analogi Dunia Nyata

Bayangkan kita sedang membuat sistem komputer untuk sebuah **Kantor Cabang Bank Nyata**:

1. **Nasabah / Buku Tabungan (`Account`):** Setiap nasabah yang datang memiliki buku tabungan fisik. Di buku itu tercatat Nomor Rekening, Nama Pemilik, PIN rahasia, Saldo saat ini, dan status apakah rekening aktif atau terblokir.
2. **Lembar Mutasi / Struk Transaksi (`Transaction`):** Setiap kali ada uang keluar atau masuk, bank mencetak selembar struk mutasi (berisi ID transaksi, jenis transaksi, tanggal, nominal, dan sisa saldo).
3. **Brankas / Database Bank (`AccountManager`):** Bank memiliki lemari arsip pusat yang menyimpan semua buku tabungan nasabah. Petugas bank bisa mencari buku tabungan berdasarkan nomor rekening atau menambahkan buku tabungan baru ke lemari ini.
4. **Mesin Cetak Transaksi (`TransactionManager`):** Alat yang otomatis mencetak struk transaksi baru dengan nomor urut transaksi unik (`TRX1`, `TRX2`, dst.).

---

## Modul 2: Struktur File C++ (Kenapa Ada .h dan .cpp?)

Di proyek skala menengah, kita tidak menulis ribuan baris kode di satu file `main.cpp`. Kita membaginya menjadi dua jenis file:

### 1. File Header (`.h`) $\rightarrow$ Seperti "Daftar Menu Restoran"

- Hanya berisi **daftar nama fungsi dan cetakan class** tanpa logika panjangnya.
- Tujuannya agar file lain bisa membaca fungsi apa saja yang tersedia tanpa harus membaca ratusan baris isi kodenya.
- Di baris paling atas selalu ada `#pragma once` agar file ini tidak dibaca berulang kali oleh compiler.

### 2. File Source (`.cpp`) $\rightarrow$ Seperti "Dapur Restoran"

- Tempat menulis **resep dan logika detail** dari fungsi-fungsi yang tadi didaftarkan di file `.h`.

### 3. File Bantuan (`helpers/`)

- Berisi fungsi utilitas siap pakai agar kita tidak perlu membuat ulang:
  - `displayHeader("JUDUL")`: Mencetak header bergaris `=` yang rapi.
  - `waitEnter()`: Menghentikan program sejenak dan menunggu user menekan tombol Enter.
  - `inputPassword()`: Menginput PIN dengan sensor bintang `*`.
  - `getCurrentTimestamp()`: Mengambil tanggal dan jam saat ini.

---

## Modul 3: Konsep PBO dari Nol

Bagi yang belum pernah belajar PBO, jangan khawatir dengan istilah-istilah sulit. Cukup pahami 4 pilar sederhana ini:

### 1. Class vs Object (Cetakan vs Kue Nyata)

- **Class (`Account`):** Adalah **formulir kosong pembukaan rekening**. Di formulir sudah tertulis bahwa setiap nasabah _pasti punya_:
  - Nomor Rekening
  - Nama
  - PIN
  - Saldo
- **Object (`acc1`, `acc2`):** Adalah **hasil formulir yang sudah diisi**:
  - Objek 1: Rekening Budi Santoso (Saldo 5 Juta)
  - Objek 2: Rekening Siti Aminah (Saldo 2.5 Juta)
  - Keduanya punya bentuk yang sama persis, tetapi data di dalamnya terpisah dan mandiri.

### 2. Attribute / Property (Variabel Objek)

Variabel yang berada di dalam class untuk menyimpan data objek:

```cpp
string accountNumber;
string ownerName;
double balance;
bool isActive;
```

### 3. Method (Fungsi Objek)

Fungsi yang melekat pada objek untuk melihat atau mengubah data objek tersebut:

```cpp
acc1.getBalance();           // Mengambil saldo milik Budi
acc1.setPin("654321");       // Mengubah PIN milik Budi
```

### 4. Encapsulation (`private` vs `public`)

- **`private`**: Data sensitif (seperti saldo dan PIN) disembunyikan. Kode dari luar **dilarang keras** mengubah saldo langsung seperti `acc1.balance = 1000000;`.
- **`public`**: Jalur resmi yang disediakan class. Jika ingin melihat saldo, panggil `acc1.getBalance()`. Jika ingin mengubah saldo, panggil `acc1.setBalance(saldoBaru)`.

---

## Modul 4: Memahami Pointer (`*`), Reference (`&`), dan Tanda Panah (`->`)

Ini adalah bagian yang paling krusial di C++:

### 1. Masalah Fotokopi (Pass by Value)

Jika kita mengirim objek rekening biasa ke sebuah fungsi:

```cpp
void tarikUang(Account acc) {
    acc.setBalance(0); // Komputer hanya mengubah fotokopiannya!
}
```

Rekening asli nasabah di database saldonya **tidak berkurang sama sekali** karena komputer secara default menduplikasi (memfotokopi) objek.

### 2. Solusinya: Berikan Alamat Aslinya (Pointer `Account*` & Reference `&`)

- **Pointer (`Account*`)**: Menyimpan **alamat memori** dari buku tabungan asli.
- **Tanda Panah (`->`)**: Digunakan untuk mengakses fungsi objek jika kita memegang pointer-nya:

  ```cpp
  Account* loggedInAccount = ...; // Menunjuk ke buku tabungan asli

  // Ambil saldo asli nasabah:
  double saldo = loggedInAccount->getBalance();

  // Ubah saldo asli nasabah:
  loggedInAccount->setBalance(saldo - 100000);
  ```

- **Reference (`&`)**: Digunakan di parameter fungsi seperti `AccountManager& accountManager` agar fungsi tersebut bekerja langsung di brankas asli, bukan fotokopian brankas.

---

## Modul 5: Menyimpan Banyak Data dengan Vector

Di C++ dasar, kita biasanya menggunakan array biasa: `int arr[10];`. Kelemahannya, ukurannya kaku dan tidak bisa bertambah jika nasabah bertambah.

Di proyek ini, kita menggunakan `std::vector` (array dinamis yang ukurannya bisa membesar otomatis):

### 3 Operasi Vector yang Wajib Diketahui:

1. **Menambahkan Data Baru (`push_back`):**
   ```cpp
   accounts.push_back(newAccount); // Menambah rekening baru di akhir list
   ```
2. **Mengecek Apakah Data Kosong (`empty()`):**
   ```cpp
   if (loggedInAccount->getTransactions().empty()) {
       cout << "Belum ada riwayat transaksi." << endl;
   }
   ```
3. **Menampilkan Seluruh Data (Perulangan Modern):**
   ```cpp
   // Looping seluruh riwayat transaksi nasabah:
   for (const auto& trx : loggedInAccount->getTransactions()) {
       cout << trx.getTransactionId() << " | "
            << trx.getType() << " | "
            << trx.getAmount() << endl;
   }
   ```

---

## Modul 6: Kodingan Praktek Sederhana (Studi Kasus Dompet Digital)

Untuk membuktikan semua teori di atas, kita telah membuat satu file latihan mandiri bernama **`contoh_sederhana.cpp`** (hanya 80 baris, tanpa folder terpisah).

### Cara Menjalankan Contoh Ini di Terminal:

```powershell
g++ contoh_sederhana.cpp -o contoh.exe
.\contoh.exe
```

---

### Bedah Kode Bertahap:

#### 1. Membuat Class & Enkapsulasi (Private vs Public)

```cpp
class Dompet {
private:
    string pemilik;
    double saldo; // RAHASIA: Tidak bisa diubah seenaknya dari luar

public:
    // Constructor: Cetakan awal
    Dompet(string namaPemilik, double saldoAwal) {
        pemilik = namaPemilik;
        saldo = saldoAwal;
    }

    // Getter: Jalur resmi melihat data
    string getPemilik() const { return pemilik; }
    double getSaldo() const { return saldo; }

    // Setter/Method: Jalur resmi mengubah saldo dengan verifikasi
    void kurangiUang(double jumlah) {
        if (jumlah <= saldo) {
            saldo -= jumlah;
        } else {
            cout << "Saldo tidak cukup!" << endl;
        }
    }
};
```

> **Poin Utama:** Kode luar tidak bisa mengetik `dompetBudi.saldo = 999999;`. Jika ingin mengurangi saldo, wajib memanggil `dompetBudi.kurangiUang(...)`.

---

#### 2. Uji Coba: Kenapa Butuh Pointer (`*` dan `->`)?

Perhatikan perbedaan dua fungsi di bawah ini:

```cpp
// KASUS A: Objek Biasa (Fotokopian / Pass by Value)
void cobaTarikFotokopi(Dompet dompetCopy, double jumlah) {
    dompetCopy.kurangiUang(jumlah);
    // Yang berkurang cuma fotokopiannya!
}

// KASUS B: Pointer (Alamat Asli / Pass by Pointer)
void tarikUangAsli(Dompet* dompetAsli, double jumlah) {
    // Karena memegang pointer (*), kita gunakan tanda panah (->)
    dompetAsli->kurangiUang(jumlah);
}
```

**Hasil Saat Dijalankan di `main()`:**

```cpp
Dompet dompetBudi("Budi Santoso", 500000);

// Uji Coba 1: Tanpa Pointer
cobaTarikFotokopi(dompetBudi, 200000);
cout << dompetBudi.getSaldo(); // Output: Rp500.000 (TIDAK BERKURANG!)

// Uji Coba 2: Menggunakan Pointer
tarikUangAsli(&dompetBudi, 200000); // Tanda '&' memberikan alamat asli
cout << dompetBudi.getSaldo(); // Output: Rp300.000 (BERHASIL BERKURANG!)
```

> **Kesimpulan:** Di proyek ATM kita, user yang login disimpan sebagai pointer: `Account* loggedInAccount`. Itulah sebabnya saat transaksi penarikan kita memanggil tanda panah: `loggedInAccount->setBalance(...)`.

---

#### 3. Uji Coba: Menyimpan Banyak Objek dengan `vector`

```cpp
vector<Dompet> daftarDompet;

// Memasukkan dompet ke dalam list:
daftarDompet.push_back(dompetBudi);
daftarDompet.push_back(dompetSiti);
daftarDompet.push_back(Dompet("Joko Widodo", 1000000));

// Looping menampilkan semua isi vector:
for (int i = 0; i < daftarDompet.size(); i++) {
    cout << i + 1 << ". " << daftarDompet[i].getPemilik()
         << " | Saldo: Rp" << daftarDompet[i].getSaldo() << endl;
}
```

---

## Modul 7: Menelusuri Alur Program Saat Dijalankan

Mari kita ikuti bagaimana data berpindah dari awal sampai akhir:

```
[1. main.cpp]
    │
    ├── Buat AccountManager (Database Bank)
    ├── Buat 3 rekening dummy (Budi, Siti, Joko) dan masukkan ke manager
    │
    ▼
[2. Menu Utama Bank]
    ├── Pilih 1: Admin Login
    │       └── loginAdmin() ──> Jika sukses ──> adminDashboard(accountManager)
    │
    └── Pilih 2: User Login
            └── loginUser(accountManager, loggedInAccount)
                    │
                    ├── 1. Minta No Rekening ──> cari via accountManager.findAccount()
                    ├── 2. Cek apakah rekening aktif
                    ├── 3. Minta PIN (maks 3x coba) ──> cek acc->getPin()
                    │
                    ▼ Jika sukses: Alamat rekening asli (loggedInAccount) dikembalikan
            └── userDashboard(loggedInAccount, accountManager, transactionManager)
                    ├── Tarik Tunai
                    ├── Setor Tunai
                    ├── Cek Saldo
                    ├── Transfer
                    └── Riwayat Transaksi
```

---

## Modul 8: Contekan Kode (Cheat Sheet) untuk Tugas Setiap Anggota

Buka file yang menjadi tanggung jawab Anda, dan gunakan pola kode di bawah ini:

---

### 🔹 Untuk DEVA (Tahap 2: Manajemen Rekening di `admin/admin.cpp`)

#### A. Melihat Seluruh Rekening:

```cpp
void viewAllAccounts(AccountManager& accountManager) {
    system("cls");
    displayHeader("DAFTAR REKENING NASABAH");

    vector<Account>& list = accountManager.getAllAccounts();
    if (list.empty()) {
        cout << "Belum ada nasabah terdaftar." << endl;
    } else {
        for (const auto& acc : list) {
            cout << "No Rek : " << acc.getAccountNumber() << endl;
            cout << "Nama   : " << acc.getOwnerName() << endl;
            cout << "Saldo  : Rp" << acc.getBalance() << endl;
            cout << "Status : " << (acc.getIsActive() ? "Aktif" : "Nonaktif") << endl;
            cout << "---------------------------------" << endl;
        }
    }
    waitEnter();
}
```

#### B. Membuat Rekening Baru:

```cpp
void createAccount(AccountManager& accountManager) {
    system("cls");
    displayHeader("BUAT REKENING BARU");

    string name, accNum, pin;
    cout << "Nama Pemilik: "; cin >> name;
    cout << "Nomor Rekening (10 digit): "; cin >> accNum;

    // Cek apakah nomor rekening sudah dipakai:
    if (accountManager.findAccount(accNum) != nullptr) {
        cout << "Nomor rekening sudah terdaftar!" << endl;
        waitEnter();
        return;
    }

    cout << "PIN (6 digit): "; pin = inputPassword();

    // Buat objek rekening baru dan simpan ke manager:
    Account newAcc(accNum, name, pin, 0.0, true);
    accountManager.addAccount(newAcc);

    cout << "\nRekening berhasil dibuat!" << endl;
    waitEnter();
}
```

---

### 🔹 Untuk RAYXEL (Tahap 3: Cek Saldo & Riwayat di `user/user.cpp`)

#### A. Cek Saldo User:

```cpp
void checkBalance(Account* loggedInAccount) {
    system("cls");
    displayHeader("INFORMASI SALDO");

    cout << "Nomor Rekening : " << loggedInAccount->getAccountNumber() << endl;
    cout << "Nama Nasabah   : " << loggedInAccount->getOwnerName() << endl;
    cout << "Sisa Saldo     : Rp" << loggedInAccount->getBalance() << endl;
    cout << "Waktu Akses    : " << getCurrentTimestamp() << endl;

    waitEnter();
}
```

#### B. Melihat Riwayat Transaksi:

```cpp
void viewUserTransactionHistory(Account* loggedInAccount) {
    system("cls");
    displayHeader("RIWAYAT TRANSAKSI");

    const vector<Transaction>& history = loggedInAccount->getTransactions();
    if (history.empty()) {
        cout << "Belum terdapat riwayat transaksi." << endl;
    } else {
        for (const auto& trx : history) {
            cout << "[" << trx.getTimestamp() << "] " << trx.getType() << endl;
            cout << "ID Transaksi : " << trx.getTransactionId() << endl;
            cout << "Nominal      : Rp" << trx.getAmount() << endl;
            cout << "Saldo Akhir  : Rp" << trx.getBalanceAfter() << endl;
            cout << "Keterangan   : " << trx.getDescription() << endl;
            cout << "----------------------------------------" << endl;
        }
    }
    waitEnter();
}
```

---

### 🔹 Untuk NANDA (Tahap 4: Tarik Tunai & Setor Tunai di `user/user.cpp`)

#### A. Tarik Tunai:

```cpp
void withdrawCash(Account* loggedInAccount, TransactionManager& transactionManager) {
    system("cls");
    displayHeader("TARIK TUNAI");

    double nominal;
    cout << "Masukkan nominal penarikan: Rp";
    cin >> nominal;

    // 1. Cek saldo mencukupi
    if (nominal > loggedInAccount->getBalance()) {
        cout << "Saldo tidak mencukupi!" << endl;
        waitEnter();
        return;
    }

    // 2. Kurangi saldo
    double saldoBaru = loggedInAccount->getBalance() - nominal;
    loggedInAccount->setBalance(saldoBaru);

    // 3. Catat transaksi
    Transaction trx = transactionManager.createTransaction(
        "Tarik Tunai", nominal, getCurrentTimestamp(), "Penarikan Tunai ATM", saldoBaru
    );
    loggedInAccount->addTransaction(trx);

    cout << "\nPenarikan berhasil! Sisa saldo: Rp" << saldoBaru << endl;
    waitEnter();
}
```

#### B. Setor Tunai:

```cpp
void depositCash(Account* loggedInAccount, TransactionManager& transactionManager) {
    system("cls");
    displayHeader("SETOR TUNAI");

    double nominal;
    cout << "Masukkan nominal setor tunai: Rp";
    cin >> nominal;

    if (nominal <= 0) {
        cout << "Nominal setor tidak valid!" << endl;
        waitEnter();
        return;
    }

    // 1. Tambah saldo
    double saldoBaru = loggedInAccount->getBalance() + nominal;
    loggedInAccount->setBalance(saldoBaru);

    // 2. Catat transaksi
    Transaction trx = transactionManager.createTransaction(
        "Setor Tunai", nominal, getCurrentTimestamp(), "Setor Tunai ATM", saldoBaru
    );
    loggedInAccount->addTransaction(trx);

    cout << "\nSetor tunai berhasil! Saldo saat ini: Rp" << saldoBaru << endl;
    waitEnter();
}
```

---

### 🔹 Untuk ANDIKA (Tahap 5: Transfer Antar Rekening di `user/user.cpp`)

```cpp
void transferFunds(Account* loggedInAccount, AccountManager& accountManager, TransactionManager& transactionManager) {
    system("cls");
    displayHeader("TRANSFER ANTAR REKENING");

    string targetNo;
    cout << "Masukkan Nomor Rekening Tujuan: ";
    cin >> targetNo;

    // 1. Validasi tidak transfer ke rekening sendiri
    if (targetNo == loggedInAccount->getAccountNumber()) {
        cout << "Tidak dapat transfer ke nomor rekening sendiri!" << endl;
        waitEnter();
        return;
    }

    // 2. Cari rekening tujuan
    Account* targetAcc = accountManager.findAccount(targetNo);
    if (targetAcc == nullptr) {
        cout << "Nomor rekening tujuan tidak ditemukan!" << endl;
        waitEnter();
        return;
    }

    // 3. Cek status aktif rekening tujuan
    if (!targetAcc->getIsActive()) {
        cout << "Rekening tujuan sedang dinonaktifkan!" << endl;
        waitEnter();
        return;
    }

    cout << "Penerima: " << targetAcc->getOwnerName() << endl;
    double nominal;
    cout << "Masukkan Nominal Transfer: Rp";
    cin >> nominal;

    // 4. Cek kecukupan saldo pengirim
    if (nominal > loggedInAccount->getBalance() || nominal <= 0) {
        cout << "Saldo tidak mencukupi atau nominal tidak valid!" << endl;
        waitEnter();
        return;
    }

    // 5. Eksekusi transfer (kurangi pengirim, tambah penerima)
    double saldoPengirimBaru = loggedInAccount->getBalance() - nominal;
    double saldoPenerimaBaru = targetAcc->getBalance() + nominal;

    loggedInAccount->setBalance(saldoPengirimBaru);
    targetAcc->setBalance(saldoPenerimaBaru);

    // 6. Catat mutasi di KEDUA rekening
    Transaction trxPengirim = transactionManager.createTransaction(
        "Transfer Keluar", nominal, getCurrentTimestamp(),
        "Transfer ke " + targetAcc->getOwnerName(), saldoPengirimBaru
    );
    loggedInAccount->addTransaction(trxPengirim);

    Transaction trPenerima = transactionManager.createTransaction(
        "Transfer Masuk", nominal, getCurrentTimestamp(),
        "Transfer dari " + loggedInAccount->getOwnerName(), saldoPenerimaBaru
    );
    targetAcc->addTransaction(trPenerima);

    cout << "\nTransfer berhasil ke " << targetAcc->getOwnerName() << "!" << endl;
    cout << "Sisa saldo Anda: Rp" << saldoPengirimBaru << endl;
    waitEnter();
}
```

---

## Modul 9: Troubleshooting Error Umum di C++

| Pesan Error                                              | Penyebab                                                     | Solusi                                                                                   |
| :------------------------------------------------------- | :----------------------------------------------------------- | :--------------------------------------------------------------------------------------- |
| `undefined reference to ...`                             | File `.cpp` lainnya tidak ikut dikompilasi.                  | Jangan compile cuma 1 file. Jalankan perintah kompilasi lengkap atau tekan **Run Code**. |
| `request for member ... in ... which is of pointer type` | Menggunakan titik (`.`) pada variabel pointer.               | Ganti titik (`.`) menjadi tanda panah (`->`). Contoh: `acc->getBalance()`.               |
| `no matching function for call to ...`                   | Parameter fungsi tidak sesuai dengan deklarasi di file `.h`. | Cek file `.h` dan pastikan tipe data serta urutan argumennya sama.                       |
| Layar langsung menutup sendiri / skip input              | Tombol `Enter` tertinggal di buffer `cin`.                   | Gunakan fungsi `waitEnter()` yang sudah disediakan di `helpers.h`.                       |
