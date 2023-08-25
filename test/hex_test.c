#include "main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	unsigned int i;

	for (i = INT_MAX - USHRT_MAX; i <= INT_MAX; i++)
	{
		_printf("Address:%d = %p\n", i, i);
		/*printf("Address:%d = %p\n", i , i);*/
	}
        return (0);
}
