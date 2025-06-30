#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

int n;
bool scan = true;

int partition(int arr[],int left,int right) {
    int pivot = arr[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

void QuiSort(int arr[],int left, int right) {
    if (left <= right) {
        int poivo = partition(arr, left, right);
        QuiSort(arr, left, poivo - 1);
        QuiSort(arr, poivo + 1, right);
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
    QuiSort(arr, 0, n -1);
    print(arr);
    return 0;
}
