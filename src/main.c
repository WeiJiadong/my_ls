#include <stdio.h>
#include <myls_main.h>
int main(int argc, char *argv[])
{
    int res = NG;

    res = myls_main(argc, argv);
    if (NG == res) {
        show_usage(argv[0]);
    }/*end if*/

    return res;
}
