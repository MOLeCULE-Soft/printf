#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	int *addr = malloc(sizeof(int) * 10);
	int i;
	char *s;

	int a, b, c;
	a = 0; b = -10; c = 10;


	_printf("a:%+ d\t<end>b:%+ d\t<end>c:%+ d<end>\n", a, b, c);
	_printf("a:%+d\t<end>b:%+d\t<end>c:%+d<end>\n", a, b, c);
	_printf("a:% d\t<end>b:% d\t<end>c:% d<end>\n", a, b, c);
	_printf("a:% +d\t<end>b:% +d\t<end>c:% +d<end>\n", a, b, c);
	_printf("a:% + d\t<end>b:% + d\t<end>c:% + d<end>\n", a, b, c);
	_printf("a:%  d\t<end>b:%  d\t<end>c:%  d<end>\n", a, b, c);
	_printf("a:%d\t<end>b:%d\t<end>c:%d<end>\n", a, b, c);
	for (i = 0; i < 10; i++)
	{
		_printf("_Address:%d = %p\n", i, (void*)(addr + i));
		printf("Address:%d = %p\n", i , (void*)(addr + i));
	}
	_printf("%S\n", "Best\nSchool");

	_printf("_Address NULL: %p\n", NULL);
	printf("Address NULL: %p\n", NULL);
	
	s = "Felix";
	_printf("_String:%+s\n", s);
	_printf("String:%  +s\n", s);
	_printf("_String:% s\n", s);
	_printf("String:% s\n", s);
	_printf("_String:%  + s\n", s);
	_printf("String:%+ s\n", s);
	_printf("_String:% +s\n", s);
	_printf("String:% +  s\n", s);
        return (0);
}
