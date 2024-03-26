# <h1 align="center">Laporan Praktikum Modul 3 - SINGLE AND DOUBLE LINKED LIST</h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Dasar Teori

Single Linked List
Single Linked List merupakan bentuk struktur data yang berisi sekumpulan data yang dikenal sebagai node yang tersusun secara sekuensisal dan saling sambung menyambung. Antara elemen dalam linked list dihubungkan melalui pointer. Pointer adalah alamat elemen. Setiap simpul terbagi atas dua bagian yaitu bagian data dan bagia pointer. Bagian data berisi nilai yang disimpan oleh simpul, sedangkan bagian pointer alamat dari node berikut atau sebelummya. Elemen pada awal suatu list disebut head
dan elemen terakhir dari suatu list disebut tail.

Double Linked List
Double Linked List adalah struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya. Dengan adanya pointer prev memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul mana saja. Namun, kekurangan dari Double Linked List adalah penggunaan memori yang lebih besar dibandingkan dengan Single Linked List, karena setiap simpul membutuhkan satu pointer tambahan. Selain itu, Double Linked List juga membutuhkan waktu eksekusi yang lebih lama

## Guided 

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
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
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
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
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
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
    if (isEmpty() == false)
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
    Node *bantu, *hapus;
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
    Node *bantu;
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
    hapusBelakang();
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
![alt text](<Screenshot 2024-03-26 231352.png>)
program di atas merupakan program single linked list, terdapat beberapa opsi untuk mengubah data yang ada seperti insert depan, tengah, belakang, ubah depan, tengah, belakang, hapus depan, tengah, belakang, hapus data, serta tampilkan data

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
![alt text](<Screenshot 2024-03-26 214919.png>)
program di atas merupakan program double linked list, dengan beberapa fungsi di dalam program tersebut yang dapat dipilih untuk mengubah menambah atau menghapus data yang diinputkan manual oleh user melalui pilihan menu yang tersedia

## Unguided 

### 1. UNGUIDED 1

```C++
// Dzaki Resalianto 2311102161

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string NamaMahasiswa;
    int UsiaMahasiawa;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:

    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }

    void LeboknoNgarep(string NamaMahasiswa, int UsiaMahasiawa) {
        Node* newNode = new Node;
        newNode->NamaMahasiswa = NamaMahasiswa;
        newNode->UsiaMahasiawa = UsiaMahasiawa;
        newNode->next = head;
        head = newNode;
    }

    void MLeboknoMburi(string NamaMahasiswa, int UsiaMahasiawa) {
        Node* newNode = new Node;
        newNode->NamaMahasiswa = NamaMahasiswa;
        newNode->UsiaMahasiawa = UsiaMahasiawa;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void LeboknoTengah(string NamaMahasiswa, int UsiaMahasiawa, string posisi, string NamaMahasiswaSebelum) {
        Node* newNode = new Node;
        newNode->NamaMahasiswa = NamaMahasiswa;
        newNode->UsiaMahasiawa = UsiaMahasiawa;

        Node* current = head;
        while (current != NULL && current->NamaMahasiswa != NamaMahasiswaSebelum) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Data Tidak Ada" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void BusekData(string NamaMahasiswa) {
        if (head == NULL) {
            cout << "List" << endl;
            return;
        }

        if (head->NamaMahasiswa == NamaMahasiswa) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->NamaMahasiswa != NamaMahasiswa) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "Data Tidak Ada" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void Gantidata(string NamaMahasiswa, string newNamaMahasiswa, int newUsiaMahasiawa) {
        Node* current = head;
        while (current != NULL) {
            if (current->NamaMahasiswa == NamaMahasiswa) {
                current->NamaMahasiswa = newNamaMahasiswa;
                current->UsiaMahasiawa = newUsiaMahasiawa;
                return;
            }
            current = current->next;
        }
        cout << "Data Tidak Ada" << endl;
    }

    void Tampilnodata() {
        if (head == NULL) {
            cout << "List" << endl;
            return;
        }

        Node* current = head;
        cout << endl;
        while (current != NULL) {
            cout << "" << current->NamaMahasiswa << "\t\t" << current->UsiaMahasiawa << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    string NamaMahasiswaUser;
    int UsiaMahasiawaUser;

    cout << "Masukkan Nama : ";
    getline(cin, NamaMahasiswaUser);
    cout << "Masukkan Usia : ";
    cin >> UsiaMahasiawaUser;

    list.LeboknoNgarep(NamaMahasiswaUser, UsiaMahasiawaUser);
    cin.ignore();
    // Untuk Memasukkan Data
    list.MLeboknoMburi("John", 19);
    list.MLeboknoMburi("Jane", 20);
    list.MLeboknoMburi("Michael", 18);
    list.MLeboknoMburi("Yusuke", 19);
    list.MLeboknoMburi("Akechi", 20);
    list.MLeboknoMburi("Hoshino", 18);
    list.MLeboknoMburi("Karin", 18);

    // Untuk Hapus Data Akechi
    list.BusekData("Akechi");

    // Untuk Menambahkan data Futaba diantara John dan Jane
    list.LeboknoTengah("Futaba", 18, "tengah", "John");

    // Untuk menambhkan data Igot pada awal data
    list.LeboknoNgarep("Igor", 20);

    // Untuk mengubah data michael menjadi Reyn 18
    list.Gantidata("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Data Mahasiswa :";
    list.Tampilnodata();
}
```
#### Output: 
![alt text](<Screenshot 2024-03-26 143335.png>)
program tersebut merupakan program singel linked list, terdapat beberapa fungsi di dalamnya serta data yang sudah tersedia, kemudian user diminta mengganti atau berubah pada beberapa data yang ada seperti nama dan umur mahasiswa

### 2. UNGUIDED 2

```C++
// Dzaki Resalianto 2311102161
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node {
    string JenengBarang;
    int RegoBarang;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~DoubleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    void LebokkeMburi(string JenengBarang, int RegoBarang) {
        Node* newNode = new Node;
        newNode->JenengBarang = JenengBarang;
        newNode->RegoBarang = RegoBarang;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    void Tampilke() {
        Node* current = head;
        cout << "================================" << endl;
        cout << " Nama Produk \t|| Harga Produk" << endl;
        cout << "================================" << endl;
        while (current != nullptr) {
            cout << setw(10) << current->JenengBarang << "\t|| " << setw(6) << current->RegoBarang << endl;
            current = current->next;
        }
        cout << "================================" << endl;
    }

    void Leboknoningposisi(string JenengBarang, int RegoBarang, int posisi) {
        Node* newNode = new Node;
        newNode->JenengBarang = JenengBarang;
        newNode->RegoBarang = RegoBarang;

        Node* current = head;
        int count = 1;

        while (current != nullptr && count < posisi) {
            current = current->next;
            count++;
        }

        if (current == nullptr && count < posisi) {
            cout << "Posisi diluar jangkauan." << endl;
            return;
        }

        newNode->next = current;
        newNode->prev = current->prev;

        if (current->prev == nullptr) {
            head = newNode;
        } else {
            current->prev->next = newNode;
        }
        current->prev = newNode;
    }

    void deleteAtposisi(int posisi) {
        if (head == nullptr || posisi <= 0) {
            cout << "Linked list kosong !" << endl;
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != nullptr && count < posisi) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Posisi diluar jangkauan." << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }

    void busekKabeh() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    void buseksingonojenenge(string JenengBarang) {
        Node* current = head;
        while (current != nullptr) {
            if (current->JenengBarang == JenengBarang) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Data berhasil dihapus." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan." << endl;
    }

    void nganyaridata(string JenengBarang, string JenengBarang_Baru, int RegoBarang_Baru) {
        Node* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->JenengBarang == JenengBarang) {
                found = true;
                current->JenengBarang = JenengBarang_Baru;
                current->RegoBarang = RegoBarang_Baru;
                cout << "Data berhasil diupdate." << endl;
                return;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Data dengan nama produk '" << JenengBarang << "' tidak ditemukan." << endl;
        }
    }
};

int main() {
    DoubleLinkedList list;

    list.LebokkeMburi("Originote", 60000);
    list.LebokkeMburi("Somethinc", 150000);
    list.LebokkeMburi("Skintific", 100000);
    list.LebokkeMburi("Wardah", 50000);
    list.LebokkeMburi("Hanasui", 30000);

    int choice;
    string JenengBarang, JenengBarang_Baru;
    int RegoBarang;
    int posisi;

    do {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan Anda (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin.ignore();
                getline(cin, JenengBarang);
                cout << "Masukkan HargaProduk: ";
                cin >> RegoBarang;
                list.LebokkeMburi(JenengBarang, RegoBarang);
                break;
            case 2:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin.ignore();
                getline(cin, JenengBarang);
                list.buseksingonojenenge(JenengBarang);
                break;
            case 3:
                cout << "Masukkan nama produk yang ingin diperbarui: ";
                cin.ignore();
                getline(cin, JenengBarang);
                cout << "Masukkan nama produk yang baru: ";
                getline(cin, JenengBarang_Baru);
                cout << "Masukkan Harga Produk yang baru: ";
                cin >> RegoBarang;
                list.nganyaridata(JenengBarang, JenengBarang_Baru, RegoBarang);
                break;
            case 4:
                cout << "Masukkan nama produk: ";
                cin.ignore();
                getline(cin, JenengBarang);
                cout << "Masukkan Harga Produk: ";
                cin >> RegoBarang;
                cout << "Masukkan posisi produknya: ";
                cin >> posisi;
                list.Leboknoningposisi(JenengBarang, RegoBarang, posisi);
                break;
            case 5:
                cout << "Masukkan posisi data yang akan dihapus: ";
                cin >> posisi;
                list.deleteAtposisi(posisi);
                break;
            case 6:
                list.busekKabeh();
                cout << "Semua Data Dihapus." << endl;
                break;
            case 7:
                cout << "Daftar Produk Toko Skincare Purwokerto :" << endl;
                list.Tampilke();
                break;
            case 8:
                cout << "Terimakasih." << endl;
                break;
            default:
                cout << "Pilihan tidak ada." << endl;
        }
    } while (choice != 8);
}
```
#### Output:
![alt text](<Screenshot 2024-03-26 222519.png>)
program tersebut merupakan program double linked list, terdapat beberapa fungsi pada program tersebut dan sudah ada data awal yang tersedia, disini user diminta mengganti beberapa data yang ada dengan memilih fungsi pada menu yang tersedia untuk menambah, mengubah, atau menghapus dari data yang sudah ada

## Kesimpulan
dalam menyimpan dan mengubah data yang sudah ada akan lebih mudah jika menggunakan linked list. linked list disini ada dua yaitu single linked list dan double linked list. keuntungan menggunakan single linked list adalah penggunaan memori yang lebih sedikit dibanding double linked list. Keuntungan dari Double Linked List adalah memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul dimana saja dengan efisien, sehingga sangat berguna dalam implementasi beberapa algoritma yang membutuhkan operasi tersebut,

## Referensi
[1]A. Goponenko and S. Carroll, “A C++ implementation of a lock-free priority queue based on Multi-Dimensional Linked List,” ResearchGate, 11 2019.
[2]Alexander Goponenko and Steven Carroll, "A C++ Implementation of a Lock-Free Priority
Queue Based on Multi-Dimensional Linked List", 2019