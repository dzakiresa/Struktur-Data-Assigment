// perkondisian count, int count++
#include <iostream>
using namespace std;

//2311102161

// Fungsi untuk menghitung jumlah angka 4 dalam array
int hitungBanyak(int data[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 4) {
            count++;
        }
    }
    return count;
}

int main() {
    // Data yang diberikan
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]); // Jumlah elemen dalam data

    // Menampilkan hasil
    cout << "Banyaknya angka 4 ada : " << hitungBanyak(data, n) << endl;

    return 0;
}

