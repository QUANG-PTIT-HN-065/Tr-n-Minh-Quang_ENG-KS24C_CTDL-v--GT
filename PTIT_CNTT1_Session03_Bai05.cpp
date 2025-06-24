#include <iostream>
using namespace std;

int main()
{
    int color = 0;
    int row = 0;
    int k;
    do
    {
        cout << "Enter color (> 0 <= 100): ";
        cin >> color;
        cout << "Enter row  (> 0 <= 100): ";
        cin >> row;
    } while (row < 1 || row > 100 || color < 1 || color > 100); 
    int arr[row][color];
    cout << "Enter the elements of the array:\n";
    if (row < color || row > color)
    {
        cout << "khong ton tai duong cheo chinh va duong cheo phu" << endl;
        return 1;
    }
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < color; j++)
        {
            if (i == j)
            {
                sum1 += arr[i][j];
            }
            if (i + j == row - 1)
            {
                sum2 += arr[i][j];
            }
        }
    }
    cout << "Sum of main diagonal: " << sum1 << endl;
    cout << "Sum of secondary diagonal: " << sum2 << endl;
    return 0;
}