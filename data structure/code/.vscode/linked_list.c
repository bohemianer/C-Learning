#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // pointer to the next node
};

void release(struct node *head) // release the memory of each node in the linked list
{
    struct node *temp = head;
    while (temp != NULL)
    {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
}

// write a function to insert a node at the end of the linked list
void endinsert_node(struct node *head, int data)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    temp->next = new_node;
}



void delete_node(struct node *head, int data)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            struct node *next = temp->next->next;
            free(temp->next);
            temp->next = next;
            break;
        }
        temp = temp->next;
    }
}

void intsert_node_at(struct node *head, int data, int index) 
{
    struct node *temp = head;
    int i = 0;
    while (temp->next != NULL)
    {
        if (i == index)
        {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = data;
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
        temp = temp->next;
        i++;
    }
}



void research_node(struct node *head, int data)
{
    struct node *temp = head;
    int i = 0;
    while (temp->next != NULL)
    {
        if (temp->data == data)
        {
            printf("The node is at index %d\n", i);
            break;
        }
        temp = temp->next;
        i++;
        if (temp->next == NULL && temp->data == data)
        {
            printf("The node is at index %d\n", i);
            break;
        }
    }
}









void print_node(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}




// int main()
// {
//     struct node *head = NULL; // pointer to the first node
//     struct node *second = NULL;
//     struct node *third = NULL;

//     head = (struct node *)malloc(sizeof(struct node)); // allocate 3 nodes in the heap
//     second = (struct node *)malloc(sizeof(struct node));
//     third = (struct node *)malloc(sizeof(struct node));

//     head->data = 1; // assign data in first node
//     head->next = second;

//     second->data = 2;
//     second->next = third;

//     third->data = 3;
//     third->next = NULL;

//    // insert a node at the end of the linked list
//     endinsert_node(head, 4);
//     endinsert_node(head, 5);
//     research_node(head, 5);
//     print_node(head);
//     delete_node(head, 2);
//     print_node(head);
//    // print_node(head);                  cx
//     release(head);

//     return 0;
// }