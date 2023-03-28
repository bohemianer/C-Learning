#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    int age;
    int score;
}student;

student *create_student(char *name, int age, int score)
{
    student *p = (student *)malloc(sizeof(student));
    strcpy(p->name, name);
    p->age = age;
    p->score = score;
    return p;
};

int main()
{
    student *s1;
    s1 = create_student("Tom", 20, 90);
    // 对 s1 所指向的结构体对象的成员进行操作，例如：
    printf("Name: %s, Age: %d, Score: %d\n", s1->name, s1->age, s1->score);
    // 记得在程序结束前释放动态分配的内存空间
    free(s1);
    return 0;
}