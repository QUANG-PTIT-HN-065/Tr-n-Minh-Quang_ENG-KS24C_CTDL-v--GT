#include<stdio.h>


int n;
void swap(int *a, int *b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int end,int isNegative) {
    for (int i = 0; i < end; i++) {
        for (int j = 0; j < end - i - 1; j++) {
            if (isNegative) {
                if (arr[j] < arr[j + 1]) {
                   swap(&arr[j], &arr[j + 1]);
                }
            } else {
                if (arr[j] > arr[j + 1]) {
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
    int negative[n], positive[n];
    int countNegative = 0, countPositive = 0;
    int zeroIndex = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0) {
            negative[countNegative++] = arr[i];
        } else if (arr[i] > 0) {
            positive[countPositive++] = arr[i];
        }else
        {
            zeroIndex = i;
        }
    }
    bubbleSort(negative, countNegative, 1);
    bubbleSort(positive, countPositive, 0);
    printf("mang chua sap xep: \n");
    print(arr);
    printf("mang da sap xep: \n");
    printArray(negative, countNegative);
    if (zeroIndex != -1) {
        printf("0 ");
    }
    printArray(positive, countPositive);
}