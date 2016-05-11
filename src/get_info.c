#include <myls_main.h>
int get_info(char **str, char *name, int how)
{
    int   res = OK;
    char *str_info = NULL;
    char  temp[SIZE];
    str_info = (char *)malloc(MAX);
    if (NULL == str_info) {
        printf("内存不足！");
        exit(NG);
    }/*end if*/

    memset(str_info, 0x0, MAX);

    *str = str_info;

    if (IS_DIR & how || NULL == name) {
        if (NULL == name) {
            memset(temp, 0x0, SIZE);
            sprintf(temp, "%s", LOCAL);
            name = temp;
        }
        res = get_dir_info(name, how);
        printf("\n");
    }else {
        res = get_file_info(&str_info, name, how);
    }/*end else*/

    return res;
}
