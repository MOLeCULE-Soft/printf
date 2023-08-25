#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
    _printf("[%x]\n", USHRT_MAX);
    printf("[%x]\n", USHRT_MAX);
    _printf("[%5x]\n", USHRT_MAX);
    printf("[%5x]\n", USHRT_MAX);
    _printf("[%15x]\n", USHRT_MAX);
    printf("[%15x]\n", USHRT_MAX);
    _printf("[%-15x]\n", USHRT_MAX);
    printf("[%-15x]\n", USHRT_MAX);
    _printf("[%#15x]\n", USHRT_MAX);
    printf("[%#15x]\n", USHRT_MAX);
    _printf("[%#-15x]\n", USHRT_MAX);
    printf("[%#-15x]\n", USHRT_MAX);
    return (0);
}
