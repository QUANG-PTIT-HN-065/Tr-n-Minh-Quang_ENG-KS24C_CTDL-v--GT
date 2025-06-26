#include <stdio.h>

int countPaths(int row, int col, int maxRow, int maxCol, int blockRow, int blockCol) {
    if (row >= maxRow || col >= maxCol || (row == blockRow && col == blockCol)) {
        return 1;
    }

    if (row == maxRow -1 || col == maxCol - 1 ) {
        return 0;
    }
    int downPaths = countPaths(row + 1, col, maxRow, maxCol, blockRow, blockCol);
    int rightPaths = countPaths(row, col + 1, maxRow, maxCol,blockRow, blockCol);

    return downPaths + rightPaths;
}

int main() {
    int rows, cols,blockRow,blockCol;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    printf("nhap vao hang bi chan: ");
    scanf("%d", &blockRow);
    printf("nhap vao cot bi chan: ");
    scanf("%d", &blockCol);
    if (rows <= 0 || cols <= 0) {
        printf("So hang hoac so cot khong hop le!\n");
        return 0;
    }

    int totalPaths = countPaths(0, 0, rows, cols, blockRow, blockCol);
    printf("Tong so duong di hop le: %d\n", totalPaths,blockRow,blockCol); 

    return 0;
}
