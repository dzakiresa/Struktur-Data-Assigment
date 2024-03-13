#include <iostream>
using namespace std;
// Fungsi untuk menjumlahkan dua angka
int tambah(int angka1, int angka2) {
    return angka1 + angka2;
}
// Fungsi untuk mengalikan dua angka
int kali(int angka1, int angka2) {
    return angka1 * angka2;
}
int main() {
    // Program Utama
    int bilangan1 = 5;
    int bilangan2 = 3;
    // Menggunakan fungsi tambah dan kali
    int hasil_penjumlahan = tambah(bilangan1, bilangan2);
    int hasil_perkalian = kali(bilangan1, bilangan2);
    // Menampilkan hasil ke layar
    cout << "Hasil penjumlahan: " << hasil_penjumlahan << endl;
    cout << "Hasil perkalian: " << hasil_perkalian << endl;
    return 0;
}
