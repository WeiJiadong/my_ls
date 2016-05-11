#include <myls_main.h>
int  get_file_info(char **str, char *name, int how)
{
    int res = OK;
    struct stat buf;

    if (IS_l & how) {
        res = stat(name, &buf);
        if (NG == res) {
            return res;
        }/*end if*/

        get_more_file_info(str, name, &buf, how);
    }else {
        strcpy(*str, name);
    }/*end else*/

    return res;
}
