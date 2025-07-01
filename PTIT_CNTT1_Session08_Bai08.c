#include <stdio.h>

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
void linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("phan tu o vi tri: %d\n",i+1);
            return;
        }
    }
    printf("khong tim thay\n");
}
void binarySearch(int arr[], int n, int search) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == search) {
            printf("phan tu o vi tri: %d",mid + 1);
            return ;
        }
        if (arr[mid] < search) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("khong tim thay\n");
    return;
}
void prinfArray(int arr[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Nhap so phan tu cua mang (0 < n < 1000): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: ");
    prinfArray(arr,n);
    QuiSort(arr,0,n-1);
    printf("Mang sau khi sap xep: ");
    prinfArray(arr,n);
    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    printf("tim kiem tuyen tinh: ");
    linearSearch(arr,n,value);
    printf("tim kiem nhi phan: ");
    binarySearch(arr,n,value);
    return 0;
}