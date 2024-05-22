# <h1 align="center">Laporan Praktikum Modu8  - ALGORITMA SEARCHING</h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Tujuan Praktikum
a. Menunjukkan beberapa algoritma dalam Pencarian.
b. Menunjukkan bahwa pencarian merupakan suatu persoalan yang bisa diselesaikan
dengan beberapa algoritma yang berbeda.
c. Dapat memilih algoritma yang paling sesuai untuk menyelesaikan suatu
permasalahan pemrograman.

## Dasar Teori
Searching atau pencarian adalah proses untuk menemukan suatu nilai dalam kumpulan data yang ada. terdapat beberapa hasil dalam searching atauu pencarian, tiga hasil tersebut adalah data ditemukan, data ditemukan lebih dari satu dan data tidak ditemukan. Terdapat dua metode pencarian yaitu Sequential Search dan Binary Search.
Sequential Search merupakan metode serarching paling mudah untuk menemukan data dalam array, dengan mengurutkan dan membaca data satu persatu dari indeks terkecil hingga indeks terbesar maupun sebaliknya. Selain itu Sequential Search juga bisa digunakan untuk pencarian data berpola acak atau belum terurut. Sengan menggunakan konsep sebagai berikut : membandingkan elemen yang ada satu persatu secara berurutan, pencarian dimulai dari indeks pertama hingga terakhir, pencarian akan berhenti jika data yang dicari sudah ditemukan, pencarian akan teteap dihentikan apabila data yang dicari tidak ditemukan, proses perulangan pada pencarian dilakukan sebanyak data yang ada.
Binary Search meruppakan metode searching yang digunakan pada data yang sudah terurut (dikombinasikan dengan algoritma sorting). Metode ini mengharuskan data terurut terlebih dahulu, kemudian data dibagi dua secara logika dalam pencariannya, kemudia menentukan apakah nilai yang dicari berkemungkinan ada di sebelah kiri atau sebelah kanan hasil pembagian, pencarian ini akan terus berlangsung hingga data ditemukan. metode pencarian ini efektif untuk mencari data dalam jumlah besar. Konsep dalam Binary Search yaitu data yang sudah terurut diambil dari posisi pertama hingga terakhir, kemudian data dibagi dua untuk mendpatkan posisi tengah, lalu membandingkan data tengah apakah lebih besar atau kecil, jika data yang dicari lebih kecil dari data tengah kemungkinan data berada di sebelah kiri, kemudian data kiri akan dibagii menjadi dua untuk mendapatkan nillai tengah begitu seterusnya proses berulang hingga data ditemukan, apabila data berniali sama maka akan langsung ditemuakn.
## Guided 

### 1. Latihan 

```C++
#include <iostream>
using namespace std;
  
int arr[]={1,2,3,4,5,6,7,8,9,10};
int cari = 5;
bool ketemu = false; 
int panjangArray = sizeof(arr)/sizeof(arr[0]);
int i; // variabel global
int main()
{
    for(i = 0; i<panjangArray; i++)
    {
     if(arr[i] == cari){
        ketemu = true;
        break;
     }
     else{
        i++;
     }
    }    

    cout <<"panjang array " <<panjangArray<<endl;
    cout<<"nilai " <<cari<<" terdapat pada indeks ke "<< i;
}
```
#### Output: 
![alt text](<Screenshot 2024-05-22 185858.png>)
program pencarian data yang terdapat pada array ddengan panjang 10, dengan menggunakan loop for untuk mengecek dara array satu persatu dari indeks 0 hingga 9, apabila data sudah ditemukan maka pencarian akan dihentikan.

### 2. Latihan 

```C++
#include <iostream>
#include <iomanip>
using namespace std;

//deklarasi array  dan variabel untk pencarian

int arrayData[7] = {1,8,2,5,4,9,7};
int cari;

void selectionShort(int arr[], int n){
    int temp, min;
    for(int i = 0; i < n -1; i++){
        min = i;
        for(int j = i +1; j < n; j++ )
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }

        //tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void binarySearch (int arr[], int n, int target){
    int awal = 0, akhir = n-1, tengah, b_flag = 0;

    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if(arr[tengah]== target){
            b_flag = 1;
            break;
        } 
        else if (arr[tengah] < target){
            awal = tengah +1;
        }
        else{
            akhir = tengah -1;
        }
    }

    if(b_flag == 1){
        cout << "Ddata ditemukan pada indeks ke "<< tengah << endl;
    }
    else{
        cout <<"/nData tidak ditemukan/n" ;
    }
}

int main() {
cout << "\tBINARY SEARCH" << endl;
cout << "\nData awal: ";
// Tampilkan data awal
for (int x = 0; x < 7; x++) {
cout << setw(3) << arrayData[x];
}
cout << endl;
cout << "\nMasukkan data yang ingin Anda cari: ";
cin >> cari;
// Urutkan data dengan selection sort
selectionShort(arrayData, 7);
cout << "\nData diurutkan: ";
// Tampilkan data setelah diurutkan
for (int x = 0; x < 7; x++) {
cout << setw(3) << arrayData[x];
}
cout << endl;
// Lakukan binary search
binarySearch(arrayData, 7, cari);
return 0;
}

```
#### Output: 
![alt text](<Screenshot 2024-05-22 191026.png>)
progeam pencarian dengan metode Binary Search dengan mengurutkan terlebih dahulu data menggunakan selection sort.

## UNGUIDED 1

```C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 2311102161

bool binarySearch(const string& Kalimat161, char cariKalimat161) {
  int Low161 = 0;
  int High161 = Kalimat161.length() - 1;
  while (Low161 <= High161) {
    int mid = (Low161 + High161) / 2;
    if (Kalimat161[mid] == cariKalimat161) {
      return true;
    } 
    else if (Kalimat161[mid] < cariKalimat161) {
      Low161 = mid + 1;
    } 
    else {
      High161 = mid - 1;
    }
  }
  return false;
}

int main() {
  string Kalimat161;
  char cariKalimat161;

  cout << "Masukkan Nama: ";
  getline(cin, Kalimat161);

  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> cariKalimat161;

  // Mengubah semua huruf dalam kalimat dan huruf yang dicari menjadi huruf kecil
  transform(Kalimat161.begin(), Kalimat161.end(), Kalimat161.begin(), ::tolower);
  cariKalimat161 = tolower(cariKalimat161);

  // Mengurutkan kalimat sebelum melakukan pencarian biner
  sort(Kalimat161.begin(), Kalimat161.end());

  bool ditemukan = binarySearch(Kalimat161, cariKalimat161);

  if (ditemukan) {
    cout << "Huruf '" << cariKalimat161 << "' ada dalam kalimat." << endl;
  } 
  else {
    cout << "Huruf '" << cariKalimat161 << "' tidak ada dalam kalimat." << endl;
  }
  return 0;
}
```
#### Output:
![alt text](<Screenshot 2024-05-22 192750.png>)
Program ini menerima input berupa nama dan huruf yang ingin dicari dari pengguna. Program kemudian mencari huruf tersebut dalam nama yang telah diinput tanpa memperhatikan huruf kapital atau huruf kecil.

## UNGUIDED 2

```C++
// pengkondisian if vokal dihitung 1, jadi vokal doang yang di hitung, dijumlah doang
 //2311102161
#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam kalimat
int countVocal(string sentence)
{
    // Inisialisasi variabel penghitung
    int count = 0;
    int i;
    // Looping melalui setiap karakter dalam kalimat
    for (i = 0; i < sentence.length(); i++)
    {
        // Mendapatkan karakter saat ini
        char huruf = sentence[i];

        // Memeriksa apakah karakter adalah huruf vokal
        if (huruf == 'a' || huruf == 'A' || huruf == 'e' || huruf == 'E' || huruf == 'i' || huruf == 'I' || huruf == 'o' || huruf == 'O' || huruf == 'u' || huruf == 'U')
        {
            // Jika vokal, tambahkan ke penghitung
            count++;
        }
    }
    // Mengembalikan jumlah vokal
    return count;
}

int main()
{
    // Deklarasi variabel untuk kalimat
    string kalimat;

    // Minta input kalimat dari pengguna
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Tampilkan hasil penghitungan
    cout << "seluruh huruf vocal dalam kalimat: " << countVocal(kalimat) << endl;

    return 0;
}
```
#### Output:
![alt text](<Screenshot 2024-05-22 222351.png>)
program ini untuk menghitung total jumlah huruf vokal yang ada baik non maupun kapital. Dengan perulangan seluruh karakter lalu perkondisian dimana hanya huruf vokal saja yang dihitung.

## UNGUIDED 3

```C++
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
```
#### Output:
![alt text](<Screenshot 2024-05-22 223609.png>)
program menghitung banyaknya angka 4 dalam array menggunakan Sequential Search. 

## Kesimpulan
Dari kedua metode pencarian tersebut dapat ditarik kesimpulan bahwa :
1. binary serch lebih cocok digunakan untuk  mencari sebudah nilai dari kumpulan data yang berjumlah banyak
2. sedangkan Sequential Search program pencarian yang mengguakan perulangan sederhana untuk mencari di setiap elemennya dan fleksibel ketika data berubah. 
## Referensi
[1] Budiman, A. & Rusdi, A. (2020). Penerapan Algoritma Pencarian Binary Search pada Sistem Basis Data untuk Meningkatkan Kecepatan Pencarian Data. Jurnal Sains dan Teknologi Komputer, 11(2), 123-130.
[2] Fenina Adline Twince Tobing, Rena Nainggolan, ANALISIS PERBANDINGAN PENGGUNAAN METODE BINARY SEARCH DENGAN REGULAR SEARCH EXPRESSION, Vol. 4, No. 2, 168-172, Oktober 2020.