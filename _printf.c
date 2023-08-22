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
	va_list var_arg_list;
	char *tmp;
	short cursor = 0, base;
	uint64_t pc, i, j, k;
	option flags = {0};
	param params;
	char cur_spec[3];
	char buffer[WRITE_BUFFER_SIZE];
	char conv_buffer[CONV_BUFFER_SIZE];

	/*memset(buffer, 0, WRITE_BUFFER_SIZE);*/
	bzero(buffer, WRITE_BUFFER_SIZE);
	va_start(var_arg_list, format);
	i = 0;
	pc = 0;
	while (format != NULL && format[i] != '\0')
	{
		flags.count = 0;
		base = 10;
		flags._long = 0;
		flags._short = 0;
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
				else if (flag_set(&flags, 'l') || flag_set(&flags, 'h'))
				{
					j = i + 1;
					break;
				}
				else if (strchr(OPTIONS, format[j]) != NULL)
				{
					update_flag(&flags, format[j]);
					flags.count++;
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
				case 'c':
					params.Int = (char)va_arg(var_arg_list, int);
					buf_add_ch(buffer, &cursor, params.Int, &pc);
					i++;
					break;
				case 's':
				case 'x':
				case 'X':
				case 'S':
				case 'p':
				case 'r':
				case 'R':
					if (format[j] == 'x' || format[j] == 'X')
					{
						if (flag_set(&flags, '#'))
						{
							buf_add_ch(buffer, &cursor, '0', &pc);
							buf_add_ch(buffer, &cursor, format[j], &pc);
						}
						if (flag_set(&flags, 'h'))
							params.UInt = (unsigned short)va_arg(var_arg_list, unsigned int);
						else if (flag_set(&flags, 'l'))
							params.UInt = va_arg(var_arg_list, unsigned long);
						else
							params.UInt = va_arg(var_arg_list, unsigned int);
						tmp = dec2hex(params.UInt, format[j], conv_buffer);
						buf_add_str(buffer, &cursor, tmp, &pc);
					}
					else if (format[j] == 'p')
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
						if (format[j] == 'S')
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
							if (format[j] == 'r')
								_strrev(buffer, &cursor, params.String, &pc);
							else if (format[j] == 'R')
								_rot13(buffer, &cursor, params.String, &pc);
							else
								buf_add_str(buffer, &cursor, params.String, &pc);
						}
					}
					i++;
					break;
				case '%':
					buf_add_ch(buffer, &cursor, format[j], &pc);
					i++;
					break;
				case 'd':
				case 'i':
					if (flag_set(&flags, 'l'))
						params.Int = va_arg(var_arg_list, long);
					else if (flag_set(&flags, 'h'))
						params.Int = (short)va_arg(var_arg_list, int);
					else
						params.Int = va_arg(var_arg_list, int);
					if (flags.count > 0)
					{
						if (flag_set(&flags, '+') && params.Int >= 0)
							buf_add_ch(buffer, &cursor, '+', &pc);
						else if (flag_set(&flags, ' ') && params.Int >= 0)
							buf_add_ch(buffer, &cursor, ' ', &pc);
					}
					if (params.Int < 0)
						buf_add_ch(buffer, &cursor, '-', &pc);
					tmp = base_conv(params.Int, base, conv_buffer);
					buf_add_str(buffer, &cursor, tmp, &pc);
					i++;
					break;
				case 'b':
				case 'u':
				case 'o':
					if (flag_set(&flags, 'l') && format[j] != 'b')
						params.UInt = va_arg(var_arg_list, unsigned long);
					else if (flag_set(&flags, 'h') && format[j] != 'b')
						params.UInt = (short)va_arg(var_arg_list, unsigned int);
					else
						params.UInt = va_arg(var_arg_list, unsigned int);
					if (format[j] == 'b')
						base = 2;
					else if (format[j] == 'o')
						base = 8;
					tmp = base_conv(params.UInt, base, conv_buffer);
					buf_add_str(buffer, &cursor, tmp, &pc);
					i++;
					break;
				default:
					/*while (format[i + 1] == '\0' && format[i + 1] == ' ')
						i++;
					*/
					break;
			}
		}
		else
		{
			buf_add_ch(buffer, &cursor, format[i], &pc);
		}
		i += flags.count;
		i++;
	}
	if (cursor > 0)
	{
		_write(buffer, cursor);
	}
	va_end(var_arg_list);
	return (pc);
}
