#include "main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
        int chars_printed, i;
        chars_printed = _printf("We're gonna have an %c grade (100%%) in the %s project%!", 'A', "0x11. C - printf");
        _printf("\n\n%d characters printed %i.\n", chars_printed, 987);
	_printf("Binary of %d is %b\n", 5, 5);
	for (i = 500; i <= 512; i++)
	{
		_printf("- Binary of %d: %b", i, i);
		_putchar('\n');
	}

	printf("INT_MAX: %d\tINT_MIN %d!\n", INT_MAX + 1, INT_MIN - 1);
	printf("INT_MAX: %i\tINT_MIN %i!\n", INT_MAX + 2, INT_MIN - 2);
	printf("UINT_MAX: %u\n", UINT_MAX);
	printf("UINT_MAX: %i\n", UINT_MAX);

        return (0);
}
