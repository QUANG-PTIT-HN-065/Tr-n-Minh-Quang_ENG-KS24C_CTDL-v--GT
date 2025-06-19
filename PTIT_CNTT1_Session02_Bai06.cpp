#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    do
    {
        cin >> n;
        if (n < 1 || n > 100) {
            cout << "Nhap lai n , n phải lớn 0 và nhỏ hơn 100: ";
        }
        
    } while (n < 1 || n > 100 );
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap arr[" << i << "]: ";
        cin >> arr[i];
    }
    
    int pos;
    cout << "Nhap vi tri can them: ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Vi tri khong hop le!" << endl;
        return 0;
    }
    int value;
    cout << "Nhap gia tri can them: ";
    cin >> value;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    n++;
    arr[pos] = value;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    return 0;
}