#include <stdio.h>

// дһ�������½��ļ��ĳ���Ҫ���ļ������û�����
int creat_file();


int main()
{
    creat_file();
    return 0;
}


int creat_file()
{
    char filename[100];
    printf("Please input the filename: ");
    scanf("%s", filename);
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
    return 0;
}

