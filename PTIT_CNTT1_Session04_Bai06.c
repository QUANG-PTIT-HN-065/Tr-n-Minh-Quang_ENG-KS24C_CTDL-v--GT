#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

typedef struct {
    int id;
    char ten[100];
    int tuoi;
} sinhVien;
void search(sinhVien *arr, int n) {
    int id;
    printf("Nhap id sinh vien can tim: ");
    scanf("%s", id);
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) {
            printf("Sinh vien tim thay: ID: %d, Ten: %s, Tuoi: %d\n", arr[i].id, arr[i].ten, arr[i].tuoi);
            return; 
        }
        
    }
    printf("Khong tim thay sinh vien voi ID: %d\n", id);
}
int main() {
    int n = 5;
    sinhVien *arr = (sinhVien *)malloc(n * sizeof(sinhVien));
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        arr[i].id = i +1; 
        printf("Ten: ");
        scanf("%s", arr[i].ten); 
        printf("Tuoi: ");
        scanf("%d", &arr[i].tuoi);
    }
    
    search(arr, n);
    free(arr);
    return 0;
}