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