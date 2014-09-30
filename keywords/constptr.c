/*
 * keywords/constptr.c
 * 
 * Constant pointer: 
 * - ptr is pointing to the address of 'a' (which is of type int) and this is declared as 'const'
 * - All the constant variables (both pointer variable and normal variables will reside at .rodata (i.e. read-only data section)
 * - An attempt to change the pointer value i.e change the pointer address from 'a' to 'NULL' [(void*)0x0] is not possible
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
	int a=1;
	int * const ptr=&a;
	ptr=NULL;
	return 0;
}

/*

Error:
------
=> gcc -Wall -Wextra -g3 -o ./bin/constptr ./constptr.c 
./constptr.c: In function ‘main’:
./constptr.c:32:2: error: assignment of read-only variable ‘ptr’
./constptr.c:31:14: warning: variable ‘ptr’ set but not used [-Wunused-but-set-variable]

*/
