#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int pop(struct node **top) {

    struct node *temp = top;
    int pop_data = temp->data;
    printf("%d", pop_data);
    top = top->next;
    free(temp);
    return 0; 
}

int main() {
    float num;
   struct node *top = NULL;
    do {
        scanf("%f", &num);
        if (num > 0 && (int)num == num) { 
            push(&top ,(int)num);
        }
    } while (num > 0 && (int)num == num);
    printf("Print Stack\n");
    pop(&top);
    pop(&top);
    pop(&top);

    return 0;
}

