#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_LINES 10
#define DEFAULT_BYTES 0 
int opt;
int num_lines = DEFAULT_LINES;
int num_bytes = DEFAULT_BYTES;
int use_lines = 1;
int quiet_mode = 0;
int main(int argc, char* argv[]) {
	while ((opt = getopt(argc, argv, "n:c:q")) != -1) {
		switch (opt) {
		case 'n':
			num_lines = atoi(optarg);
			use_lines = 1;
			break;
		case 'c':
			num_bytes = atoi(optarg);
			use_lines = 0;
			break;
		case 'q':
			quiet_mode = 1;
			break;
		default:
			fprintf(stderr, "Usage: %s [-n num_lines] [-c num_bytes] [-q] [file]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	// 출력할 파일이 있을 시
	if (optind < argc) {
		for (int i = optind; i < argc; i++) {
			// argv[i]를 r모드로 열고 file에 저장
			FILE* file = fopen(argv[i], "r");
			if (file == NULL) {
				perror("fopen");
				continue;
			}
			// 출력할 파일이 1개가 아니고 -q 옵션이 아닐시
			// 파일명 출력
			if (!(argc - optind == 1) && !quiet_mode) printf("==> %s <==\n", argv[i]);
			// n option인지 아닌지
			if (use_lines) print_lines(file);
			else print_bytes(file);
			// 출력 파일 수가 1개이고 q option이 아닐 경우
			if ((i != argc - 1) && !quiet_mode) printf("\n");
			fclose(file);
		}
	}

	return 0;
}
// n option (지정된 라인 수만큼 읽기)
void print_lines(FILE* file){
	char buffer[BUFSIZ];
	int line_count = 0;

	while (fgets(buffer, sizeof(buffer), file) != NULL && line_count < num_lines) {
		printf("%s", buffer);
		line_count++;
	}
}
// c option (지정된 바이트 수만큼 읽기)
void print_bytes(FILE* file){
	char buffer[num_bytes + 1];
	fread(buffer, 1, num_bytes, file);
	buffer[num_bytes] = '\0';
	printf("%s", buffer);
}