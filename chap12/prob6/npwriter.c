#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXLINE 100

#include <sys/types.h>
#include <sys/stat.h>
int mkfifo(const char *pathname, mode_t mode);

int main(){
	int fd, length, i;
    char message[MAXLINE];
    sprintf(message, "Hello from PID %d", getpid());
    length = strlen(message)+1;
	do {
      fd = open("myPipe", O_WRONLY);
      if (fd == -1) sleep(1);
   } while (fd == -1);

   for (i = 0; i <= 3; i++) {
      write(fd, message, length);
      sleep(3);
   }
   close(fd);
   return 0;
}


