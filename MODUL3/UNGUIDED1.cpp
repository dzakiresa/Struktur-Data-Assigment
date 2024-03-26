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