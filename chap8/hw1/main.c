#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
int main(int argc, char *argv[])
{
	char **ptr;
	extern char **environ;
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'e'){
		for(ptr = environ; *ptr != 0; ptr++) printf("%s \n", *ptr);
	}
	else if (argc == 3 && strcmp(argv[1], "-e") == 0) {
        char *value = getenv(argv[2]);
        if (value) {
            printf("%s=%s\n", argv[2], value);
        } else {
            printf("fail");
        }
   	}

	if(argc == 2&& argv[1][0] == '-' && argv[1][1] == 'i'){
		printf("my process number : [%d]\n", getpid());
	}
	if(argc == 2&& argv[1][0] == '-' && argv[1][1] == 'p'){
		printf("my parent's process number :  [%d]\n", getppid());
	}

	if (argc == 2&& argv[1][0] == '-' && argv[1][1] == 'u'){
		printf("My Realistic User ID : %d(%s)\n", getuid(),  getpwuid(getuid())->pw_name);
		printf("My Valid User ID : %d(%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
	}

	if(argc == 2&&argv[1][0] == '-' && argv[1][1] == 'g'){
		printf("My Realistic Group ID : %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
		printf("My Valid Group ID : %d(%s)\n", getegid(), getgrgid(getegid())->gr_name);
	}
	exit(0);
}
