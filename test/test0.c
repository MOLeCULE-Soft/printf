#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
    _printf("_Len: %d\n", _printf("%+d", -1024));
    printf("=Len: %d\n", printf("%+d", -1024));
    return (0);
}
