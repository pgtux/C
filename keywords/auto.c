/*
 * keywords/auto.c
 * Automatic variable and its scope exlained in this code
 * - Auto variables are created in stack after push and deleted after pop
 * - Exchamining the stack with 'gdb | valgrind' will help to understand the memory footprint
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
	int a=10;
	if(1) {
		int a;
		a=5;
		printf("Value of 'a' inside if block %d\n",a);
	}
	printf("Value of 'a' outside if block  %d\n",a);
	return 0;
}

/* 
Output:
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ gcc -Wall -Wextra -g3 -o ./bin/auto ./auto.c 
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ ./bin/auto 
Value of 'a' inside if block 5
Value of 'a' outside if block  10
*/
