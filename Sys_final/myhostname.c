#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for gethostname

int main(int argc, char* argv[])
{
	char host_name[80];

	if (gethostname(host_name, sizeof(host_name)) != 0) {
		printf("gethostname() 실행 실패\n");
		exit(1);
	}
	printf("%s\n", host_name);
	return 0;
}
