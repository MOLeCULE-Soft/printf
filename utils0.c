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
	int16_t mod;

	bzero(buffer, CONV_BUFFER_SIZE);
	buffer[tmp_cur--] = '\0';
	if (n < base && n > -base)
	{
		buffer[tmp_cur--] = (n < 0 ? -n : n) + '0';
	}
	else
	{
		while (n != 0)
		{
			mod = n % base;
			mod = mod < 0 ? -mod : mod;
			buffer[tmp_cur--] = mod + '0';
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

	bzero(buffer, CONV_BUFFER_SIZE);
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
* @flags: structure of flags
* @flag: flag to be updated
*/
void update_flag(opt_flag *flags, char flag)
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
* update_length - updates lengths
* @lengths: structure of lengths
* @length: length to be updated
*/
void update_length(opt_length *lengths, char length)
{
	switch (length)
	{
		case 'h':
			lengths->_short = 1;
			break;
		case 'l':
			lengths->_long = 1;
			break;
		default:
			break;
	}
}

/**
* init_options - initializes options to 0
* @options: structure of options
*/
void init_options(option *options)
{
	options->flag = 0;
	options->width = 0;
	options->precision = 0;
	options->length = 0;
	options->conversion = 0;
}
