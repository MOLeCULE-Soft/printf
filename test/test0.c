#include "../main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
    _printf("In the middle %*s of a sentence.\n", 6, "Hey");
    printf("In the middle %*s of a sentence.\n", 6, "Hey");
    _printf("%6d\n", 102498402);
    _printf("%06d\n", -1024);
    printf("%06d\n", -1024);
    _printf("% 6d\n", -1024);
    printf("% 6d\n", -1024);
    /*_printf("[%x]\n", USHRT_MAX);
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
    _printf("[%c]\n", 65);
    printf("[%c]\n", 65);
    _printf("[%5c]\n", 65);
    printf("[%5c]\n", 65);
    _printf("[%-5c]\n", 65);
    printf("[%-5c]\n", 65);
    _printf("[%s]\n", "Felix");
    printf("[%s]\n", "Felix");
    _printf("[%10s]\n", "Felix");
    printf("[%10s]\n", "Felix");
    _printf("[%-10s]\n", "Felix");
    printf("[%-10s]\n", "Felix");
    _printf("[%u]\n", UINT_MAX);
    printf("[%u]\n", UINT_MAX);
    _printf("[%20u]\n", UINT_MAX);
    printf("[%20u]\n", UINT_MAX);
    _printf("[%-20u]\n", UINT_MAX);
    printf("[%-20u]\n", UINT_MAX);
    _printf("[%#-20u]\n", UINT_MAX);
    printf("[%#-20u]\n", UINT_MAX);
    _printf("[%##-20u]\n", UINT_MAX);
    printf("[%##-20u]\n", UINT_MAX);
    _printf("[%##0-20u]\n", UINT_MAX);
    printf("[%##0-20u]\n", UINT_MAX);
    _printf("[%##020u]\n", UINT_MAX);
    printf("[%##020u]\n", UINT_MAX);
    _printf("[%##020u]\n", UINT_MAX);
    printf("[%##020u]\n", UINT_MAX);*/
    return (0);
}
