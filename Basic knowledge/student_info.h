// example.h
#ifndef STUDENT_INFO_H   // 头文件保护
#define STUDENT_INFO_H

// 函数原型



typedef struct {
    char name[20];
    int age;
    int score;
} student;


student *create_student(char *name, int age, int score);


#endif