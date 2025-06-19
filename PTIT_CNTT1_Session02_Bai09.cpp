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
    
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = arr[i];
        }
    }
    if (maxCount == 0)
    {
        cout << "Khong co phan tu nao lap lai." << endl;
    }
    else
    {
        cout << maxCount << endl;
    }
    return 0;
}