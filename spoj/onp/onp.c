/* Aidan Racaniello, Bradford Smith, Nicholas Zubrycki
 * CS 370 Assignment 2: SPOJ ONP onp.c
 * 02/12/2016
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <stdio.h>
#include <stdlib.h>

/* pre: takes in a char c
 * post: determines is c is an operand
 * return: 1 if c is a letter a-zA-Z, else 0
 */
int is_operand(char c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        return 1;
    return 0;
}

/* pre: takes in a char c
 * post: determines if c is an operator
 * return: 1 if c is +,-,*,/,^, else 0
 */
int is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

/* pre: takes in a char c1 and char c2
 * post: determines the precedence between c1 and c2
 * return: 0 if equal, -1 if c1 comes first (c1 has greater precedence),
 *      and 1 if c2 comes first (c2 has greater precedence)
 */
int precedence(char c1, char c2)
{
    static char priority[] = {'^', '/', '*', '-', '+'};
    int i;

    if (c1 == c2)
        return 0;
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (priority[i] == c1 && priority[i] != c2)
                return -1;
            else if (priority[i] == c2 && priority[i] != c1)
                return 1;
        }
    }
}

/* pre: none
 * post: reads in a number of expressions and prints them out in reverse polish
 *      notation
 * return: 0, always
 */
int main()
{
    int numExpr; /* number of expressions to read */
    char expr[401]; /* the expression */
    char ghettoStack[401];
    char output[401];
    int i;
    int outCount = -1;
    int gs_top = -1;


    /* read in number of expressions */
    scanf("%d", &numExpr);
    /* printf("[DEBUG]: %d\n", numExpr); */

    while (numExpr-- > 0)
    {
        scanf("%s", (char*)&expr);
        for (i = 0; expr[i] != '\0'; i++) /* while there are tokens to be read */
        { /* read a token */
            if (is_operand(expr[i]))
            {
                /* if the token is an operand add it to the output queue */
                output[++outCount] = expr[i];
            }
            else if (is_operator(expr[i]))
            {
                /* if the token is an operator, o1 */
                while (is_operator(gs_top != -1 && ghettoStack[gs_top]) &&
                        (precedence(expr[i], ghettoStack[gs_top])) >= 0)
                /* while there is an operator, o2, at the top of the stack
                 * and o1's precedence is less than or equal to o2 */
                {
                    /* pop o2 off the stack and add it to the output queue */
                    output[++outCount] = ghettoStack[gs_top--];
                }
                /* push o1 onto the stack */
                ghettoStack[++gs_top] = expr[i];
            }
            else if (expr[i] == '(')
            {
                /* if the token is a left parenthesis, push it onto the stack */
                ghettoStack[++gs_top] = expr[i];
            }
            else if (expr[i] == ')')
            {
                /* if the token is a right parenthesis */
                while (gs_top != -1 && ghettoStack[gs_top] != '(')
                /* until the token on the top of the stack is a left parenthesis */
                {
                    /* pop operators of the stack and add them to the output queue */
                    output[++outCount] = ghettoStack[gs_top--];
                }
                /* pop the stack one more time to remove the '(' */
                gs_top--;
            }
        }
        /* when there are no more tokens to be read */
        while (gs_top != -1 && ghettoStack[gs_top])
        /* while there are still oeprators on the stack */
        {
            /* pop the operator off the stack and add it to the output queue */
            output[++outCount] = ghettoStack[gs_top--];
        }

        /* print the output queue */
        printf("%s\n", output);
        outCount = -1;
    }

    return 0;
}

