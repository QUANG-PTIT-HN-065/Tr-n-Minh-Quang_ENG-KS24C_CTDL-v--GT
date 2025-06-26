#include <stdio.h>

int fibonacci(int n){
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } 
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    if (fibonacci(n) == 0) {
        printf("Khong hop le.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    
}