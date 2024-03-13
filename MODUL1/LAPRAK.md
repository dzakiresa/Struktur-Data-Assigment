# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Dasar Teori

Tipe data adalah suatu memori atau media pada komputer yang digunakan untuk menampung informasi atau data sementara. Tipe data berfungsi untuk mempresentasikan jenis dari sebuah nilai yang terdapat dalam program. Berikut ini merupakan macam-macam tipe data serta penjelasannya yang terdapat pada C++:

1. Tipe Data Primitif<br/>
Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem dan disediakan oleh banyak bahasa pemrograman. Ini adalah blok bangunan fundamental untuk menyimpan nilai-nilai sederhana. Contoh tipe data primitif:
    - Int (Bilangan bulat)
    - Float (Bilangan desimal)
    - Char (Huruf)
    - Boolean (True/False)

2. Tipe Data Abstrak<br/>
Tipe data abstrak atau yang biasa disebut Abstrak Data Type merupakan tipe data yang dibentuk oleh programmer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data

3. Tipe Data Koleksi<br/>
Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Contoh data koleksi:
    - Array (struktur data statis yang menyimpan elemen-elemen dengan
    tipe data yang sama)
    - Vector (vector mirip seperti array yang memiliki
    kemampuan untuk menyimpan data dalam bentuk elemen-elemen yang alokasi
    memorinya dilakukan otomatis dan bersebelahan)
    - Map (Map terasa mirip dengan array namun dengan index yang memungkinkan
    untuk berupa tipe data selain integer)

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << "Result: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Result: " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Result: " << num1 * num2 << endl;
        break;
    case '/':
        if (num2 == 0) {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2 << endl;
        } else {
            cout << "Error!: Division by zero" << endl;
        }
        break;

    default:
        cout << "Error! operator is not correct" << endl;
        break;
    }
    return 0;
}
```
Kode di atas digunakan untuk memilih operasi penambahan, pengurangan, perkalian, dan pembagian. Keempat operasi ini akan berjalan ketita user sudah menginputkan dalam cin. Terdapat dua tipe data primitif pada program ini, yaitu char dan float. Tipe data char digunakan pada saat pemilihan switch case dan float digunakan sebagai tipe data 2 angka yang diinput user.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>
#include <string.h>
// Struct
struct Mahasiswa
{
    char name[50];
    char address[50];
    int age;
};
int main() {
    // Menggunakan Struct
    struct Mahasiswa mhs1, mhs2;
    // Mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;
    // Mencetak isi dari struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
Kode di atas digunakan untuk mencetak isi dari struct. Struct merupakan contoh dari salah satu tipe data abstrak. Pada kode di atas terdapat struct Mahasiswa. Pada struct Mahasiswa terdapat 3 nilai, yaitu char name dengan ukuran 50, char address dengan ukuran 50 juga, dan int age. Pada int main diisi nilai dan dideklarasikan struct Mahasiswa dengan 2 objek, yaitu mhs1 dengan nama Dian dan mhs2 dengan nama Bambang.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
#include <array>
using namespace std;
int main() {
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak isi dari array. Array merupakan contoh dari tipe data koleksi. Pada kode di atas, terdapat library array yang membantu proses pemrogramannya. Terdapat array nilai yang dapat menampung 5 nilai, yaitu 23, 50, 34, 78, dan 90. Lalu dideklarasikan di bawahnya.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
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
```
#### Output:
![Screenshot Output Unguided 1](Output-Unguided-1_Jordan.png)
Kode di atas digunakan untuk menjalankan operasi penjumlahan dan perkalian dengan nilai yang sudah dimasukkan sebelum program berjalan

Kesimpulan Tipe Data Primitif:<br/>
Tipe data primitif merupakan sebuah tipe data yang sudah ditentukan oleh sistem dan disediakan oleh banyak bahasa pemrograman

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++
/* fungsi dari class. 
Class berfungsi untuk mengelompokkan data dan variabel yang berhubungan menjadi satu kesatuan

fungsi dari struct.
Struck berfungsi untuk mengelompokkan beberapa data yang berbeda tipe menjadi satu unit
*/

#include <iostream>
using namespace std;
// Struct Person yang berisi data nama string dan umur int
struct Person {
    string Name;
    int Year;
};
// Class Vehicle yang berisi data brand string, model string, dan tahun rilis int dalam akses public
class Vehicle {
  public:
    string Brand;   
    string Model;
    int YearReleased;
};
int main() {
    // Deklarasi Struct Person
    Person person{" Shozo Kawasaki", 1878};
    cout << "\n- Biography - " << endl;
    cout << "Name: " << person.Name << endl;
    cout << "Year: " << person.Year << endl;
    // Deklarasi Class Vehicle
    Vehicle vehicle;
    vehicle.Brand = "Kawasaki";
    vehicle.Model = "H2R";
    vehicle.YearReleased = 2015;
    cout << "Vehicle brand: " << vehicle.Brand << endl;
    cout << "Vehicle model: " << vehicle.Model << endl;
    cout << "Vehicle year released: " << vehicle.YearReleased << endl;
    return 0;
}
```
#### Output:
![Screenshot Output Unguided 2](Output-Unguided-2_Jordan.png)
Kode di atas digunakan untuk mencetak class dan struct. Pada kode di atas, terdapat class Vehicle yang menampung nilai string Brand, string Model, dan int YearReleased dengan akses publik. Ada juga struct Person dengan nilai string Name dan int Age. Struct Person ini diisi dengan Shozo Kawasaki dengan tahun 1878 dan Class Vehicle diisi dengan nilai Kawasaki H2R tahun 2015, lalu struct & class ini kemudian dijalankan.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
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

```
#### Output:
![Screenshot Output Unguided 3](Output-Unguided-3_Jordan.png)
Program tersebut menunjukkan penggunaan map untuk menyimpan dan mengakses data dengan kunci-nilai. Dalam hal ini, digunakan map yang memetakan nama ke usia. Program menambahkan beberapa entri, mengakses nilai berdasarkan kunci, dan menampilkan informasi usia ke layar.


## Kesimpulan
Pemahaman yang baik tentang tipe data primitif, tipe data abstrak, dan koleksi dalam C++ dapat digunakan untuk memiliih dengan bijak dan merancang struktur data yang sesuai kebutuhan

## Referensi
[1]Khoirudin, Algoritma & Struktur Data dengan Python 3. Semarang: Universitas Semarang Press, 2019.
[2]Zenda,A.D.(2018, July 13).PENGERTIAN ARRAY.
[3]Wahyuni, Zelfi. “Makalah Dasar-dasar Pemograman Komputer.” OSF Preprints, 27 Feb. 2023. Web.