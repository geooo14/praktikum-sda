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

// ================== SWAP ==================
void swapData(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// ================== TAMPIL ==================
void tampil(Hewan* arr) {
    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << (arr + i)->id << " | "
             << (arr + i)->nama << " | "
             << (arr + i)->jenis << " | "
             << (arr + i)->harga << endl;
    }
}

// ================== TAMBAH ==================
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
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;

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

// ================== QUICK SORT ==================
int partitionQS(Hewan* arr, int low, int high) {
    int pivot = (arr + high)->id;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((arr + j)->id < pivot) {
            i++;
            swapData(arr + i, arr + j);
        }
    }

    swapData(arr + i + 1, arr + high);
    return i + 1;
}

void quickSort(Hewan* arr, int low, int high) {
    if (low < high) {
        int pi = partitionQS(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ================== BOYER MOORE ==================
int badChar[256];

void badCharHeuristic(string str, int size) {
    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < size; i++)
        badChar[(int)str[i]] = i;
}

void boyerMooreSearch(Hewan* arr) {
    string pattern;
    cout << "\nCari Nama (Boyer Moore): ";
    cin.ignore();
    getline(cin, pattern);

    for (int k = 0; k < jumlah; k++) {
        string text = (arr + k)->nama;

        int m = pattern.size();
        int n = text.size();

        badCharHeuristic(pattern, m);

        int s = 0;
        while (s <= (n - m)) {
            int j = m - 1;

            while (j >= 0 && pattern[j] == text[s + j])
                j--;

            if (j < 0) {
                cout << "Ditemukan: " << text << endl;

                if (k != 0) {
                    swapData(arr + k, arr);
                }
                return;
            } else {
                s += max(1, j - badChar[(int)text[s + j]]);
            }
        }
    }

    cout << "Tidak ditemukan\n";
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
        cout << "7. Sort ID (Quick)\n";
        cout << "8. Cari Nama (Boyer Moore)\n";
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
            case 7:
                quickSort(data, 0, jumlah - 1);
                cout << "Sorting ID selesai (Quick Sort)\n";
                break;
            case 8: boyerMooreSearch(data); break;
        }

    } while (pilih != 0);

    return 0;
}