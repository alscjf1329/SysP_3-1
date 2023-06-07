#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *name = argv[1];

    int idx = 0;

    if (name[strlen(name)-1]=='/'){
        name[strlen(name)-1] = '\0';
    }

    for (int i=0; i<strlen(name); i++){
        if (name[i]=='/'){
            idx = i;
        }
    }

    if (idx==0){
        for (int i=0; i<strlen(name); i++){
            printf("%c", name[i]);
        }
    }
    else {
        for (int i=idx+1; i<strlen(name); i++){
            printf("%c", name[i]);
        }
    }
    
    printf("\n");
    return 0;
}