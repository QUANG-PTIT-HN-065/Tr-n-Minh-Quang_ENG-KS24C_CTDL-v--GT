#include <stdio.h>
int countWays(int n) {
    if (n <= 1) return 1;
    return countWays(n - 1) + countWays(n - 2);
}
int main() {
    int n;
    printf("Nhap so buac thang: ");
    scanf("%d", &n);
    
    if (n < 0) {
        return 0;
    }
    
    int ways = countWays(n);
    printf("So cach di: %d\n", ways);
    
    return 0;
}