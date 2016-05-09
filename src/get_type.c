#include <myls_main.h>

int get_type(int argc, char *argv[], char **name)
{
    int index = 0;
    int count = 0;
    int res   = 0;
    int flag  = OK;
    struct stat buf;

    for (index = 1; index < argc; ++index) {
        if (argv[index][0] != '-') {
            if (count) {
                printf("目标参数过多!\n");
                flag = NG;
                break;
            }/*end if*/
            count++;
            *name = argv[index];
        }/*end if*/
    }/*end for*/

    if (NG == flag || NULL == *name) {
        return flag;
    }/*end if*/

    res = stat(*name, &buf);
    if (NG == res) {
        return res;
    }/*end if*/

    if (S_ISDIR(buf.st_mode)) {
        flag = IS_DIR;
    }

    return flag;
}
