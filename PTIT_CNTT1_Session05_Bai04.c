#include <stdio.h>
#include <string.h>

int isValid = 0;

void checkPalindrome(char str[], int start, int end) {
    if (start >= end) {
        isValid = 1;
        return;
    }
    if (str[start] != str[end]) {
        isValid = 0;
        return;
    }
    checkPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[1000];
    printf("Nhap chuoi: ");
    fgets(str, 1000, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    checkPalindrome(str, 0, len - 1);
    if (isValid) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }
    return 0;
}