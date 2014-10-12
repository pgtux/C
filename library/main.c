#include <stdio.h>
#include "common.h"

int main(void) {
	printf("-- We are gonna check the call to shared object --\n");
	shared_function();
	addon();
	return 0;
}
