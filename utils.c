#include "main.h"
#include <stdint.h>

int _pow(int, int);
/**
* print_number - prints an integer to the stdout
* @n: integer to be printed
*/
int64_t print_number(int n)
{
	int64_t right_most_digit, n_cpy, char_count;
	int radix_power = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	n_cpy = n;
	while (n_cpy >= 10)
	{
		n_cpy =  n_cpy / 10;
		radix_power++;
	}
	char_count = radix_power;

	while (radix_power >= 0)
	{
		right_most_digit = n / _pow(10, radix_power--) % 10;
		_putchar(right_most_digit + 48);
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

/**
* dec2bin - converts decimal to binary
* @n: number in decimal
*
* Return: integer holding n in binary format
*/
int dec2bin(unsigned int n)
{
	int i = 0;
	unsigned int n_bin = 0;

	while (n != 0)
	{
		n_bin += n % 2 * _pow(10, i++);
		n /= 2;
	}

	return (n_bin);
}
