#include <stdio.h>
#include <string.h>

int totalArr(int arr[],int n) {
    if (n == 0) 
    {
        return 0;
    }
    return arr[n - 1] + totalArr(arr,n-1);
}

int main() {
    int n,total=0;
    printf("nhap n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Tong cac phan tu trong mang la: %d\n", totalArr(arr, n));
    return 0;
}
