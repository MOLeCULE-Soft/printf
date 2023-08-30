#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
    _printf("%.-8d\n", 1024);
    printf("%.-8d", 1024);
    return (0);
}
