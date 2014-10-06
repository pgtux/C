#include <unistd.h>

#define BUFFSIZE 4096

int main(void) {
	int    n;
	char   buf[BUFFSIZE]={'\0'};

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			write(STDOUT_FILENO,"write error\n",13);

	if (n < 0)
		write(STDOUT_FILENO,"read error\n",12);

	return 0;
}
