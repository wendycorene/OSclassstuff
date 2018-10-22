#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int bad_idea = 666;

int main(int argc, char* argv[])
{
  //srand(time(NULL));
  int c = fork();
  srand(getpid());
  bad_idea += rand() % 100;
  printf("%d %d %d\n", getpid(), c, bad_idea);
  return 0;
}
