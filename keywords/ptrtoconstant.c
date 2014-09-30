/*
 * keywords/ptrtoconstant.c
 * 
 * Pointer to Constant:
 * - Here 'ptr' is an pointer which is pointer to an integer i.e. 'ptr' will hold the address of an integer
 * - The declaration states that the integer which is pointed by 'ptr' is an constant.
 * - An attempt to change the value of 'a' using this pointer 'ptr' will result in error
 * - An attempt to change the address which is pointing is possible i.e. in this example 'ptr' can be used to point someother address (uncomment 34th line and comment 33rd line to understand)
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
	int b=2;
	const int *ptr =&a;
	*ptr = 2;
//	ptr=&b;
	return 0;
}

/*

GDB recording for assiging different address to 'ptr':
======================================================
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ gcc -Wall -Wextra -g3 -o ./bin/ptrtoconstant ./ptrtoconstant.c 
./ptrtoconstant.c: In function ‘main’:
./ptrtoconstant.c:32:13: warning: variable ‘ptr’ set but not used [-Wunused-but-set-variable]
parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ gdb -q
(gdb) file ./bin/ptrtoconstant 
Reading symbols from /home/parthiban/git/penguintux/workspace/C/C/keywords/bin/ptrtoconstant...done.
(gdb) b main
Breakpoint 1 at 0x4004b8: file ./ptrtoconstant.c, line 30.
(gdb) r
Starting program: /home/parthiban/git/penguintux/workspace/C/C/keywords/bin/ptrtoconstant 

Breakpoint 1, main () at ./ptrtoconstant.c:30
30		int a=1;
(gdb) n
31		int b=2;
(gdb) 
32		const int *ptr =&a;
(gdb) p &a
$1 = (int *) 0x7fffffffdda8
(gdb) p &b
$2 = (int *) 0x7fffffffddac
(gdb) n
34		ptr=&b;
(gdb) p ptr
$3 = (const int *) 0x7fffffffdda8
(gdb) n
35		return 0;
(gdb) p ptr
$4 = (const int *) 0x7fffffffddac
(gdb) c
Continuing.
[Inferior 1 (process 6494) exited normally]
(gdb) q

 */


/*
 * Compilation ERROR when value attempt to change the value
 * parthiban@ubuntu:~/git/penguintux/workspace/C/C/keywords$ gcc -Wall -Wextra -g3 -o ./bin/ptrtoconstant ./ptrtoconstant.c 
 * ./ptrtoconstant.c: In function ‘main’:
 * ./ptrtoconstant.c:33:2: error: assignment of read-only location ‘*ptr’
 * ./ptrtoconstant.c:31:6: warning: unused variable ‘b’ [-Wunused-variable]
 */
