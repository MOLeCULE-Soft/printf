#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
    /*_printf("skfn%!\n");*/
    /* printf("% % % %\n"); */
    /*_printf("%ld\n\n", LONG_MIN);
    printf("\n\n%ld", LONG_MIN);*/

    /*_printf("%500ld + %*500ld = %ld\n", LONG_MIN, UCHAR_MAX, LONG_MAX, (LONG_MIN + LONG_MAX));
    printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));*/
    /*_printf("%5c\n", 'A');
    printf("%5c", 'A');*/
    _printf("%#o", UINT_MAX);

    return (0);
}
