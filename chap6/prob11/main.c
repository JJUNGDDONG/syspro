#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*, int, int);

int main(int argc, char **argv) {
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];
    int show_inode = 0, exclude_dot = 0, quote_name = 0;

    // 옵션 처리
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) show_inode = 1;
        else if (strcmp(argv[i], "-p") == 0) exclude_dot = 1;
        else if (strcmp(argv[i], "-Q") == 0) quote_name = 1;
        else dir = argv[i];
    }

    if (argc == 1 || dir == NULL) 
        dir = ".";

    if ((dp = opendir(dir)) == NULL) 
        perror(dir);

    while ((d = readdir(dp)) != NULL) {
        // -p 옵션으로 .과 .. 디렉토리 제외
        if (exclude_dot && (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0))
            continue;

        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0)
            perror(path);
        else
            printStat(path, d->d_name, &st, show_inode, quote_name);
    }

    closedir(dp);
    exit(0);
}

void printStat(char *pathname, char *file, struct stat *st, int show_inode, int quote_name) {
    if (show_inode) 
        printf("%8ld ", st->st_ino);

    printf("%5ld ", st->st_blocks);
    printf("%c%s ", type(st->st_mode), perm(st->st_mode));
    printf("%3ld ", st->st_nlink);
    printf("%s %s ", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
    printf("%9ld ", st->st_size);
    printf("%.12s ", ctime(&st->st_mtime)+4);

    // -Q 옵션으로 파일명을 큰따옴표로 출력
    if (quote_name)
        printf("\"%s\"\n", file);
    else
        printf("%s\n", file);
}

char type(mode_t mode) {
    if (S_ISREG(mode)) return('-');
    if (S_ISDIR(mode)) return('d');
    if (S_ISCHR(mode)) return('c');
    if (S_ISBLK(mode)) return('b');
    if (S_ISLNK(mode)) return('l');
    if (S_ISFIFO(mode)) return('p');
    if (S_ISSOCK(mode)) return('s');
    return('?');
}

char* perm(mode_t mode) {
    static char perms[10];
    strcpy(perms, "---------");

    for (int i = 0; i < 3; i++) {
        if (mode & (S_IRUSR >> i*3)) perms[i*3] = 'r';
        if (mode & (S_IWUSR >> i*3)) perms[i*3+1] = 'w';
        if (mode & (S_IXUSR >> i*3)) perms[i*3+2] = 'x';
    }
    return(perms);
}

