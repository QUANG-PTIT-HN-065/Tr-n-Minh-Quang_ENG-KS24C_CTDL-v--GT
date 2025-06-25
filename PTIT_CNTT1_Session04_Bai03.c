#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu phai lon hon 0.\n");
        return 1;
    }

    int arr[n];


    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < max) {
            max = arr[i];
            index = i;
        }
    }

    printf("Phan tu nho nhat dau tien trong mang la %d tai vi tri chi so %d.\n", max, index);

    return 0;
}
