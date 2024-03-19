#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    // Membuat array dengan ukuran yang ditentukan oleh pengguna
    int arr[n];

    // Memasukkan elemen-elemen array
    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elemen " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Mencari nilai maksimum dan minimum
    int maksimum = arr[0];
    int minimum = arr[0];
    double total = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] > maksimum) {
            maksimum = arr[i];
        }
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
        total += arr[i];
    }

    // Menghitung rata-rata
    double rata_rata = total / n;

    // Menampilkan hasil
    cout << "Nilai maksimum: " << maksimum << endl;
    cout << "Nilai minimum: " << minimum << endl;
    cout << "Nilai rata-rata: " << rata_rata << endl;
}
