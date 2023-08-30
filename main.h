#ifndef GroupPrintf
#define GroupPrintf

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#define FLAGS  "+- 0#"
#define LENGTHS "lh"
#define OPTIONS "FWPL"
#define SPECIFIERS "dixXsSpoucbrR%"
#define WRITE_BUFFER_SIZE 1024
#define CONV_BUFFER_SIZE 40
#define BASE_10 10
#define BASE_2 2
#define BASE_8 8

/**
* struct opt_flag - structure holding flags
* @plus: + flag
* @minus: - flag
* @space: space flag
* @hash: # flag
* @zero: 0 flag
*/
typedef struct opt_flag
{
	short plus;
	short minus;
	short space;
	short hash;
	short zero;
} opt_flag;

/**
* struct option - structure holding options
* @flag: flags
* @width: width
* @precision: precision
* @length: lendth
* @conversion: conversion
*/
typedef struct option
{
	short flag;
	short width;
	short precision;
	short length;
	short conversion;
} option;

/**
* struct opt_length - structure holding lengths
* @_long: long integer
* @_short: shot integer
*/
typedef struct opt_length
{
	short _long;
	short _short;
} opt_length;

/**
* struct config - structure holding configs
* @width: value of width
* @precision: value of precision
* @spec_start: position after %
* @width_buffer: buffer if width is set
* @width_malloc: flag if there is malloc for width
* @tmp_malloc: flag if there is malloc for tmp
*/
typedef struct config
{
	uint64_t width;
	uint64_t precision;
	char *spec_start;
	char *width_buffer;
	short width_malloc;
	short tmp_malloc;
} config;

/**
* struct param - structure holding variadic params
* @Int: for signed integers
* @UInt: for unsigned integers
* @String: for strings
*/
typedef struct param
{
	int64_t Int;
	uint64_t UInt;
	char *String;
} param;

/**
 * struct bundle - structure hundler bundle of data objects
 * @list: variable list
 * @flags: flags
 * @lengths: lengths
 * @cfgs: configs
 * @opts: options
 * @params: paramters
 * @cursor: buffer cursor
 * @print_counter: for characters printed
 * @buffer: for writing
 * @conv_buffer: for conversions
 * @tmp: temporal helper
 * @cur_conv: current format character
*/
typedef struct bundle
{
	va_list list;
	opt_flag flags;
	opt_length lengths;
	config cfgs;
	option opts;
	param params;
	short cursor;
	uint64_t print_counter;
	char buffer[WRITE_BUFFER_SIZE];
	char conv_buffer[CONV_BUFFER_SIZE];
	char *tmp;
	char cur_conv;
} bundle;

int _write(char *buffer, int bytes);
int _printf(const char *format, ...);
char *base_conv(int64_t n, short base, char *buffer);
char *dec2hex(uint64_t n, char _case, char *buffer);
void update_flag(opt_flag *flags, char flag);
void update_length(opt_length *lengths, char length);
void init_options(option *options);
void buf_add_ch(char *buffer, short *cursor, char ch, uint64_t *pc);
void buf_add_str(char *buffer, short *cursor, char *str, uint64_t *pc);
void _strrev(char *buffer, short *cursor, char *s, uint64_t *pc);
void _rot13(char *buffer, short *cursor, char *s, uint64_t *pc);
void w_buf_add_str(config *cfgs, opt_flag *flgs, char **data);

#endif
