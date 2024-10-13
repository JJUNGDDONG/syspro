#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i = 0, c=0, fd, currentLine = 1;
    int start, end;
    char saveText[10][100], buf;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            saveText[i][j] = 0;

        }
    }


    if ((fd = open(argv[1], O_RDWR)) == -1) {
        printf("file open erro\n");
        return 1;
    }

    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n') {
	    c++;
            saveText[currentLine - 1][i] = '\0';
            currentLine++;
            i = 0;
        } else {
            saveText[currentLine - 1][i++] = buf;

        }
    }
   
    for (int i = c-1; i >=0; i--) printf("%s\n", saveText[i]);
	
}
