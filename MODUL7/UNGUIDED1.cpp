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