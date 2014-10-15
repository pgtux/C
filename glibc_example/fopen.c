/*
 * glibc_example/fopen.c
 * This sample code shows the API 'fopen', 'fclose' and 'fprintf' usage under LIBC 
 * 
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
	FILE * fp=NULL;

	fp = fopen("file", "w+");
	fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014);

	fclose(fp);
	return 0;
}

/*

To compile:
-----------
gcc -Wall -Wextra -g3 -o ./bin/fopen ./fopen.c -lc

ltrace:
-------
>> ltrace ./bin/fopen 
__libc_start_main(0x400594, 1, 0x7fffb931b848, 0x400600, 0x400690 <unfinished ...>
fopen("file", "w+")                                                                                                            = 0x1a5d010
fprintf(0x1a5d010, "%s %s %s %d", "We", "are", "in", 2014)                                                                     = 14
fclose(0x1a5d010)                                                                                                              = 0
+++ exited (status 0) +++


strace:
-------
>>strace ./bin/fopen 
execve("./bin/fopen", ["./bin/fopen"], [ 56 vars ]) = 0
brk(0)                                  = 0x1d14000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f453ff88000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=155354, ...}) = 0
mmap(NULL, 155354, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f453ff62000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\200\30\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1811128, ...}) = 0
mmap(NULL, 3925176, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f453f9a9000
mprotect(0x7f453fb5e000, 2093056, PROT_NONE) = 0
mmap(0x7f453fd5d000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b4000) = 0x7f453fd5d000
mmap(0x7f453fd63000, 17592, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f453fd63000
close(3)                                = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f453ff61000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f453ff60000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f453ff5f000
arch_prctl(ARCH_SET_FS, 0x7f453ff60700) = 0
mprotect(0x7f453fd5d000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7f453ff8a000, 4096, PROT_READ) = 0
munmap(0x7f453ff62000, 155354)          = 0
brk(0)                                  = 0x1d14000
brk(0x1d35000)                          = 0x1d35000
open("file", O_RDWR|O_CREAT|O_TRUNC, 0666) = 3
fstat(3, {st_mode=S_IFREG|0664, st_size=0, ...}) = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f453ff87000
write(3, "We are in 2014", 14)          = 14
close(3)                                = 0
munmap(0x7f453ff87000, 4096)            = 0
exit_group(0)                           = ?

 */
