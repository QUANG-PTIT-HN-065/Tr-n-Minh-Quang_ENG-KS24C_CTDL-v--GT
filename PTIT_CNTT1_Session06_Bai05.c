#include<stdio.h>

void check(int n,int ar[],int *min,int *max){
    if (n < 0) {
        return ;
    }
    if (ar[n] < *min) {
        *min = ar[n];
    }
    if (ar[n] > *max) {
        *max = ar[n];
    }
    return check(n - 1, ar, min, max);
    
}
int main(){
    int n;
    scanf("%d", &n);
    if (n < 1 )
    {
        return 0;
    }
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    int min, max = ar[0];
    check(n - 1, ar, &min, &max);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    return 0;   
}