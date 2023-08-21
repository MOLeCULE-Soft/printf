#include "main.h"
#include <unistd.h>

/**
* _putchar - Custom putchar function
* @ch: Character to be printed
*
* Description: This function prints a character to
* the stdout using the putchar function.
* Return: nothing
*/
int _putchar(char ch)
{
	return (write(STDOUT_FILENO, &ch, sizeof(char)));
}

/**
* _write - passes a buffer to write function
* @buffer: buffer
* @bytes: number of bytes to be written
*
* Return: number of bytes written
*/
int _write(char *buffer, int bytes)
{
	return (write(STDOUT_FILENO, buffer, bytes));
}

/**
* buf_add_ch - adds a char to the buffer
* @buffer: output buffer
* @cursor: buffer cursor
* @ch: char to be added to buffer
* @pc: count of chars printed
*
* Description: If buffer is already full, it will be
* written to the stdout, emptied and cursor set to 0
* before adding ch to buffer
*/
void buf_add_ch(char *buffer, short *cursor, char ch, uint64_t *pc)
{
	if (*cursor == WRITE_BUFFER_SIZE)
	{
		_write(buffer, WRITE_BUFFER_SIZE);
		memset(buffer, 0, WRITE_BUFFER_SIZE);
		*cursor = 0;
	}
	buffer[*cursor] = ch;
	*cursor = *cursor + 1;
	*pc = *pc + 1;
}

/**
* buf_add_str - adds a string to the buffer
* @buffer: output buffer
* @cursor: buffer cursor
* @str: string to be added to buffer
* @pc: count of chars printed
*
* Description: If buffer is already full, it will be
* written to the stdout, emptied and cursor set to 0
* before adding str to buffer. However, if length of
* str is above the free space if the buffer, part of
* str will be copied to fill the buffer and a recursive
* call made with the rest of str.
*/
void buf_add_str(char *buffer, short *cursor, char *str, uint64_t *pc)
{
	short space_left = WRITE_BUFFER_SIZE - *cursor;
	short copied = 0;

	if (*cursor == WRITE_BUFFER_SIZE)
	{
		_write(buffer, WRITE_BUFFER_SIZE);
		memset(buffer, 0, WRITE_BUFFER_SIZE);
		*cursor = 0;
	}
	strncpy(buffer + *cursor, str, space_left);
	copied = (short)strlen(str) < space_left ? (short)strlen(str) : space_left;
	*cursor = *cursor + copied;
	*pc = *pc + copied;
	if (strlen(str + copied) > 0)
		buf_add_str(buffer, cursor, str + copied, pc);
}

/**
* _strrev - reverses contents of a string
* @buffer: output buffer
* @cursor: buffer cursor
* @s: string to be reversed
* @pc: count of chars to write
*/
void _strrev(char *buffer, short *cursor, char *s, uint64_t *pc)
{
	int64_t end = strlen(s) - 1;

	while (end >= 0)
		buf_add_ch(buffer, cursor, s[end--], pc);
}
