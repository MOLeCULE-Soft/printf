#include "main.h"
#include <stdint.h>

int _pow(int, int);
/**
* print_number - prints an integer to the stdout
* @n: integer to be printed
*/
int64_t print_number(int n)
{
	int64_t x, m, l, char_count;
	int radix_power = 0;

	l = n;
	if (l == 0)
	{
		_putchar(l + 48);
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		l = -l;
	}
	m = l;
	while (m >= 10)
	{
		m =  m / 10;
		radix_power++;
	}
	char_count = radix_power;
	/*
	* Using log below works, but for the
	* compilation flags used for the task
	* it cannot work with using -lm flag
	*/
	/* radix_power = log((double)abs(n)); */

	while (radix_power >= 0)
	{
		x = l / _pow(10, radix_power--);
		_putchar(x % 10 + 48);
	}
	return (char_count + 1);
}


/**
* _pow - raises an integer to the power of another
* @b: base
* @p: power
*
* Return: b^p
*/
int _pow(int b, int p)
{
	if (p == 0)
		return (1);
	else if (p == 1)
		return (b);

	while (p > 0)
		return (b * _pow(b, --p));

	return (-1);
}
