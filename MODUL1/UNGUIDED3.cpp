/*Perbedaan antara Array dan Map:
Tipe Data:
Array: Menyimpan elemen dengan indeks berurutan (integer).
Map: Menyimpan elemen sebagai pasangan kunci-nilai, di mana kunci bisa berupa tipe data apa pun.

Akses ke Elemen:
Array: Akses menggunakan indeks integer.
Map: Akses menggunakan kunci, yang bisa memiliki tipe data apa pun.

Ukuran:
Array: Ukuran array tetap dan dideklarasikan pada saat kompilasi.
Map: Dinamis, ukuran dapat berubah seiring waktu.

Inisialisasi:
Array: Memerlukan inisialisasi dengan elemen-elemen pada saat deklarasi.
Map: Dapat diisi secara dinamis selama eksekusi program.

Kemudahan Penggunaan:
Array: Sederhana untuk akses elemen berdasarkan indeks.
Map: Fleksibel, memungkinkan penyimpanan dan akses data dengan kunci yang dapat didefinisikan sendiri.*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    // Membuat map dengan kunci bertipe string dan nilai bertipe int
    map<string, int> data;
    // Menambahkan pasangan kunci-nilai ke dalam map
    data["Angelina"] = 18;
    data["Jeane"] = 16;
    data["Aurelia"] = 20;
    // Mengakses dan menampilkan nilai menggunakan kunci
    cout << "Usia Angelina: " << data["Angelina"] << " tahun" << endl;
    cout << "Usia Jeane: " << data["Jeane"] << " tahun" << endl;
    cout << "Usia Aurelia: " << data["Aurelia"] << " tahun" << endl;
    return 0;
}
