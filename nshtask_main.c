// How to create a NuttX Task for NSH Shell
#include <nuttx/sched.h>
#include <stdio.h>
#include "nshlib/nshlib.h"

int main(int argc, char *argv[])
{
  pid_t pid = task_create(
    "nsh",     // Task Name
    100,       // Task Priority
    CONFIG_DEFAULT_TASK_STACKSIZE,  // Task Stack Size
    nsh_consolemain,  // Task Function
    NULL  // Task Arguments
  );
  if (pid < 0) {
    printf("Error creating task\n");
  }
  return 0;
}
