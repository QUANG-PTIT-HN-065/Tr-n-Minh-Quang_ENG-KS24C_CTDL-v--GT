#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

int n;
bool scan = true;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[],int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n -1);
    print(arr);
    return 0;
}
