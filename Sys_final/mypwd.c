#include <stdio.h>
#include <unistd.h> // for getcwd

int main(int argc, char* argv[]) {
	char buff[1024];
	getcwd(buff, 1024);
	printf("%s\n", buff);
	return 0;
}
