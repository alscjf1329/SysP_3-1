#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_LINES 10
#define DEFAULT_BYTES 0 

int main(int argc, char* argv[]) {
    int opt;
    int num_lines = DEFAULT_LINES;
    int num_bytes = DEFAULT_BYTES;
    int use_lines = 1;
    int quiet_mode = 0;

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

    if (optind == argc) {
        // No file provided, read from standard input
        if (use_lines) {
            char buffer[BUFSIZ];
            int line_count = 0;

            while (fgets(buffer, sizeof(buffer), stdin) != NULL && line_count < num_lines) {
                printf("%s", buffer);
                line_count++;
            }
        }
        else {
            // Read specified number of bytes
            char buffer[num_bytes + 1];
            fread(buffer, 1, num_bytes, stdin);
            buffer[num_bytes] = '\0';
            printf("%s", buffer);
        }
    }
    else {
        // Read from file(s)
        for (int i = optind; i < argc; i++) {
            FILE* file = fopen(argv[i], "r");
            if (file == NULL) {
                perror("fopen");
                continue;
            }
            if (!(argc - optind==1) && !quiet_mode) {
                printf("==> %s <==\n", argv[i]);
            }

            if (use_lines) {
                char buffer[BUFSIZ];
                int line_count = 0;

                while (fgets(buffer, sizeof(buffer), file) != NULL && line_count < num_lines) {
                    printf("%s", buffer);
                    line_count++;
                }
            }
            else {
                // Read specified number of bytes
                char buffer[num_bytes + 1];
                fread(buffer, 1, num_bytes, file);
                buffer[num_bytes] = '\0';
                printf("%s", buffer);
            }
            if ((i != argc - 1) && !quiet_mode) printf("\n");
            fclose(file);
        }
    }

    return 0;
}