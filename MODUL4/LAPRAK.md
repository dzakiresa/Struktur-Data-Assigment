# <h1 align="center">Laporan Praktikum Modul 4 - LINKED LIST CIRCULAR DAN NON CIRCULAR</h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Dasar Teori

Linked List Non Circular
Linked List Non Circular adalah linked list dengan head dan tail yang tidak saling terhubung. pointer tail pada linked list non circular ini selalu bernilai NULL yang berfungsi sebagai tanda data terakhir dalam list nya.

Linked List Circular
Linked List Circular adalah linked list yang tidak memiliki akhir karena tail nya tidak bernilai NULL melainkan terrhubung dengan head. Dalam linked list circular kita membutuhkan dummy node sebagai pengecoh yang dinamakan node current yang berfungsi untuk menghentikan penghitungan data ketika node current mencapai head. linked list circular ini biasanya digunakan untuk menyimpan data yang sering diakses secara berulang seperti memori berulang dalam aplikasi, daftar pesan dalam antrian, atau seperti daftar putar lagu.

## Guided 

### 1. Latihan Linked List Non Circular

```C++
#include <iostream>
using namespace std;
// PROGRAM SINGLE LINK LIST NON CIRCULAR
// DEKLARASI STRUCT NODE

struct node
{
    int data;
    node *next;
};
node *head;
node *tail;

// INSTALASI NODE
void init()
{
    head = NULL;
    tail = NULL;
}

//PENGECEKAN
bool isEmpty()
{
    if(head == NULL)
        return true;

    else
        return false;
}

// TAMBAH DEPAN
void insertDepan(int nilai)
{
    //BUAT NODE BARU
    node *baru = new node;
    baru -> data = nilai;
    baru -> next = NULL;
    if(isEmpty() == true)
    {
        head = tail = baru;
        tail -> next = NULL;
    }
    else
    {
        baru -> next = head;
        head = baru;
    }
}

// TAMBAH BELAKANG
void insertBelakang(int nilai)
{
    // BUAT NODE BARU
    node *baru = new node;
    baru -> data = nilai;
    baru -> next = NULL;
    if(isEmpty() == true)
    {
        head = tail = baru;
        tail -> next = NULL;
    }
    else
    {
        tail -> next = baru;
        tail = baru;
    }
}

// HITUNG JUMLAH LIST
int hitungList()
{
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while(hitung != NULL)
    {
        jumlah++;
        hitung = hitung -> next;
    }
    return jumlah;
}

// TAMBAH TENGAH
void insertTengah(int data, int posisi)
{
    if(posisi < 1 || posisi > hitungList())
    {
        cout << "posisi di liar jangkauan" << endl;
    }
    else if(posisi == 1)
    {
        cout << "posisi buan posisi tengah" << endl;
    }
    else
    {
        node *baru, *bantu;
        baru = new node();
        baru -> data = data;

        // TRANSVERSING
        bantu = head;
        int nomor = 1;
        while(nomor < posisi -1)
        {
            bantu =bantu -> next;
            nomor++;
        }
    
    baru -> next = bantu -> next;
    bantu -> next = baru;
    }
}

//HAPUS DEPAN
void hapusDepan()
{
    node *hapus;
    if(isEmpty() == false)
    {
        if(head -> next != NULL)
        {
            hapus = head;
            head = head -> next;
            delete hapus;
        }
    
    else
    {
        head = tail = NULL;
    }
    }
    else
    {
        cout <<"list kosong" << endl;
    }
}

// HAPUS BELAKNG
void hapusBelakng()
{
    node *hapus;
    node *bantu;
    if(isEmpty() == false)
    {
        if(head != tail)
        {
            hapus = tail;
            bantu = head;
            while(bantu -> next != tail)
            {
                bantu = bantu -> next;
            }
            tail = bantu;
            tail -> next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout <<"list kosiing"<< endl;
    }
}

// HAPUS TENGAH
void hapusTengah(int posisi)
{
    node *bantu, *hapus, *sebelum;
    if( posisi < 1 || posisi > hitungList())
    {
        cout <<"posisi di liar jangkauan"<< endl;
    }
    else if(posisi == 1)
    {
        cout <<"posisi bukan posisi tengah"<< endl;
    }
    else 
    {
        int nomor = 1;
        bantu = head;
        while(nomor <= posisi)
        {
            if(nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if(nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu -> next;
            nomor++;
        }
        sebelum  -> next = bantu;
        delete hapus;
    }

}

// Ubah Depan
void ubahDepan(int data)
{
if (isEmpty() == 0)
{
head->data = data;
}
else
{
cout << "List masih kosong!" << endl;
}
}

// Ubah Tengah
void ubahTengah(int data, int posisi)
{
node *bantu;
if (isEmpty() == 0)
{
    if (posisi < 1 || posisi > hitungList())
{
cout << "Posisi di luar jangkauan" << endl;
}
else if (posisi == 1)
{

}
else
{
cout << "Posisi bukan posisi tengah" << endl;

bantu = head;
int nomor = 1;
while (nomor < posisi)
{
bantu = bantu->next;
nomor++;
}
bantu->data = data;
}
}
else
{
cout << "List masih kosong!" << endl;
}
}

// Ubah Belakang
void ubahBelakang(int data)
{
if (isEmpty() == 0)
{
tail->data = data;
}
else
{
cout << "List masih kosong!" << endl;
}
}

// Hapus List
void clearList()
{
node *bantu, *hapus;
bantu = head;
while (bantu != NULL)
{
hapus = bantu;
bantu = bantu->next;
delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
node *bantu;
bantu = head;
if (isEmpty() == false)
{
while (bantu != NULL)
{
cout << bantu->data << ends;
bantu = bantu->next;
}
cout << endl;
}
else
{
cout << "List masih kosong!" << endl;
}
}

int main()
{
init();
insertDepan(3);
tampil();
insertBelakang(5);
tampil();
insertDepan(2);
tampil();
insertDepan(1);
tampil();
hapusDepan();
tampil();
hapusBelakng();
tampil();
insertTengah(7, 2);
tampil();
hapusTengah(2);
tampil();
ubahDepan(1);
tampil();
ubahBelakang(8);
tampil();
ubahTengah(11, 2);
tampil();

return 0;
}
```
#### Output: 
![alt text](<Screenshot 2024-04-03 103004.png>)
program di atas merupakan program linked list non circular, head dan tail dalam program tersebut tidak terhubung, terdapat beberapa prosedur seperti tambah depan, belakang dan tengah, ubah depan, belakang dan tengah, hapus depan, belakang dan tengah, hapus list dan tampilkan list.

### 2. Latihan Linked List Circular 

```C++
#include <iostream>

using namespace std;

// Program SINGLE LINGKED LIST SIRCULAR

// Deklarasi Struct Node
struct  Node
{
    string data;
    Node*next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
    return 1; // true
    else
    return 0; // false
}

// Buat Node baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

//hitung list
int hitunglist()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan

void insertDepan(string data)
{
    // buat Node Baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else 
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if(isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru; 
        baru->next = head;
        tail = baru;
    }
}
// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if(isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        //Transvering
        int nomor = 1;
        bantu = head;
        while(nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = NULL;

        delete hapus;
    }
    else 
    {
        while(tail->next != hapus)
        {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        hapus->next = NULL;

        delete hapus;
    }
}
// hapus belakang
void hapusBelakang()
{
    if(isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if(hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        //Transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus list
void clearlist()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan list
void tampil()
{
    if(isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } 
        while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
init();
insertDepan("Ayam");
tampil();
insertDepan("Bebek");
tampil();
insertBelakang("Cicak");
tampil();
insertBelakang("Domba");
tampil();
hapusBelakang();
tampil();
hapusDepan();
tampil();
insertTengah("keboo", 3);
tampil();
hapusTengah(2);
tampil();

return 0;
}
```
#### Output: 
![alt text](<Screenshot 2024-04-03 103342.png>)
program tersebut merupakan program linked list circular yang antara heaad dan tail saling terhubung. Secara keseluruhan hampir sama dengan non circular hanya berbeda pada head dan tail yang saling terhubung.


## UNGUIDED 

```C++
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
```
#### Output:
![alt text](<Screenshot 2024-04-03 001756.png>)
![alt text](<Screenshot 2024-04-03 002851.png>)
Program ini merupakan program linked list non circular ditandai dengan tidak terhubungnya antara head dengan tail dan tail selalu bernilai NULL. Dalam program terdapat beberapa prosedur untuk mengeksekusi program utama dalam int main, dalam int main terdapat pilihan menu linked list non circular yang switch case nya terbungkus dalam perulangan do while, namun di sini polihan menu tidak dimassukkan pada perulangan agar tidak terlalu panjang dan memenuhi output jadi hanya muncul satu kali saja. Disini user diminta menginputkan data mahasiswa yang ada kemudian menambahkan, mengubah, atau menghapus data yang sudah tersimpan kemudian menampilkan seluruh data yang sudah di simpan tadi. 
## Kesimpulan
Linked list secara umum digunakan sebagai tempat menyimpan data, salah satu metode lain dari array. Dalam bab ini fokus pada linked list non circular dan linked list circular. pada linked list non circular head dan tail terpisah atau tidak saling terhubung, sedangkan pada linked list circular head dan tail saling terhubung yang membuatnya lebih fleksibel dalam perubahan data yang disimpan
## Referensi
[1] Wisam Abed Shukur, Ahmed Badrulddin, Mohammed Kamal Nsaif, A proposed encryption technique of different texts using circular link lists, Vol 9, No 2 (2021)
[2]yulianti, Meyka. “Struktur Data_double Linked List Circular.” OSF Preprints, 29 Mar. 2019. Web.