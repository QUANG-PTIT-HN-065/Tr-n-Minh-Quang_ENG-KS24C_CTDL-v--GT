#include <stdio.h>

#define MAX 100

int main() {
    int n, v;
    int matrix[MAX][MAX] = {0};

    do {
        printf("Nhap so dinh (0 < n < 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);

    do {
        printf("Nhap so canh (0 < v < 100): ");
        scanf("%d", &v);
    } while (v <= 0 || v >= 100);

    printf("Nhap cac canh (u v):\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        do {
            printf("Canh %d: ", i + 1);
            scanf("%d %d", &u, &w);
        } while (u < 0 || u >= n || w < 0 || w >= n);

        matrix[u][w] = 1;
        matrix[w][u] = 1;
    }

    int k;
    do {
        printf("Nhap dinh k (0 <= k < %d): ", n);
        scanf("%d", &k);
    } while (k < 0 || k >= n);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[k][i] == 1) {
            count++;
        }
    }

    printf("So dinh lien ke voi dinh %d la: %d\n", k, count);

    return 0;
}
