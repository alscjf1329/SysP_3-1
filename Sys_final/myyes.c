#include <stdio.h>

int main(int argc, char *argv[]) {
    // 인자가 들어올 시
    if (argc > 1){
        while (1){
            for (int i=1; i<argc; i++){
                printf("%s ", argv[i]);
            }
            printf("\n");
        }
    }
    // 인자가 없을 시
    else {
        while (1) {
            printf("y\n");
        }
    }

    return 0;
}