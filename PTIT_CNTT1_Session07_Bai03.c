#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

int n;
bool scan = true;

void insertionSort(int arr[]) {
    for (int i = 0; i < n-1; i++)
    {
        int key = arr[i + 1];
        int j = i;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}
void print(int arr[]) {
    for (int i = 0; i < n; i++) {
        if (scan) {
            scanf("%d", &arr[i]); 
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n"); 
    scan = false;
}

int main() {
    printf("Nhap so nguyen: ");
    scanf("%d", &n);
    if (n < 1 || n > 1000)
    {
        return 0;
    }
    
    int arr[n];

    print(arr); 
    printf("Mang da nhap: \n");
    print(arr); 
    printf("Mang da sap xep: \n");
    insertionSort(arr);
    print(arr);
    return 0;
}
