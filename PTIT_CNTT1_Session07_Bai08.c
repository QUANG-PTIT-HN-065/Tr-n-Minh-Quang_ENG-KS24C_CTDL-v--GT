#include <stdio.h>
void swap(int *a, int *b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int col , row,k;
    scanf("%d %d", &col, &row);
    if (col < 1 || col > 1000 || row < 1 || row > 1000) {
        return 0;
    }
    int arr[col][row];
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Nhap cot can sap xep: ");
    scanf("%d", &k);
    if (k < 1 || k > col) {
        return 0;
    }

    printf("Mang da nhap: \n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < col-1; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            if (arr[i][k-1] > arr[j][k-1]) {
                swap(&arr[i][k-1],&arr[j][k-1]);
            }
        }
    }
    
    printf("Mang da sap xep: \n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}