#include<stdio.h>
int total(int n) {
    if (n < 1) {
        return 1;
    }    
    return n * total(n - 1);
}
int main() {
    int n,sum = 1;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Nhap so khong hop le!\n");
        return 1;
    }
    total(n);
    sum = total(n);
    printf("Tong tu 1 den %d la: %d\n", n, sum);
    return 0;
}