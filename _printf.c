#include "main.h"

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
	unsigned long int i = 0, j, count = 0;
	va_list var_arg_list;
	char *s_param;
	int int_param;

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
					s_param = va_arg(var_arg_list, char *);
					s_param = s_param == NULL ? "(null)" : s_param;
					j = 0;
					while (s_param[j] != '\0')
					{
						_putchar(s_param[j++]);
						count++;
					}
					i++;
					break;
				case '%':
					_putchar(format[i]);
					count++;
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
