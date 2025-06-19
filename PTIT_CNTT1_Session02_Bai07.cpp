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
            cout << "Nhap lai n, n phai lon hon 0 va nho hon 100: ";
        }
    } while (n < 1 || n > 100);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap arr[" << i << "]: ";
        cin >> arr[i];
    }

    bool found = false;
    int value;
    cout << "Nhap gia tri bat ky: ";
    cin >> value;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] + arr[j] == value)
            {
                cout << "Cac phan tu arr[" << i << "] = " << arr[i]
                     << " va arr[" << j << "] = " << arr[j]
                     << " co tong bang " << value << endl;
                found = true;
            }
        }
    }

    if (!found)
    {
        cout << "Khong co hai phan tu nao co tong bang " << value << endl;
    }

    return 0;
}
