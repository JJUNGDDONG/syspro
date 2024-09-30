#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINES 1000  

char lines[MAXLINES][MAXLINE];  
int lengths[MAXLINES];          
int line_count = 0;             

int main() {
    int len;
    while (fgets(lines[line_count], MAXLINE, stdin) != NULL) {
        len = strlen(lines[line_count]);

        if (lines[line_count][len - 1] == '\n') {
            lines[line_count][len - 1] = '\0';
            len--;
        }

        lengths[line_count] = len;
        line_count++;
    }

    for (int i = 0; i < line_count - 1; i++) {
        for (int j = i + 1; j < line_count; j++) {
            if (lengths[i] < lengths[j]) {
                char temp[MAXLINE];
                int temp_len;

                copy(lines[i], temp);
                copy(lines[j], lines[i]);
                copy(temp, lines[j]);

                temp_len = lengths[i];
                lengths[i] = lengths[j];
                lengths[j] = temp_len;
            }
        }
    }

    for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

