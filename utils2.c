#include "main.h"

/**
* w_buf_add_str - adds a string to the width buffer
* @cfgs: width buffer
* @flgs: data to be added
* @data: string to be added to buffer
*
* Description:
*/
void w_buf_add_str(config *cfgs, opt_flag *flgs, char **data)
{
	char fill = flgs->zero ? '0' : ' ';
	int64_t start;

	cfgs->width_buffer = malloc(cfgs->width + 1);
	memset(cfgs->width_buffer, fill, cfgs->width);
	*(cfgs->width_buffer + cfgs->width) = '\0';
	if (flgs->minus)
		start =  0;
	else
		start = cfgs->width - strlen(*data);
	strncpy(cfgs->width_buffer + start, *data, strlen(*data));
	*data = cfgs->width_buffer;
}
