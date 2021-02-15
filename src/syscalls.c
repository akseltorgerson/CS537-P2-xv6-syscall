#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv) {
  
  int mypid, i;
  int totalCalls = atoi(argv[1]);
  int goodCalls = atoi(argv[2]);
  int badCalls = totalCalls - goodCalls;

  if(argc < 3){
    printf(2, "usage: syscalls <number of expected syscalls> <number that should succeed>\n");
    exit();
  }

  // bad system calls first
  for (i = 0; i < badCalls; i++) {
    kill(-1);
  }

  // good system calls
  for (i = 0; i < goodCalls - 1; i++) {
    getpid();
  }

  mypid = getpid();
  printf(2, "%d %d\n", getnumsyscalls(mypid), getnumsyscallsgood(mypid));

  exit();
}
