#include <myls_main.h>
int  get_file_info(char **str, char *name, int how)
{
    int res = OK;

    if (IS_l && how) {
        //详细信息
    }else {
        strcpy(*str, name);
    }/*end else*/

    return res;
}
