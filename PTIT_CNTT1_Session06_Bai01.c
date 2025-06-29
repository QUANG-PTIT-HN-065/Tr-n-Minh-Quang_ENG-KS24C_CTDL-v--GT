#include <stdio.h>
#include <string.h>

void toBinary(int n, char *s) {
    if (n == 0) {
        strcpy(s, "0");
        return;
    }

    char temp[100];
    int i = 0;

    while (n > 0) {
        temp[i++] = (n % 2) + '0'; 
        n = n / 2;
    }
    temp[i] = '\0';

    int len = strlen(temp);
    for (int j = 0; j < len; j++) {
        s[j] = temp[len - j - 1];
    }
    s[len] = '\0';
}

int main() {
    int n;
    char s[100];

    printf("Nhap so nguyen: ");
    scanf("%d", &n);

    toBinary(n, s);

    printf("Dang nhi phan: %s\n", s);

    return 0;
}
