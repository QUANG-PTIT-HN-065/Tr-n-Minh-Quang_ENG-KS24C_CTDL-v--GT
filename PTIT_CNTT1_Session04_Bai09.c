#include <stdio.h>

int xapXep(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = xapXep(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x){
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int main() {
    int n;
    printf("Nhap so luong phan tu cho mang: ");
    scanf("%d", &n);

    int arr[n]; 

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);
    int x;
    printf("nhap vao so can tim: ");
    scanf("%d", &x);
    int low = 0;
    int right = n - 1;
    int result = binarySearch(arr, low, right, x); 
    if (result != -1) {
        printf("co ton tai phan tu %d trong mang", x);
    } else {
        printf("khong tim thay phan tu %d trong mang\n", x);
    }
    return 0;
}
