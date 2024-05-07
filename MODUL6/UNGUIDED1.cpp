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
