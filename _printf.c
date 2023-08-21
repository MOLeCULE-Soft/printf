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
	uint64_t u_int_param;
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
					buffer[cursor++] = int_param;
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
								buffer[cursor++] = '0';
								buffer[cursor++] = format[j];
							}
						}
						u_int_param = va_arg(var_arg_list, unsigned int);
						tmp = dec2hex(u_int_param, format[j], conv_buffer);
						strcpy(buffer + cursor, tmp);
						cursor += strlen(tmp);
					}
					else if (format[j] == 'p')
					{
						u_int_param = va_arg(var_arg_list, uint64_t);
						if (u_int_param == 0)
						{
							strcpy(buffer + cursor, "(nil)");
							cursor += 5;
						}
						else
						{
							tmp = dec2hex(u_int_param, 'x', conv_buffer);
							buffer[cursor++] = '0';
							buffer[cursor++] = 'x';
							strcpy(buffer + cursor, tmp);
							cursor += strlen(tmp);
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
									buffer[cursor++] = '\\';
									buffer[cursor++] = 'x';
									if (s_param[k] < 16)
									{
										buffer[cursor++] = '0';
										buffer[cursor++] = *conv_buffer;
									}
									else
									{
										buffer[cursor++] = *conv_buffer;
										buffer[cursor++] = *(conv_buffer + 1);
									}
								}
								else
								{
									buffer[cursor++] = s_param[k];
								}
								k++;
							}
						}
						else
						{
							strcpy(buffer + cursor, s_param);
							cursor += strlen(s_param);
						}
					}
					i++;
					break;
				case '%':
					buffer[cursor++] = format[j];
					i++;
					break;
				case 'd':
				case 'i':
					int_param = va_arg(var_arg_list, int);
					if (j != i + 1)
					{
						if (flag_set(&flags, '+') && int_param >= 0)
							buffer[cursor++] = '+';
						else if (flag_set(&flags, ' ') && int_param >= 0)
							buffer[cursor++] = ' ';
					}
					if (int_param < 0)
						buffer[cursor++] = '-';
					tmp = base_conv(int_param, base, conv_buffer);
					strcpy(buffer + cursor, tmp);
					cursor += strlen(tmp);
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
					strcpy(buffer + cursor, tmp);
					cursor += strlen(tmp);
					i++;
					break;
				default:
					break;
			}
		}
		else
		{
			buffer[cursor++] = format[i];
		}
		i += flag_count;
		i++;
	}
	if (cursor > 0)
	{
		buffer[cursor++] = '\0';
		_write(buffer, cursor - 1);
		/*printf("String:\n%s\nCount:%d\n", buffer, cursor - 1);*/
	}
	va_end(var_arg_list);
	return (cursor - 1);
}
