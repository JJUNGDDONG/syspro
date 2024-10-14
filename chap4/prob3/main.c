#include  <stdio.h>
#define MAX 80

int main(int argc,char *argv[]){
	FILE *fp;
	int line = 0;
	char buffer[MAX];

	if (argc != 2) {
		fprintf(stderr, "how to use : line FileName\n");
		return 1;
	}
	if ((fp = fopen(argv[1],"r")) ==NULL){
		fprintf(stderr, "erro open file\n");
		return 2;
	}
	while (fgets(buffer, MAX, fp) != NULL) { 
		line++;
		printf("%3d %s", line, buffer); 
    }
	return 0;
}
