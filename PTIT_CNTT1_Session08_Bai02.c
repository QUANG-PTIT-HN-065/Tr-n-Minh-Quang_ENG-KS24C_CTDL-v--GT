#include <stdio.h>
#include <stdbool.h>

int n;
bool scan = true;
bool checkSorted(int arr[]) {
    bool graduallyIncrease = true;
    bool graduallyDecreasing = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            graduallyIncrease = false;  
        }
        if (arr[i] < arr[i + 1]) {
            graduallyDecreasing = false; 
        }
    }
    if (!graduallyDecreasing && !graduallyIncrease)
    {
        return false;
    }else
    {
        return true;
    }
}
void binarySearch(int arr[], int value) {
    int left = 0,right = n -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
        {
           printf("vị tri thu: %d",mid+1);
           return;
        }else if (arr[mid] < value)
        {
            left = mid + 1;
        }else {
            right = mid -1;
        }
    }
    printf("khong tim thay");
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
    int value;
    printf("phan tu can tim: ");
    scanf("%d",&value);
    printf("Mang da nhap: \n");
    print(arr); 
    if (checkSorted(arr))
    {
        
        binarySearch(arr,value);
        return 0;
    }
    printf("mang chua dc xap sep:");
    return 0;
}
