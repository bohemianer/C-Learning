#include <stdio.h>
#include <stdlib.h>

typedef struct node  //define a node structure
{
    int data;
    struct node *next;
} node;


typedef struct Stack  //define a stack structure
{
    node* head;  //head pointer  node* represents a pointer to a node structure
    int size;    //stack size
} Stack;


void linkstack_init(Stack* s)    //initialize the stack
{
    s->head = NULL;
    s->size = 0;
}


int linkstack_is_empty(Stack* s)  // 
{
    if (s->size == 0)
        return 1;
    else
        return 0;
}


//push data into the stack
void linkstack_push(Stack* s, int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->head;
    s->head = new_node;
    s->size++;
}


int linkstack_pop(Stack* s)
{
    if (linkstack_is_empty(s))
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        node* temp = s->head;
        int data = temp->data;
        s->head = s->head->next;
        free(temp);
        s->size--;
        return data;
    }
}

int linkstack_top(Stack* s)
{
    if (linkstack_is_empty(s))
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return s->head->data;
    }
}

void linkstack_destroy(Stack* s)
{
    node* temp;
    while (s->head != NULL)
    {
        temp = s->head;
        s->head = s->head->next;
        free(temp);
    }
    s->size = 0;
}




// int main()
// {
//     Stack s;
//     linkstack_init(&s);
//     linkstack_push(&s, 1);
//     linkstack_push(&s, 2);

 
//     printf("%d\n", linkstack_pop(&s));

//     linkstack_destroy(&s);
//     return 0;
// }

 