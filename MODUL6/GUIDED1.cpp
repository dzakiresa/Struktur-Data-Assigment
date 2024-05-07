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