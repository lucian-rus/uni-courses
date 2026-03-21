#include "ourhdr.h"

#define	BUFFSIZE 8192

int main(void)
{
	int n;
	char buf[BUFFSIZE];

	char prev;
	while ( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
		int alt = 0;
		for(int i = 0; i < n; i++) {
			if(buf[i] != 0) {
				buf[alt++] = buf[i];
			}
		}
		n = alt;

		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
	}

	if (n < 0)
		err_sys("read error");

	exit(0);
}
