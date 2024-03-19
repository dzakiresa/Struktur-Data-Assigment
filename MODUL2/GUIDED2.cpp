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