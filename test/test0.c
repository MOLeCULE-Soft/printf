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
    _printf("%S", "No special character.");
    _printf("%S", "\n");
    _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
    _printf("Could you print some non-prntable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");
    _printf("");
    _printf("- What did you say?\n- %S\n- That's what I thought.\n", "");
    
    return (0);
}
