#include <stdio.h>
#include <stdlib.h>

typedef struct stringnode 
{
    char *str;
    struct stringnode *next;
} stringnode,*String;

void new_stringnode(stringnode **head, char *str) 
{
    stringnode *newnode = malloc(sizeof(stringnode));
    newnode->str = str;
    newnode->next = *head;
    *head = newnode;
}

void strInsert(stringnode **head,int pos, char *str) 
{
    stringnode *newnode = malloc(sizeof(stringnode));
    newnode->str = str;
    newnode->next = NULL;
    if (pos == 0) 
    {
        newnode->next = *head;
        *head = newnode;
    } 
    else 
    {
        stringnode *p = *head;
        int i = 0;
        while (p != NULL && i < pos - 1) 
        {
            p = p->next;
            i++;
        }
        if (p == NULL) 
        {
            printf("pos is out of range\n");
            return;

        }
        newnode->next = p->next;
        p->next = newnode;
        }
}

void strPrint(stringnode *head) 
{
    stringnode *p = head;
    while (p != NULL) 
    {
        printf("%s\t", p->str);
        p = p->next;
    }
    printf("\n");
}

// int main() 
// {
//     stringnode *head = NULL;
//     new_stringnode(&head, "hello");
//     new_stringnode(&head, "world");
//     new_stringnode(&head, "!");
//     strPrint(head);
//     strInsert(&head, 1, "insert");
//     strPrint(head);
//     return 0;
// }