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
    bool found = false;
    int value;
    cout << "Nhap gia tri bất kỳ: ";
    cin >> value;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            if (i + j == value)
            {
                cout << "Cac phan tu co chi so " << i << " va " << j << " co tong bang " << value << endl;
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