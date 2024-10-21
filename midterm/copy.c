

#include <string.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
   char c;
   int num;
   FILE *fp1, *fp2;
   if (argc !=4) {
      fprintf(stderr,  "How to use: %s File1 File2\n", argv[0]);
      return 1;
   }
   if (argv[1][0] == '0') {
        fp1 = fopen(argv[2], "r");
        if (fp1 == NULL) {
            printf("File %s Open Error\n", argv[2]);
            return 2;
        }
        fp2 = fopen(argv[3], "w");
        while ((c = fgetc(fp1)) != EOF){
            fputc(c, fp2);
			printf("%c", c);
		}
			
        fclose(fp1);
        fclose(fp2);
    }
   if (argv[1][0] == '1') {
        fp1 = fopen(argv[2], "r");
        if (fp1 == NULL) {
            printf("File %s Open Error\n", argv[1]);
            return 2;
        }
        fp2 = fopen(argv[3], "w");
		while ((c = fgetc(fp1)) != EOF){
			if (c >= 'A' && c <= 'Z') c += 32;
			fputc(c, fp2);
			printf("%c", c);
		}

        fclose(fp1);
        fclose(fp2);
    }

   if (argv[1][0] == '2'){
	   fp1 = fopen(argv[2], "r");
	   if (fp1 == NULL) {
		   printf("File %s Open Error\n", argv[1]);
		   return 2;
	   }
	   fp2 = fopen(argv[3], "w");
	   while ((c = fgetc(fp1)) != EOF){
		   if (c >= 'a' && c <= 'z') c -= 32;
		   fputc(c, fp2);
		   printf("%c", c);
	   }
	   fclose(fp1);
	   fclose(fp2);
   }	   
   return 0;
}
