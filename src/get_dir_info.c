#include <myls_main.h>
int get_dir_info(char *name, int how)
{
    int res            = OK;
    DIR *dir           = NULL;
    struct dirent *ptr = NULL;
    char *result       = NULL;
    char path[SIZE];
    struct stat buf;

    res = stat(name, &buf);
    if (NG == res) {
        return res;
    }/*end if*/

    dir = opendir(name);
    if (NULL == dir) {
        res = NG;
        return res;
    }/*end if*/

    result = (char *)malloc(MAX);
    if (NULL == result) {
        printf("内存不足！");
        exit(NG);
    }/*end if*/

    if (how & IS_R) {
        printf("\n%s:\n", name);
    }

    while ((ptr = readdir(dir)) != NULL) {
        if ('.' == ptr->d_name[0]) {
            if (IS_a & how) {
                printf("%s :\n", ptr->d_name);
            }
        }else {
            memset(path, 0x0, SIZE);
            sprintf(path, "%s", name);
            if ('/' != path[strlen(path) - 1]) {
                path[strlen(path)] = '/';
                path[strlen(path) + 1] = '\0';
            }/*end if*/
            strcat(path, ptr->d_name);
            res = stat(path, &buf);
            if (NG == res) {
                return res;
            }/*end if*/

            if (!(S_ISDIR(buf.st_mode))) {   /*是文件*/
                memset(result, 0x0, MAX);
                get_file_info(&result, path, how);
                print_info(result);
            }else {
                if (how & IS_R) {
                    get_dir_info(path, how);
                }else {
                    printf("%s ", ptr->d_name);
                }/*end else*/
            }/*end else*/
        }/*end else*/
    }/*end while*/

    free(result);
    closedir(dir);

    return res;
}
