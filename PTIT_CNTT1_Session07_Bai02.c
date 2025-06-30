#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

int n;
bool scan = true;

void selectionSort(int arr[]) {
    for (int i = 0; i < n-1; i++)
    {
        int minInDex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minInDex])
            {
                minInDex = j;
            }   
        }
        int temp = arr[i];
        arr[i] = arr[minInDex];
        arr[minInDex] = temp;
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
    selectionSort(arr);
    print(arr);
    return 0;
}
