#include<stdio.h>


int n;
void swap(int *a, int *b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int end,int isEven) {
    for (int i = 0; i < end; i++) {
        for (int j = 0; j < end - i - 1; j++) {
            if (isEven) {
                if (arr[j] > arr[j + 1]) {
                   swap(&arr[j], &arr[j + 1]);
                }
            } else {
                if (arr[j] < arr[j + 1]) {
                    swap(&arr[j],&arr[j + 1]);
                }
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
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    scanf("%d", &n);
    if (n < 1 || n > 1000) {
        return 0;
    }
    int arr[n];
    int even[n], odd[n];
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0) 
        {
            even[evenCount++] = arr[i];
        } else 
        {
            odd[oddCount++] = arr[i];
        }
    }
    bubbleSort(even, evenCount, 1);
    bubbleSort(odd, oddCount, 0);
    printf("mang chua sap xep: \n");
    print(arr);
    printf("mang da sap xep: \n");
    printArray(even, evenCount);
    printArray(odd, oddCount);
}