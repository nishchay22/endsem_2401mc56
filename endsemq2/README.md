Changes made (Question 2 - Set 2, 2401mc56):

- proc.h: Added int priority field to struct proc.
- proc.c: Initialized priority to 10 in allocproc(), implemented set_priority(int pid, int priority) holding ptable.lock, and updated scheduler() to pick the RUNNABLE process with the smallest priority number (first in table order on ties).
- defs.h: Declared set_priority.
- syscall.h, syscall.c, sysproc.c, user.h, usys.S: Wired set_priority system call.
- schedtest.c: User program setting parent priority to 1, forking 3 CPU-bound children with priorities 5, 10, and 15, and waiting for them to finish in priority order.
- Makefile: Added _schedtest to UPROGS.
