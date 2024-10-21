#include <stdio.h> 
#define MAX 24
#define start_num 1

struct book_information{
    int book_num;
    char book_name[MAX];
    char writer[MAX];
    int year;
    int loan_num;
    char loan_TorF[MAX];
};

int main(int argc, char* argv[])  
{ 
   struct book_information book;
   FILE *fp;

   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n",argv[0]);
      return 1; 
   }

   fp = fopen(argv[1], "wb");
   printf("%s %s %s %s %s %s\n", "book_num", "book_name", "writer", "year", "loan_num", "loan_TorF"); 
   while (scanf("%d %s %s %d %d %s", &book.book_num, book.book_name, book.writer, &book.year, &book.loan_num, book.loan_TorF) == 6) 
      fwrite(&book, sizeof(book), 1, fp);

   fclose(fp);
   return 0;
} 
