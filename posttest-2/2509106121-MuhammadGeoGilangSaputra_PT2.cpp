#include <iostream>
#include <string>
using namespace std;

// ================== STRUCT ==================
struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

int jumlah = 0;
const int MAX = 100;

// ================== SWAP POINTER ==================
void swapData(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// ================== TAMPIL DATA ==================
void tampil(Hewan* arr) {
    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << (arr + i)->id << " | "
             << (arr + i)->nama << " | "
             << (arr + i)->jenis << " | "
             << (arr + i)->harga << endl;
    }
}

// ================== TAMBAH DATA ==================
void tambah(Hewan* arr) {
    cout << "\nTambah Data\n";
    cout << "ID     : "; cin >> (arr + jumlah)->id;
    cin.ignore();
    cout << "Nama   : "; getline(cin, (arr + jumlah)->nama);
    cout << "Jenis  : "; getline(cin, (arr + jumlah)->jenis);
    cout << "Harga  : "; cin >> (arr + jumlah)->harga;

    jumlah++;
}

// ================== LINEAR SEARCH ==================
void linearSearch(Hewan* arr) {
    string cari;
    cout << "\nCari Nama: ";
    cin.ignore();
    getline(cin, cari);

    for (int i = 0; i < jumlah; i++) {
        cout << "Iterasi ke-" << i + 1 << endl;

        if ((arr + i)->nama == cari) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;

            // swap pointer
            if (i != 0) {
                swapData(arr + i, arr);
            }
            return;
        }
    }

    cout << "Tidak ditemukan\n";
}

// ================== FIBONACCI SEARCH ==================
void fibonacciSearch(Hewan* arr, int x) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < jumlah) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, jumlah - 1);

        if ((arr + i)->id < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if ((arr + i)->id > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            cout << "Data ditemukan: " << (arr + i)->nama << endl;

            // swap pointer
            if (i != 0) {
                swapData(arr + i, arr);
            }
            return;
        }
    }

    cout << "Tidak ditemukan\n";
}

// ================== BUBBLE SORT ==================
void bubbleSort(Hewan* arr) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swapData(arr + j, arr + j + 1);
            }
        }
    }
    cout << "Sorting nama selesai\n";
}

// ================== SELECTION SORT ==================
void selectionSort(Hewan* arr) {
    for (int i = 0; i < jumlah - 1; i++) {
        int min = i;

        for (int j = i + 1; j < jumlah; j++) {
            if ((arr + j)->harga < (arr + min)->harga) {
                min = j;
            }
        }

        swapData(arr + i, arr + min);
    }
    cout << "Sorting harga selesai\n";
}

// ================== MAIN ==================
int main() {
    Hewan data[MAX];
    int pilih;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil\n";
        cout << "2. Tambah\n";
        cout << "3. Cari Nama (Linear)\n";
        cout << "4. Cari ID (Fibonacci)\n";
        cout << "5. Sort Nama (Bubble)\n";
        cout << "6. Sort Harga (Selection)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tampil(data); break;
            case 2: tambah(data); break;
            case 3: linearSearch(data); break;
            case 4: {
                int id;
                cout << "Masukkan ID: ";
                cin >> id;
                fibonacciSearch(data, id);
                break;
            }
            case 5: bubbleSort(data); break;
            case 6: selectionSort(data); break;
        }

    } while (pilih != 0);

    return 0;
}