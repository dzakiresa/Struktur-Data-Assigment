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
