#include "main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	int i;
	char s[2];

	s[1] = '\0';
	for (i = -2; i < 130; i++)
	{
		s[0] = i;
		_printf("Char Hex:[%d, %c] = %S\n", i, i, s);
	}
	_printf("%S\n", "Best\nSchool");
        return (0);
}
