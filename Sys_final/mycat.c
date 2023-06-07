#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 4096

void display_file(const char* filename, int number_lines, int show_ends, int show_tabs, int show_nonprint, int squeeze_blank) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    char buffer[BUFFER_SIZE];
    int lineNums = 1;

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (squeeze_blank && buffer[0] == '\n') {
            continue;
        }

        if (number_lines) {
            printf("%6d  ", lineNums++);  // 라인 번호 출력
        }

        for (int i = 0; buffer[i] != '\0'; i++) {
            if (show_ends && buffer[i] == '\n') {
                printf("$\n");
            }
            else if (show_tabs && buffer[i] == '\t') {
                printf("^I");
            } else if (show_nonprint && (buffer[i] < 32 || buffer[i] > 126)) {
                printf("^%c", buffer[i] + 64);
            } else {
                putchar(buffer[i]);
            }
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    int number_lines = 0;
    int show_ends = 0;
    int show_tabs = 0;
    int show_nonprint = 0;
    int squeeze_blank = 0;

    int opt;
    while ((opt = getopt(argc, argv, "nbsETv")) != -1) {
        switch (opt) {
            case 'n':
                number_lines = 1;
                break;
            case 'b':
                number_lines = 1;
                squeeze_blank = 1;
                break;
            case 'E':
                show_ends = 1;
                break;
            case 'T':
                show_tabs = 1;
                break;
            case 'v':
                show_nonprint = 1;
                break;
            case 's':
                squeeze_blank = 1;
                break;
            default:
                fprintf(stderr, "Invalid option: -%c\n", optopt);
                return 1;
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "Usage: %s [options] <file>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[optind];
    display_file(filename, number_lines, show_ends, show_tabs, show_nonprint, squeeze_blank);

    return 0;
}
