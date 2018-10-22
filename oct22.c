#include <stdio.h>
#include <unistd.h>

int bad_idea = 666;

int main(int argc, char* argv[])
{
  int c = fork();
  printf("%d %d\n", getpid(), c, bad_idea);
  return 0;
}
