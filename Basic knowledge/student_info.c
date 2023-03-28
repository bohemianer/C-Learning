#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_info.h"  // 引入头文件


student *create_student(char *name, int age, int score) {
    student *p = (student *) malloc(sizeof(student));
    strcpy(p->name, name);
    p->age = age;
    p->score = score;
    return p;
}
