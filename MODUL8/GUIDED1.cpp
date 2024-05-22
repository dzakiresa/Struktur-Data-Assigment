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