#include <stdio.h>

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
        fprintf(stderr, "Usage: ./head <filename> <num_lines>\n");
        return 1;
    }

    const char* filename = argv[1];
    int numLines = atoi(argv[2]);

    printHead(filename, numLines);

    return 0;
}
