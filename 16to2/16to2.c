#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END_COMMAND "q"
#define RESULT_SIZE 17

int isEnd(char str[], char endCommand[])
{
    int i = 0;
    while (str[i] != '\0' && endCommand[i] != '\0')
    {
        if (str[i] != endCommand[i])
            return 0;
        i++;
    }

    return (str[i] == '\0' && endCommand[i] == '\0') ? 1 : 0;
}

void hexToBi(long hex, int hexLen, char *result)
{
    int biLen = hexLen * 4;
    for (int i = biLen - 1; i >= 0; i--)
    {
        if (((hex >> i) & 1) == 1)
            result[biLen - 1 - i] = '1';
        else
            result[biLen - 1 - i] = '0';
    }
    result[biLen] = '\0';
}

int main(int argc, char const *argv[])
{
    char str[16];
    long num;
    char *result;
    printf("\"q\"누를 시 quit\n");
    printf("모든 비트에 수를 채워야 원하는 답이 나옵니다.\n");
    printf("ex) 4비트의 16진수인 1 -> 0001로 표현하기\n");
    while (1)
    {
        printf("16진수 : ");
        result = (char *)malloc(RESULT_SIZE * sizeof(char));
        if (result == NULL)
        {
            printf("Memory allocation error\n");
            exit(1);
        }
        scanf("%s", str);
        if (isEnd(str, END_COMMAND))
            break;
        num = strtol(str, NULL, 16);
        hexToBi(num, strlen(str), result);
        printf("%lu비트의 2진수 : %s\n", strlen(str) * 4, result);
        free(result);
    }
    return 0;
}
