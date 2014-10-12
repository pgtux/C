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

/*	free(p);  Allowing memory leak */
	return 0;
}

/*
Valgrind:
========
*/

/*

memcheck:
---------

parthiban@parthi:~/git/penguintux/learn/C/gdb$ gcc -Wall -Wextra -g3 -o ./bin/leak ./leak.c 
parthiban@parthi:~/git/penguintux/learn/C/gdb$ ./bin/leak 
Value of p is updated: 1
parthiban@parthi:~/git/penguintux/learn/C/gdb$ valgrind --tool=memcheck ./bin/leak
==13618== Memcheck, a memory error detector
==13618== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==13618== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==13618== Command: ./bin/leak
==13618== 
Value of p is updated: 1
==13618== 
==13618== HEAP SUMMARY:
==13618==     in use at exit: 4 bytes in 1 blocks
==13618==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==13618== 
==13618== LEAK SUMMARY:
==13618==    definitely lost: 4 bytes in 1 blocks
==13618==    indirectly lost: 0 bytes in 0 blocks
==13618==      possibly lost: 0 bytes in 0 blocks
==13618==    still reachable: 0 bytes in 0 blocks
==13618==         suppressed: 0 bytes in 0 blocks
==13618== Rerun with --leak-check=full to see details of leaked memory
==13618== 
==13618== For counts of detected and suppressed errors, rerun with: -v
==13618== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

/*
Cachegrind:
-----------
parthiban@parthi:~/git/penguintux/learn/C/gdb/bin$ valgrind --tool=cachegrind ./leak
==5439== Cachegrind, a cache and branch-prediction profiler
==5439== Copyright (C) 2002-2013, and GNU GPL'd, by Nicholas Nethercote et al.
==5439== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==5439== Command: ./leak
==5439== 
Value of p is updated: 1
==5439== 
==5439== I   refs:      164,009
==5439== I1  misses:        890
==5439== LLi misses:        882
==5439== I1  miss rate:    0.54%
==5439== LLi miss rate:    0.53%
==5439== 
==5439== D   refs:       54,824  (41,046 rd   + 13,778 wr)
==5439== D1  misses:      3,153  ( 2,590 rd   +    563 wr)
==5439== LLd misses:      2,425  ( 1,930 rd   +    495 wr)
==5439== D1  miss rate:     5.7% (   6.3%     +    4.0%  )
==5439== LLd miss rate:     4.4% (   4.7%     +    3.5%  )
==5439== 
==5439== LL refs:         4,043  ( 3,480 rd   +    563 wr)
==5439== LL misses:       3,307  ( 2,812 rd   +    495 wr)
==5439== LL miss rate:      1.5% (   1.3%     +    3.5%  )



parthiban@parthi:~/git/penguintux/learn/C/gdb/bin$ cg_annotate cachegrind.out.5439 
--------------------------------------------------------------------------------
I1 cache:         65536 B, 64 B, 2-way associative
D1 cache:         16384 B, 64 B, 4-way associative
LL cache:         2097152 B, 64 B, 16-way associative
Command:          ./leak
Data file:        cachegrind.out.5439
Events recorded:  Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Events shown:     Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Event sort order: Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Thresholds:       0.1 100 100 100 100 100 100 100 100
Include dirs:     
User annotated:   
Auto-annotation:  off

--------------------------------------------------------------------------------
     Ir I1mr ILmr     Dr  D1mr  DLmr     Dw D1mw DLmw 
--------------------------------------------------------------------------------
164,009  890  882 41,046 2,590 1,930 13,778  563  495  PROGRAM TOTALS

--------------------------------------------------------------------------------
    Ir I1mr ILmr     Dr  D1mr DLmr    Dw D1mw DLmw  file:function
--------------------------------------------------------------------------------
56,045   10   10 13,657 1,037  856    17    2    0  /build/buildd/eglibc-2.19/elf/dl-addr.c:_dl_addr
22,299   13   13  7,197   240  131 3,429   11    0  /build/buildd/eglibc-2.19/elf/dl-lookup.c:do_lookup_x
18,400   11   11  3,701   107   89 2,117    8    0  /build/buildd/eglibc-2.19/elf/dl-lookup.c:_dl_lookup_symbol_x
16,307   21   21  3,772   561  537 2,018  252  239  /build/buildd/eglibc-2.19/elf/../sysdeps/x86_64/dl-machine.h:_dl_relocate_object
10,049    1    1  2,997    40   11     0    0    0  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../strcmp.S:strcmp
 8,265   10   10  1,967    91   71   116    3    0  /build/buildd/eglibc-2.19/elf/do-rel.h:_dl_relocate_object
 4,392    6    6  1,849    40   18   531    5    0  /build/buildd/eglibc-2.19/elf/dl-lookup.c:check_match.9458
 2,226    1    1     13     0    0 2,148   34   34  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/rtld-memset.S:memset
 1,176   13   13    383    17   14   161   14   13  /build/buildd/eglibc-2.19/elf/dl-version.c:_dl_check_map_versions
 1,147   36   36    281     2    2   130   15   15  /build/buildd/eglibc-2.19/elf/dl-load.c:_dl_map_object_from_fd
 1,055   30   30    224     6    0   115    1    1  /build/buildd/eglibc-2.19/elf/dl-deps.c:_dl_map_object_deps
 1,049    3    2    271     7    0   156    2    0  /build/buildd/eglibc-2.19/elf/dl-misc.c:_dl_name_match_p
 1,018   12   12    252    11   11    76    3    3  /build/buildd/eglibc-2.19/string/../string/memcmp.c:bcmp
 1,014    2    2    319     0    0     2    0    0  /build/buildd/eglibc-2.19/elf/dl-minimal.c:strsep
   950   68   68    204    24   12   114   11   11  /build/buildd/eglibc-2.19/elf/rtld.c:dl_main
   831    6    6    223     0    0   132    1    0  /build/buildd/eglibc-2.19/libio/fileops.c:_IO_file_overflow@@GLIBC_2.2.5
   805    5    5     81     1    1     0    0    0  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../rtld-strlen.S:strlen
   793    4    4      9     0    0   263   32   32  /build/buildd/eglibc-2.19/malloc/malloc.c:malloc_consolidate
   710    4    4    119     0    0   117    2    2  /build/buildd/eglibc-2.19/elf/dl-minimal.c:__libc_memalign
   666    4    4    100     9    9     0    0    0  /build/buildd/eglibc-2.19/elf/dl-cache.c:_dl_cache_libcmp
   605   14   14    109     3    3   112   24   24  /build/buildd/eglibc-2.19/elf/dl-object.c:_dl_new_object
   555    8    8     96    14   14    47   11   11  /build/buildd/eglibc-2.19/elf/get-dynamic-info.h:_dl_map_object_from_fd
   522   11   11    175    19    1   109    0    0  /build/buildd/eglibc-2.19/elf/dl-reloc.c:_dl_relocate_object
   484    7    7    176    47    1    54    0    0  /build/buildd/eglibc-2.19/elf/../elf/dl-runtime.c:_dl_fixup
   476   11   11    134    19   17    28    5    5  /build/buildd/eglibc-2.19/elf/../elf/dl-sysdep.c:_dl_sysdep_start
   471    6    6    154    48    1    15    4    2  /build/buildd/eglibc-2.19/malloc/arena.c:ptmalloc_init.part.7
   453   10   10     70     6    6    12    0    0  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../cacheinfo.c:intel_check_word
   446    2    2    153    33   33     2    0    0  /build/buildd/eglibc-2.19/elf/dl-environ.c:_dl_next_ld_env_entry
   442   26   26     95     1    1    77    5    5  /build/buildd/eglibc-2.19/elf/dl-load.c:_dl_map_object
   441    6    6     68     0    0    55    6    6  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../memcpy.S:memcpy
   377    5    5     54     2    1    39    5    5  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/memcpy.S:mempcpy
   372    4    4    123     0    0    28    0    0  /build/buildd/eglibc-2.19/libio/genops.c:_IO_default_xsputn
   350    2    2      0     0    0     0    0    0  /build/buildd/eglibc-2.19/string/../bits/stdlib-bsearch.h:intel_check_word
   338   16   16     59     2    2    65    6    6  /build/buildd/eglibc-2.19/elf/dl-load.c:_dl_init_paths
   332    3    3      7     0    0   295   37   37  /build/buildd/eglibc-2.19/elf/dl-tls.c:_dl_allocate_tls_storage
   318   11   11     72     0    0    53    1    1  /build/buildd/eglibc-2.19/elf/dl-load.c:open_verify.constprop.6
   317   13   13    107     0    0    43    0    0  /build/buildd/eglibc-2.19/elf/dl-load.c:open_path
   294   43   43     93     9    4    62    5    0  /build/buildd/eglibc-2.19/stdio-common/vfprintf.c:vfprintf
   277   16   16     49     7    7    25    0    0  /build/buildd/eglibc-2.19/elf/dl-cache.c:_dl_load_cache_lookup
   268   33   33     47     9    5    41    2    1  /build/buildd/eglibc-2.19/malloc/malloc.c:_int_malloc
   263   19   19     41     0    0    42    2    2  /build/buildd/eglibc-2.19/elf/dl-hwcaps.c:_dl_important_hwcaps
   263   13   13     98    15    0    31    2    0  /build/buildd/eglibc-2.19/elf/dl-fini.c:_dl_fini
   254   10   10     44     7    7    18    6    6  /build/buildd/eglibc-2.19/elf/get-dynamic-info.h:_dl_start
   237    9    9     34     7    7    23    5    5  /build/buildd/eglibc-2.19/elf/get-dynamic-info.h:dl_main
   225    1    1     66    13   13    19    4    4  /build/buildd/eglibc-2.19/elf/../sysdeps/x86_64/dl-machine.h:_dl_start
   209    6    6     27     2    2     0    0    0  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../strchr.S:index
   198   22   16     98    10    1    29    1    1  ???:???
   194    7    7     40     1    0    25    1    0  /build/buildd/eglibc-2.19/libio/fileops.c:_IO_file_xsputn@@GLIBC_2.2.5
   189   10   10     33     6    6    17    0    0  /build/buildd/eglibc-2.19/elf/dl-load.c:open_verify
   187    6    6     50     2    0    23    0    0  /build/buildd/eglibc-2.19/elf/dl-fini.c:_dl_sort_fini
   185    4    4     72     7    4    27    0    0  /build/buildd/eglibc-2.19/elf/dl-version.c:match_symbol
   169    3    3     59    12    0    29    0    0  /build/buildd/eglibc-2.19/elf/dl-init.c:call_init.part.0
   165   10   10     27     4    2    26    7    6  /build/buildd/eglibc-2.19/elf/rtld.c:_dl_start

 */

/*
Callgrind:
----------
parthiban@parthi:~/git/penguintux/learn/C/gdb/bin$ valgrind --tool=callgrind ./leak
==5431== Callgrind, a call-graph generating cache profiler
==5431== Copyright (C) 2002-2013, and GNU GPL'd, by Josef Weidendorfer et al.
==5431== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==5431== Command: ./leak
==5431== 
==5431== For interactive control, run 'callgrind_control -h'.
Value of p is updated: 1
==5431== 
==5431== Events    : Ir
==5431== Collected : 164006
==5431== 
==5431== I   refs:      164,006

parthiban@parthi:~/git/penguintux/learn/C/gdb/bin$ callgrind_annotate callgrind.out.5431 
--------------------------------------------------------------------------------
Profile data file 'callgrind.out.5431' (creator: callgrind-3.10.0.SVN)
--------------------------------------------------------------------------------
I1 cache: 
D1 cache: 
LL cache: 
Timerange: Basic block 0 - 37599
Trigger: Program termination
Profiled target:  ./leak (PID 5431, part 1)
Events recorded:  Ir
Events shown:     Ir
Event sort order: Ir
Thresholds:       99
Include dirs:     
User annotated:   
Auto-annotation:  off

--------------------------------------------------------------------------------
     Ir 
--------------------------------------------------------------------------------
164,006  PROGRAM TOTALS

--------------------------------------------------------------------------------
    Ir  file:function
--------------------------------------------------------------------------------
56,050  /build/buildd/eglibc-2.19/elf/dl-addr.c:_dl_addr [/lib/x86_64-linux-gnu/libc-2.19.so]
22,299  /build/buildd/eglibc-2.19/elf/dl-lookup.c:do_lookup_x [/lib/x86_64-linux-gnu/ld-2.19.so]
18,400  /build/buildd/eglibc-2.19/elf/dl-lookup.c:_dl_lookup_symbol_x [/lib/x86_64-linux-gnu/ld-2.19.so]
16,307  /build/buildd/eglibc-2.19/elf/../sysdeps/x86_64/dl-machine.h:_dl_relocate_object
 8,740  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../strcmp.S:strcmp'2 [/lib/x86_64-linux-gnu/ld-2.19.so]
 8,265  /build/buildd/eglibc-2.19/elf/do-rel.h:_dl_relocate_object
 4,392  /build/buildd/eglibc-2.19/elf/dl-lookup.c:check_match.9458 [/lib/x86_64-linux-gnu/ld-2.19.so]
 2,226  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/rtld-memset.S:memset [/lib/x86_64-linux-gnu/ld-2.19.so]
 1,309  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../strcmp.S:strcmp [/lib/x86_64-linux-gnu/ld-2.19.so]
 1,179  /build/buildd/eglibc-2.19/elf/dl-version.c:_dl_check_map_versions [/lib/x86_64-linux-gnu/ld-2.19.so]
 1,147  /build/buildd/eglibc-2.19/elf/dl-load.c:_dl_map_object_from_fd [/lib/x86_64-linux-gnu/ld-2.19.so]
 1,058  /build/buildd/eglibc-2.19/elf/dl-deps.c:_dl_map_object_deps [/lib/x86_64-linux-gnu/ld-2.19.so]
 1,049  /build/buildd/eglibc-2.19/elf/dl-misc.c:_dl_name_match_p [/lib/x86_64-linux-gnu/ld-2.19.so]
 1,018  /build/buildd/eglibc-2.19/string/../string/memcmp.c:bcmp [/lib/x86_64-linux-gnu/ld-2.19.so]
 1,014  /build/buildd/eglibc-2.19/elf/dl-minimal.c:strsep [/lib/x86_64-linux-gnu/ld-2.19.so]
   950  /build/buildd/eglibc-2.19/elf/rtld.c:dl_main [/lib/x86_64-linux-gnu/ld-2.19.so]
   831  /build/buildd/eglibc-2.19/libio/fileops.c:_IO_file_overflow@@GLIBC_2.2.5 [/lib/x86_64-linux-gnu/libc-2.19.so]
   805  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../rtld-strlen.S:strlen [/lib/x86_64-linux-gnu/ld-2.19.so]
   793  /build/buildd/eglibc-2.19/malloc/malloc.c:malloc_consolidate [/lib/x86_64-linux-gnu/libc-2.19.so]
   710  /build/buildd/eglibc-2.19/elf/dl-minimal.c:__libc_memalign [/lib/x86_64-linux-gnu/ld-2.19.so]
   666  /build/buildd/eglibc-2.19/elf/dl-cache.c:_dl_cache_libcmp [/lib/x86_64-linux-gnu/ld-2.19.so]
   610  /build/buildd/eglibc-2.19/elf/dl-object.c:_dl_new_object [/lib/x86_64-linux-gnu/ld-2.19.so]
   555  /build/buildd/eglibc-2.19/elf/get-dynamic-info.h:_dl_map_object_from_fd
   522  /build/buildd/eglibc-2.19/elf/dl-reloc.c:_dl_relocate_object [/lib/x86_64-linux-gnu/ld-2.19.so]
   484  /build/buildd/eglibc-2.19/elf/../elf/dl-runtime.c:_dl_fixup [/lib/x86_64-linux-gnu/ld-2.19.so]
   476  /build/buildd/eglibc-2.19/elf/../elf/dl-sysdep.c:_dl_sysdep_start [/lib/x86_64-linux-gnu/ld-2.19.so]
   471  /build/buildd/eglibc-2.19/malloc/arena.c:ptmalloc_init.part.7 [/lib/x86_64-linux-gnu/libc-2.19.so]
   453  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../cacheinfo.c:intel_check_word [/lib/x86_64-linux-gnu/libc-2.19.so]
   446  /build/buildd/eglibc-2.19/elf/dl-environ.c:_dl_next_ld_env_entry [/lib/x86_64-linux-gnu/ld-2.19.so]
   443  /build/buildd/eglibc-2.19/elf/dl-load.c:_dl_map_object [/lib/x86_64-linux-gnu/ld-2.19.so]
   441  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../memcpy.S:memcpy [/lib/x86_64-linux-gnu/ld-2.19.so]
   377  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/memcpy.S:mempcpy [/lib/x86_64-linux-gnu/ld-2.19.so]
   372  /build/buildd/eglibc-2.19/libio/genops.c:_IO_default_xsputn [/lib/x86_64-linux-gnu/libc-2.19.so]
   350  /build/buildd/eglibc-2.19/string/../bits/stdlib-bsearch.h:intel_check_word
   341  /build/buildd/eglibc-2.19/elf/dl-load.c:_dl_init_paths [/lib/x86_64-linux-gnu/ld-2.19.so]
   334  /build/buildd/eglibc-2.19/elf/dl-tls.c:_dl_allocate_tls_storage [/lib/x86_64-linux-gnu/ld-2.19.so]
   318  /build/buildd/eglibc-2.19/elf/dl-load.c:open_verify.constprop.6 [/lib/x86_64-linux-gnu/ld-2.19.so]
   317  /build/buildd/eglibc-2.19/elf/dl-load.c:open_path [/lib/x86_64-linux-gnu/ld-2.19.so]
   294  /build/buildd/eglibc-2.19/stdio-common/vfprintf.c:vfprintf [/lib/x86_64-linux-gnu/libc-2.19.so]
   277  /build/buildd/eglibc-2.19/elf/dl-cache.c:_dl_load_cache_lookup [/lib/x86_64-linux-gnu/ld-2.19.so]
   268  /build/buildd/eglibc-2.19/malloc/malloc.c:_int_malloc [/lib/x86_64-linux-gnu/libc-2.19.so]
   264  /build/buildd/eglibc-2.19/elf/dl-hwcaps.c:_dl_important_hwcaps [/lib/x86_64-linux-gnu/ld-2.19.so]
   263  /build/buildd/eglibc-2.19/elf/dl-fini.c:_dl_fini [/lib/x86_64-linux-gnu/ld-2.19.so]
   254  /build/buildd/eglibc-2.19/elf/get-dynamic-info.h:_dl_start
   237  /build/buildd/eglibc-2.19/elf/get-dynamic-info.h:dl_main
   225  /build/buildd/eglibc-2.19/elf/../sysdeps/x86_64/dl-machine.h:_dl_start
   209  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../strchr.S:index [/lib/x86_64-linux-gnu/ld-2.19.so]
   194  /build/buildd/eglibc-2.19/libio/fileops.c:_IO_file_xsputn@@GLIBC_2.2.5 [/lib/x86_64-linux-gnu/libc-2.19.so]
   189  /build/buildd/eglibc-2.19/elf/dl-load.c:open_verify [/lib/x86_64-linux-gnu/ld-2.19.so]
   187  /build/buildd/eglibc-2.19/elf/dl-fini.c:_dl_sort_fini [/lib/x86_64-linux-gnu/ld-2.19.so]
   185  /build/buildd/eglibc-2.19/elf/dl-version.c:match_symbol [/lib/x86_64-linux-gnu/ld-2.19.so]
   169  /build/buildd/eglibc-2.19/elf/dl-init.c:call_init.part.0 [/lib/x86_64-linux-gnu/ld-2.19.so]
   165  /build/buildd/eglibc-2.19/elf/rtld.c:_dl_start [/lib/x86_64-linux-gnu/ld-2.19.so]
   161  /build/buildd/eglibc-2.19/elf/dl-load.c:fillin_rpath [/lib/x86_64-linux-gnu/ld-2.19.so]
   151  /build/buildd/eglibc-2.19/elf/do-rel.h:_dl_start
   144  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../cacheinfo.c:init_cacheinfo [/lib/x86_64-linux-gnu/libc-2.19.so]
   126  /build/buildd/eglibc-2.19/elf/../sysdeps/x86_64/dl-trampoline.S:_dl_runtime_resolve [/lib/x86_64-linux-gnu/ld-2.19.so]
   120  /build/buildd/eglibc-2.19/elf/dl-error.c:_dl_catch_error [/lib/x86_64-linux-gnu/ld-2.19.so]
   106  /build/buildd/eglibc-2.19/elf/dl-object.c:_dl_add_to_namespace_list [/lib/x86_64-linux-gnu/ld-2.19.so]
   101  /build/buildd/eglibc-2.19/libio/genops.c:_IO_cleanup [/lib/x86_64-linux-gnu/libc-2.19.so]
   100  /build/buildd/eglibc-2.19/elf/dl-lookup.c:_dl_setup_hash [/lib/x86_64-linux-gnu/ld-2.19.so]
    98  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/multiarch/../cacheinfo.c:handle_intel [/lib/x86_64-linux-gnu/libc-2.19.so]
    88  /build/buildd/eglibc-2.19/libio/genops.c:_IO_flush_all_lockp [/lib/x86_64-linux-gnu/libc-2.19.so]
    88  /build/buildd/eglibc-2.19/elf/../sysdeps/unix/sysv/linux/dl-sysdep.c:_dl_discover_osversion [/lib/x86_64-linux-gnu/ld-2.19.so]
    86  /build/buildd/eglibc-2.19/elf/dl-tls.c:_dl_allocate_tls_init [/lib/x86_64-linux-gnu/ld-2.19.so]
    84  /build/buildd/eglibc-2.19/elf/dl-minimal.c:malloc [/lib/x86_64-linux-gnu/ld-2.19.so]
    83  /build/buildd/eglibc-2.19/elf/dl-init.c:_dl_init [/lib/x86_64-linux-gnu/ld-2.19.so]
    78  /build/buildd/eglibc-2.19/csu/../sysdeps/x86_64/multiarch/init-arch.c:__init_cpu_features [/lib/x86_64-linux-gnu/libc-2.19.so]
    75  /build/buildd/eglibc-2.19/elf/dl-version.c:_dl_check_all_versions [/lib/x86_64-linux-gnu/ld-2.19.so]
    75  /build/buildd/eglibc-2.19/setjmp/../sysdeps/x86_64/setjmp.S:__sigsetjmp [/lib/x86_64-linux-gnu/libc-2.19.so]
    73  /build/buildd/eglibc-2.19/elf/dl-tls.c:_dl_determine_tlsoffset [/lib/x86_64-linux-gnu/ld-2.19.so]
    72  /build/buildd/eglibc-2.19/elf/dl-minimal.c:calloc [/lib/x86_64-linux-gnu/ld-2.19.so]
    71  /build/buildd/eglibc-2.19/elf/rtld.c:init_tls [/lib/x86_64-linux-gnu/ld-2.19.so]
    64  /build/buildd/eglibc-2.19/string/../sysdeps/x86_64/strchr.S:strchrnul [/lib/x86_64-linux-gnu/libc-2.19.so]
    63  /build/buildd/eglibc-2.19/libio/fileops.c:_IO_do_write@@GLIBC_2.2.5 [/lib/x86_64-linux-gnu/libc-2.19.so]
    60  /build/buildd/eglibc-2.19/csu/libc-start.c:(below main) [/lib/x86_64-linux-gnu/libc-2.19.so]
    60  /build/buildd/eglibc-2.19/misc/../sysdeps/unix/syscall-template.S:mmap [/lib/x86_64-linux-gnu/libc-2.19.so]
    60  /build/buildd/eglibc-2.19/elf/dl-load.c:expand_dynamic_string_token [/lib/x86_64-linux-gnu/ld-2.19.so]
    54  /build/buildd/eglibc-2.19/stdlib/exit.c:__run_exit_handlers [/lib/x86_64-linux-gnu/libc-2.19.so]
    51  /build/buildd/eglibc-2.19/io/../sysdeps/unix/syscall-template.S:open [/lib/x86_64-linux-gnu/ld-2.19.so]
    49  /build/buildd/eglibc-2.19/io/../sysdeps/unix/sysv/linux/wordsize-64/xstat.c:_xstat [/lib/x86_64-linux-gnu/ld-2.19.so]
    47  /build/buildd/eglibc-2.19/libio/filedoalloc.c:_IO_file_doallocate [/lib/x86_64-linux-gnu/libc-2.19.so]

 */

/*
massif:
-------
parthiban@parthi:~/git/penguintux/learn/C/gdb/bin$ valgrind --tool=massif ./leak
==5389== Massif, a heap profiler
==5389== Copyright (C) 2003-2013, and GNU GPL'd, by Nicholas Nethercote
==5389== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==5389== Command: ./leak
==5389== 
Value of p is updated: 1
==5389==

parthiban@parthi:~/git/penguintux/learn/C/gdb/bin$ ms_print massif.out.5389 
--------------------------------------------------------------------------------
Command:            ./leak
Massif arguments:   (none)
ms_print arguments: massif.out.5389
--------------------------------------------------------------------------------


     B
   24^                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
   0 +----------------------------------------------------------------------->ki
     0                                                                   110.0

Number of snapshots: 2
 Detailed snapshots: []

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1        112,640               24                4            20            0

 */

/*
Helgrind and DRD are thread debugger, which can't be covered as part of this example.
 */

/* 
 GDB:
-----

parthiban@parthi:~/git/penguintux/learn/C/gdb$ gdb -q
(gdb) file ./bin/leak 
Reading symbols from ./bin/leak...done.
(gdb) break main
Breakpoint 1 at 0x4005dc: file ./leak.c, line 10.
(gdb) r
Starting program: /home/parthiban/git/penguintux/learn/C/gdb/bin/leak 

Breakpoint 1, main () at ./leak.c:10
warning: Source file is more recent than executable.
10		int *p=NULL;
(gdb) n
11		p = (int*)malloc(sizeof(int));
(gdb) 
13		if (p == NULL) {
(gdb) print p
$1 = (int *) 0x602010
(gdb) n
18		function(&p);
(gdb) 
19		printf("Value of p is updated: %d\n", *p);
(gdb) 
Value of p is updated: 1
22		return 0;
(gdb) print p
$2 = (int *) 0x602010
(gdb) n
23	}
(gdb) 
__libc_start_main (main=0x4005d4 <main>, argc=1, argv=0x7fffffffdf28, init=<optimized out>, fini=<optimized out>, 
    rtld_fini=<optimized out>, stack_end=0x7fffffffdf18) at libc-start.c:321
321	libc-start.c: No such file or directory.
(gdb) 
[Inferior 1 (process 13629) exited normally]
(gdb) q

*/
