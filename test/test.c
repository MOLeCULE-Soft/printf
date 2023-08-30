#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
        int chars_printed, i;
        chars_printed = _printf("We're gonna have an %c grade (100%%) in the %s project%!", 'A', "0x11. C - printf");
        _printf("\n\n%d characters printed %i.\n", chars_printed, 987);
	_printf("Binary of %d is %b\n", 5, 5);
	_printf("Octal of %d is %o\n", 345, 345);
	_printf("Hex of %d is %x\n", 26, 26);
	for (i = 0; i <= 100; i = i + 14)
	{
		_printf("- L_Hex of %d: %x", i, i);
		_printf("- U_Hex of %d: %X", i, i);
		_putchar('\n');
	}

	printf("INT_MAX: %d\tINT_MIN %d!\n", INT_MAX + 1, INT_MIN - 1);
	printf("INT_MAX: %i\tINT_MIN %i!\n", INT_MAX + 2, INT_MIN - 2);
	printf("UINT_MAX: %u\n", UINT_MAX);
	printf("UINT_MAX: %i\n", UINT_MAX);

    return (0);
}
