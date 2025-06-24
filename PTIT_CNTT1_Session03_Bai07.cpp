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
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < color; j++)
        {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < color; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Enter the row you want to sum";
    cin >> k;
    if (k < 1 || k > row) {
        cout << "Invalid row number." << endl;
    } else {
        int sum = 0;
        for (int j = 0; j < color; j++) {
            sum += arr[k - 1][j];
        }
        cout << "Sum of elements in row " << k << ": " << sum << endl;
    }
    return 0;
}