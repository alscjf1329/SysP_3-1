#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // isdigit
#include <unistd.h> // getopt

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

int isDigitStr(const char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (!isdigit(str[i])) return 0;
	}
	return 1;
}

int main(int argc, char** argv) {
	int numLines = 10; // 기본적으로 10줄을 출력
	const char* filename = NULL;
	int cnt = argc;
	if (isDigitStr(argv[argc - 1])) --cnt;
	int opt = 0;
	while ((opt = getopt(argc, argv, "n:")) != -1) {
		switch (opt) {
		case 'n':
			numLines = atoi(optarg);
			break;
		default:
			fprintf(stderr, "Usage: ./head [-n <num_lines>] <filename>\n");
			return 1;
		}
	}
	if (optind >= argc) {
		fprintf(stderr, "Usage: ./head [-n <num_lines>] <filename>\n");
		return 1;
	}
	if (argc >= 3 && strcmp(argv[1], "-n") == 0) {
		cnt -= 3;
	}
	else if (argc >= 2) {
		cnt -= 1;
	}
	else {
		fprintf(stderr, "Usage: ./head <filename> <num_lines>\n");
		fprintf(stderr, "Usage: ./head [-n <num_lines>] <filename>\n");
		return 1;
	}
	for (int i = 0; i < cnt; i++) {
		if (argc >= 3 && strcmp(argv[1], "-n") == 0) filename = argv[3 + i];
		else if (argc >= 2) filename = argv[1 + i];
		if (isDigitStr(filename)) break;
		if (cnt != 1) fprintf(stderr, "=====> %s <=====\n", filename);
		printHead(filename, numLines);
	}
	return 0;
}