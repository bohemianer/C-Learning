#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"  // 引入头文件
#include "student_info.h"  // 引入头文件



int main()
{

    char content[100];

    //写一个可以读取输入三个学生信息的程序，分别存入结构体数组中，然后输出到屏幕上
    student *students[3];
    for (int i = 0; i < 3; i++) {
        char name[20];
        int age;
        int score;
        printf("请输入第%d个学生的姓名，年龄，成绩：", i + 1);
        scanf("%s %d %d", name, &age, &score);
        students[i] = create_student(name, age, score);
    }

    creat_file("student_info.txt");

    for (int i = 0; i < 3; i++) {
        sprintf(content, "%s %d %d\n", students[i]->name, students[i]->age, students[i]->score);
        append_file("student_info.txt", content);
        printf("学生信息：%s %d %d\n", students[i]->name, students[i]->age, students[i]->score);
    }

   fclose("student_info.txt");


}