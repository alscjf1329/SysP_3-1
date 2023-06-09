#include <stdio.h>

int main(int argc, char *argv[]) {
    char *message = "y";
    
    if (argc > 1){;
        while (1){
            for (int i=1; i<argc; i++){
                printf("%s ", argv[i]);
            }
            printf("\n");
        }
    }
    else {
        while (1) {
        printf("%s\n", message);
        }
    }

    return 0;
}