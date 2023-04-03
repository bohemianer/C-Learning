#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;


typedef struct Stack {
    Node* head;
    Node* rear;
} queue;

queue *que_init()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->rear = NULL;
    return q;
}

void que_push(queue *q, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->head == NULL) 
    {
        q->head = new_node;
        q->rear = new_node;
    } 
    else 
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

void que_pop(queue *q)
{
    if (q->head == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node *temp = q->head;
    q->head = q->head->next;
    free(temp);
}
void print_queue(queue *q)
{
    Node *temp = q->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// int main()
// {
//     queue *q = que_init();
//     que_push(q, 1);
//     que_push(q, 2);
//     que_push(q, 3);
//     que_push(q, 4);
//     que_push(q, 5);
//     que_pop(q);
//     que_pop(q);
//     print_queue(q);

//     return 0;
// }