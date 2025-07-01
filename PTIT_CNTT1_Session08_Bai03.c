#include <stdio.h>
#include <stdbool.h>

int n;
bool scan = true;
void bubbleSort(int arr[]) {                        // Độ phức tạp về thời gian tốt thất O(n) , tệ nhất O(n^2)
    for (int i = 0; i < n - 1; i++) {
        bool check = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                check = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (check)
        {
            return ;
        }
        
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
        printf("so phan tu ko hop le: ");
        return 0;
    }
    
    int arr[n];

    print(arr); 
    printf("Mang da nhap: \n");
    print(arr); 
    printf("Mang da sap xep: \n");
    bubbleSort(arr);
    print(arr);
    return 0;
}
