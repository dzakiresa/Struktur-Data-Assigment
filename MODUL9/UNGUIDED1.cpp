#include <iostream>
#include <vector> 
#include <iomanip> 
using namespace std;

int main() {
    int jarakKota_161;

    cout << "Silahkan masukan Jumalah Simpul : "; cin >> jarakKota_161;

    vector<string> kota(jarakKota_161); 
    cout << "Silahkan masukan Nama Simpul" << endl;
    for (int i = 0; i < jarakKota_161; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> kota[i]; 
    }

    cout << "Silahkan masukkan bobot antar simpul\n";

    vector<vector<int>> kota2(jarakKota_161, vector<int>(jarakKota_161)); 
    for (int i = 0; i < jarakKota_161; ++i) {
        for (int j = 0; j < jarakKota_161; ++j) { 
            cout << kota[i] << " --> " << kota[j] << " = ";
            cin >> kota2[i][j];
        }
    }
    
    cout << "\n           ";
    for (const auto& city : kota) { 
        cout << setw(10) << city;
    }
    cout << '\n';

    for (int i = 0; i < jarakKota_161; ++i) { 
        cout << setw(10) << kota[i];
        for (int j = 0; j < jarakKota_161; ++j) {
            cout << setw(10) << kota2[i][j]; 
        }
        cout << '\n';
    }
    return 0;
}