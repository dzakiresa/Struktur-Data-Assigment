# <h1 align="center">Laporan Praktikum Modu7  - QUEUE</h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Tujuan Praktikum
1. Mahasiswa mampu menjelaskan definisi dan konsep dari double queue
2. Mahasiswa mampu menerapkan operasi tambah, menghapus pada queue
3. Mahasiswa mampu menerapkan operasi tampil data pada queue

## Dasar Teori
Queue merupakan struktur data yang berfungsi menyimpan data dengan metode FIFO (First-In First-Out). Data yang pertama diinputkan pada Queue merupakan data yang akan keluar pertama juga dalam Queue. konsep ini mengimplementasi dari metode antrian dalam sehari hari dimana yang pertama kali datang adalah yang pertaman akan dilayani.
Implementasi Queue dapat dilakukan dengan menggunakan array atau linked list, dengan memiliki dua pointer yaitu pointer front (pointer ke elemen pertama) dan pointer rear (pointer ke elemen terakhir).
![alt text](<Screenshot 2024-05-15 232532.png>)
Terdapat perbedaan antara konsep stack dan queue pada aturan penambahan dan penghapusan elemen. pada stack penambahan dan penghapusan dilakukan di satu ujung, elemen paling akhir diinputkan akan dianggap paling atas sehingga pada penghapusan elemen tersebut akan dihapus paling awal, ini dikenal dengan sisitem LIFO (Last In First Out). Sementara pada Queue operasi tersebut dilakukan pada salah satu ujung karena perubahan data selalu berada di head maka hanya ada satu jenis insert maupun delete, ini sering disebut Enqueue dan Dequeue pada Queue. Untuk Enqueue, cukup tambahkan elemen setelah elemen terakhir Queue, dan untuk Dequeue, cukup "geser"kan Head menjadi elemen selanjutnya.
 Operasi pada Queue :
- enqueue() : menambahkan data ke dalam queue.
- dequeue() : mengeluarkan data dari queue.
- peek() : mengambil data dari queue tanpa menghapusnya.
- isEmpty() : mengecek apakah queue kosong atau tidak.
- isFull() : mengecek apakah queue penuh atau tidak.
- size() : menghitung jumlah elemen dalam queue.

## Guided 

### 1. Latihan 

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; 
int front = 0; 
int back = 0; 
string queueTeller[5]; 

bool isFull() { 
    if (back == maksimalQueue) {
        return true; 
    } else {
        return false;
    }
}

bool isEmpty() { 
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { 
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { 
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { 
    return back;
}

void clearQueue() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { 
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
#### Output: 
![alt text](<Screenshot 2024-05-19 185912.png>)
Program ini mengimplementasikan sebuah antrian (Queue) menggunakan array dengan kapasitas elemen maksimal adalah 5. menggunakan penambahan dan penghapusan data dengan sistem FIFO (First-In First-Out). 


## UNGUIDED 1

```C++
#include <iostream>
using namespace std;
//2311102161

struct Node {
  string Data161;
  Node* next;
};
Node* head = NULL;
Node* tail = NULL; 

bool isEmpty() {
  return head == NULL;
}

void insertAntrian(string Data161) {
  Node* newNode = new Node; 
  newNode->Data161 = Data161; 
  newNode->next = NULL; 

  if (isEmpty()) { 
    head = newNode;
    tail = newNode;
  } else { 
    tail->next = newNode;
    tail = newNode;
  }
}


void deleteAntrian() {
  if (isEmpty()) {
    cout << "Data ini kosong, tidak ada data untuk dihapus" << endl;
    return;
  }

  Node* temp = head; 
  head = head->next; 
  delete temp; 

  if (head == NULL) { 
    tail = NULL;
  }
}


int hitungQueue() {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}


void clearQueue() {
  while (!isEmpty()) {
    deleteAntrian();
  }
}


void tampilkanQueue() {
  if (isEmpty()) {
    cout << "Queue sedang kosong" << endl;
    return;
  }

  cout << "Data antrian teller :" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->Data161 << endl;
    i++;
    current = current->next;
  }
}

int main() {
    cout << "TELLER QUEUE" << endl;
    insertAntrian("Andi");
    insertAntrian("Maya");
    tampilkanQueue();
    cout << "Jumlah antrian: " << hitungQueue() << endl;

    deleteAntrian();
    tampilkanQueue();
    cout << "Jumlah antrian: " << hitungQueue() << endl;

    clearQueue();
    tampilkanQueue();
    cout << "Jumlah antrian: " << hitungQueue() << endl;

    return 0;
}
```
#### Output:
![alt text](<Screenshot 2024-05-19 191707.png>)
Program ini mengimplementasika antria Queue dnegan menggunakn linekd list untuk  menyimpan data, program ini memiliki fungsi penambahan, penghapusan, memeriksa apakah antrian kosong, menghitung jumlah antrian, menghapus semua antrian dan menampilkan semua antrian. Pada fungsi main, program menambahkan data teller ke antrian, menghapus data dari antrian, dan mengosongkan antrian, sambil menampilkan kondisi antrian setelah setiap operasi untuk mendemonstrasikan cara kerja fungsi-fungsi tersebut.


## UNGUIDED 2

```C++
#include <iostream>
using namespace std;
//2311102161

struct Node {
  string namaMahasiswa161;
  long long int nimMahasiawa161;
  Node* next;
};

Node* head = NULL; 
Node* tail = NULL; 

bool isEmpty() {
  return head == NULL;
}


void insertAntrian(string nama, long long int NIM) {
  Node* newNode = new Node; // Buat node baru
  newNode->namaMahasiswa161 = nama;
  newNode->nimMahasiawa161 = NIM;
  newNode->next = NULL; 

  if (isEmpty()) { 
    head = newNode;
    tail = newNode;
  } else { 
    tail->next = newNode;
    tail = newNode;
  }
}


void deleteAntrian() {
  if (isEmpty()) {
    cout << "Data ini kosong, tidak ada data untuk dihapus" << endl;
    return;
  }

  Node* temp = head; 
  head = head->next; 
  delete temp; 

  if (head == NULL) { 
    tail = NULL;
  }
}


int hitungQueue() {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}


void clearQueue() {
  while (!isEmpty()) {
    deleteAntrian();
  }
}


void tampilkanQueue() {
  if (isEmpty()) {
    cout << "Queue sedang kosong" << endl;
    return;
  }

  cout << "Mahasiswa Queue Data:" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->namaMahasiswa161 << " (" << current->nimMahasiawa161 << ")" << endl;
    i++;
    current = current->next;
  }
}

int main() {
  cout << " Queue Mahasiswa " << endl;

  insertAntrian("Dzaki", 2311102161);
  insertAntrian("Christy", 2307051205);
  insertAntrian("Lily", 2312191007);
  insertAntrian("Erine", 2312210807);

  tampilkanQueue();
  cout << "Jumlah antrian: " << hitungQueue() << endl;
  cout << endl;

  deleteAntrian();
  tampilkanQueue();
  cout << "Jumlah antrian: " << hitungQueue() << endl;
  cout << endl;

  deleteAntrian();
  tampilkanQueue();
  cout << "Jumlah antrian: " << hitungQueue() << endl;
  cout << endl;

  deleteAntrian();
  tampilkanQueue();
  cout << "Jumlah antrian: " << hitungQueue() << endl;
  cout << endl;

  cout  << endl;
  clearQueue();
  tampilkanQueue();
  cout << "Jumlah antrian: " << hitungQueue() << endl;

  return 0;
}

```
#### Output:
![alt text](<Screenshot 2024-05-19 193720.png>)
Program implementasi Queue dengan linekd list untuk menimpan data mahasiswa. Node dalam linked list menyimpan nama dan NIM mahasiswa. penginputan data mahasiswa dilakukan dlam main program. Program ini mencakup beberapa fungsi utama:
1. Mengecek apakah antrian kosong.
2. Menambahkan data mahasiswa ke antrian
3. Menghapus data mahasiswa dari antrian
4. Menghitung jumlah data mahasiswa dalam antrian dengan mengiterasi melalui semua node.
5. Mengosongkan seluruh antrian dengan menghapus semua node secara berurutan.
6. Menampilkan seluruh data mahasiswa dalam antrian dengan mengiterasi melalui semua node dan mencetak informasi nama dan NIM.


## Kesimpulan
## Referensi
[1] Stroustrup, B., A Tour of C++ Third Edition. United States: Pearson Education, Inc., 2023.
[2] Zheng Li dkk, C++ Programming. Republic State of China: De Gruyter, 2019.
[3] Carroll, Steven, and Alexander Goponenko. "A C++ implementation of a threadsafe priority queue based on multi-dimensional linked lists and MRLock." (2019).