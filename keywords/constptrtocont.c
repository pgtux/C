/*
 * keywords/ptrtoconstant.c
 * 
 * Constant pointer to a Constat
 * - Here both the 'ptr' and the value pointed are declared are constant
 * - Attempt to change the pointer value or Value pointed results in compilation error
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

int main(void) {
	int a=1;
	const int* const ptr = &a;
	ptr=NULL;
	*ptr=2;
	return 0;
}

/* 
ERROR:
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ gcc -Wall -Wextra -g3 -o ./bin/constptrtocont ./constptrtocont.c 
./constptrtocont.c: In function ‘main’:
./constptrtocont.c:32:6: error: ‘NULL’ undeclared (first use in this function)
./constptrtocont.c:32:6: note: each undeclared identifier is reported only once for each function it appears in
./constptrtocont.c:33:2: error: assignment of read-only location ‘*ptr’
 */
