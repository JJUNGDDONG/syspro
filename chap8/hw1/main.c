#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char **ptr;
    extern char **environ;
	if (argv[1][0] == '-' && argv[1][1] == 'e' && argv[2][0] != NULL){
		ptr = argv[2][0];
		printf("%s \n", *ptr);
	}
    if (argv[1][0] == '-' && argv[1][1] == 'e'){
        for (ptr = environ; *ptr != 0; ptr++) printf("%s \n", *ptr);
    }
exit(0);
}
