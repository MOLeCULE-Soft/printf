#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	int len, len2;

	len = _printf("%*c", 6, 0);
	len2 = printf("%*c", 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
