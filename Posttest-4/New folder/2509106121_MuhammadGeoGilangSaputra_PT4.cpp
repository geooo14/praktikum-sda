#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// ================== STRUCT ==================
struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

// ================== GLOBAL ==================
int jumlah = 0;

// Queue
int front = -1, rear = -1;

// Stack
int top = -1;

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

// ================== QUEUE ==================
// ENQUEUE
void enqueue(Hewan* q, Hewan data) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow!\n";
        return;
    }

    if (front == -1) front = 0;

    rear++;
    *(q + rear) = data; // pointer
    cout << "Masuk antrian: " << data.nama << endl;
}

// DEQUEUE
Hewan dequeue(Hewan* q) {
    Hewan kosong;

    if (front == -1 || front > rear) {
        cout << "Queue Underflow!\n";
        return kosong;
    }

    Hewan ambil = *(q + front);

    // geser pakai pointer
    for (int i = front; i < rear; i++) {
        *(q + i) = *(q + i + 1);
    }

    rear--;

    if (rear < front) {
        front = rear = -1;
    }

    cout << "Dipanggil: " << ambil.nama << " (" << ambil.id << ")\n";
    return ambil;
}

// TAMPIL QUEUE
void tampilQueue(Hewan* q) {
    if (front == -1) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (int i = front; i <= rear; i++) {
        cout << (q + i)->nama << endl;
    }
}

// ================== STACK ==================
// PUSH
void push(Hewan* s, Hewan data) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!\n";
        return;
    }

    top++;
    *(s + top) = data;
    cout << "Masuk riwayat: " << data.nama << endl;
}

// POP
void pop(Hewan* s) {
    if (top == -1) {
        cout << "Stack Underflow!\n";
        return;
    }

    cout << "Hapus riwayat: " << (s + top)->nama << endl;
    top--;
}

// TAMPIL STACK
void tampilStack(Hewan* s) {
    if (top == -1) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (int i = top; i >= 0; i--) {
        cout << (s + i)->nama << endl;
    }
}

// ================== PEEK ==================
void peek(Hewan* q, Hewan* s) {
    if (front != -1)
        cout << "Antrian terdepan: " << (q + front)->nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top != -1)
        cout << "Riwayat terakhir: " << (s + top)->nama << endl;
    else
        cout << "Riwayat kosong\n";
}

// ================== MAIN ==================
int main() {
    Hewan data[MAX];
    Hewan queue[MAX];
    Hewan stack[MAX];

    int pilih;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Masuk Antrian\n";
        cout << "4. Panggil Pasien\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "7. Pop Riwayat\n";
        cout << "8. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tampil(data); break;
            case 2: tambah(data); break;

            case 3: {
                int idx;
                cout << "Index hewan: ";
                cin >> idx;
                enqueue(queue, *(data + idx));
                break;
            }

            case 4: {
                Hewan h = dequeue(queue);
                push(stack, h);
                break;
            }

            case 5: tampilQueue(queue); break;
            case 6: tampilStack(stack); break;
            case 7: pop(stack); break;
            case 8: peek(queue, stack); break;
        }

    } while (pilih != 0);

    return 0;
}