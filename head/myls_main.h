#ifndef MYLS_MAIN_H_INCLUDED
#define MYLS_MAIN_H_INCLUDED

/*包含的头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*状态码的定义*/
#define OK     ( 0)
#define NG     (-1)

/*参数宏值*/
#define NONE    (1)
#define IS_l    (1<<1)
#define IS_a    (1<<2)
#define IS_R    (1<<3)
#define IS_u    (1<<4)
#define IS_h    (1<<5)
#define IS_DIR  (1<<31)

/*接口函数定义*/
void show_usage(char *proc);
int  myls_main(int argc, char *argv[]);
int  get_argopt(char *argstr);
int get_type(int argc, char *argv[], char **name);
#endif/*MYLS_MAIN_H_INCLUDED*/
