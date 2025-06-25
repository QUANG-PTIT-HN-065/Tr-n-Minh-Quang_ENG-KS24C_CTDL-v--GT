#include<stdio.h>

int main() {
    printf("Nhap so luong phan tu cho mang:\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i );
        scanf("%d", &arr[i]);
    }
    int m = -1;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == arr[n -i -1])
        {
            m ++;
            printf("cap doi doi xung la: %d %d\n", arr[i], arr[n - i - 1]);
        }
    }
    if (m == -1) {
        printf("Khong tim thay cap doi doi xung trong mang.\n");
    } else
    
    return 0;
}