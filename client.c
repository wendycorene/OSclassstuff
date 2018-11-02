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

void handler(int sig);

int main(int argc, char* argv[])
{
  sock = socket (AF_INET, SOCK_STREAM, 0);
  signal(SIGINT, handler);
  struct sockaddr_in server;
  struct hostent * host;
  char mesg[] = "hello world";
  char input[100];
  host = gethostbyname (argv[1]);

  if (!host)
  {
    printf("host not found\n");
    exit(1);
  }

  if (sock == -1)
  {
    printf("error creating socket. exiting\n");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(9999);
  memcpy(&server.sin_addr, host->h_addr, host->h_length);

  if (connect(sock, (const struct sockaddr*) &server, sizeof(struct sockaddr_in)) == -1)
  {
    printf("Error connecting the sock.\n");
    close(sock);
    exit(1);
  }

  char* input2 = calloc(100, sizeof(char));
  size_t read_in = 100;
  while (1)
  {
    getline(&input2, &read_in, stdin);
    write(sock, input2, strlen(input)+1);
    read(sock, input, 100);
    printf("client got: %s\n", input);
  }
  close(sock);

  return 0;
}

void handler (int sig)
{
  close(sock);
  exit(0);
}
