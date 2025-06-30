#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

void sortString(char str[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            char temp = str[i];
            str[i] = str[minIndex];
            str[minIndex] = temp;
        }
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    int size = strlen(str); 

    if (size <= 0) {
        return 0;
    }

    printf("before = %s\n", str);
    sortString(str, size);
    printf("after = %s\n", str);

    return 0;
}
