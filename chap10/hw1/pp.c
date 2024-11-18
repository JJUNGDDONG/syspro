#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
void push(struct node *top, int data){
	struct node *node = (struct node*) malloc(sizeof(struct node));
	node -> data = data;
	node -> next = top;
}
int pop(struct node *top){
	if(top == NULL){
		printf("under flow\n");
		return 1;
	}
	struct node *node  = top;
	int data = node -> data;
	top = node -> next;
	free(node);
	return data;
}

int show(struct node *top){
	struct node *cur = top;
	printf("top end\n");
	while (cur != NULL){
		printf("%d\n", pop(cur));
	}
	printf("lowest top\n");
}
int main(){
	int num;
	for(int i = 0; i < 3; i++){
		scanf("%d", &num);
		push(struct node *top, num);
	
	}
	show(node);
	return 0;
}
