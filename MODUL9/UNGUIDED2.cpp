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