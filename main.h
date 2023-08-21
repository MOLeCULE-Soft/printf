#ifndef GroupPrintf
#define GroupPrintf

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

#define OPTIONS  "+- 0#"
#define SPECIFIERS {	"d", "i", "x", "X", "s",\
			"S", "p", "o", "u", "%",\
			"c", "b", "r", "R"}
#define SPEC_LENGTH 14
#define WRITE_BUFFER_SIZE 1024
#define CONV_BUFFER_SIZE 21

/**
* struct option - structure holding flags
* @plus: + flag
* @minus: - glas
* @space: space flag
* @hash: # flag
* @zero: 0 flag
* @width: width specifier
*/
typedef struct option
{
	short plus;
	short minus;
	short space;
	short hash;
	short zero;
	short width;
} option;

int _putchar(char c);
int _write(char *buffer, int bytes);
int _printf(const char *format, ...);
char *base_conv(int64_t n, short base, char *buffer);
char *dec2hex(uint64_t n, char _case, char *buffer);
void update_flag(option *flags, char flag);
short flag_set(option *flags, char flag);
short _is_spec(char *spec);
void buf_add_ch(char *buffer, short *cursor, char ch, uint64_t *pc);
void buf_add_str(char *buffer, short *cursor, char *str, uint64_t *pc);
void _strrev(char *buffer, short *cursor, char *s, uint64_t *pc);
void _rot13(char *buffer, short *cursor, char *s, uint64_t *pc);

#endif
