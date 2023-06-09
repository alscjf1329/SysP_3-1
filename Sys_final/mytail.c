#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// 함수 선언
void print_last_n_lines(FILE* file, int n);
void print_last_n_chars(FILE* file, int n);
void print_quiet(FILE* file);

int main(int argc, char* argv[]) {
    // 옵션 초기화
    int n = 10; // 기본적으로 10줄 출력
    int c = 0;  // 문자 수 옵션 초기화
    int q = 0;  // 조용한 모드 옵션 초기화

    // 명령행 인수 처리
    int opt;
    while ((opt = getopt(argc, argv, "n:c:q")) != -1) {
        switch (opt) {
        case 'n':
            n = atoi(optarg);
            break;
        case 'c':
            c = atoi(optarg);
            break;
        case 'q':
            q = 1;
            break;
        default:
            fprintf(stderr, "사용법: %s [-n 숫자] [-c 숫자] [-q] 파일...\n", argv[0]);
            return 1;
        }
    }

    // 파일 처리
    for (int i = optind; i < argc; i++) {
        char* filename = argv[i];

        // 파일 열기
        FILE* file = fopen(filename, "r");
        if (file == NULL) {
            perror("파일 열기 실패");
            continue;
        }

        // 파일명 출력
        if (!(argc - optind == 1) && !q) {
            printf("==> %s <==\n", filename);
        }

        // -c 옵션인 경우
        if (c > 0) print_last_n_chars(file, c);
        // -n 옵션인 경우
        else print_last_n_lines(file, n);

        // 파일 닫기
        fclose(file);

        // 받는 인자(파일명)가 2개이상일 시) 파일 간 구분을 위한 개행 출력
        if (!(argc - i == 1) && !q) printf("\n");
    }

    return 0;
}

// 지정된 파일에서 마지막 n줄을 출력하는 함수
void print_last_n_lines(FILE* file, int n) {
    char buffer[BUFFER_SIZE][BUFFER_SIZE];
    // 버퍼에 저장된 줄 수
    int count = 0;

    // 파일을 끝까지 읽으면서 버퍼를 순환시키면서 최근 n줄 유지
    while (fgets(buffer[count % n], BUFFER_SIZE, file) != NULL) {
        count++;
    }
    // 시작 줄 설정
    int start = (count > n) ? (count % n) : 0;
    // 출력할 줄 수
    int lines_to_print = (count > n) ? n : count;
    
    for (int i = 0; i < lines_to_print; i++) printf("%s", buffer[(start + i) % n]);
}

// 지정된 파일에서 마지막 n개의 문자를 출력하는 함수
// FILE* file은 출력할 파일을 가리키는 파일 포인터입니다.
void print_last_n_chars(FILE* file, int n) {
    // fseek 함수를 사용하여 파일의 끝으로 이동
    fseek(file, 0, SEEK_END);
    // 파일 포인터의 현재 위치를 알아냄 (file 크기를 구함)
    long file_size = ftell(file);
    // 읽을 char 개수
    int chars_to_read = (n < file_size) ? n : file_size;
    char buffer[BUFFER_SIZE];
    // fseek 함수를 사용하여 파일의 끝에서 (-chars_to_read)만큼 이동
    fseek(file, -chars_to_read, SEEK_END);
    
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
}

