/* Bradford Smith (bsmith8)
 * CS 370 SPOJ FCTRL fctrl.c
 * 02/16/2016
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "stdio.h"
#include "stdlib.h"

#define MAGIC_NUMBER 5

unsigned int power(unsigned int b, unsigned int x)
{
    unsigned int ret = 1;
    while (x--)
        ret *= b;
    return ret;
}

unsigned int check(unsigned int n)
{
    unsigned int i = 1;
    unsigned int b;
    unsigned int result = 0;

    while ((b = power(MAGIC_NUMBER, i++)) <= n)
    {
        result += n / b;
    }
    return result;
}

int main()
{
    unsigned int num;
    unsigned int n;

    /* read in number of lines */
    scanf("%d", &num);

    while (num--)
    {
        scanf("%d", &n);
        printf("%d\n", check(n));
    }
    return 0;
}

