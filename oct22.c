#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  int c = fork();
  printf("%d %d\n", getpid(), c);
  return 0;
}
