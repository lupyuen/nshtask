// From ChatGPT, doesn't compile
#include <nuttx/sched.h>
#include <nuttx/nsh.h>

int nsh_main(int argc, char *argv[]);

int nsh_task(int argc, char *argv[])
{
  nsh_main(argc, argv);
  return 0;
}

int main(int argc, char *argv[])
{
  pid_t pid = task_create("nsh", 100, 2048, nsh_task, (FAR char * const *)argv);
  if (pid < 0) {
    printf("Error creating task\n");
  } else {
    task_start(pid);
  }
  return 0;
}
