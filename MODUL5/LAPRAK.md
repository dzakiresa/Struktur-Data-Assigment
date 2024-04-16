# <h1 align="center">Laporan Praktikum Modul 5 - HASH TABLE</h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Dasar Teori
Hash Table merupakann struktur data yang mengorganisir data ke dalam pasangan kunci nilai. Hash Table umumnya terdiri dari dua komponen utama yaitu array dan fungsi hash. Hashing merupakan teknik untuk mengubah rentang nilai kunci menjadi rentang indeks array. Array menyimpan data dalam slot-slot yang disebut bucket. Setiap bucket dapat menampung satu atau beberapa item data. Fungsi hash digunakan untuk menghasilkan nilai unik dari setiap item data, yang digunakan sebagai indeks array. Dengan cara ini, hash table memungkinkan pencarian data dalam waktu yang konstan (O(1)) dalam kasus terbaik. Sistem hash table bekerja dengan cara mengambil input kunci dan memetakkannya ke nilai indeks array menggunakan fungsi hash. Kemudian, data disimpan pada posisi indeks array yang dihasilkan oleh fungsi hash. Ketika data perlu dicari, input kunci dijadikan sebagai parameter untuk fungsi hash, dan posisi indeks array yang dihasilkan digunakan untuk mencari data.
## Guided 

### 1. Latihan 

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node {
int key;
int value;
Node* next;
Node(int key, int value) : key(key), value(value),
next(nullptr) {}
};
// Class hash table
class HashTable {
private:
Node** table;
public:
HashTable() {
table = new Node*[MAX_SIZE]();
}
~HashTable() {
for (int i = 0; i < MAX_SIZE; i++) {
Node* current = table[i];
while (current != nullptr) {
Node* temp = current;
current = current->next;
delete temp;
}
}
delete[] table;
}
// Insertion
void insert(int key, int value) {
int index = hash_func(key);
Node* current = table[index];
while (current != nullptr) {
if (current->key == key) {
current->value = value;
return;
}
current = current->next;
}
Node* node = new Node(key, value);
node->next = table[index];
table[index] = node;
}
// Searching
int get(int key) {
int index = hash_func(key);
Node* current = table[index];
while (current != nullptr) {
if (current->key == key) {
return current->value;
}
current = current->next;
}
return -1;
}
// Deletion
void remove(int key) {
int index = hash_func(key);
Node* current = table[index];
Node* prev = nullptr;
while (current != nullptr) {
if (current->key == key) {
if (prev == nullptr) {
table[index] = current->next;
} else {
prev->next = current->next;
}
delete current;
return;
}
prev = current;
current = current->next;
}
}
// Traversal
void traverse() {
for (int i = 0; i < MAX_SIZE; i++) {
Node* current = table[i];
while (current != nullptr) {
cout << current->key << ": " << current->value

<< endl;

current = current->next;
}
}
}
};
int main() {
HashTable ht;
// Insertion
ht.insert(1, 10);
ht.insert(2, 20);
ht.insert(3, 30);
// Searching
cout << "Get key 1: " << ht.get(1) << endl;
cout << "Get key 4: " << ht.get(4) << endl;
// Deletion
ht.remove(4);
// Traversal
ht.traverse();
return 0;
}
```
#### Output: 
![alt text](<Screenshot 2024-04-17 001033.png>)
Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam
hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node
merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan
modulus untuk memetakan setiap input kunci ke nilai indeks array.

### 2. Latihan 
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode {
public:
string name;
string phone_number;
HashNode(string name, string phone_number) {
this->name = name;
this->phone_number = phone_number;
}
};
class HashMap {
private:
vector<HashNode*> table[TABLE_SIZE];
public:
int hashFunc(string key) {
int hash_val = 0;
for (char c : key) {
hash_val += c;
}
return hash_val % TABLE_SIZE;
}
void insert(string name, string phone_number) {
int hash_val = hashFunc(name);
for (auto node : table[hash_val]) {
if (node->name == name) {
node->phone_number = phone_number;
return;
}
}
table[hash_val].push_back(new HashNode(name,
phone_number));
}
void remove(string name) {
int hash_val = hashFunc(name);
for (auto it = table[hash_val].begin(); it !=
table[hash_val].end(); it++) {
if ((*it)->name == name) {
table[hash_val].erase(it);
return;
}
}
}
string searchByName(string name) {
int hash_val = hashFunc(name);
for (auto node : table[hash_val]) {
if (node->name == name) {
return node->phone_number;
}
}
return "";
}
void print() {
for (int i = 0; i < TABLE_SIZE; i++) {
cout << i << ": ";
for (auto pair : table[i]) {
if(pair != nullptr){
cout << "[" << pair->name << ", " <<

pair->phone_number << "]";

}
}
cout << endl;
}
}
};
int main() {
HashMap employee_map;
employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");
cout << "Nomer Hp Mistah : "
<<employee_map.searchByName("Mistah") << endl;
cout << "Phone Hp Pastah : "
<<employee_map.searchByName("Pastah") << endl;
employee_map.remove("Mistah");
cout << "Nomer Hp Mistah setelah dihapus : "
<<employee_map.searchByName("Mistah") << endl << endl;
cout << "Hash Table : " << endl;
employee_map.print();
return 0;
}
```
#### Output: 

### 2. Latihan Linked List Circular 

```C++
```
#### Output: 
![alt text](<Screenshot 2024-04-17 001415.png>)
Pada program di atas, class HashNode merepresentasikan setiap node dalam hash
table, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap
digunakan untuk mengimplementasikan struktur hash table dengan menggunakan
vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan
untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi
insert digunakan untuk menambahkan data baru ke dalam hash table. Fungsi
remove digunakan untuk menghapus data dari hash table, dan fungsi
searchByName digunakan untuk mencari nomor telepon dari karyawan dengan
nama yang diberikan.

## UNGUIDED 

```C++
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
```
#### Output:
![alt text](<Screenshot 2024-04-16 234912.png>)
![alt text](<Screenshot 2024-04-16 234943.png>)
![alt text](<Screenshot 2024-04-16 235123.png>)
Progeam diatas merupakan prgram hash table, yang didalamnya user diminta menginputkan nama, nim, dan nilai mahasiswa. kemudian terdapat beberapa pilihan menu seperti masukkan data, hapus data yang ingin dihapus, cari berdasarkan nim, cari berdasarkna rentang nilai, tampilkan tabel dan keluar
## Kesimpulan
Hash Table mengorganisir data ke pasangan kunci nilai. terdiri dari dua komponen utama yaitu array dan fungsi hash. Hashing adalah teknik untuk mengubah rentang nilai kunci menjadi rentang indeks array. Fungsi hash digunakan untuk menghasilkan nilai unik dari setiap item data, yang digunakan sebagai indeks array. Dengan cara ini, hash table memungkinkan pencarian data dalam waktu.
yang konstan
## Referensi
[1] Karimov, E. (2020). Hash Table. In: Data Structures and Algorithms in Swift. Apress, Berkeley, CA.
[2] Ega Patra Nugraha dkk. (2021). Analisa Performansi Dan Keamanan Penyimpanan Data Pada Distributed Hash Table.