#include<stdio.h>
int total(int n,int m) {
    if (n < 1) {
        return 0;
    }    
    printf("%d ", m);
    return total(n - 1,m+1);
}
int main() {
    int n;
    int m = 1;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Nhap so khong hop le!\n");
        return 1;
    }
    total(n,m);
    
    return 0;
}