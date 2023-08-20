#include "main.h"
#include <stdint.h>

uint64_t _pow(uint64_t, uint64_t);
/**
* print_number - prints an integer to the stdout
* @n: integer to be printed
*
* Return: number of chars printed
*/
int64_t print_number(int64_t n)
{
	int64_t right_most_digit, n_cpy, char_count = 0;
	int radix_power = 0;

	if (n < 0)
	{
		_putchar('-');
		char_count++;
		n = -n;
	}
	n_cpy = n;
	while (n_cpy >= 10)
	{
		n_cpy =  n_cpy / 10;
		radix_power++;
	}
	char_count += radix_power;

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
uint64_t _pow(uint64_t b, uint64_t p)
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
uint64_t dec2bin(unsigned int n)
{
	int i = 0;
	uint64_t n_bin = 0;

	while (n != 0)
	{
		n_bin += n % 2 * _pow(10, i++);
		n /= 2;
	}

	return (n_bin);
}

/**
* dec2oct - converts decimal to octal
* @n: number in decimal
*
* Return: integer holding n in octal format
*/
int64_t dec2oct(unsigned int n)
{
	int i = 0;
	int64_t n_oct = 0;

	while (n != 0)
	{
		n_oct += n % 8 * _pow(10, i++);
		n /= 8;
	}

	return (n_oct);
}

/**
* dec2hex - converts decimal to hexadecimal
* @n: number in decimal
* @_case: case determinant for Hex
*
* Return: char pointer holding n in hexadecimal format
*/
char *dec2hex(uint64_t n, char _case)
{
	int rem;
	u_int64_t n_cpy = n;
	char *n_hex = n == 0 ? "0" : "", *tmp;

	_case = _case == 'x' ? 97 : 65;
	while (n != 0)
	{
		tmp = n_hex;
		n_hex = malloc(sizeof(char) * strlen(tmp) + 2);
		if (n_hex == NULL)
			return (NULL);
		rem = (n % 16);
		*(n_hex) = rem < 10 ? 48 + rem : _case + (rem - 10);
		*(n_hex + 1) = '\0';
		strcat(n_hex, tmp);
		n /= 16;
	}
	if (n_cpy >= 16)
		free(tmp);
	return (n_hex);
}

/**
* update_flag - updates flag
* @flags: structure of options
* @flag: character for flag
*/
void update_flag(option *flags, char flag)
{
	switch (flag)
	{
		case '+':
			flags->plus = 1;
			break;
		case '-':
			flags->minus = 1;
			break;
		case ' ':
			flags->space = 1;
			break;
		case '#':
			flags->hash = 1;
			break;
		case '0':
			flags->zero = 1;
			break;
		default:
			break;
	}
}

/**
* flag_set - checks if a flag is set
* @flags: structure of options
* @flag: character flag to check in options
*
* Return: 1 if flag is set, otherwise 0
*/
short flag_set(option *flags, char flag)
{
	switch (flag)
	{
		case '+':
			return (flags->plus);
		case '-':
			return (flags->minus);
		case ' ':
			return (flags->space);
		case '#':
			return (flags->hash);
		case '0':
			return (flags->zero);
		default:
			return (0);
	}
}

/**
* _is_spec - checks if a string is a spec
* @spec: string to check
*
* Return: 1 if is spec otherwise 0
*/
short _is_spec(char *spec)
{
	int i;
	const char *my_specs[] = SPECIFIERS;

	for (i = 0; i < SPEC_LENGTH; i++)
	{
		if (strcmp(spec, my_specs[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
