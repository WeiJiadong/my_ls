#ifndef MYLS_MAIN_H_INCLUDED
#define MYLS_MAIN_H_INCLUDED

/*包含的头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

/*常量宏值定义*/
#define MAX     (4096)
#define SIZE    (128)
#define LOCAL   (".")
/*状态码的定义*/
#define OK      ( 0)
#define NG      (-1)

/*参数宏值定义*/
#define NONE    (1)
#define IS_l    (1<<1)
#define IS_a    (1<<2)
#define IS_R    (1<<3)
#define IS_u    (1<<4)
#define IS_h    (1<<5)
#define IS_DIR  (1<<10)

/*接口函数定义*/
void show_usage(char *proc);
int  myls_main(int argc, char *argv[]);
int  get_argopt(char *argstr);
int  get_type(int argc, char *argv[], char **name);
int  get_info(char **str, char *name, int how);
int  get_file_info(char **str, char *name, int how);
int  get_dir_info(char *name, int how);
void get_more_file_info(char **str, char *name, struct stat *buf, int how);
void print_info(char *str);

#endif/*MYLS_MAIN_H_INCLUDED*/
