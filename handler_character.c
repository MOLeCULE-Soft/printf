#include "main.h"
#include "handlers.h"

/**
 * handle_character - conversion handler for character
 * @b: of struct bundle
 * Description: handles chanracters (c)
*/
void handle_character(bundle *b)
{
	b->params.Int = (char)va_arg(b->list, int);
	if (b->opts.width && b->cfgs.width > 1)
	{
		bzero(b->conv_buffer, CONV_BUFFER_SIZE);
		*b->conv_buffer = b->params.Int;
		b->tmp = (char *)b->conv_buffer;
		w_buf_add_str(&b->cfgs, &b->flags, &b->tmp);
		buf_add_str(b->buffer, &b->cursor, b->tmp, &b->print_counter);
		if (b->cfgs.width_malloc)
			free(b->tmp);
	}
	else
	{
		buf_add_ch(b->buffer, &b->cursor, b->params.Int, &b->print_counter);
	}
}
