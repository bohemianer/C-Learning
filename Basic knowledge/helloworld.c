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
    // �� s1 ��ָ��Ľṹ�����ĳ�Ա���в��������磺
    printf("Name: %s, Age: %d, Score: %d\n", s1->name, s1->age, s1->score);
    // �ǵ��ڳ������ǰ�ͷŶ�̬������ڴ�ռ�
    free(s1);
    return 0;
}