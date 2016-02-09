/* Bradford Smith (bsmith8)
 * HackerRank maxElement.c
 * 02/08/2016
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int numOps; /* number of operations to process */
    int op; /* current operation number */
        /* operations:
         * 1: push element to stack
         * 2: pop stack
         * 3: print max element in stack
         */
    int n; /* current number */
    int i; /* loop counter */

    int ghettoStack[100000];
    int gs_top = -1;
    int maxStack[100000];
    int ms_top = -1;

    /* read in total number of operations */
    scanf("%d\n", &numOps);

    /* loop for numOps and do operations */
    for (i = 0; i < numOps; i++)
    {
        scanf("%d", &op);
        if (op == 2 || op == 3)
            scanf("\n");
        else
            scanf(" %d\n", &n);

        if (op == 1)
        {
            ghettoStack[++gs_top] = n;

            if (ms_top == -1 || n >= maxStack[ms_top])
                maxStack[++ms_top] = n;
        }
        else if (op == 2)
        {
            if (gs_top >= 0)
            {
                if (ghettoStack[gs_top] == maxStack[ms_top])
                    ms_top--;
                gs_top--;
            }
        }
        else if (op == 3)
        {
            if (ms_top >= 0)
                printf("%d\n", maxStack[ms_top]);
        }
    }
}

