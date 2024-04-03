#include <iostream>
#include <iomanip>
using namespace std;
// DZAKI RESALIANTO 2311102161

// Deklarasi Struct Mahasiswaa
struct Mahasiswaa {
    string nama;
    string NIM;
    Mahasiswaa *next;
};

// Deklarasi variabel head dan tail
Mahasiswaa *head;
Mahasiswaa *tail;

// Inisialisasi linked list
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool KosonG() {
    return head == NULL;
}
// Menghitung jumlah Mahasiswaa dalam linked list
int hitungList() {
    int jumlah = 0;
    Mahasiswaa *bantu = head;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void tambahDepan(string nama, string NIM) {
    // Membuat Mahasiswaa baru
    Mahasiswaa *baru = new Mahasiswaa;
    baru->nama = nama;
    baru->NIM = NIM;
    baru->next = NULL;

    // Jika linked list kosong
    if (KosonG()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void tambahBelakang(string nama, string NIM) {
    // Membuat Mahasiswaa baru
    Mahasiswaa *baru = new Mahasiswaa;
    baru->nama = nama;
    baru->NIM = NIM;
    baru->next = NULL;

    // Jika linked list kosong
    if (KosonG()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void tambahTengah(string nama, string NIM, int posisi) {
    if (posisi < 1 || posisi > hitungList() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi == 1) {
            tambahDepan(nama, NIM);
        } else if (posisi == hitungList() + 1) {
            tambahBelakang(nama, NIM);
        } else {
            Mahasiswaa *baru = new Mahasiswaa;
            baru->nama = nama;
            baru->NIM = NIM;

            Mahasiswaa *bantu = head;
            for (int i = 1; i < posisi - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubahDepan(string nama, string NIM) {
    if (!KosonG()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama;
        string NIM_sebelum = head->NIM;

        // Mengubah data
        head->nama = nama;
        head->NIM = NIM;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubahBelakang(string nama, string NIM) {
    if (!KosonG()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail->nama;
        string NIM_sebelum = tail->NIM;

        // Mengubah data
        tail->nama = nama;
        tail->NIM = NIM;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubahTengah(string nama, string NIM, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        Mahasiswaa *bantu = head;
        for (int i = 1; i < posisi; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu->nama;
        string NIM_sebelum = bantu->NIM;

        // Mengubah data
        bantu->nama = nama;
        bantu->NIM = NIM;

        // Menampilkan informasi
        cout << "Data pada posisi " << posisi << " telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    }
}

// Menghapus data mahasiswa di depan linked list
void Hapus_depan() {
    if (!KosonG()) {
        Mahasiswaa *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void Hapus_belakang() {
    if (!KosonG()) {
        Mahasiswaa *hapus = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            Mahasiswaa *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void Hapus_tengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi == 1) {
            Hapus_depan();
        } else if (posisi == hitungList()) {
            Hapus_belakang();
        } else {
            Mahasiswaa *hapus = head;
            for (int i = 1; i < posisi - 1; ++i) {
                hapus = hapus->next;
            }
            Mahasiswaa *hapus_Mahasiswaa = hapus->next;
            hapus->next = hapus_Mahasiswaa->next;
            delete hapus_Mahasiswaa;
        }
    }
}

// Menghapus seluruh data di dalam linked list
void Hapus_list() {
    while (!KosonG()) {
        Hapus_depan();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan seluruh data dalam linked list
void Tampil() {
    if (!KosonG()) {
        Mahasiswaa *bantu = head;
        int nomor = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while (bantu != NULL) {
            cout << setw(5) << left << nomor << setw(15) << left << bantu->nama << bantu->NIM << endl;
            bantu = bantu->next;
            nomor++; // Menginkremen nomor indeks atau nomor urut
        }
    } else {
        cout << "Linked list kosong!" << endl;
    }
}
int main() {
    init();
    int pilihan;
    string nama;
    string NIM;
    int posisi;

    // Menampilkan menu
        cout << "Menu Linked List Non Circular Mahasiswa" << endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampil" << endl;
        cout << "0.Keluar" << endl;


    do {
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << endl << "TAMBAH DEPAN" << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> NIM;
                cout << "Data telah ditambahkan" << endl;
                cout << endl;
                tambahDepan(nama, NIM);
                break;
            case 2:
                cout << endl << "Tambah Belakang" << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> NIM;
                cout << "Data telah ditambahkan" << endl;
                cout << endl;
                tambahBelakang(nama, NIM);
                break;
            case 3:
                cout << endl << "Tambah Tengah" << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> NIM;
                cout << "Masukkan Posisi :";
                cin >> posisi;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                tambahTengah(nama, NIM, posisi);
                break;
            case 4:
                cout << endl << "Ubah Depan" << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> NIM;
                cout << endl;
                ubahDepan(nama, NIM);
                break;
            case 5:
                cout << endl << "Ubah Belakang" << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> NIM;
                cout << endl;
                ubahBelakang(nama, NIM);
                break;
            case 6:
                cout << endl << "Ubah Tengah" << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> NIM;
                cout << "Masukkan Posisi :";
                cin >> posisi;
                cout << endl;
                ubahTengah(nama, NIM, posisi);
                break;
            case 7:
                cout << endl << "Hapus Depan" << endl;
                cout << "Masukkan Nama: ";
                cin >>nama;
                cout << "data "<<nama<<" berhasil untuk dihapus" << endl;
                cout <<endl;
                Hapus_depan();
                break;
            case 8:
                cout << endl << "Hapus Belakang" << endl;
                cout <<"Masukkan Nama: ";
                cin >>nama;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                Hapus_belakang();
                break;
            case 9:
                cout << endl << "Hapus Tengah" << endl;
                cout <<"Masukkan Nama: ";
                cin >>nama;
                cout <<"Posisi: ";
                cin >>posisi;
                cout << "data "<<nama<<" berhasil untuk dihapus" << endl;
                cout <<endl;
                Hapus_tengah(posisi);
                break;
            case 10:
                cout << endl << "Hapus List" << endl;
                cout <<endl;
                Hapus_list();
                break;
            case 11:
                cout << endl << "Menampilkan Semua data mahasiswa" << endl;
                cout <<"Data Mahasiswa"<<endl;
                cout << endl;
                Tampil();
                break;
            case 0:
                cout << endl << "Keluar dari program." << endl;
                break;
            default:
                cout << endl << "ORA ONO PILIHAN E SAM.." << endl;
        }
    } while (pilihan != 0);

    return 0;
}