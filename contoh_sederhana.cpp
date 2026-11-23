#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==============================================================
// 1. CLASS & ENKAPSULASI (Private vs Public)
// ==============================================================
class Dompet {
private:
    // DATA RAHASIA: Tidak bisa diubah sembarangan dari luar
    string pemilik;
    double saldo;

public:
    // CONSTRUCTOR: Cetakan awal saat dompet pertama kali dibuat
    Dompet(string namaPemilik, double saldoAwal) {
        pemilik = namaPemilik;
        saldo = saldoAwal;
    }

    // GETTER: Jalur resmi untuk "melihat" data
    string getPemilik() const {
        return pemilik;
    }

    double getSaldo() const {
        return saldo;
    }

    // SETTER / METHOD: Jalur resmi untuk "mengubah" saldo secara aman
    void tambahUang(double jumlah) {
        if (jumlah > 0) {
            saldo += jumlah;
        }
    }

    void kurangiUang(double jumlah) {
        if (jumlah <= saldo) {
            saldo -= jumlah;
        } else {
            cout << ">> [Gagal]: Saldo " << pemilik << " tidak cukup!" << endl;
        }
    }
};

// ==============================================================
// 2. POINTER VS OBJEK BIASA (Fotokopi vs Buku Asli)
// ==============================================================

// Kasus A: Mengirim objek biasa (Pass by Value / Fotokopian)
void cobaTarikFotokopi(Dompet dompetCopy, double jumlah) {
    cout << "--> Menarik uang dari dompet fotokopi..." << endl;
    dompetCopy.kurangiUang(jumlah); 
    // Yang berkurang hanya dompetCopy di dalam fungsi ini!
}

// Kasus B: Mengirim pointer (Pass by Pointer / Alamat Asli)
void tarikUangAsli(Dompet* dompetAsli, double jumlah) {
    cout << "--> Menarik uang dari dompet asli menggunakan POINTER (->)..." << endl;
    // Karena memegang pointer (*), kita pakai tanda panah (->)
    dompetAsli->kurangiUang(jumlah); 
}

// ==============================================================
// 3. FUNGSI UTAMA (MAIN)
// ==============================================================
int main() {
    cout << "==================================================" << endl;
    cout << "   DEMO TEKNIS SEDERHANA: PBO, POINTER & VECTOR   " << endl;
    cout << "==================================================\n" << endl;

    // A. MEMBUAT OBJEK (Mencetak dari class Dompet)
    Dompet dompetBudi("Budi Santoso", 500000);
    Dompet dompetSiti("Siti Aminah", 300000);

    cout << "[Kondisi Awal]" << endl;
    cout << "Saldo " << dompetBudi.getPemilik() << ": Rp" << dompetBudi.getSaldo() << endl;
    cout << "Saldo " << dompetSiti.getPemilik() << ": Rp" << dompetSiti.getSaldo() << endl;
    cout << "--------------------------------------------------\n" << endl;


    // B. DEMO BUKTI: KENAPA BUTUH POINTER?
    cout << "[Uji Coba 1: Tanpa Pointer (Fotokopi)]" << endl;
    cobaTarikFotokopi(dompetBudi, 200000);
    // Cek saldo asli Budi:
    cout << "Saldo asli Budi setelah fungsi: Rp" << dompetBudi.getSaldo() << " (TIDAK BERKURANG!)\n" << endl;

    cout << "[Uji Coba 2: Memakai Pointer (Alamat Asli)]" << endl;
    // Tanda '&' artinya kita memberikan ALAMAT ASLI milik Budi
    tarikUangAsli(&dompetBudi, 200000);
    // Cek saldo asli Budi:
    cout << "Saldo asli Budi setelah fungsi: Rp" << dompetBudi.getSaldo() << " (BERHASIL BERKURANG!)\n" << endl;
    cout << "--------------------------------------------------\n" << endl;


    // C. DEMO VECTOR (Menyimpan Banyak Objek)
    cout << "[Uji Coba 3: Menyimpan Banyak Dompet dengan Vector]" << endl;
    vector<Dompet> daftarDompet;

    // Memasukkan objek ke dalam vector dengan push_back:
    daftarDompet.push_back(dompetBudi);
    daftarDompet.push_back(dompetSiti);
    daftarDompet.push_back(Dompet("Joko Widodo", 1000000));

    cout << "Total dompet tersimpan di vector: " << daftarDompet.size() << " dompet.\n" << endl;

    // Looping untuk menampilkan semua isi vector:
    cout << "Daftar Saldo Nasabah di Vector:" << endl;
    for (int i = 0; i < daftarDompet.size(); i++) {
        cout << i + 1 << ". " << daftarDompet[i].getPemilik() 
             << " | Saldo: Rp" << daftarDompet[i].getSaldo() << endl;
    }

    cout << "\n==================================================" << endl;
    cout << "                  DEMO SELESAI                    " << endl;
    cout << "==================================================" << endl;

    return 0;
}
