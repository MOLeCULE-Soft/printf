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
	return (write(1, &ch, 1));
}
