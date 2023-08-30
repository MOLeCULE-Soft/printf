#include "main.h"
#include "handlers.h"

void handle_integer(bundle *);

/**
 * handle_integer - conversion handler for signed int
 * @b: of struct bundle
 * Description: handles signed integers (d and i)
*/
void handle_integer(bundle *b)
{
	if (b->lengths._long)
		b->params.Int = va_arg(b->list, long);
	else if (b->lengths._short)
		b->params.Int = (short)va_arg(b->list, int);
	else
		b->params.Int = va_arg(b->list, int);
	b->tmp = base_conv(b->params.Int, BASE_10, b->conv_buffer);
	if (b->flags.plus)
	{
		buf_add_ch(b->buffer, &b->cursor, '+', &b->print_counter);
		b->cfgs.width--;
	}
	else if (b->flags.space)
	{
		buf_add_ch(b->buffer, &b->cursor, ' ', &b->print_counter);
		b->cfgs.width--;
	}
	if (b->params.Int < 0)
	{
		if ((b->flags.plus + b->flags.space))
		{
			*(b->buffer + --(b->cursor)) = '\0';
			b->cfgs.width++;
			b->print_counter--;
		}
		if (!b->flags.zero)
		{
			*--b->tmp = '-';
		}
		else
		{
			buf_add_ch(b->buffer, &b->cursor, '-', &b->print_counter);
			b->cfgs.width--;
		}
	}
	if (b->opts.width && strlen(b->tmp) <= b->cfgs.width)
	{
		w_buf_add_str(&b->cfgs, &b->flags, &b->tmp);
	}
	buf_add_str(b->buffer, &b->cursor, b->tmp, &b->print_counter);
	if (b->cfgs.width_malloc)
		free(b->tmp);
}
