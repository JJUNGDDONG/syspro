#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
/* 디렉터리 내의 파일 이름들을 리스트한다. */
int main(int argc, char **argv)
{
   DIR *dp;
   char *dir;
   struct dirent *d;
   struct stat st;
   char path[BUFSIZ+1];

   if (argc == 1)
      dir = ".";
   else dir = argv[1];

   if ((dp = opendir(dir)) == NULL)
      perror(dir);

   while ((d = readdir(dp)) != NULL) 
      printf("%s %lu \n", d->d_name, d->d_ino);

   closedir(dp);
   return 0;
 }

