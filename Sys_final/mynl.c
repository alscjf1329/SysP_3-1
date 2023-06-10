#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void addLineNumbers(FILE* file, int width, char* separator, int startNumber, int increment);
void printUsage(char* programName);
int isBlankLine(const char* line);

int main(int argc, char* argv[]) {
    FILE* file;
    int opt;
    int width = 6;
    char* separator = "\t";
    int startNumber = 1;
    int increment = 1;

    // options 처리
    while ((opt = getopt(argc, argv, "w:s:v:i:")) != -1) {
        switch (opt) {
        case 'w':
            width = atoi(optarg);
            break;
        case 's':
            separator = optarg;
            break;
        case 'v':
            startNumber = atoi(optarg);
            break;
        case 'i':
            increment = atoi(optarg);
            break;
        default:
            fprintf(stderr,"Usage: %s [-w width] [-s separator] [-v startNumber] [-i increment] [file]\n");
            exit(EXIT_FAILURE);
        }
    }
    // 파일명 인자가 하나도 없는 경우
    if (optind < argc) {
        // r모드로 argv[optind]를 열고 file에 저장
        file = fopen(argv[optind], "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }
    
    addLineNumbers(file, width, separator, startNumber, increment);
    printf("\n");
    fclose(file);
    return 0;
}

// 번호를 붙여서 출력
void addLineNumbers(FILE* file, int width, char* separator, int startNumber, int increment) {
    char line[BUFSIZ];
    int lineNumber = startNumber;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (!isBlankLine(line)) {
            printf("%*d%s%s", width, lineNumber, separator, line);
            lineNumber += increment;
        }
        else {
            printf("%s", line);
        }
    }
}

// 빈 줄인지 확인해주는 함수
int isBlankLine(const char* line) {
    int i = 0;
    // EOF확인
    while (line[i] != '\0') {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r') {
            return 0;
        }
        i++;
    }
    return 1;
}