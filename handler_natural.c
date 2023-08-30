#include "main.h"
#include "handlers.h"

/**
 * handle_natural - conversion handler for unsigned int
 * @b: of struct bundle
 * Description: handles binary (b), unsigned int (u)
 * and octals (o)
*/
void handle_natural(bundle *b)
{
	if (b->lengths._long && b->cur_conv != 'b')
		b->params.UInt = va_arg(b->list, unsigned long);
	else if (b->lengths._short && b->cur_conv != 'b')
		b->params.UInt = va_arg(b->list, unsigned int) % (USHRT_MAX + 1);
	else
		b->params.UInt = va_arg(b->list, unsigned int);
	if (b->cur_conv == 'b')
		b->tmp = base_conv(b->params.UInt, BASE_2, b->conv_buffer);
	else if (b->cur_conv == 'o')
		b->tmp = base_conv(b->params.UInt, BASE_8, b->conv_buffer);
	else
		b->tmp = base_conv(b->params.UInt, BASE_10, b->conv_buffer);

	if (b->flags.hash && b->cur_conv == 'o' && b->params.UInt)
		*--b->tmp = '0';
	if (b->opts.width && strlen(b->tmp) <= b->cfgs.width && b->cur_conv != 'b')
	{
		w_buf_add_str(&b->cfgs, &b->flags, &b->tmp);
	}
	buf_add_str(b->buffer, &b->cursor, b->tmp, &b->print_counter);
	if (b->cfgs.width_malloc)
		free(b->tmp);
}
