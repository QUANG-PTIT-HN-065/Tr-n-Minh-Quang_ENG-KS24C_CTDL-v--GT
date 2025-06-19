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
    bool check;
    for (int i = 0; i < n; i++)
    {
        check = true;
        for (int j = i; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << arr[i] << " ";
        }
        
    }
    return 0;
}