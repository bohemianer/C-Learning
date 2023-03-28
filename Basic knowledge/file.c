#include <stdio.h>
#include <stdlib.h>

// 写一个可以新建文件的程序，要求文件名由用户输入，并在参数传入
void creat_file(char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Can't create file %s, please check the path and filename.\r", filename);
    }
    else
    {
        printf("File %s created successfully\n", filename);
        // fprintf(fp, "This is a new file created by C language!");
    }
    fclose(fp);

}

//写一个可以读取文件的程序，要求文件名由用户输入，并在参数传入，读取文件内容
void read_file(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Can't open file %s, please check the path and filename.\r", filename);
    }
    else
    {
        printf("File %s opened successfully\n", filename);
        char ch;
        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
    }
    fclose(fp);

}

// 写一个可以删除文件的程序，要求文件名由用户输入，并在参数传入
void delete_file(char *filename)
{
    int ret = remove(filename);
    if (ret == 0)
    {
        printf("File %s deleted successfully\n", filename);
    }
    else
    {
        printf("Can't delete file %s, please check the path and filename.\r", filename);
    }

}

//写一个可以合并文件的程序，要求文件名由用户输入，并在参数传入，合并文件内容
void merge_file(char *filename1, char *filename2)
{
    FILE *fp1 = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "r");
    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Can't open file %s or %s, please check the path and filename.\r", filename1, filename2);
    }
    else
    {
        printf("File %s and %s opened successfully\n", filename1, filename2);
        char ch;
        while ((ch = fgetc(fp1)) != EOF)
        {
            printf("%c", ch);
        }
        while ((ch = fgetc(fp2)) != EOF)
        {
            printf("%c", ch);
        }
    }
    fclose(fp1);
    fclose(fp2);

}

//写一个可以往文件中写入内容的程序，要求文件名由用户输入，并在参数传入，写入文件内容也在参数传入
void write_file(char *filename, char *content)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Can't open file %s, please check the path and filename.\r", filename);
    }
    else
    {
        printf("File %s opened successfully\n", filename);
        fprintf(fp, content);
    }
    fclose(fp);

}

// 写一个往文件中追加内容的程序，要求文件名由用户输入，并在参数传入，追加文件内容也在参数传入
void append_file(char *filename, char *content)
{
    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("Can't open file %s, please check the path and filename.\r", filename);
    }
    else
    {
        printf("File %s opened successfully\n", filename);
        fprintf(fp, content);
    }
    fclose(fp);

}