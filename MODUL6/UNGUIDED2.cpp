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
