#ifndef GroupPrintf
#define GroupPrintf

#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define OPTIONS  "+- 0#"
#define SPECIFIERS {"d", "i", "x", "X", "s", "S", "p", "o", "u", "%", "c", "b"}
#define SPEC_LENGTH 12


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

int _putchar(char);
int _printf(const char *format, ...);
int64_t print_number(int64_t n);
uint64_t dec2bin(unsigned int n);
int64_t dec2oct(unsigned int n);
char *dec2hex(uint64_t n, char _case);
void update_flag(option *flags, char flag);
short flag_set(option *flags, char flag);
short _is_spec(char *spec);

#endif
