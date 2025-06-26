#include <stdio.h>
#include <string.h>

int ChuoiDoiXung(char str[], int left, int right) {
    if (left >= right) {
        return 1;
    }
    if (str[left] != str[right]) { 
        return 0;
    }
    return ChuoiDoiXung(str, left + 1, right - 1);
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    if (ChuoiDoiXung(str, 0, len - 1)) {
        printf("Chuoi doi xung.\n");
    } else {
        printf("Chuoi khong doi xung.\n");
    }

    return 0;
}
