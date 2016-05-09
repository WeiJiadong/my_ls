#include <myls_main.h>
int get_info(char **str, char *name, int how)
{
    int   res = OK;
    char *str_info = NULL;

    str_info = (char *)malloc(MAX);
    if (str_info) {
        printf("内存不足！");
        exit(NG);
    }/*end if*/

    str = &str_info;

    if (IS_DIR && how) {
        res = get_dir_info(str, name, how);
    }else {
        res = get_file_info(str, name, how);
    }/*end else*/

    return res;
}
