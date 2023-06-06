#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char* argv[]) {
    int opt;
    char* separator = "\t"; // 기본 구분자

    // 옵션 처리를 위한 루프
    while ((opt = getopt(argc, argv, "s:")) != -1) {
        switch (opt) {
        case 's':
            separator = optarg; // -s 옵션의 인자를 구분자로 설정
            break;
        case '?':
            fprintf(stderr, "잘못된 옵션입니다.\n");
            return 1;
        }
    }

    // 파일명 인자가 없는 경우
    if (optind >= argc) {
        fprintf(stderr, "사용법: %s [-s 구분자] 파일...\n", argv[0]);
        return 1;
    }

    // 파일 처리
    int lineNumber = 1;
    for (int i = optind; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다: %s\n", argv[i]);
            continue;
        }

        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%d%s%s", lineNumber, separator, line);
            lineNumber++;
        }

        fclose(file);
    }

    return 0;
}
