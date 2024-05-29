# <h1 align="center">Laporan Praktikum Modu9  - GRAPH DAN TREE </h1>
<p align="center">Dzaki Resalianto - 2311102161</p>

## Dasar Teori
Graf merupakan struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node dan sambungan antara node tersebut dalam bentuk sisi atau edge. Graf terdiri dari simpul dan busur G = (V, E). G adalah Graph, V adalah simpul atau vertex dan E sebagai sisi atau edge. Beberapa pengaplikasian Graf seperti jaringan sosial, pemetaan jalan dan pemodelan data. 
Beberapa jenis Graf : 
1. Graph berarah (directed graph): Urutan simpul mempunyai arti.
2. Graph tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak diperhatikan.
3. Weight Graph : Graph yang mempunyai nilai pada tiap edgenya.

Tree atau Pohon merupakan kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layaknya struktur sebuah pohon. Struktur pohon adalah suatu cara merepresentasikan suatu struktur hirarki (one-to-many) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan node-node dari atas ke bawah. Struktur data tree digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema pertandingan, struktur organisasi. 
Beberapa istilah dalam Tree :
- Predecessor, node yang berada diatas node tertentu
- Successor, node yang berada dibawah node tertentu
- Ancestor, seluruh node yang terletak sebelum node tertentu dan terleteak pada jalur yang sama
- Descendant, seluruh node yang terletak setelah node tertentu dan terletak pada jalur yang sama
- Parent, predecessor satu level di atas suatu node
- Child, successor satu level di bawah suatu node
- Sibling, node-node yang memiliki parent yang sama
- Subtree, suatu node beserta descendantnya
- Size, banyaknya node dalam suatu tree
- Height, banyaknya tingkatan dalam suatu tree
- Root, node khusus yang tidak memiliki predecessor
- Leaf, node-node dalam tree yang tidak memiliki successor
- Degree, banyaknya child daalm suatu node

Beberapa jenis tree :
1. Binary tree, Tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua sub pohon dan kedua subpohon harus terpisah.
2. Full Binary Tree, Semua node, kecuali leaf pasti memiliki 2 anak dan tiap subpohon memiliki panjang path yang sama.
3. Complete Binary Tree, Tree yang mirip dengan full binary tree, tapi tiap subtree boleh memiliki panjang path yang berbeda dan tiap node (kecuali leaf) memiliki 2 anak.
4. Skewed Binary Tree, Binary tree yang semua nodenya (kecuali leaf) hanya memiliki satu anak.

## Guided 

### 1. Latihan 

```C++
#include <iostream> 
#include <iomanip> 
using namespace std; 
 
string simpul[7] = { 
    "Ciamis",  
    "Bandung",  
    "Bekasi",  
    "tasikmalaya", 
    "Cianjur",  
    "Purwokerto",  
    "Yogyakarta"  
}; 
 
int busur[7][7] = { 
    {0, 7, 8, 0, 0, 0, 0}, 
    {0, 0, 5, 0, 0, 15, 0}, 
    {0, 6, 0, 0, 5, 0, 0}, 
    {0, 5, 0, 0, 2, 4, 0}, 
    {23, 0, 0, 10, 0, 0, 8}, 
    {0, 0, 0, 0, 7, 0, 3}, 
    {0, 0, 0, 0, 9, 4, 0} 
}; 
 
void tampilGraph(){ 
    for (int baris = 0; baris <7; baris ++){ 
        cout <<" " << setiosflags (ios::left)<<setw (15) 
        << simpul [baris] << " : "; 
        for (int kolom = 0; kolom<7; kolom++){ 
            if (busur[baris][kolom]!=0){ 
                cout << " " << simpul[kolom]<< "(" << busur[baris][kolom] 
<< ")"; 
            } 
        } 
        cout << endl; 
    }       
} 
 
int main(){ 
    tampilGraph(); 
    return 0; 
}
```
#### Output: 
![alt text](<Screenshot 2024-05-29 213520.png>)
Menampilkan sebuah graf berbasis matriks ketetanggaan untuk tujuh kota di Indonesia (Ciamis, Bandung, Bekasi, Tasikmalaya, Cianjur, Purwokerto, Yogyakarta). Fungsi tampilGraph() digunakan untuk menampilkan graf ini dalam bentuk yang mudah dibaca, dengan mencetak setiap kotabeserta kota-kota yang terhubung langsung dengannya dan jarak antar kota tersebut.

### 2. Latihan 

```C++
#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;

            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main()
{
    init();
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    return 0;
}
```
#### Output: 
![alt text](<Screenshot 2024-05-27 232351.png>)
![alt text](<Screenshot 2024-05-27 232414.png>)
Operasi pada pohon biner menggunakan struktur data Pohon yang mencakup simpul (node), anak kiri dan kanan (left, right), serta induk (parent). Fungsi utama mencakup pembuatan pohon, penambahan simpul anak kiri dan kanan, pembaruan data simpul, pengambilan dan pencarian data simpul, penelusuran pohon dengan metode pre-order, in-order, dan post-order. Program ini juga dapat menghapus simpul tertentu atau keseluruhan pohon, serta menghitung ukuran dan tinggi pohon, dan menampilkan karakteristik pohon.


## UNGUIDED 

```C++
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
```
#### Output:
![alt text](<Screenshot 2024-05-29 220156.png>)
Pengguna memasukkan sejumlah kota dan memasukkan jarak antar kota yang akan ditampilkan dalam bentuk grafik matriks. pertama pengguna diminta memasukkan jumlah kota yang ingin dimasukkan kemudian namanya, kedua memasukkan jarak antar setiap kota, kketiga menampilkan jarak setiap kota dalam bentuk grafik matriks.  
## UNGUIDED 

```C++
#include <iostream>
#include <queue>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

Pohon *PohonBaru_161(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = PohonBaru_161(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = PohonBaru_161(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = PohonBaru_161(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;

            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Menampilkan anak-anak node
void displayChildren(Pohon *node)
{
    if (!node)
    {
        cout << "Node tidak ada!" << endl;
        return;
    }

    cout << "Anak-anak dari node " << node->data << ": ";
    if (node->left)
        cout << node->left->data << " ";
    if (node->right)
        cout << node->right->data << " ";
    if (!node->left && !node->right)
        cout << "(tidak ada)";
    cout << endl;
}

// Menampilkan keturunan node
void displayDescendants(Pohon *node)
{
    if (!node)
    {
        cout << "Node tidak ada!" << endl;
        return;
    }

    cout << "Keturunan dari node " << node->data << ": ";
    queue<Pohon *> q;
    if (node->left)
        q.push(node->left);
    if (node->right)
        q.push(node->right);

    if (q.empty())
    {
        cout << "(tidak ada)";
    }
    else
    {
        while (!q.empty())
        {
            Pohon *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    cout << endl;
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

Pohon* findNode(Pohon *node, char data)
{
    if (node == NULL)
        return NULL;
    if (node->data == data)
        return node;
    Pohon* foundNode = findNode(node->left, data);
    if (foundNode == NULL)
        foundNode = findNode(node->right, data);
    return foundNode;
}

void menu()
{
    int choice;
    char data;
    char parentData;
    Pohon *node;

    
        cout << "\nMenu: \n";
        cout << "1. Buat Root Node\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Tampilkan Anak Node\n";
        cout << "8. Tampilkan Keturunan Node\n";
        cout << "9. PreOrder Traversal\n";
        cout << "10. InOrder Traversal\n";
        cout << "11. PostOrder Traversal\n";
        cout << "12. Hapus SubTree\n";
        cout << "13. Clear Tree\n";
        cout << "14. Tampilkan Karakteristik Tree\n";
        cout << "0. Exit\n";
        
    do {
        cout << "Pilihan: ";
        cin >> choice;
    
        switch (choice)
        {
        case 1:
            cout << "Masukkan data root: ";
            cin >> data;
            buatNode(data);
            break;
        case 2:
            cout << "Masukkan data node baru: ";
            cin >> data;
            cout << "Masukkan data parent: ";
            cin >> parentData;
            node = findNode(root, parentData);
            if (node)
                insertLeft(data, node);
            else
                cout << "Parent tidak ditemukan!" << endl;
            break;
        case 3:
            cout << "Masukkan data node baru: ";
            cin >> data;
            cout << "Masukkan data parent: ";
            cin >> parentData;
            node = findNode(root, parentData);
            if (node)
                insertRight(data, node);
            else
                cout << "Parent tidak ditemukan!" << endl;
            break;
        case 4:
            cout << "Masukkan data node yang akan diupdate: ";
            cin >> data;
            cout << "Masukkan data baru: ";
            cin >> parentData;
            node = findNode(root, data);
            if (node)
                update(parentData, node);
            else
                cout << "Node tidak ditemukan!" << endl;
            break;
        case 5:
            cout << "Masukkan data node yang ingin di-retrieve: ";
            cin >> data;
            node = findNode(root, data);
            retrieve(node);
            break;
        case 6:
            cout << "Masukkan data node yang ingin dicari: ";
            cin >> data;
            node = findNode(root, data);
            find(node);
            break;
        case 7:
            cout << "Masukkan data node yang ingin dilihat anak-anaknya: ";
            cin >> data;
            node = findNode(root, data);
            displayChildren(node);
            break;
        case 8:
            cout << "Masukkan data node yang ingin dilihat keturunannya: ";
            cin >> data;
            node = findNode(root, data);
            displayDescendants(node);
            break;
        case 9:
            cout << "\nPreOrder Traversal: \n";
            preOrder(root);
            cout << "\n";
            break;
        case 10:
            cout << "\nInOrder Traversal: \n";
            inOrder(root);
            cout << "\n";
            break;
        case 11:
            cout << "\nPostOrder Traversal: \n";
            postOrder(root);
            cout << "\n";
            break;
        case 12:
            cout << "Masukkan data node subtree yang ingin dihapus: ";
            cin >> data;
            node = findNode(root, data);
            if (node)
                deleteSub(node);
            else
                cout << "Node tidak ditemukan!" << endl;
            break;
        case 13:
            clear();
            break;
        case 14:
            characteristic();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    } while (choice != 0);
}

int main()
{
    init();
    menu();
    return 0;
}
```
#### Output:
![alt text](<Screenshot 2024-05-29 224558.png>)
![alt text](<Screenshot 2024-05-29 224643.png>)
Program ini menyediakan berbagai fungsi dasar untuk manipulasi dan pengelolaan pohon biner, termasuk penambahan, penghapusan, pembaruan, penelusuran, dan menampilkan informasi pohon dan node secara interaktif.
## Kesimpulan
Graf dan Tree merupakan struktur data untuk merepresentasikan hubungan antar objek. Graf terdiri dari simpul dan sisi terdapat beberapa jenis graf (Graph berarah, Graph tak berarah, Weight Graph) dengan karakteristik dan pengaplikasiannya masing masing. tree adalah struktur data hirarkis yang juga terdiri dari node yang saling terhubung, dengan istilah-istilah khusus seperti root, leaf, parent, dan child. Terdapat beberapa jenis Tree (Binary tree, Full Binary Tree, Complete Binary Tree, Skewed Binary Tree) dengan penggunaan yang spesifik pada setiap jenis.
## Referensi
[1] Berry, A., Simonet, G., Computing the Atom Graph of a Graph and the Union Join Graph of a Hypergraph, Vol. 14, Hal. 1-20, 28 November 2021.
[2] Sedgewick, R., Algorithms in C++ Part 5: Graph Algorithms 3rd Edition. Boston: Addison-Wesley Professional, 2020.