#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap n: ";
    do
    {
        cin >> n;
        if (n < 1 || n > 100)
        {
            cout << "Nhap lai n , n phải lớn 0 và nhỏ hơn 100: ";
        }

    } while (n < 1 || n > 100);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap arr[" << i << "]: ";
        cin >> arr[i];
    }

    bool counted[n] = {false};

    for (int i = 0; i < n; i++) {
        if (!counted[i]) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] == arr[i]) {
                    count++;
                    counted[j] = true;
                }
            }
            cout << "Phan tu " << arr[i] << " xuat hien " << count << " lan" << endl;
        }
    }

    return 0;
}