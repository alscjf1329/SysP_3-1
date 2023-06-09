#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printReverse(FILE* file) {
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(size + 1);
    if (buffer == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return;
    }

    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    for (long i = size - 1; i >= 0; i--) {
        putchar(buffer[i]);
    }

    free(buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("파일 이름을 제공해야 합니다.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        printReverse(file);
        fclose(file);
    }

    return 0;
}
