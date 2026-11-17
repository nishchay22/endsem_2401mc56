Roll Number: 2401mc56
Set: Set 2

Question 1: Page Protection with mprotect() and munprotect()
- vm.c, defs.h: Implemented mprotect(void *addr, int len) and munprotect(void *addr, int len) to check page alignment, len > 0, address bounds within myproc()->sz, and page presence (PTE_P) via walkpgdir(), clear or set PTE_W across len pages, and flush the TLB with lcr3(V2P(myproc()->pgdir)).
- syscall.h, syscall.c, sysproc.c, user.h, usys.S: Added system call numbers, declarations, and wrappers for mprotect and munprotect.
- prottest.c, Makefile: Added user test program prottest (and _prottest to UPROGS) that allocates a page with sbrk(4096), verifies read access after mprotect, forks a child that gets killed on write while parent still sees 'A', restores write access with munprotect to write 'C', and verifies -1 on invalid inputs.

Question 2: Priority-Based CPU Scheduler
- proc.h, proc.c, defs.h: Added priority field to struct proc, initialized priority to 10 in allocproc(), and implemented set_priority(int pid, int priority) under ptable.lock to update priority (1-20) and return old priority (or -1 on error).
- proc.c: Modified scheduler() to scan ptable.proc while holding ptable.lock and select the RUNNABLE process with the smallest priority number (picking the first in table order on ties).
- syscall.h, syscall.c, sysproc.c, user.h, usys.S: Added system call number, declaration, and wrapper for set_priority.
- schedtest.c, Makefile: Added user test program schedtest (and _schedtest to UPROGS) where the parent sets its priority to 1, forks three CPU-bound children with priorities 5, 10, and 15, and waits for them to complete in priority order before printing Done.
