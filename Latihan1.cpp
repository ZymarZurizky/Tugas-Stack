#include <iostream>
using namespace std;

// Deklarasi stack dengan struct dan array
struct Stack
{
    int data[5];
    int top;
};

// Inisialisasi stack
void initialize(Stack &s)
{
    s.top = -1;
}

// Menambahkan data ke dalam stack (push)
void push(Stack &s, int book)
{
    if (s.top < 4)
    {
        s.data[++s.top] = book;
        cout << "Buku berhasil ditambahkan ke dalam tumpukan." << endl;
    }
    else
    {
        cout << "Tumpukan sudah penuh. Tidak dapat menambahkan buku lagi." << endl;
    }
}

// Mengeluarkan data dari stack (pop)
void pop(Stack &s)
{
    if (s.top >= 0)
    {
        cout << "Buku dengan ID " << s.data[s.top--] << " diambil dari tumpukan." << endl;
    }
    else
    {
        cout << "Tumpukan kosong. Tidak ada buku yang bisa diambil." << endl;
    }
}

// Melihat buku paling atas dalam stack (peek)
void peek(const Stack &s)
{
    if (s.top >= 0)
    {
        cout << "Buku dengan ID " << s.data[s.top] << " berada di paling atas tumpukan." << endl;
    }
    else
    {
        cout << "Tumpukan kosong. Tidak ada buku yang bisa dilihat." << endl;
    }
}

// Memeriksa apakah stack kosong
bool isEmpty(const Stack &s)
{
    return s.top == -1;
}

// Menghitung jumlah buku dalam stack
int size(const Stack &s)
{
    return s.top + 1;
}

int main()
{
    Stack tumpukan;
    initialize(tumpukan);

    int choice, bookId;
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Tambah buku" << endl;
        cout << "2. Ambil buku" << endl;
        cout << "3. Lihat buku paling atas" << endl;
        cout << "4. Cek apakah tumpukan kosong" << endl;
        cout << "5. Jumlah buku dalam tumpukan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih operasi: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan ID buku: ";
            cin >> bookId;
            push(tumpukan, bookId);
            break;
        case 2:
            pop(tumpukan);
            break;
        case 3:
            peek(tumpukan);
            break;
        case 4:
            cout << (isEmpty(tumpukan) ? "Tumpukan kosong." : "Tumpukan tidak kosong.") << endl;
            break;
        case 5:
            cout << "Jumlah buku dalam tumpukan: " << size(tumpukan) << endl;
            break;
        case 0:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    } while (choice != 0);

    return 0;
}