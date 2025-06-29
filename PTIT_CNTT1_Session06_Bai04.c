#include <stdio.h>

void ABC(int num, char x, char y, char z);

int main()
{
    int num;
    printf("\nNhap so dia:");
    scanf("%d", &num);

    TOH(num, 'A', 'C', 'B');
    return (0);
}

void ABC(int num, char x, char y, char z)
{
    if (num == 1)
    {
        printf("\n dia %d -> %c", num, y);
        return;
    }
    ABC(num - 1, x, z, y);
    printf("\n dia %d -> %c", num, y);
    ABC(num - 1, z, y, x);
}
