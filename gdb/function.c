#include <stdio.h>
#include <stdlib.h>

void function(int **);
void function(int **p) {
	**p = 1;
}

int main(void) {
	int *p=NULL;
	p = (int*)malloc(sizeof(int));

	if (p == NULL) {
		printf("Malloc failed\n");
		return -1;
	}

	function(&p);
	printf("Value of p is updated: %d\n", *p);

	free(p);
	return 0;
}

/*

parthiban@parthi:~/git/penguintux/learn/C/gdb$ gcc -Wall -Wextra -g3 -o ./bin/function ./function.c 
parthiban@parthi:~/git/penguintux/learn/C/gdb$ ./bin/function 
Value of p is updated: 1
parthiban@parthi:~/git/penguintux/learn/C/gdb$ gdb -q 
(gdb) file ./bin/function 
Reading symbols from ./bin/function...done.
(gdb) break main
Breakpoint 1 at 0x40062c: file ./function.c, line 10.
(gdb) show breakpoint 
(gdb) r
Starting program: /home/parthiban/git/penguintux/learn/C/gdb/bin/function 

Breakpoint 1, main () at ./function.c:10
10		int *p=NULL;
(gdb) l
5	void function(int **p) {
6		**p = 1;
7	}
8	
9	int main(void) {
10		int *p=NULL;
11		p = (int*)malloc(sizeof(int));
12	
13		if (p == NULL) {
14			printf("Malloc failed\n");
(gdb) print p
$1 = (int *) 0x0
(gdb) n
11		p = (int*)malloc(sizeof(int));
(gdb) 
13		if (p == NULL) {
(gdb) print p
$2 = (int *) 0x602010
(gdb) n
18		function(&p);
(gdb) s
function (p=0x7fffffffde28) at ./function.c:6
6		**p = 1;
(gdb) bt
#0  function (p=0x7fffffffde28) at ./function.c:6
#1  0x0000000000400668 in main () at ./function.c:18
(gdb) bt full
#0  function (p=0x7fffffffde28) at ./function.c:6
No locals.
#1  0x0000000000400668 in main () at ./function.c:18
        p = 0x602010
(gdb) n
7	}
(gdb) n
main () at ./function.c:19
19		printf("Value of p is updated: %d\n", *p);
(gdb) 
Value of p is updated: 1
21		free(p);
(gdb) 
22		return 0;
(gdb) p p
$3 = (int *) 0x602010
(gdb) n
23	}
(gdb) 
__libc_start_main (main=0x400624 <main>, argc=1, argv=0x7fffffffdf18, init=<optimized out>, fini=<optimized out>, 
    rtld_fini=<optimized out>, stack_end=0x7fffffffdf08) at libc-start.c:321
321	libc-start.c: No such file or directory.
(gdb) c
Continuing.
[Inferior 1 (process 13550) exited normally]
(gdb)

 */


/*
ltrace:
-------

parthiban@parthi:~/git/penguintux/learn/C/gdb$ ltrace ./bin/function >>./function.c 
__libc_start_main(0x400624, 1, 0x7fff6d178178, 0x4006a0 <unfinished ...>
malloc(4)                                                                  = 0x22cc010
printf("Value of p is updated: %d\n", 1)                                   = 25
free(0x22cc010)                                                            = <void>
+++ exited (status 0) +++


 */



/*
strace:
-------

parthiban@parthi:~/git/penguintux/learn/C/gdb$ strace ./bin/function 
execve("./bin/function", ["./bin/function"], [ 64 vars ]) = 0
brk(0)                                  = 0xa1f000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ff49233d000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=112280, ...}) = 0
mmap(NULL, 112280, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7ff492318000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\320\37\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1845024, ...}) = 0
mmap(NULL, 3953344, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7ff491d50000
mprotect(0x7ff491f0b000, 2097152, PROT_NONE) = 0
mmap(0x7ff49210b000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bb000) = 0x7ff49210b000
mmap(0x7ff492111000, 17088, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7ff492111000
close(3)                                = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ff492338000
arch_prctl(ARCH_SET_FS, 0x7ff492338740) = 0
mprotect(0x7ff49210b000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7ff49233a000, 4096, PROT_READ) = 0
munmap(0x7ff492318000, 112280)          = 0
brk(0)                                  = 0xa1f000
brk(0xa40000)                           = 0xa40000
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ff492337000
write(1, "Value of p is updated: 1\n", 25Value of p is updated: 1
) = 25
exit_group(0)                           = ?
+++ exited with 0 +++

 */
