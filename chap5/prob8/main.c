#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i = 0, fd, currentLine = 1;
    int start, end;
    char saveText[10][100], buf;
    char input[50], *tok1, *tok2;
    printf("input >> ");
    scanf("%s", input);


    if ((fd = open(argv[1], O_RDWR)) == -1) {
        printf("file open erro\n");
        return 1;
    }

    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n') {
            saveText[currentLine - 1][i] = '\0';
            currentLine++;
            i = 0;
        } else {
            saveText[currentLine - 1][i++] = buf;

        }
    }
        if ((strchr(input,',')==0) && (strchr(input,'-')==0) && (strchr(input,'*')==0)){
                int num = atoi(input)-1;
                printf("%s\n", saveText[num]);
        }


    if (strcmp(input, "*") == 0) {
                for (int k = 0; k < currentLine - 1; k++) {
                printf("%s\n", saveText[k]);
        }
    }
        if (strchr(input, '-')){
         char* tok;
         tok = strtok(input, "-");
         tok1 = tok;
         tok = strtok(NULL, "\0");
         tok2 = tok;
         start = atoi(tok1);
         end = atoi(tok2);
         for (int i = start; i <= end; i++){
                printf("%s\n", saveText[i-1]);
         }

    }
       if (strchr(input, ',')) {
        char* tok;
        int i = 0;
        int arr[10] = {0};


        tok = strtok(input, ",");
        while (tok != NULL && i < 10) {
            arr[i] = atoi(tok);
            i++;
            tok = strtok(NULL, ",");
        }
        for(int n = 0; n < i; n++){
                printf("%s\n", saveText[arr[n]-1]);
        }
        }


        close(fd);
}

