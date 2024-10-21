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
    int num;
   printf("0: list of all books, 1: liost of available books ) ");
   scanf("%d", &num);
   
   struct book_information book;
   FILE *fp;
   if (argc != 2) { 
      printf("How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   if ((fp = fopen(argv[1], "rb")) == NULL ) {
      printf("Error Open File\n");
      return 2;
   }
   
   
   if (num == 0){
        printf("book_num\tbook_name\twriter\tyear\tloan_num\tloan_TorF\n");
       for(int i = 0; i < 4; i++){
		   fseek(fp, (i - start_num)*sizeof(book), SEEK_SET);
		   if((fread(&book, sizeof(book),1,fp))
            printf("%d\t%s\t%s\t%d\t%d\t%s\n", book.book_num, book.book_name, book.writer, book.year, book.loan_num, book.loan_TorF);  
		}
   }
   
}
