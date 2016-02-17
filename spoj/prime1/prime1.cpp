/* Bradford Smith (bsmith8)
 * CS 370 SPOJ PRIME1 prime1.cpp
 * 02/16/2016
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <cmath>
#include <string>
#include <cstring>
#include <iostream>

bool* sieve(unsigned int upper)
{
    unsigned int i;
    unsigned int j;
    int upperSqrt = (int)sqrt((double)upper);
    bool* isPrime = new bool[upper + 1];

    if (upper > 1) {
        isPrime[0] = false;
        isPrime[1] = true;
    }
    for (i = 2; i <= upper; i++)
        isPrime[i] = true;
    for (i = 2; i <= upperSqrt; i++)
    {
        if (isPrime[i])
        {
            for (j = i * i; j <= upper; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime;
}

int main()
{
    unsigned int num;
    unsigned int hi;
    unsigned int lo;
    bool* low_primes;
    bool* high_primes;

    std::cin >> num;

    while (num--)
    {
        std::cin >> lo;
        std::cin >> hi;
        low_primes = sieve(hi);
        high_primes = new bool[hi - lo + 1];
    }
    return 0;
}

