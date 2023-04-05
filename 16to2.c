#include <stdio.h>
#include <stdlib.h>
#define END_COMMAND "q"

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

int main(int argc, char const *argv[])
{
    char str[16];
    long num;
    while (1)
    {
        scanf("%s", str);
        if (isEnd(str, END_COMMAND))
            break;
        num = strtol(str, NULL, 16);
        printf("%ld", num);
    }
}
