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
    printf("phan tu cam tim trong mang la: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m)
        {
            printf("%d ", i);
        }
    }
    if (m == -1) {
        printf("Khong tim thay phan tu trong mang.\n");
    } 

    return 0;
}