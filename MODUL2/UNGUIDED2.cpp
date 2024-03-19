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
