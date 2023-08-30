#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
        int chars_printed;
        chars_printed = _printf("%r", "We're gonna have an %c grade (100%%) in the %s project%!", 'A', "0x11. C - printf");
        _printf("\n\n%d characters printed %i.\n", chars_printed, 987);

        return (0);
}
