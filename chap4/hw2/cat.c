#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int show_line_numbers = 0;
    int file_index = 1;

    if (argc == 1) {
        fp = stdin;
        int line_number = 1;
        if (show_line_numbers) {
            printf("%6d  ", line_number++);
        }
        while ((c = getc(fp)) != EOF) {
            putc(c, stdout);
            if (c == '\n' && show_line_numbers && !feof(fp)) {
                printf("%6d  ", line_number++);
            }
        }
        fclose(fp);
        return 0;
    }

    if (argv[1][0] == '-' && argv[1][1] == 'n') {
        show_line_numbers = 1;
        file_index = 2;
    }

    for (int i = file_index; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            perror("Cannot open file");
            continue;
        }

        int line_number = 1;

        if (show_line_numbers) {
            printf("%6d  ", line_number++);
        }
        while ((c = getc(fp)) != EOF) {
            putc(c, stdout);
            if (c == '\n' && show_line_numbers && !feof(fp)) {
                printf("%6d  ", line_number++);
            }
        }
        fclose(fp);

        if (i < argc - 1) {
            printf("\n");
        }
    }

    return 0;
}
