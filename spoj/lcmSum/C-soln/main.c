/* Mike Curry, Kareem Mohamed and Bradford Smith
 * CS 370 Group Project 2 SPOJ LCMSUM main.c
 * 05/02/2016
 * "We pledge our honor that we have abided by the Stevens Honor System."
 */

#include <stdio.h>

int phi[1000001];

/* pre: none
 * post: generates the results of the phi (euler totient) function from 1 to
 *      1000000
 */
void generate_phi()
{
    for (int i = 1; i < 1000001; ++i)
    {
        phi[i] = i;
    }
    for (int i = 2; i < 1000001; ++i)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= 1000001; j += i)
            {
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
}

/* pre: takes in a unsigned long 'c' and an unsigned long 'd'
 * post: computes the GCD of 'c' and 'd'
 * return: an unsigned long that is the GCD of 'c' and 'd'
 */
unsigned long gcd(unsigned long c, unsigned long d)
{
    unsigned long r;

    if ((c == 0) || (d == 0))
        return 0;
    while (1)
    {
        r = c % d;
        if (r == 0)
            break;
        c = d;
        d = r;
    }
    return d;
}

/* pre: takes in a unsigned long 'c' and an unsigned long 'd'
 * post: computes the GCD of 'c' and 'd' using the generated phi lookup table
 * return: an unsigned long that is the GCD of 'c' and 'd'
 */
unsigned long gcd_phi(unsigned long c, unsigned long d)
{
    unsigned long ans = 0;
    for (unsigned long k = 1; k * k <= d; ++k)
    {
        if (c % k == 0 && d % k == 0)
        {
            ans += phi[k];
        }
    }
    return ans;
}

/* pre: takes in a unsigned long 'a' and an unsigned long 'b'
 * post: computes the LCM of 'a' and 'b' using the `gcd` function
 * return: an unsigned long that is the LCM of 'a' and 'b'
 */
unsigned long lcm(unsigned long a, unsigned long b)
{
    return (a * b) / gcd(a, b);
}

/* pre: takes in a unsigned long 'a' and an unsigned long 'b'
 * post: computes the LCM of 'a' and 'b', using `gcd_phi` function
 * return: an unsigned long that is the LCM of 'a' and 'b'
 */
unsigned long lcm_phi(unsigned long a, unsigned long b)
{
    return (a * b) / gcd_phi(a, b);
}

/* pre: none
 * post: computes the LCM sums for a read in number of test cases
 * return: zero, always
 */
int main()
{

    unsigned long num_cases;
    scanf("%lu", &num_cases);

    unsigned long i, j;
    unsigned long sum;
    unsigned long input;
    generate_phi();
    for (i = 0; i < num_cases; ++i)
    {
        scanf("%lu", &input);

        /* we know that LCM(1, input) = input and that LCM(input, input) = input
         * so we can start at input * 2 when input is not than 1
         */
        if (input != 1)
            sum = input * 2;
        else
            sum = 1;
        for (j = 2; j < input; ++j)
        {
            sum += lcm_phi(j, input);
        }
        printf("%lu\n", sum);
    }

    return 0;
}
