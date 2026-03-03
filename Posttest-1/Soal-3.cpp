#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;

    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int arr[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik:" << endl;
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Alamat memori setiap elemen:" << endl;
    int* ptr = arr;
    for(int i = 0; i < 7; i++) {
        cout << "Elemen " << i << " = " << *(ptr + i)
             << " | Alamat = " << (ptr + i) << endl;
    }

    reverseArray(arr, 7);

    cout << endl << "Array setelah dibalik:" << endl;
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}