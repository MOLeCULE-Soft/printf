#include "main.h"

int _printf(const char *format, ...);
/**
* _printf - prints formatted string to
* the stdout
* @format: format specifications or option
* ...: [ARGUMENTS], varaible params
*
* Return: count of characters printed
* Example:
*    _printf("%c grade (100%%) in %s", 'A', "0x11"); --> A grade (100%) in 0x11
*/
int _printf(const char *format, ...)
{
	va_list var_arg_list;
	char *tmp;
	short cursor = 0, base;
	uint64_t pc, k;
	opt_flag flags = {0};
	opt_length lengths = {0};
	option options;
	config configs = {0};
	param params;
	char buffer[WRITE_BUFFER_SIZE];
	char conv_buffer[CONV_BUFFER_SIZE];

	bzero(buffer, WRITE_BUFFER_SIZE);
	va_start(var_arg_list, format);
	pc = 0;
	if (format == NULL)
		return (-1);
	while (*format)
	{
		init_options(&options);
		if (*format == '%')
		{
			if (*format == 1)
				return (-1);
			format++;
			if (isspace(*format) || *format == '\0')
				return (-1);
			configs.spec_start = (char *)format;
			while (*format)
			{
				k = options.width + options.precision + options.length;
				if (strchr(SPECIFIERS, *format) != NULL)
				{
					options.conversion = 1;
					break;
				}
				else if (strchr(FLAGS, *format) != NULL)
				{
					if (options.width + options.precision + options.length)
						break;
					update_flag(&flags, *format);
					options.flag = 1;
				}
				else if (isdigit(*format) && !k)
				{
					tmp = (char *)format++;
					while (isdigit(*format))
						format++;
					bzero(conv_buffer, CONV_BUFFER_SIZE);
					strncpy(conv_buffer, tmp, format - tmp);
					configs.width = atoll(conv_buffer);
					options.width = 1;
					continue;
				}
				else if (*format == '.' && !(options.precision + options.length))
				{
					tmp = (char *) ++format;
					while (isdigit(*format))
						format++;
					if (format - tmp > 0)
					{
						bzero(conv_buffer, CONV_BUFFER_SIZE);
						strncpy(conv_buffer, tmp, format - tmp);
						configs.precision = atoll(conv_buffer);
						options.precision = 1;
						continue;
					}
					break;

				}
				else if (strchr(LENGTHS, *format) != NULL && !options.length)
				{
					update_length(&lengths, *format);
					options.length = 1;
				}
				else
				{
					break;
				}
				format++;
			}

			if (!options.conversion)
			{
				format = configs.spec_start;
				break;
			}
			base = 10;
			switch (*format)
			{
			case 'c':
				params.Int = (char)va_arg(var_arg_list, int);
				buf_add_ch(buffer, &cursor, params.Int, &pc);
				break;
			case 's':
			case 'x':
			case 'X':
			case 'S':
			case 'p':
			case 'r':
			case 'R':
				if (*format == 'x' || *format == 'X')
				{
					if (flags.hash)
					{
						buf_add_ch(buffer, &cursor, '0', &pc);
						buf_add_ch(buffer, &cursor, *format, &pc);
					}
					if (lengths._short)
						params.UInt = (unsigned short)va_arg(var_arg_list, unsigned int);
					else if (lengths._long)
						params.UInt = va_arg(var_arg_list, unsigned long);
					else
						params.UInt = va_arg(var_arg_list, unsigned int);
					tmp = dec2hex(params.UInt, *format, conv_buffer);
					buf_add_str(buffer, &cursor, tmp, &pc);
				}
				else if (*format == 'p')
				{
					params.UInt = va_arg(var_arg_list, uint64_t);
					if (params.UInt == 0)
					{
						buf_add_str(buffer, &cursor, "(nil)", &pc);
					}
					else
					{
						tmp = dec2hex(params.UInt, 'x', conv_buffer);
						buf_add_ch(buffer, &cursor, '0', &pc);
						buf_add_ch(buffer, &cursor, 'x', &pc);
						buf_add_str(buffer, &cursor, tmp, &pc);
					}
				}
				else
				{
					params.String = va_arg(var_arg_list, char *);
					params.String = params.String == NULL ? "(null)" : params.String;
					if (*format == 'S')
					{
						k = 0;
						while (params.String[k] != '\0')
						{
							if (!isprint(params.String[k]))
							{
								tmp = dec2hex(params.String[k], 'X', conv_buffer);
								buf_add_ch(buffer, &cursor, '\\', &pc);
								buf_add_ch(buffer, &cursor, 'x', &pc);
								if (params.String[k] < 16)
								{
									buf_add_ch(buffer, &cursor, '0', &pc);
									buf_add_ch(buffer, &cursor, *tmp, &pc);
								}
								else
								{
									buf_add_ch(buffer, &cursor, *tmp, &pc);
									buf_add_ch(buffer, &cursor, *(tmp + 1), &pc);
								}
							}
							else
							{
								buf_add_ch(buffer, &cursor, params.String[k], &pc);
							}
							k++;
						}
					}
					else
					{
						if (*format == 'r')
							_strrev(buffer, &cursor, params.String, &pc);
						else if (*format == 'R')
							_rot13(buffer, &cursor, params.String, &pc);
						else
							buf_add_str(buffer, &cursor, params.String, &pc);
					}
				}
				break;
			case '%':
				buf_add_ch(buffer, &cursor, *format, &pc);
				break;
			case 'd':
			case 'i':
				if (lengths._long)
					params.Int = va_arg(var_arg_list, long);
				else if (lengths._short)
					params.Int = (short)va_arg(var_arg_list, int);
				else
					params.Int = va_arg(var_arg_list, int);
				if (flags.plus && params.Int >= 0)
					buf_add_ch(buffer, &cursor, '+', &pc);
				else if (flags.space && params.Int >= 0)
					buf_add_ch(buffer, &cursor, ' ', &pc);
				if (params.Int < 0)
					buf_add_ch(buffer, &cursor, '-', &pc);
				tmp = base_conv(params.Int, base, conv_buffer);
				buf_add_str(buffer, &cursor, tmp, &pc);
				break;
			case 'o':
			case 'u':
			case 'b':
				if (lengths._long && *format != 'b')
					params.UInt = va_arg(var_arg_list, unsigned long);
				else if (lengths._short && *format != 'b')
					params.UInt = va_arg(var_arg_list, unsigned int) % (USHRT_MAX + 1);
				else
					params.UInt = va_arg(var_arg_list, unsigned int);
				if (*format == 'b')
					base = 2;
				else if (*format == 'o')
					base = 8;
				if (flags.zero && *format == 'o' && params.UInt)
					buf_add_ch(buffer, &cursor, '0', &pc);

				tmp = base_conv(params.UInt, base, conv_buffer);
				buf_add_str(buffer, &cursor, tmp, &pc);
				break;
			default:
				break;
			}
		}
		else
		{
			buf_add_ch(buffer, &cursor, *format, &pc);
		}
		format++;
	}
	if (cursor > 0)
	{
		_write(buffer, cursor);
	}
	va_end(var_arg_list);
	return (pc);
}
1692758411
1692758414
1692758417
1692758420
1692758423
1692758425
1692758427
1692758430
1692758432
1692758435
