#ifndef GroupPrintf
#define GroupPrintf

#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int _putchar(char);
int _printf(const char *format, ...);
int64_t print_number(int64_t n);
uint64_t dec2bin(unsigned int n);
int64_t dec2oct(unsigned int n);
char *dec2hex(unsigned int n, char _case);

#endif
