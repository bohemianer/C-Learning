// example.h
#ifndef FILE_H   // 头文件保护
#define FILE_H

// 函数原型
void creat_file(char *filename);
void read_file(char *filename);
void write_file(char *filename, char *content);
void merge_file(char *filename1, char *filename2);
void delete_file(char *filename);
void append_file(char *filename, char *content);




// // 结构体定义
// typedef struct {
//     int x;
//     int y;
// } Point;

#endif