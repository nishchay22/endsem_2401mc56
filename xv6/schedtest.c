#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int priorities[3] = {5, 10, 15};
  int i, pid;

  set_priority(getpid(), 1);

  for(i = 0; i < 3; i++){
    pid = fork();
    if(pid < 0){
      printf(1, "fork failed\n");
      exit();
    }
    if(pid == 0){
      volatile int x = 0;
      int j;
      for(j = 0; j < 50000000; j++){
        x += j;
      }
      printf(1, "priority %d finished\n", priorities[i]);
      exit();
    }
    set_priority(pid, priorities[i]);
  }

  for(i = 0; i < 3; i++){
    wait();
  }
  printf(1, "Done\n");
  exit();
}
