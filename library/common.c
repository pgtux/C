#include <stdio.h>
#include "common.h"

void shared_function(void) {
	printf("-- Called shared object --\n");
	return;
}
