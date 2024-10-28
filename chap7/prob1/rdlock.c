#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "student.h"
#define PWD_MAX 200

int main(int argc, char *argv[])
{
    int fd, id;
    struct student record;
    struct flock lock;
	char pwd[PWD_MAX];

    if (argc < 2)
    {
	fprintf(stderr, "How to use : %s File \n", argv[0]);
	return 1;
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror(argv[1]);
        return 2;
    }

    printf("\nEnter StudentID to search : ");
    while (scanf("%d", &id) == 1)
    {
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = (id - START_ID) * sizeof(record);
        lock.l_len = sizeof(record);
        if (fcntl(fd, F_SETLKW, &lock) == -1)
        {
            getcwd(pwd, PWD_MAX);
			printf("%s\n", pwd);
            return 3;
        }
        lseek(fd, (id - START_ID) * sizeof(record), SEEK_SET);
        if ((read(fd, (char *)&record, sizeof(record)) > 0) && (record.id != 0))
            printf("Name : %s\t StuID : %d\t Score : % d\n ", record.name, record.id, record.score);
        else printf("No record %d \n", id);

lock.l_type = F_UNLCK;
fcntl(fd,F_SETLK, &lock); 
printf("\nEnter StudentID to search : ");
    }

    close(fd);
    exit(0);
}
