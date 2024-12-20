#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct stack_top {
    struct node *top;
};

void init(struct stack_top *s) {
    s->top = NULL;
}

int empty(struct stack_top *s) {
    return (s->top == NULL);
}

void push(struct stack_top *s, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = s->top;
    s->top = temp;
}

void pop_all(struct stack_top *s) {
    while (!empty(s)) {
        struct node *temp = s->top;
        int data = temp->data;
        s->top = s->top->next;
        free(temp);
        printf("%d\n", data);
    }
}

int is_valid_integer(const char *str, int *value) {
    char *endptr;
    *value = (int)strtol(str, &endptr, 10);
    return *endptr == '\0';
}

int main() {
    char input[100];
    int num;
    struct stack_top s;
    init(&s);

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        if (is_valid_integer(input, &num) && num > 0) {
            push(&s, num);
        } else {
	    printf("Print stack\n");
            pop_all(&s);
	    break;
        }
    }

    return 0;
}

