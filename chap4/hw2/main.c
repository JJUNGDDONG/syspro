#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int line_number = 1;
    int show_line_numbers = 0;  // 줄 번호를 출력할지 여부를 결정하는 변수
    int file_index = 1;         // 명령줄 인수에서 파일 시작 인덱스

    // 명령줄 인수가 없으면 표준 입력을 사용
    if (argc == 1) {
        fp = stdin;
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

    // 첫 번째 인자가 '-n'이면 줄 번호를 출력
    if (argv[1][0] == '-' && argv[1][1] == 'n') {
        show_line_numbers = 1;
        file_index = 2;  // 파일은 두 번째 인덱스부터
    }

    // 여러 파일을 처리하는 루프
    for (int i = file_index; i < argc; i++) {
        // 파일 열기
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            perror("파일을 열 수 없습니다.");
            continue;  // 다음 파일로 넘어감
        }

        // 첫 번째 문자를 읽는다
        c = getc(fp);

        // 줄 번호가 필요하면 첫 번째 줄 번호 출력
        if (show_line_numbers && c != EOF) {
            printf("%6d  ", line_number++);
        }

        // EOF가 나올 때까지 한 문자씩 출력
        while (c != EOF) {
            putc(c, stdout);
            if (c == '\n' && show_line_numbers && !feof(fp)) {
                printf("%6d  ", line_number++);
            }
            c = getc(fp);
        }

        // 파일 닫기
        fclose(fp);
    }

    return 0;
}
