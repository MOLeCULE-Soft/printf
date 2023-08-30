#include "main.h"
#include "handlers.h"

/**
 * handle_character - conversion handler for character
 * @b: of struct bundle
 * Description: handles chanracters (c)
*/
void handle_character(bundle *b)
{
	char fill = b->flags.zero && !b->flags.minus ? '0' : ' ';
	short start;

	b->params.Int = (char)va_arg(b->list, int);
	if (b->opts.width && b->cfgs.width > 1)
	{
		b->cfgs.width_buffer = malloc(b->cfgs.width);
		if (b->cfgs.width_buffer)
		{
			memset(b->cfgs.width_buffer, fill, b->cfgs.width);
			if (b->flags.minus)
				start =  0;
			else
				start = b->cfgs.width - 1;
			*(b->cfgs.width_buffer + start) = b->params.Int;
			_write(b->buffer, b->cursor);
			bzero(b->buffer, WRITE_BUFFER_SIZE);
			b->cursor = 0;
			_write(b->cfgs.width_buffer, b->cfgs.width);
			b->print_counter += b->cfgs.width;
			free(b->cfgs.width_buffer);
		}
	}
	else
	{
		buf_add_ch(b->buffer, &b->cursor, b->params.Int, &b->print_counter);
	}
}
