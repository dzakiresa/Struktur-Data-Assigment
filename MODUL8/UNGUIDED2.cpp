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