/*
 * keywords/dowhile.c
 * do..while looping executes the loop atlest once
 * - Here the value of 'a' is init to '3' and the while conditional's at the same value
 * - Still the code executes atleast once as it is do..while
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
	int a=3;
	do {
		printf("Value of a: %d\n",a);
	} while (a != 3); /* Don't forget the semicolon here */

	return 0;
}


/*
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ gcc -Wall -Wextra -g3 -o ./bin/dowhile ./dowhile.c 
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ ./bin/dowhile 
Value of a: 3
 */
