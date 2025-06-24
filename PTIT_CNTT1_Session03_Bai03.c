#include <stdio.h>
#include <stdlib.h>


float tinhTrungBinhChan(int *arr, int n) {
    int tong = 0, dem = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) { 
            tong += arr[i];
            dem++;
        }
    }
    if (dem == 0) {
        return 0; 
    }
    return (float)tong / dem;
}
int main() {
    int n;

    do {
        printf("Nhap so luong phan tu cua mang (0 < n < 1000): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000) {
            printf("So luong phan tu khong hop le. Vui long nhap lai.\n");
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
    float trungBinh = tinhTrungBinhChan(arr, n);

    if (trungBinh == 0) {
        printf("Khong co so chan trong mang.\n");
    } else {
        printf("Trung binh cong cac so chan trong mang la: %.2f\n", trungBinh);
    }
    free(arr);
    return 0;
}
