#include <myls_main.h>
int myls_main(int argc, char *argv[])
{
    int res    = OK;
    int how    = NONE;
    int index  = 0;
    char *name = NULL;

    for (index = 1; index < argc; ++index) {
        res = get_argopt(argv[index]);
        if (NG == res) {
            printf("参数输入有误！\n");
            break;
        }/*end if*/
        how |= res;
    }/*end for*/

    if (NG == res) {
        return res;
    }/*end if*/

    res = get_type(argc, argv, &name);
    if (NG == res) {
        return res;
    }/*end if*/


    return res;
}
