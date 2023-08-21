#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...);
/**
* _printf - prints formatted string
* @format: format specifications or option
* ...: [ARGUMENTS], varaible params
*
* Return: count of characters printed
* Example:
*    _printf("%c grade (100%%) in %s", 'A', "0x11"); --> A grade (100%) in 0x11
*/
int _printf(const char *format, ...)
{
	unsigned long int i = 0, j;
	va_list var_arg_list;
	char *s_param, *tmp_hex;
	int int_param, count = 0;
	uint64_t u_int_param;
	void *void_param;

	va_start(var_arg_list, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					int_param = va_arg(var_arg_list, int);
					_putchar(int_param);
					count++;
					i++;
					break;
				case 's':
				case 'x':
				case 'X':
				case 'S':
				case 'p':
					if (format[i + 1] == 'x' || format[i + 1] == 'X')
					{
						u_int_param = va_arg(var_arg_list, unsigned int);
						s_param = dec2hex(u_int_param, format[i + 1]);
					}
					else if (format[i + 1] == 'p')
					{
						void_param = va_arg(var_arg_list, void *);
						if (void_param == NULL)
						{
							s_param = "(nil)";
						}
						else
						{
							s_param = dec2hex(u_int_param, 'x');
							_putchar('0');
							_putchar('x');
						}
					}
					else
					{
						s_param = va_arg(var_arg_list, char *);
					}
					s_param = s_param == NULL ? "(null)" : s_param;
					j = 0;
					while (s_param[j] != '\0')
					{
						if (format[i + 1] == 'S' && !isprint(s_param[j]))
						{
							tmp_hex = dec2hex(s_param[j], 'X');
							_putchar('\\');
							_putchar('x');
							if (s_param[j] < 16)
							{
								_putchar('0');
								_putchar(*tmp_hex);
							}
							else
							{
								_putchar(*tmp_hex);
								_putchar(*(tmp_hex + 1));
							}
							count += 4;
						}
						else
						{
							_putchar(s_param[j]);
							count++;
						}
						j++;
					}
					/*if (u_int_param)*/
					i++;
					break;
				case '%':
					_putchar(format[i]);
					count++;
					i++;
					break;
				case 'd':
				case 'i':
					int_param = va_arg(var_arg_list, int);
					count += print_number(int_param);
					i++;
					break;
				case 'b':
				case 'u':
				case 'o':
					u_int_param = va_arg(var_arg_list, unsigned int);
					if (format[i + 1] == 'b')
					{
						u_int_param = dec2bin(u_int_param);
					}
					else if (format[i + 1] == 'o')
					{
						u_int_param = dec2oct(u_int_param);
					}
					count += print_number(u_int_param);
					i++;
					break;
				default:
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(var_arg_list);
	return (count);
}