#include <myls_main.h>
int myls_main(int argc, char *argv[])
{
    int res    = OK;
    int how    = NONE;
    int index  = 0;
    char *name = NULL;
    char *str  = NULL;

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
        printf("文件或者文件夹不存在！\n");
        return res;
    }/*end if*/

    how |= res;

    res = get_info(&str, name, how);
    if (NG == res) {
        return res;
    }/*end if*/

    print_info(str);
    printf("\n");
    free(str);

    return res;
}
