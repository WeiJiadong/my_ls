#include <myls_main.h>
void get_more_file_info(char **str, char *name, struct stat *buf, int how)
{
    int   res    = OK;
    int   index  = 0;
    char *result = NULL;
    char  temp[SIZE];

    result = *str;
    strcpy(result, "----------");
    if (S_ISDIR(buf->st_mode)) {
        result[index] = 'd';
    }/*end if*/
    if (S_ISCHR(buf->st_mode)) {
        result[index] = 'c';
    }/*end if*/
    if (S_ISBLK(buf->st_mode)) {
        result[index] = 'b';
    }/*end if*/
    index++;

    /*判断权限*/
    if (buf->st_mode & S_IRUSR) {
        result[index] = 'r';
    }/*end if*/
    index++;
    if (buf->st_mode & S_IWUSR) {
        result[index] = 'w';
    }/*end if*/
    index++;
    if (buf->st_mode & S_IXUSR) {
        result[index] = 'x';
    }/*end if*/
    index++;
    if (buf->st_mode & S_IRGRP) {
        result[index] = 'r';
    }/*end if*/
    index++;
    if (buf->st_mode & S_IWGRP) {
        result[index] = 'w';
    }/*end if*/
    index++;
    if (buf->st_mode & S_IXGRP) {
        result[index++] = 'x';
    }/*end if*/
    index++;
    if (buf->st_mode & S_IROTH) {
        result[index++] = 'r';
    }/*end if*/
    index++;
    if (buf->st_mode & S_IWOTH) {
        result[index++] = 'w';
    }/*end if*/
    index++;
    if (buf->st_mode & S_IXOTH) {
        result[index++] = 'x';
    }/*end if*/
    index++;
    memset(temp, 0x0, SIZE);
    sprintf(temp, " %d ", (int)buf->st_nlink);
    strcat(result, temp);
    strcat(result, getpwuid(buf->st_uid)->pw_name);
    sprintf(temp, " %s ", getgrgid(buf->st_uid)->gr_name);
    strcat(result, temp);
    sprintf(temp, "%ld ", (long)buf->st_size);
    strcat(result, temp);
    if (IS_u & how) {
        ctime_r(&buf->st_atime, temp);
    }else {
        ctime_r(&buf->st_mtime, temp);
    }/*end else*/
    temp[strlen(temp) - 1] = '\0';
    strcat(result, temp);
    sprintf(temp, " %s", name);
    strcat(result, temp);
    result[strlen(result)] = '\n';
    result[strlen(result) + 1] = '\0';
}
