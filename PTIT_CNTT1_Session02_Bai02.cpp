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
    
    int x; 
    int count = 0;
    cout << "Nhap x: ";
    cin >> x ;
    for (int i = 1; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    cout << "So lan xuat hien cua "<< x <<" trong mang la: " << count << endl;
    return 0;
}