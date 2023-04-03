#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //定义栈的最大长度

typedef struct
{
    int data[MAXSIZE];
    int top; //栈顶指针
} SeqStack;                //定义顺序栈

void InitStack(SeqStack *S) //初始化栈
{
    S->top = -1;
}

int isempty(SeqStack *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int isfull(SeqStack *s)
{
    if(s->top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

 int push(SeqStack *s, int x)
{
    if(isfull(s))
        return 0;
    else
    {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

int Pop(SeqStack *s, int *x) //出栈 x为出栈元素
{
    if(isempty(s))
        return 0;
    else
    {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}


void GetTop(SeqStack *s, int *x) //取栈顶元素
{
    if(isempty(s))
    printf("Stack is empty!\n");
    else
    {
        *x = s->data[s->top];
        printf("Top is :%d\n",*x);
    }
}



// int main()
// {
//     SeqStack s;
//     int x;
//     InitStack(&s);
//     push(&s, 1);
//     push(&s, 2);
//     push(&s, 3);
//     push(&s, 4);
//   //  printf("Top is :%d\n",s.data[s.top]);
//     GetTop(&s, &x);

//     return 0;
// }