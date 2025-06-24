#include <iostream>
using namespace std;

int main()
{
    int n;
    do {
        cout << "Nhap n (1 - 100): ";
        cin >> n;
    } while (n < 1 || n > 100);

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap arr[" << i << "]: ";
        cin >> arr[i];
    }

    int m;
    int X = 0;
    cout << "Cap phat bo nho lan mot: ";
    cin >> X;
    m = n + X;
    if (X <= 0) {
        cout << "Kich thuoc khong họp le" << endl;
        delete[] arr;
        return 1;
    }

    int* temp = new int[m];

    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    for (int i = n; i < m; i++) {
        cout << "Nhap arr[" << i << "]: ";
        cin >> temp[i];
    }

    delete[] arr;
    arr = temp;
    n = m;

    cout << "Mang sau khi cap phat bo nho lan 1: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Cap phat bo nho lan hai: ";
    cin >> X;
    m = n + X;
    if (X <= 0) {
        cout << "Kich thuoc moi khong hop le" << endl;
        delete[] arr;
        return 1;
    }

    temp = new int[m];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    for (int i = n; i < m; i++) {
        cout << "Nhap arr[" << i << "]: ";
        cin >> temp[i];
    }

    delete[] arr;
    arr = temp;
    n = m;

    cout << "Mang sau khi cap phat bo nho lan hai: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
