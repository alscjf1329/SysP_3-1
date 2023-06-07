#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int opt;
    int create_file = 1;
    int change_access_time = 0;
    int change_modification_time = 0;
    int preserve = 0;
    char *date = NULL;
    char *reference_file = NULL;

    while ((opt = getopt(argc, argv, "acmd:r:thp")) != -1) {
        switch (opt) {
            case 'a':
                change_access_time = 1;
                break;
            case 'c':
                create_file = 0;
                break;
            case 'm':
                change_modification_time = 1;
                break;
            case 'd':
                date = optarg;
                break;
            case 'r':
                reference_file = optarg;
                break;
            case 't':
                change_access_time = 1;
                change_modification_time = 1;
                date = optarg;
                break;
            case 'h':
                preserve = 1;
                break;
            case 'p':
                preserve = 1;
                break;
            default:
                fprintf(stderr, "Usage: %s [-a] [-c] [-m] [-d date] [-r reference_file] [-t date] [-h] [-p] file...\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (optind == argc) {
        fprintf(stderr, "No files specified.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = optind; i < argc; i++) {
        char *filename = argv[i];

        struct stat st;
        if (stat(filename, &st) == 0 && preserve) {
            if (reference_file != NULL) {
                struct stat ref_st;
                if (stat(reference_file, &ref_st) == 0) {
                    st.st_mode = ref_st.st_mode;
                    st.st_uid = ref_st.st_uid;
                    st.st_gid = ref_st.st_gid;
                }
            }

            if (change_access_time || change_modification_time) {
                struct utimbuf times;
                if (date != NULL) {
                    struct tm tm;
                    strptime(date, "%Y-%m-%d %H:%M:%S", &tm);
                    times.actime = times.modtime = mktime(&tm);
                } else {
                    times.actime = times.modtime = time(NULL);
                }
                utime(filename, &times);
            }

            if (chmod(filename, st.st_mode) != 0) {
                perror("chmod");
                exit(EXIT_FAILURE);
            }

            if (chown(filename, st.st_uid, st.st_gid) != 0) {
                perror("chown");
                exit(EXIT_FAILURE);
            }
        } else {
            if (create_file) {
                FILE *fp = fopen(filename, "w");
                if (fp == NULL) {
                    perror("fopen");
                    exit(EXIT_FAILURE);
                }
                fclose(fp);
            }

            if (change_access_time || change_modification_time) {
                struct utimbuf times;
                if (date != NULL) {
                    struct tm tm;
                    strptime(date, "%Y-%m-%d %H:%M:%S", &tm);
                    times.actime = times.modtime = mktime(&tm);
                } else {
                    times.actime = times.modtime = time(NULL);
                }
                utime(filename, &times);
            }
        }
    }

    return 0;
}
