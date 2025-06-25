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
    int high = n - 1;
    int left = 0;
    int mid;
    while (left <= high) {
        mid = left + (high - left) / 2;
        if (arr[mid] == x) {
            printf("co ton tai phan tu %d trong mang\n", x);
            return 1;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("khong ton tai phan tu %d trong mang\n", x);
    return 0;
}
