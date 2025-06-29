#include <stdio.h>

int fibonacci(int i) {
    if (i <= 1) {
        return i;
    }
    return fibonacci(i - 1) + fibonacci(i - 2);
}
void fillFibonacci(int arr[], int n, int index) {
    if (index >= n) {
        return;
    }
    arr[index] = fibonacci(index + 1);
    fillFibonacci(arr, n, index + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le");
        return 0;
    }
    int arr[1000];
    fillFibonacci(arr, n, 0);
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
        if (i  > 0) {
            printf(", ");
        }
    }
    printf("\n");
    return 0;
}