#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void init(struct queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

int empty(struct queue *q) {
    return (q->head == NULL);
}

void addq(struct queue *q, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (q->tail != NULL) {
        q->tail->next = temp;
    }
    q->tail = temp;
    if (q->head == NULL) {
        q->head = temp;
    }
}

void delete_all(struct queue *q) {
    while (!empty(q)) {
        struct node *temp = q->head;
        int data = temp->data;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
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
    struct queue q;
    init(&q);

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        if (is_valid_integer(input, &num) && num > 0) {
            addq(&q, num);
        } else {
	    printf("print queue\n");
            delete_all(&q);
	    break;
        }
    }

    return 0;
}

