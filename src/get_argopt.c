#include <myls_main.h>
int get_argopt(char *argstr)
{
    int index = 0;
    int how   = NONE;

    if ('-' == argstr[index]) {
        for (index = 1; argstr[index]; ++index) {
            switch (argstr[index]) {
                case 'a':
                    how |= IS_a;
                    break;
                case 'l':
                    how |= IS_l;
                    break;
                case 'R':
                    how |= IS_R;
                    break;
                case 'u':
                    how |= IS_u;
                    break;
                case 'h':
                    how |= IS_h;
                    break;
                default:
                    how = NG;
                    break;
             }/*end switch*/
         }/*end for*/
    }/*end if*/

    return how;
}
