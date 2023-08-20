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
	unsigned long int i = 0, j, k;
	va_list var_arg_list;
	char *s_param, *tmp_hex;
	int int_param, count = 0;
	uint64_t u_int_param;
	/*void *void_param;*/
	option flags = {0, 0, 0, 0, 0, 0};
	char cur_spec[3];
	int flag_count;

	va_start(var_arg_list, format);
	while (format != NULL && format[i] != '\0')
	{
		flag_count = 0;
		if (format[i] == '%')
		{
			j = i + 1;
			while (format[j] != '\0')
			{
				cur_spec[0] = format[j];
				cur_spec[1] = '\0';
				if (_is_spec(cur_spec))
				{
					break;
				}
				else if(strchr(OPTIONS, format[j]) != NULL)
				{
					update_flag(&flags, format[j]);
					flag_count++;
					j++;
					continue;
				}
				else
				{
					j = i + 1;
					break;
				}
			}

			switch (format[j])
			{
				/*case 'c':
					int_param = va_arg(var_arg_list, int);
					_putchar(int_param);
					count++;
					i++;
					break;
				/*case 's':*/
				case 'x':
				case 'X':
				case 'S':
				case 'p':
					if (format[j] == 'x' || format[j] == 'X')
					{
						if (j != i + 1)
						{
							if (flag_set(&flags, '#'))
							{
								_putchar('0');
								_putchar(format[j]);
								count += 2;
							}
						}
						u_int_param = va_arg(var_arg_list, unsigned int);
						s_param = dec2hex(u_int_param, format[j]);
					}
					else if (format[j] == 'p')
					{
						u_int_param = va_arg(var_arg_list, uint64_t);
						if (u_int_param == 0)
						{
							s_param = "(nil)";
						}
						else
						{
							s_param = dec2hex(u_int_param, 'x');
							_putchar('0');
							_putchar('x');
							count += 2;
						}
					}
					else
					{
						s_param = va_arg(var_arg_list, char *);
					}
					s_param = s_param == NULL ? "(null)" : s_param;
					k = 0;
					while (s_param[k] != '\0')
					{
						if (format[j] == 'S' && !isprint(s_param[k]))
						{
							tmp_hex = dec2hex(s_param[k], 'X');
							_putchar('\\');
							_putchar('x');
							if (s_param[k] < 16)
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
							_putchar(s_param[k]);
							count++;
						}
						k++;
					}
					/*if (u_int_param)*/
					i++;
					break;
				case '%':
					_putchar(format[j]);
					count++;
					i++;
					break;
				case 'd':
				case 'i':
					int_param = va_arg(var_arg_list, int);
					if (j != i + 1)
					{
						if (flag_set(&flags, '+') && int_param >= 0)
						{
							_putchar('+');
							count++;
						}
						else if (flag_set(&flags, ' ') && int_param >= 0)
						{
							_putchar(' ');
							count++;
						}
					}
					count += print_number(int_param);
					i++;
					break;
				case 'b':
				case 'u':
				case 'o':
					u_int_param = va_arg(var_arg_list, unsigned int);
					if (format[j] == 'b')
					{
						u_int_param = dec2bin(u_int_param);
					}
					else if (format[j] == 'o')
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
		i += flag_count;
		i++;
	}
	va_end(var_arg_list);
	return (count);
}
