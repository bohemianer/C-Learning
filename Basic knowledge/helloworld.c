#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"  // ����ͷ�ļ�
#include "student_info.h"  // ����ͷ�ļ�



int main()
{

    char content[100];

    //дһ�����Զ�ȡ��������ѧ����Ϣ�ĳ��򣬷ֱ����ṹ�������У�Ȼ���������Ļ��
    student *students[3];
    for (int i = 0; i < 3; i++) {
        char name[20];
        int age;
        int score;
        printf("�������%d��ѧ�������������䣬�ɼ���", i + 1);
        scanf("%s %d %d", name, &age, &score);
        students[i] = create_student(name, age, score);
    }

    creat_file("student_info.txt");

    for (int i = 0; i < 3; i++) {
        sprintf(content, "%s %d %d\n", students[i]->name, students[i]->age, students[i]->score);
        append_file("student_info.txt", content);
        printf("ѧ����Ϣ��%s %d %d\n", students[i]->name, students[i]->age, students[i]->score);
    }

   fclose("student_info.txt");


}