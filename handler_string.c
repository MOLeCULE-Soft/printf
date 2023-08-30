#include "main.h"
#include "handlers.h"

void handle_string(bundle *);

/**
 * handle_string - conversion handler for strings
 * @b: of struct bundle
 * Description: handles string (s), string with non printatble
 * cahracters ASCII code in hex (S), pointers (p), hex (x and X)
 * reversed (r), ROT13 (R)
*/
void handle_string(bundle *b)
{
	if (b->cur_conv == 'x' || b->cur_conv == 'X')
	{
		if (b->lengths._short)
			b->params.UInt = (unsigned short)va_arg(b->list, unsigned int);
		else if (b->lengths._long)
			b->params.UInt = va_arg(b->list, unsigned long);
		else
			b->params.UInt = va_arg(b->list, unsigned int);
		b->tmp = dec2hex(b->params.UInt, b->cur_conv, b->conv_buffer);
		if (b->flags.hash && b->params.UInt != 0)
		{
			*--b->tmp = b->cur_conv;
			*--b->tmp = '0';
		}
		if (b->opts.width && strlen(b->tmp) <= b->cfgs.width)
		{
			w_buf_add_str(&b->cfgs, &b->flags, &b->tmp);
		}
		buf_add_str(b->buffer, &b->cursor, b->tmp, &b->print_counter);
		if (b->cfgs.width_malloc)
			free(b->tmp);
	}
	else if (b->cur_conv == 'p')
	{
		b->params.UInt = va_arg(b->list, uint64_t);
		if (b->params.UInt == 0)
		{
			b->tmp = "(nil)";
		}
		else
		{
			b->tmp = dec2hex(b->params.UInt, 'x', b->conv_buffer);
			*--b->tmp = 'x';
			*--b->tmp = '0';
		}
		if (b->opts.width && strlen(b->tmp) <= b->cfgs.width)
		{
			w_buf_add_str(&b->cfgs, &b->flags, &b->tmp);
		}
		buf_add_str(b->buffer, &b->cursor, b->tmp, &b->print_counter);
		if (b->cfgs.width_malloc)
			free(b->tmp);
	}
	else
	{
		b->params.String = va_arg(b->list, char *);
		b->params.String = b->params.String == NULL ? "(null)" : b->params.String;
		if (b->cur_conv == 'r')
		{
			_strrev(b->buffer, &b->cursor, b->params.String, &b->print_counter);
		}
		else if (b->cur_conv == 'R')
		{
			_rot13(b->buffer, &b->cursor, b->params.String, &b->print_counter);
		}
		else if (b->cur_conv == 'S')
		{
			while (*b->params.String)
			{
				if (!isprint(*b->params.String) && *b->params.String < 16)
				{
					b->tmp = dec2hex(*b->params.String, 'X', b->conv_buffer);
					buf_add_ch(b->buffer, &b->cursor, '\\', &b->print_counter);
					buf_add_ch(b->buffer, &b->cursor, 'x', &b->print_counter);
					buf_add_ch(b->buffer, &b->cursor, '0', &b->print_counter);
					buf_add_ch(b->buffer, &b->cursor, *b->tmp, &b->print_counter);
				}
				else if (!isprint(*b->params.String))
				{
					b->tmp = dec2hex(*b->params.String, 'X', b->conv_buffer);
					buf_add_ch(b->buffer, &b->cursor, '\\', &b->print_counter);
					buf_add_ch(b->buffer, &b->cursor, 'x', &b->print_counter);
					buf_add_ch(b->buffer, &b->cursor, *b->tmp, &b->print_counter);
					buf_add_ch(b->buffer, &b->cursor, *(b->tmp + 1), &b->print_counter);
				}
				else
				{
					buf_add_ch(b->buffer, &b->cursor, *b->params.String, &b->print_counter);
				}
				b->params.String++;
			}
		}
		else
		{
			b->tmp = b->params.String;
			if (b->opts.width && strlen(b->tmp) <= b->cfgs.width)
			{
				w_buf_add_str(&b->cfgs, &b->flags, &b->tmp);
			}
			buf_add_str(b->buffer, &b->cursor, b->tmp, &b->print_counter);
			if (b->cfgs.width_malloc)
				free(b->tmp);
		}
	}
}
