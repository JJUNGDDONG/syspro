#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[ ])
{
   FILE *fp;
   fp = fopen(argv[1], "r");
   if (fp == NULL) perror("error");   
   if (symlink(argv[1], argv[2]) == -1) {
      exit(1);
   }
   exit(0);
}

