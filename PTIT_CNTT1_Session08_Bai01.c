#include <stdio.h>
#include <stdbool.h>

int n;
bool scan = true;

void linearSearch (int arr[],int value){    // Dộ phức tạp Thời gian tốt nhất O(1) , xấu nhất O(n)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("vi tri thu: %d",i+1);
            return ;
        }
    }
    printf("khong tim thay: ");
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
    linearSearch(arr,value);
    return 0;
}
