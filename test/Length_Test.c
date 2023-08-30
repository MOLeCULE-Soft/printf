#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	_printf("\n1.C: %d : %ld : %hd", INT_MAX, INT_MAX, INT_MAX);
	printf("\n1.O %d : %ld : %hd", INT_MAX, INT_MAX, INT_MAX);
	_printf("\n2.C: %d : %ld : %hd", UINT_MAX, UINT_MAX, UINT_MAX);
	printf("\n2.O: %d : %ld : %hd", UINT_MAX, UINT_MAX, UINT_MAX);
	_printf("\n3.C: %i : %li : %hi", INT_MAX, INT_MAX, INT_MAX);
	printf("\n3.O: %i : %li : %hi", INT_MAX, INT_MAX, INT_MAX);
	_printf("\n4.C: %i : %li : %hi", UINT_MAX, UINT_MAX, UINT_MAX);
	printf("\n4.O: %i : %li : %hi", UINT_MAX, UINT_MAX, UINT_MAX);
	return (0);
}
