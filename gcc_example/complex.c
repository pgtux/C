#include <stdio.h>
#include "common.h"

int main(void) {
	int a;
	a=other_file();
	printf("Combined object val:%d\n",a);

	return 0;
}
