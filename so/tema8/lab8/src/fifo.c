#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int ff;
	if ((ff = mknod("fifo2", S_IFIFO, 4)) < 0)
		printf("eroare");
	exit(0);
}
