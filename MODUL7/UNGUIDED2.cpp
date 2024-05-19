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