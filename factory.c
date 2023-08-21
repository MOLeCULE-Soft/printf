#include "main.h"

/**
* _rot13 - encrypts a string with rot13 cipher
* @buffer: output buffer
* @cursor: buffer cursor
* @s: string to be encrypted
* @pc: count of chars to write
*/
void _rot13(char *buffer, short *cursor, char *s, uint64_t *pc)
{
	int64_t i = 0;
	short _case;
	char tmp;

	while (s[i] != '\0')
	{
		tmp = s[i];
		if (isalpha(tmp))
		{
			_case = (bool)islower(tmp) * 'a' + (bool)isupper(tmp) * 'A';
			tmp = (tmp +  13 - _case) % 26 + _case;
		}
		buf_add_ch(buffer, cursor, tmp, pc);
		i++;
	}
}
