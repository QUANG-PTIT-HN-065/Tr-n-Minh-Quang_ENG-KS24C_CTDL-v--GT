#include<stdio.h>
#include <stdlib.h>

int n,x;
void swap(int *a, int *b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[]){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int x_i = abs(arr[i] - x);
            int x_j = abs(arr[j] - x);
            if (x_i > x_j || (x_i == x_j && arr[i] > arr[j])) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void print(int arr[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);
    if (n < 1 || n > 1000) {
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap x: ");
    scanf("%d", &x);
    sort(arr);
    printf("Mang da sap xep: \n");
    print(arr);
}