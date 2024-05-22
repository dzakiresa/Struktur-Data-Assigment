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
