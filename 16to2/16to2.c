#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END_COMMAND "q"
#define RESULT_SIZE 65

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

void hexToBi(long hex, char* result)
{
    for(int i = 63; i >= 0; i--)
    {
        if(((hex >> i) & 1) == 1) result[63-i]='1';
        else result[63-i]='0';
    }
    result[64] = '\0';
}

int main(int argc, char const *argv[])
{
    char str[16];
    long num;
    char* result;
    printf("들어오는 16진수의 비트 수는 16\n");
    while (1)
    {
        result = (char*)malloc(RESULT_SIZE * sizeof(char));
        if (result == NULL)
        {
            printf("Memory allocation error\n");
            exit(1);
        }
        scanf("%s", str);
        if (isEnd(str, END_COMMAND))
            break;
        num = strtol(str, NULL, 16);
        hexToBi(num, result);
        printf("%s\n", result);
        free(result);
    }
    return 0;
}
