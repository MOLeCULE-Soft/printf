#include "main.h"
#include <stdio.h>
int main(void)
{
        int chars_printed;
        chars_printed = _printf("We're gonna have an %c grade (100%%) in the %s project%!", 'A', "0x11. C - printf");
        _printf("\n\n%d characters printed %i.\n", 678, 987);
        return (0);
}
