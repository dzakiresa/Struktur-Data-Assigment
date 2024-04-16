#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int fungsiHas(long long key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct mahasiswa001 {
    long long NIM;
    string nama; 
    int nilai;
    mahasiswa001* next;
    mahasiswa001(long long NIM, string nama, int nilai) : NIM(NIM), nama(nama), nilai(nilai), next(nullptr) {} // Constructor
};

// Class hash table
class HashTable {
private:
    mahasiswa001** table;

public:
    HashTable() { // Constructor
        table = new mahasiswa001*[MAX_SIZE]();
    }

    ~HashTable() { // Destructor
        for (int i = 0; i < MAX_SIZE; i++) { // Menghapus semua node yang ada
            mahasiswa001* current = table[i]; // Menunjuk ke index yang sudah ditentukan
            while (current != nullptr) {
                mahasiswa001* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insert
    void insert(long long NIM, string nama, int nilai) {
        int index = fungsiHas(NIM); // Menggunakan fungsi hash untuk menentukan index
        mahasiswa001* current = table[index]; // Menunjuk ke index yang sudah ditentukan
        while (current != nullptr) {
            if (current->NIM == NIM) {
                current->nilai = nilai;
                return;
            }
            current = current->next;
        }
        mahasiswa001* mahasiswa = new mahasiswa001(NIM, nama, nilai);
        mahasiswa->next = table[index]; // Menunjuk ke node selanjutnya
        table[index] = mahasiswa; // Menunjuk ke node yang baru dibuat
    }

    // Cari berdasar NIM
    mahasiswa001* cariNIM(long long NIM) {
        int index = fungsiHas(NIM); // Menggunakan fungsi hash untuk menentukan index
        mahasiswa001* current = table[index]; // Menunjuk ke index yang sudah ditentukan
        while (current != nullptr) {
            if (current->NIM == NIM) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Cari berdasar rentang nilai (80 - 90)
    void cariNilai(int MulaiRangeNilai, int AkhirRangeNilai) {
        cout << left << setw(15) << "-NAME-" << setw(20) << "-NIM-" << right << setw(2) << "-nilai-" << endl;
        for (int i = 0; i < MAX_SIZE; i++) { // Untuk setiap index yang ada di tabel hash table ini, akan diiterasi satu per satu untuk mencari data yang sesuai dengan range yang diinginkan
            mahasiswa001* current = table[i];
            while (current != nullptr) {
                if (current->nilai >= MulaiRangeNilai && current->nilai <= AkhirRangeNilai) { // Jika nilai mahasiswa berada di dalam range yang diinginkan
                    cout << left << setw(15) << current->nama << setw(20) << current->NIM << right << setw(6) << current->nilai << endl; // Maka data mahasiswa tersebut akan ditampilkan
                }
                current = current->next;
            }
        }
    }

    // Hapus
    void Hapuss(long long NIM) {
    int index = fungsiHas(NIM); // Menggunakan fungsi hash untuk menentukan index
    mahasiswa001* current = table[index]; // Menunjuk ke index yang sudah ditentukan
    mahasiswa001* prev = nullptr;
    
    while (current != nullptr) { // Iterasi untuk mencari data yang akan dihapus
        if (current->NIM == NIM) { // Jika data ditemukan
            if (prev == nullptr) { // Jika data yang akan dihapus berada di awal index
                table[index] = current->next; // Maka index akan menunjuk ke node selanjutnya
            } else {
                prev->next = current->next; // Jika data yang akan dihapus berada di tengah atau akhir index, maka node sebelumnya akan menunjuk ke node setelahnya
            }
            delete current; // Menghapus node yang diinginkan
            cout << "\n NIM " << NIM << " telah berhasil dihapus" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    
    // Jika NIM tidak ditemukan
    cout << "\n NIM " << NIM << " yang anda cari tidak ditemukan" << endl;
}


    // Traversal
    void Traverse() {
        cout << left << setw(17) << "-NAME-" << setw(17) << "-NIM-" << setw(12) << "-nilai-" << endl;
        for (int i = 0; i < MAX_SIZE; i++) { // Diiterasi untuk setiap index yang ada di tabel hash table ini
            mahasiswa001* current = table[i]; // Menunjuk ke index yang sudah ditentukan
            while (current != nullptr) { // Iterasi untuk menampilkan data mahasiswa
                cout << left << setw(17) << current->nama << setw(19) << current->NIM << setw(12) << current->nilai << endl;
                current = current->next;
        }
    }
}
};

int main() {
    HashTable ht; // Membuat objek hash table

    cout << "\nPROGRAM HASH TABLE DATA MAHASISWA" << endl;

    while (true) {
        cout << "\nMENU";
        cout << "\n1. Tambah Data Mahasiswa";
        cout << "\n2. Hapus Data Mahasiswa";
        cout << "\n3. Cari Data berdasarkan NIM Mahasiswa";
        cout << "\n4. Cari nilai berdasarkan rentang";
        cout << "\n5. Tampilkan Data Mahasiswa";
        cout << "\n6. Exit";
        cout << "\nPilih Menu: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nTAMBAH DATA MAHASISWA" << endl;
                long long NIM;
                string nama;
                int nilai;
                cout << "TAMBAHKAN NAMA MAHASISWA: ";
                cin.ignore(); // Untuk menghindari bug cin getline
                getline(cin, nama); // Menggunakan getline untuk input string yang mengandung spasi
                cout << "TAMBAHKAN NIM: ";
                cin >> NIM;
                cout << "MASUKKAN nilai: ";
                cin >> nilai;
                ht.insert(NIM, nama, nilai); // Memasukkan data mahasiswa ke dalam hash table
                cout << "\nSuccess! Kamu telah menambahkan data " << nama << " dengan NIM " << NIM << " dan nilai " << nilai << endl;
                break;
            }
            case 2: {
                cout << "\nHAPUS DATA MAHASISWA" << endl;
                long long NIM;
                cout << "NIM UNTUK DIHAPUS: ";
                cin >> NIM;
                ht.Hapuss(NIM); // Menghapus data mahasiswa dari hash table
                break;
            }
            case 3: {
                cout << "\nCARI BERDASARKAN NIM MAHASISWA" << endl;
                long long NIM;
                cout << "Tambahkan NIM untuk mencari data: ";
                cin >> NIM;
                mahasiswa001* mahasiswa = ht.cariNIM(NIM); // Mencari data mahasiswa berdasarkan NIM
                if (mahasiswa != nullptr) // Jika data ditemukan
                    cout << "\nNIM " << NIM << " merujuk pada " << mahasiswa->nama << " dan mempunyai nilai " << mahasiswa->nilai << endl; // Maka data mahasiswa tersebut akan ditampilkan
                else
                    cout << "\nData Tidak Ditemukan!" << endl;
                break;
            }
            case 4: {
                cout << "\nCARI BERDASSARKAN RENTANG NILAI" << endl;
                int MulaiRangeNilai, AkhirRangeNilai;
                cout << "Rentang mula nilai: ";
                cin >> MulaiRangeNilai;
                cout << "sampai nilai: ";
                cin >> AkhirRangeNilai;
                cout << "\nMahasiswa dengan nilai antara " << MulaiRangeNilai << "-" << AkhirRangeNilai << " adalah:\n";
                ht.cariNilai
        (MulaiRangeNilai, AkhirRangeNilai); // Mencari data mahasiswa berdasarkan range nilai
                break;
            }
            case 5: {
                cout << "\n" << right << setw(8) << "" << "DATA MAHASISWA" << endl;
                ht.Traverse(); // Menampilkan data mahasiswa yang ada di hash table
                break;
            }
            case 6:
                cout << "\nTERIMAKASIHH!";
                return 0;
            default:
                cout << "\nSING MBOK GOLEKI ORA ONO!" << endl;
        }
    }
}