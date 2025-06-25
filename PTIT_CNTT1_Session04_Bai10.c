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
    char searchName[100];
    char searchName1[100];
    printf("Nhap ten sinh vien can tim: ");
    scanf("%s", searchName1);
    for (int i = 0; i < n; i++) {
        strcpy(searchName, arr[i].ten);
        for (int j = 0; searchName[j] != '\0'; j++) {
            searchName[j] = tolower(searchName[j]);
        }
        if (strstr(searchName, searchName1) != NULL) {
            printf("Sinh vien tim thay: ID: %d, Ten: %s, Tuoi: %d\n", arr[i].id, arr[i].ten, arr[i].tuoi);
        }
    }
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