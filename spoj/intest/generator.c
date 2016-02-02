/* Bradford Smith (bsmith8)
 * spoj INTEST generator.c
 * 02/01/2016
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int n;
    int k;
    int i;

    if (argc != 3)
        printf("usage: ./%s n k", argv[0]);

    n = atoi(argv[1]);
    k = atoi(argv[2]);

    for (i = 0; i < n; i++)
        printf("%d\n", (rand() % 1000000000 + 1));

    return 0;
}
