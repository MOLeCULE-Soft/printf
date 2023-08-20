#include "main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	int *addr = malloc(sizeof(int) * 10);
	int i;

	for (i = 0; i < 10; i++)
	{
		_printf("_Address:%d = %p\n", i, addr + i);
		printf("Address:%d = %p\n", i , (void*)(addr + i));
	}
	_printf("%S\n", "Best\nSchool");

	_printf("_Address NULL: %p\n", NULL);
	printf("Address NULL: %p\n", NULL);
        return (0);
}
