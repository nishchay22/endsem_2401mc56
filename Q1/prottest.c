#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  char *p = sbrk(4096);
  p[0] = 'A';
  printf(1, "initial value: %c\n", p[0]);

  if(mprotect(p, 1) < 0){
    printf(1, "mprotect failed\n");
    exit();
  }
  printf(1, "after mprotect, read value: %c\n", p[0]);

  int pid = fork();
  if(pid < 0){
    printf(1, "fork failed\n");
    exit();
  }
  if(pid == 0){
    printf(1, "child trying to write to protected page...\n");
    p[0] = 'B';
    printf(1, "child write succeeded (unexpected)\n");
    exit();
  }
  wait();
  printf(1, "parent after child killed, value: %c\n", p[0]);

  if(munprotect(p, 1) < 0){
    printf(1, "munprotect failed\n");
    exit();
  }
  p[0] = 'C';
  printf(1, "after munprotect, write value: %c\n", p[0]);

  printf(1, "mprotect unaligned: %d\n", mprotect(p + 1, 1));
  printf(1, "mprotect len=0: %d\n", mprotect(p, 0));
  printf(1, "mprotect out of range: %d\n", mprotect(p, 2));

  exit();
}
