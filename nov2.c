#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>

int sock;
int client;

void handler(int sig);

int main (int argc, char* argv[])
{
  sock = socket(AF_INET, SOCK_STREAM, 0);
  signal (SIGINT, handler);
  int i;
  char data[256] = ();
  int size;
  struct sockaddr_in my_address;
  my_address.sin_family = AF_INET;
  my_address.sin_port = htons(9999);
  my_address.sin_addr.s_addr = INADDR_ANY;

  if (sock == -1)
  {
    printf("Error creating socket. exiting\n");
    exit (1);
  }

  if (bind(sock, (struct sockaddr*)&my_address, sizeof(struct sockaddr_in)) == -1)
  {
    printf("Error binding the sock.\n");
    close(sock);
    exit(1);
  }

  if (listen(sock,10) == -1)
  {
    printf("Listen errored, exiting.\n");
  }

  return 0;
}

void handlers (int sig)
{
  close(sock);
  close(client);
  exit(0);
}
