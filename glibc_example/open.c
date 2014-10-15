/*
 * glibc_example/open.c
 * This sample code is equa to fopen.c but only with system call
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
#include <unistd.h>
#include <fcntl.h>
 
int main(void) {
/* Uncomment the below line to understand the O_CREAT flag */
//	int fd = open("file", O_WRONLY | O_APPEND);  
	int fd = open("file", O_WRONLY | O_CREAT | O_APPEND, 0777);
	if(fd < 0) {
		write(2,"Unable to open to file\n",25);
		return -1;
	}

	if(write(fd,"We are in 2014\n", 16) != 16) {
		write(2,"Unable to write to file\n",25);
		return -1;
	}

	return 0;
}


/*

To compiel:

gcc -Wall -Wextra -g3 -o ./bin/open ./open.c

ltrace:
-------
>>ltrace ./bin/open 
__libc_start_main(0x400544, 1, 0x7fffd47c0208, 0x4005d0, 0x400660 <unfinished ...>
open("file", 1089, 0777)                                                                                                       = 3
write(3, "We are in 2014\n", 16)                                                                                               = 16
+++ exited (status 0) +++


strace:
--------
>>strace ./bin/open 
execve("./bin/open", ["./bin/open"], [ 56 vars ]) = 0
brk(0)                                  = 0x1226000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f0967422000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=155354, ...}) = 0
mmap(NULL, 155354, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f09673fc000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\200\30\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1811128, ...}) = 0
mmap(NULL, 3925176, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f0966e43000
mprotect(0x7f0966ff8000, 2093056, PROT_NONE) = 0
mmap(0x7f09671f7000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b4000) = 0x7f09671f7000
mmap(0x7f09671fd000, 17592, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f09671fd000
close(3)                                = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f09673fb000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f09673fa000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f09673f9000
arch_prctl(ARCH_SET_FS, 0x7f09673fa700) = 0
mprotect(0x7f09671f7000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7f0967424000, 4096, PROT_READ) = 0
munmap(0x7f09673fc000, 155354)          = 0
open("file", O_WRONLY|O_CREAT|O_APPEND, 0777) = 3
write(3, "We are in 2014\n\0", 16)      = 16
exit_group(0)                           = ?

 */
