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
	unsigned long int i = 0, j, k;
	va_list var_arg_list;
	char *s_param, *tmp;
	int int_param;
	short cursor = 0, base;
	uint64_t u_int_param, pc = 0;
	option flags = {0, 0, 0, 0, 0, 0};
	char cur_spec[3];
	int flag_count;
	char buffer[WRITE_BUFFER_SIZE];
	char conv_buffer[CONV_BUFFER_SIZE];

	memset(buffer, 0, WRITE_BUFFER_SIZE);
	va_start(var_arg_list, format);
	while (format != NULL && format[i] != '\0')
	{
		flag_count = 0;
		base = 10;
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
				else if (strchr(OPTIONS, format[j]) != NULL)
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
				case 'c':
					int_param = va_arg(var_arg_list, int);
					buf_add_ch(buffer, &cursor, int_param, &pc);
					i++;
					break;
				case 's':
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
								buf_add_ch(buffer, &cursor, '0', &pc);
								buf_add_ch(buffer, &cursor, format[j], &pc);
							}
						}
						u_int_param = va_arg(var_arg_list, unsigned int);
						tmp = dec2hex(u_int_param, format[j], conv_buffer);
						buf_add_str(buffer, &cursor, tmp, &pc);
					}
					else if (format[j] == 'p')
					{
						u_int_param = va_arg(var_arg_list, uint64_t);
						if (u_int_param == 0)
						{
							buf_add_str(buffer, &cursor, "(nil)", &pc);
						}
						else
						{
							tmp = dec2hex(u_int_param, 'x', conv_buffer);
							buf_add_ch(buffer, &cursor, '0', &pc);
							buf_add_ch(buffer, &cursor, 'x', &pc);
							buf_add_str(buffer, &cursor, tmp, &pc);
						}
					}
					else
					{
						s_param = va_arg(var_arg_list, char *);
						s_param = s_param == NULL ? "(null)" : s_param;
						if (format[j] == 'S')
						{
							k = 0;
							while (s_param[k] != '\0')
							{
								if (!isprint(s_param[k]))
								{
									tmp = dec2hex(s_param[k], 'X', conv_buffer);
									buf_add_ch(buffer, &cursor, '\\', &pc);
									buf_add_ch(buffer, &cursor, 'x', &pc);
									if (s_param[k] < 16)
									{
										buf_add_ch(buffer, &cursor, '0', &pc);
										buf_add_ch(buffer, &cursor, *conv_buffer, &pc);
									}
									else
									{
										buf_add_ch(buffer, &cursor, *conv_buffer, &pc);
										buf_add_ch(buffer, &cursor, *(conv_buffer + 1), &pc);
									}
								}
								else
								{
									buf_add_ch(buffer, &cursor, s_param[k], &pc);
								}
								k++;
							}
						}
						else
						{
							buf_add_str(buffer, &cursor, s_param, &pc);
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
					int_param = va_arg(var_arg_list, int);
					if (j != i + 1)
					{
						if (flag_set(&flags, '+') && int_param >= 0)
							buf_add_ch(buffer, &cursor, '+', &pc);
						else if (flag_set(&flags, ' ') && int_param >= 0)
							buf_add_ch(buffer, &cursor, ' ', &pc);
					}
					if (int_param < 0)
						buf_add_ch(buffer, &cursor, '-', &pc);
					tmp = base_conv(int_param, base, conv_buffer);
					buf_add_str(buffer, &cursor, tmp, &pc);
					i++;
					break;
				case 'b':
				case 'u':
				case 'o':
					u_int_param = va_arg(var_arg_list, unsigned int);
					if (format[j] == 'b')
						base = 2;
					else if (format[j] == 'o')
						base = 8;
					tmp = base_conv(u_int_param, base, conv_buffer);
					buf_add_str(buffer, &cursor, tmp, &pc);
					i++;
					break;
				default:
					break;
			}
		}
		else
		{
			buf_add_ch(buffer, &cursor, format[i], &pc);
		}
		i += flag_count;
		i++;
	}
	if (cursor > 0)
	{
		_write(buffer, cursor);
	}
	va_end(var_arg_list);
	return (pc);
}
