/*
 * keywords/continue.c
 * Continue instrution used to execute the loop on special case
 * - break and continue are used together in most special cases
 * 
 * Author: Parthiban Nallathambi <parthiban@penguintux.co.in>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <stdio.h>

int main(void) {
	int i=0;
	for(i=0; i < 5; i++) {
		if(i==2) {
			printf("Executing the continue instructions for i = %d\n",i);
			continue;
		}
		else if(i==3) {
			printf("Breaking the loop for i = %d\n",i);
			break;
		}
	}
	return 0;
}

/* 
Output:
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ gcc -Wall -Wextra -g3 -o ./bin/continue ./continue.c 
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ ./bin/continue 
Executing the continue instructions for i = 2
Breaking the loop for i = 3
 */
