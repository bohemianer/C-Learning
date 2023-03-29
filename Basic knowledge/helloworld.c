#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"  
#include "student_info.h"  



int main()
{

    char content[100];

   
    student *students[3];
    for (int i = 0; i < 3; i++) {
        char name[20];
        int age;
        int score;
        printf("please input the %dth students information", i + 1);
        scanf("%s %d %d", name, &age, &score);
        students[i] = create_student(name, age, score);
    }

    creat_file("student_info.txt");

    for (int i = 0; i < 3; i++) 
    {
        sprintf(content, "%s %d %d\n", students[i]->name, students[i]->age, students[i]->score);
        append_file("student_info.txt", content);
        printf("name:%s age:%d score:%d\n", students[i]->name, students[i]->age, students[i]->score);
    }

   fclose("student_info.txt");


}
