/*
 * gcc_example/hello.c
 * Sample code to compile with GCC at various stages for better understanding
 * - This code doesn't include anything other then main() function
 * - Find the complete details on compilation in 'README'
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

/*
 * /usr/include/stdio.h : is included for using 'printf' defined in glibc
 */

#include <stdio.h>

int main(void) {
	printf("Hello world\n");
	return 0;
}
