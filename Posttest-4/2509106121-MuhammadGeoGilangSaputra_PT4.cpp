#include <iostream>
#include <string>
using namespace std;

// ================== STRUCT NODE ==================
struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
    Hewan* next; // pointer ke node berikutnya
};

// ================== QUEUE ==================
Hewan* front = NULL;
Hewan* rear = NULL;

// ================== STACK ==================
Hewan* top = NULL;

// ================== TAMBAH DATA (NODE BARU) ==================
Hewan* buatNode() {
    Hewan* baru = new Hewan;

    cout << "ID     : "; cin >> baru->id;
    cin.ignore();
    cout << "Nama   : "; getline(cin, baru->nama);
    cout << "Jenis  : "; getline(cin, baru->jenis);
    cout << "Harga  : "; cin >> baru->harga;

    baru->next = NULL;
    return baru;
}

// ================== ENQUEUE ==================
void enqueue(Hewan* baru) {
    if (baru == NULL) return;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Masuk antrian: " << baru->nama << endl;
}

// ================== DEQUEUE ==================
Hewan* dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow (Antrian kosong)\n";
        return NULL;
    }

    Hewan* hapus = front;
    front = front->next;

    if (front == NULL) rear = NULL;

    cout << "Dipanggil: " << hapus->nama << endl;
    hapus->next = NULL;
    return hapus;
}

// ================== TAMPIL QUEUE ==================
void tampilQueue() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    Hewan* temp = front;
    while (temp != NULL) {
        cout << temp->nama << endl;
        temp = temp->next;
    }
}

// ================== PUSH ==================
void push(Hewan* data) {
    if (data == NULL) return;

    data->next = top;
    top = data;

    cout << "Masuk riwayat: " << data->nama << endl;
}

// ================== POP ==================
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow (Riwayat kosong)\n";
        return;
    }

    Hewan* hapus = top;
    cout << "Hapus riwayat: " << hapus->nama << endl;

    top = top->next;
    delete hapus;
}

// ================== TAMPIL STACK ==================
void tampilStack() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    Hewan* temp = top;
    while (temp != NULL) {
        cout << temp->nama << endl;
        temp = temp->next;
    }
}

// ================== PEEK ==================
void peek() {
    if (front != NULL)
        cout << "Antrian terdepan: " << front->nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top != NULL)
        cout << "Riwayat terakhir: " << top->nama << endl;
    else
        cout << "Riwayat kosong\n";
}

// ================== MAIN ==================
int main() {
    int pilih;

    do {
        cout << "\n=== PAWCARE PETSHOP (LINKED LIST) ===\n";
        cout << "1. Tambah & Masuk Antrian\n";
        cout << "2. Panggil (Dequeue + Push)\n";
        cout << "3. Tampil Antrian\n";
        cout << "4. Tampil Riwayat\n";
        cout << "5. Pop Riwayat\n";
        cout << "6. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                Hewan* baru = buatNode();
                enqueue(baru);
                break;
            }

            case 2: {
                Hewan* h = dequeue();
                if (h != NULL) push(h);
                break;
            }

            case 3: tampilQueue(); break;
            case 4: tampilStack(); break;
            case 5: pop(); break;
            case 6: peek(); break;
        }

    } while (pilih != 0);

    return 0;
}