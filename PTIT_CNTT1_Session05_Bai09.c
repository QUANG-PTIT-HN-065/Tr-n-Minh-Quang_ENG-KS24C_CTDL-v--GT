#include <stdio.h>

int countPaths(int row, int col, int maxRow, int maxCol) {
    if (row == maxRow - 1 && col == maxCol - 1) {
        return 1;
    }

    if (row >= maxRow || col >= maxCol) {
        return 0;
    }
    int downPaths = countPaths(row + 1, col, maxRow, maxCol);
    int rightPaths = countPaths(row, col + 1, maxRow, maxCol);

    return downPaths + rightPaths;
}

int main() {
    int rows, cols;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("So hang hoac so cot khong hop le!\n");
        return 0;
    }

    int totalPaths = countPaths(0, 0, rows, cols);
    printf("Tong so duong di hop le: %d\n", totalPaths);

    return 0;
}
