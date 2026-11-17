Changes made (Question 1 - Set 2, 2401mc56):

- vm.c: Implemented mprotect(void *addr, int len) and munprotect(void *addr, int len) using walkpgdir() to validate page-alignment, len > 0, range within myproc()->sz, and PTE_P, then clear/set PTE_W and flush TLB with lcr3(V2P(myproc()->pgdir)).
- defs.h: Declared mprotect and munprotect.
- syscall.h, syscall.c, sysproc.c, user.h, usys.S: Wired mprotect and munprotect system calls.
- prottest.c: User program testing sbrk(4096), mprotect read, child killed on write to protected page, munprotect write of 'C', and -1 return on unaligned address, len=0, and out-of-bounds range.
- Makefile: Added _prottest to UPROGS.
