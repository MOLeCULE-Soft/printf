#ifndef GroupPrintfHandlers
#define GroupPrintfHandlers

#include <stdarg.h>

/**
* enum conversion - enum for conversions
* @_character: characters
* @_integer: signed integers
* @_natural: unsigned integers
* @_string: strings
*/
typedef enum conversion
{
	_character, _integer, _natural, _string
} conversion;

void handle_character(bundle *);
void handle_integer(bundle *);
void handle_natural(bundle *);
void handle_string(bundle *);

#endif
