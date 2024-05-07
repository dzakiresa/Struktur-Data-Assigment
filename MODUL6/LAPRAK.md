# <h1 align="center">Laporan Praktikum Modul 6  - STACK</h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Dasar Teori
Stack merupakan struktur data yang mirip dengan linked list yang digunakan untuk menyimpan data. Stack menyimpan data dalam bentuk tumpukan sehingga data yang masuk pertama akan keluar terakhir sedangkan data yang masuk terakhir akan keluar pertama, ilustrasinya seperti menumpuk sebuah pakaian baju pertama akan menjadi dasar tumpukan yang akan diambil terakhir ketika terdapat tumpukan lain di atasnya sedangkan baju terakhir akan menjadi tumpukan paling atas yang akan diambil terlebihdahulu.
terdapat beberapa fungsi dasar dalam stack, berikut beserta fungsinya:
1 push (masukkan) menambahkan elemen pada tumpukan paling atas
2 pop (keluarkan) menghapus elemen dari posisi paling atas
3 top (atas) mendapatkan atau melihat elemen teratas tampa menghapusnya
4 isEmpty (kosong) memeriksa tumpukan apakah kosong atau tidak
5 isFull (penuh) memeriksa apakah tumpukan penuh atau tidak
6 size (ukuran) mengembalikan jumlah elemen yang ada dalam tumppukan
7 peek (lihat) melihat elemen pada posisi tertentu tanpa menghapusnya
8 clear (hapus semua) menghapus semua elemen pada tumpukan
9 search (cari) mencari keberadaan elemen tertentu pada tumpukan 

## Guided 
### 1. Latihan 
```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull () {
    return (top == maksimal);
}

bool isEmpty () {
    return (top == 0);
}

void pushArrayBuku (string data) {
    if (isFull()) {
        cout << "data telah penuh" << endl;
    }
    else {
        arrayBuku [top] = data;
        top++;
    }
}

void popArrayBuku () {
    if (isEmpty()) {
        cout<<"tidak ada data yang dihapus"<< endl;
    }
    else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku (int posisi) {
    if (isEmpty()) {
        cout << "tidak ada data yang ingin dilihat" << endl;
    }
    else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack () {
    return top;
}

void changeArrayBuku (int posisi, string data) {
    if (posisi > top) {
        cout << "posisi melebihi daya yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku () {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    } top = 0;
}

void cetakArrayBuku () {
    if (isEmpty()) {
        cout << "tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i>=0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main () {
    pushArrayBuku("kalkulus");
    pushArrayBuku("struktur data");
    pushArrayBuku("matematika diskrit");
    pushArrayBuku("dasar multimedia");
    pushArrayBuku("inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "apakah data stack penuh? " << isFull() << endl;
    cout << "apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "banyak data = " << countStack() << endl;
    changeArrayBuku(2, "bahasa jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "jumlah data setelah dihapus = " << top << endl;

    cetakArrayBuku();

    return 0;
}
```
#### Output: 
![alt text](<Screenshot 2024-05-08 002550.png>)
merupakan struktur data stack dengan beberapa prosedur untuk menambahkan, mengubah dan menampilkann data yang telah dimasukkan dalam program

## UNGUIDED 1
```C++
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//2311102161

// Fungsi untuk mengecek apakah sebuah kata merupakan palindrom
bool apaPalindrom(string kalimat) {
    stack<char> charStack;
    int panjang = kalimat.length();
    
    // Push setiap karakter ke dalam stack
    for (int i = 0; i < panjang; i++) {
        charStack.push(kalimat[i]);
    }

    // Bandingkan karakter asli dengan karakter yang diambil dari stack
    for (int i = 0; i < panjang; i++) {
        if (kalimat[i] != charStack.top()) {
            return false; // Jika ada perbedaan, bukan palindrom
        }
        charStack.pop(); // Pop karakter dari stack
    }

    return true; // Jika tidak ada perbedaan, adalah palindrom
}

// Prosedur untuk menampilkan hasil apakah kata merupakan palindrom atau tidak
void hasilPalindrom(const string& kata) {
    if (apaPalindrom(kata)) {
        cout << "Kata tersebut adalah palindrom." << endl;
    } else {
        cout << "Kata tersebut bukan palindrom." << endl;
    }
}

int main() {
    string kata;
    cout << "Masukkan kata: ";
    cin >> kata;

    hasilPalindrom(kata);

    return 0;
}
```
#### Output:
![alt text](<Screenshot 2024-05-08 000633.png>)
Program ini bertujuan untuk mengecek apakah sebuah kata merupakan palindrom atau tidak. Sebuah kata palindrom adalah kata yang jika dibalik tetap sama. Di dalam main, pengguna diminta untuk memasukkan sebuah kata. Kemudian, fungsi hasilPalindrom dipanggil untuk menampilkan apakah kata tersebut adalah palindrom atau tidak.

## UNGUIDED 2
```C++
#include <iostream>
#include <stack>
using namespace std;

//2311102161


// Proses input kalimat
void inputKalimat(string &kalimat) {
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
}

// Proses membalikkan kalimat menggunakan tumpukan
void balikKalimat(string &kalimat, stack<char> &tumpukan) {
    for (char c : kalimat) {
        tumpukan.push(c);
    }
    kalimat = "";
    while (!tumpukan.empty()) {
        kalimat += tumpukan.top();
        tumpukan.pop();
    }
}

// Proses menampilkan kalimat terbalik
void tampilkanKalimatTerbalik(const string &kalimat) {
    cout << "Kalimat terbalik: " << kalimat << endl;
}

int main() {
    string kalimat;
    stack<char> tumpukan;

    inputKalimat(kalimat);

    if (kalimat.length() < 3) {
        cout << "Kalimat minimal harus 3 kata!" << endl;
        return 1;
    }

    balikKalimat(kalimat, tumpukan);

    tampilkanKalimatTerbalik(kalimat);

    return 0;
}
```
#### Output:
![alt text](<Screenshot 2024-05-08 000510.png>)
Program ini menggunakan konsep stack untuk membalikkan kalimat. Setiap karakter dari kalimat dimasukkan ke dalam stack, dan kemudian diambil kembali satu per satu dari stack, sehingga menghasilkan kalimat yang telah dibalik.

## Kesimpulan
program stack adalah struktur data yang penting dalam pemrograman komputer karena memungkinkan manajemen memori yang efisien, penanganan panggilan fungsi yang tepat, perlindungan dari serangan buffer overflow, dan efisiensi akses data. Penggunaannya mempermudah pengembangan perangkat lunak dengan menyediakan mekanisme yang diperlukan untuk menyimpan dan mengelola informasi sementara selama eksekusi program.

## Referensi
[1] Anita Sindar RMS, ST., M.TI. 2019. STRUKTUR DATA DAN ALGORITMA DENGAN C++
[2] John Wiley & Sons. 2021. Data Structure and Algorithms Using C++: A Practical Implementation