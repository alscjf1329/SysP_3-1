#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHead(const char* filename, int numLines) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char line[256];
        int count = 0;
        while (fgets(line, sizeof(line), file) != NULL && count < numLines) {
            printf("%s", line);
            count++;
        }
        fclose(file);
    }
    else {
        fprintf(stderr, "Failed to open file: %s\n", filename);
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: ./head [-n <num_lines>] <filename>\n");
        return 1;
    }

    int numLines = 10;  // 기본적으로 10줄을 출력
    const char* filename = NULL;

    if (strcmp(argv[1], "-n") == 0) {
        numLines = atoi(argv[2]);
        filename = argv[3];
    }
    else {
        filename = argv[1];
    }

    printHead(filename, numLines);

    return 0;
}
