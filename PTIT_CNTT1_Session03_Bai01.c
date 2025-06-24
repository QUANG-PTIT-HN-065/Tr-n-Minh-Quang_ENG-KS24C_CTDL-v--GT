#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    do {
        printf("Nhap so luong phan tu cua mang (0 < n < 1000): ");
        scanf("%d", &n);
        if (n < 0) {
            printf("So luong phan tu khong duoc am. Vui long nhap lai.\n");
        }else if (n == 0) {
            printf("So luong phan tu phai lon hon 0. Vui long nhap lai.\n");
        } 
        
    } while (n <= 0 || n >= 1000);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Cac phan tu trong mang la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}
