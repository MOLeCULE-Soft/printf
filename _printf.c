#include "main.h"
#include "handlers.h"

int _printf(const char *format, ...);
/**
* _printf - prints formatted string to
* the stdout
* @format: format specifications or option
* ...: [ARGUMENTS], varaible params
*
* Return: count of characters printed
* Example:
*    _printf("%c grade (100%%) in %s", 'A', "0x11");
*    --> A grade (100%) in 0x11
*/
int _printf(const char *format, ...)
{
	short k;
	bundle b = {{{0}}, {0}, {0}, {0}, {0}, {0}, 0, 0, "", "", NULL, '\0'};

	void (*handlers[])(bundle *) = {handle_character, handle_integer,
									handle_natural, handle_string};
	bzero(b.buffer, WRITE_BUFFER_SIZE);
	va_start(b.list, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		init_options(&b.opts);
		b.cfgs.width_malloc = 0;
		if (*format == '%')
		{
			if (*format == 1)
				return (-1);
			format++;
			if (!*format)
				return (-1);
			b.cfgs.spec_start = (char *)format;
			while (*format)
			{
				k = b.opts.width + b.opts.precision + b.opts.length;
				if (strchr(SPECIFIERS, *format) != NULL)
				{
					b.opts.conversion = 1;
					break;
				}
				else if (strchr(FLAGS, *format) != NULL)
				{
					if (k)
						break;
					update_flag(&b.flags, *format);
					b.opts.flag = 1;
				}
				else if ((!k && isdigit(*format)) || (!k && *format == '*'))
				{
					if (*format == '*')
					{
						format++;
						b.cfgs.width = va_arg(b.list, int);
						b.opts.width = 1;
						continue;
					}
					b.tmp = (char *)format++;
					while (isdigit(*format))
						format++;
					bzero(b.conv_buffer, CONV_BUFFER_SIZE);
					strncpy(b.conv_buffer, b.tmp, format - b.tmp);
					b.cfgs.width = atoll(b.conv_buffer);
					b.opts.width = 1;
					continue;
				}
				else if (*format == '.' && !(b.opts.precision + b.opts.length))
				{
					b.tmp = (char *) ++format;
					while (isdigit(*format))
						format++;
					if (format - b.tmp > 0)
					{
						bzero(b.conv_buffer, CONV_BUFFER_SIZE);
						strncpy(b.conv_buffer, b.tmp, format - b.tmp);
						b.cfgs.precision = atoll(b.conv_buffer);
						b.opts.precision = 1;
						continue;
					}
					break;
				}
				else if (strchr(LENGTHS, *format) != NULL && !b.opts.length)
				{
					update_length(&b.lengths, *format);
					b.opts.length = 1;
				}
				else
				{
					break;
				}
				format++;
			}

			if (!b.opts.conversion)
			{
				if (*format)
				{
					k = b.opts.conversion + b.opts.length + b.opts.width;
					k = (k + b.opts.precision) - b.opts.flag;
					buf_add_ch(b.buffer, &b.cursor, '%', &b.print_counter);
					if (k == -1)
						format--;
					else
						format = b.cfgs.spec_start;
				}
				continue;
			}
			b.cur_conv = *format;
			switch (b.cur_conv)
			{
			case 'c':
				handlers[_character](&b);
				break;
			case 's':
			case 'x':
			case 'X':
			case 'p':
			case 'r':
			case 'R':
			case 'S':
				handlers[_string](&b);
				break;
			case '%':
				buf_add_ch(b.buffer, &b.cursor, b.cur_conv, &b.print_counter);
				break;
			case 'd':
			case 'i':
				handlers[_integer](&b);
			break;
			case 'o':
			case 'u':
			case 'b':
				handlers[_natural](&b);
				break;
			default:
				break;
			}
		}
		else
		{
			buf_add_ch(b.buffer, &b.cursor, *format, &b.print_counter);
		}
		format++;
	}
	if (b.cursor > 0)
	{
		_write(b.buffer, b.cursor);
	}
	va_end(b.list);
	return (b.print_counter);
}
