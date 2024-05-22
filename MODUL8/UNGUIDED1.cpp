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
