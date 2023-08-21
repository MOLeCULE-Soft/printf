#include "main.h"

/**
* base_conv - converts decimal to specified base
* @n: in decimal
* @buffer: holds converted chars
* @base: to be converted to
*
* Description: Only works bases 2 to 10
* Return: pointer to first char in buffer
*/
char *base_conv(int64_t n, short base, char *buffer)
{
	short tmp_cur = CONV_BUFFER_SIZE - 1;

	memset(buffer, 0, CONV_BUFFER_SIZE);
	buffer[tmp_cur--] = '\0';
	if (n < 0)
		n = -n;
	if (n < base)
	{
		buffer[tmp_cur--] = n + '0';
	}
	else
	{
		while (n != 0)
		{
			buffer[tmp_cur--] = n % base + '0';
			n /= base;
		}
	}
	return (buffer + tmp_cur + 1);
}

/**
* dec2hex - converts decimal to hexadecimal
* @n: in decimal
* @_case: determinant for hex
* @buffer: holds converted hex chars
*
* Return: pointer to first char in buffer
*/
char *dec2hex(uint64_t n, char _case, char *buffer)
{
	short rem, tmp_cur = CONV_BUFFER_SIZE - 1;

	memset(buffer, 0, CONV_BUFFER_SIZE);
	buffer[tmp_cur--] = '\0';
	if (n < 10)
	{
		buffer[tmp_cur--] = n + '0';
	}
	else
	{
		_case = _case == 'x' ? 'a' : 'A';
		while (n != 0)
		{
			rem = (n % 16);
			buffer[tmp_cur--] = rem < 10 ? rem + '0' : (rem - 10) + _case;
			n /= 16;
		}
	}
	return (buffer + tmp_cur + 1);
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
