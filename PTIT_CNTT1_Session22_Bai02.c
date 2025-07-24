#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int matrix[MAX][MAX];
    int edgeCount = 0;

    do {
        printf("Nhqp so đinh (0 < n < 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);
    printf("Nhap ma tran ke (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                printf("matrix[%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
            } while (matrix[i][j] != 0 && matrix[i][j] != 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }

    printf("\nSo canh: %d\n", edgeCount);

    return 0;
}
