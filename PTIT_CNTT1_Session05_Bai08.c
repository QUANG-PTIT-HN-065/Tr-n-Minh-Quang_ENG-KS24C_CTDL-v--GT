#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int StrToInt(char str[], int len)
{
    if (len == 0)
    {
        return 0;
    }
    int num = str[len - 1] - '0';
    return StrToInt(str, len - 1) * 10 + num;
}

bool isNumber(char str[], int len)
{
    int start = 0;
    if (str[0] == '-')
    {
        start = 1;
    }
    for (int i = start; i < len; i++)

    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[100];
    printf("Nhap chuoi so: ");
    scanf("%s", &str);
    int len = strlen(str);
    if (isNumber(str, len - 1))
    {
       if (str[0] == '-')
       {
           printf("So nguyen: %d\n", -StrToInt(str + 1, len - 1));
       }
       else
       {
           printf("So nguyen: %d\n", StrToInt(str, len));
       }
    }
    else
    {
        printf("input khong hop le!");
    }
}