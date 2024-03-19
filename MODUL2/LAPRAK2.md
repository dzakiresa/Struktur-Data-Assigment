# <h1 align="center">Laporan Praktikum Modul 2 - ARRAY</h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Dasar Teori

Array merupakan salah satu struktur data paling dasar. Array merupakan suatu tipe data yang berisi kumpulan suatu nilai atau tipe data lain, array umumnya juga digunakan untuk menampung banyak nilai dalam satu variabel dan urutan indeks array dimulai dari 0. 

1. Array Satu Dimensi<br/>
    Array satu dimensi merupakan variabel yang terdiri dari kumpulan data dengan tipe data yang sama yang disusun dalam satu baris. Setiap elemen memiliki indeks untuk mengakses elemen tersebut, indeks tersebut dimulai dari 0 dan berakhir pada jumlah elemen dikurangi satu.

2. Array Dua Dimensi<br/>
    Array dua dimensi merupakan variabel yang berasal dari kumpulan array sati deimensi dengan tipe data sama yang disusun dalam baris dan kolom. Dalam array dua dimensi memiliki dua indeks yaitu indeks baris dan indeks kolom, indeks baris menunjukkan letak elemen dalam baris serta indeks kolom menunjukkan letak elemen dalam kolom.

3. Array Multi Dimensi<br/>
Array Multi Dimensi merupakan array yang memiliki indeks lebih dari dua dengan kapasitas memori yang lebih besar, seperti array tiga dimensi, array empat dimensi dan seterusnya.

## Guided 

### 1. Array Tiga Dimensi 

```C++
#include <iostream>
using namespace std;
// program input array 3 dimensi
int main()
{
    // deklarasi array
    int arr[2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Array[" << x << "][" << y << "][" << z << "]: " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Kode di atas merupakan sebuah array tiga dimensi, dengan memasukkan input angka dari user program tersebut akan mencetak sebuah array tiga dimensi.

### 2. Mencari Nilai Maksimal Pada Array

```C++
#include <iostream>
using namespace std;
int main ()
{
    int maks, a, i=1, lokasi;
    cout <<"masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout <<"masukkan " << a << " angka \n";
    for (i=0; i<a; i++)
    {
        cout << "array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i=0; i<a; i++)
    {   //metode serching
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout <<"nilai maksimum adalah " << maks << " berada di array ke " << lokasi << endl;
}
```
Kode di atas digunakan untuk mencari nilai terbesar dari inputan yang telah user masukkan dan di simpan dalam array.

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Masukkan jumlah bilangan: ";
    cin >> n;

    vector<int> bilangan(n);
    vector<int> ganjil;
    vector<int> genap;

    cout << "Masukkan " << n << " bilangan: ";
    for (int i = 0; i < n; ++i) {
        cin >> bilangan[i];
        if (bilangan[i] % 2 == 0) {
            genap.push_back(bilangan[i]);
        } else {
            ganjil.push_back(bilangan[i]);
        }
    }

    cout << "Bilangan yang dimasukkan: ";
    for (int bil : bilangan) {
        cout << bil << " ";
    }
    cout << endl;

    cout << "Bilangan Ganjil: ";
    for (int bil : ganjil) {
        cout << bil << " ";
    }
    cout << endl;

    cout << "Bilangan Genap: ";
    for (int bil : genap) {
        cout << bil << " ";
    }
    cout << endl;
}
```
#### Output:
![alt text](<Screenshot 2024-03-17 221531.png>)
Kode di atas digunakan untuk memisahkan antara bilangan ganjil dan bilangan genap yang telah diinputkan user dan telah di simpan dalam array yang telah ditentikan banyaknya.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

int main() {
    int dim1, dim2, dim3;
    cout << "Masukkan jumlah elemen untuk dimensi pertama: ";
    cin >> dim1;
    cout << "Masukkan jumlah elemen untuk dimensi kedua: ";
    cin >> dim2;
    cout << "Masukkan jumlah elemen untuk dimensi ketiga: ";
    cin >> dim3;
    int arr[dim1][dim2][dim3];
    for (int x = 0; x < dim1; x++) {
        for (int y = 0; y < dim2; y++) {
            for (int z = 0; z < dim3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    for (int x = 0; x < dim1; x++) {
        for (int y = 0; y < dim2; y++) {
            for (int z = 0; z < dim3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    cout << endl;

    for (int x = 0; x < dim1; x++) {
        for (int y = 0; y < dim2; y++) {
            for (int z = 0; z < dim3; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
#### Output:
![alt text](<Screenshot 2024-03-17 234032.png>)
Kode di atas digunakan untuk mencetak array tiga dimensi yang jumlah atau ukuran elemennya diinputkan oleh user.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
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
```
#### Output:
![alt text](<Screenshot 2024-03-17 234335.png>)
Program tersebut merupakan sebuah array yang digunakan untuk mencari nilai maksimum, minimum dan rata rata dari nilai yang telah diinputkan oleh user.


## Kesimpulan
Array umumnya digunakan untuk menyimpan banyak nilai dalam satu variabel, Ututan indeks array dimulai dari 0 dan berakhir pada jumlah elemen dikurangi satu. Indeks atau nomor elemen digunakan untuk mengakses elemen tersebut. Array tidak hanya memiliki bentuk satu dimensi tapi juga memiliki bentik lain seperti array dua dimensi (dengan indeks baris dan indeks kolom) dan array multi dimensi 

## Referensi
[1]Zenda,A.D.(2018, July 13).PENGERTIAN ARRAY.
[2]Putra, Muhammad Taufik Dwi. dkk. 2022. BELAJAR DASAR PEMROGRAMAN DENGAN C++.