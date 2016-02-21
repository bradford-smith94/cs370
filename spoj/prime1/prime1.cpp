/* Aidan Racaniello and Bradford Smith
 * CS 370 SPOJ PRIME1 prime1.cpp
 * 02/21/2016
 * "We pledge our honor that we have abided by the Stevens Honor System."
 */

#include <cmath>
#include <string>
#include <cstring>
#include <iostream>

bool* sieve(int upper)
{
    int i;
    int j;
    int upperSqrt = (int)sqrt((double)upper);
    bool* isPrime = new bool[upper + 1];

    if (upper <= 1) {
        isPrime[0] = false;
        if (upper == 1) {
            isPrime[1] = false;
        }
        return isPrime;
    }
    else {
        isPrime[0] = false;
        isPrime[1] = false;
    }
    for (i = 2; i <= upper; i++)
        isPrime[i] = true;
#ifdef DEBUG
    std::cout << "[DEBUG]\tUpper bound sqrt: " << upperSqrt << std::endl;
#endif
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
    int num; //number of input operations
    int hi; //the upper bound
    int lo; //the lower bound
    int low_prime_bound; //length of low_primes array
    int high_prime_bound; //length of high_primes array
    bool* low_primes;
    bool* high_primes;
    int i; //loop counter
    int p; //loop counter

    //read in number of input operations
    std::cin >> num;

#ifdef DEBUG
    std::cout << "[DEBUG]\tNumber of test cases: " << num << std::endl;
#endif

    //while there are still inputs
    while (num-- > 0)
    {
        //read in lower and upper bounds
        std::cin >> lo;
        std::cin >> hi;

#ifdef DEBUG
        std::cout << "[DEBUG]\tLow: " << lo << " High: " << hi << std::endl;
#endif

        //skip bad inputs
        if (lo > hi || lo <= 0 || hi <= 0)
            continue;

        //do regular sieve to find low_primes
        low_prime_bound = hi + 1;
        low_primes = sieve(hi);

#ifdef DEBUG
        std::cout << "[DEBUG]\tLow primes: ";
        for (i = 0; i < hi + 1; i++)
            if (low_primes[i])
                std::cout << i << " ";
        std::cout << std::endl;
#endif

        //find the overlap
        high_prime_bound = hi - lo + 1;
        high_primes = new bool[high_prime_bound];

        //initialize high_primes to all true
        for (i = 0; i < high_prime_bound; i++)
            high_primes[i] = true;
        //if lower bound is 1 set first element to false (1 isn't prime)
        if (lo == 1)
            high_primes[0] = false;
        //for each prime p in low_primes
        for (p = 0; p < low_prime_bound; p++)
        {
            if (low_primes[p])
            {
                i = ceil((double)lo / p) * p - lo;
                if (lo <= p)
                    i = i + p;
                //from i remove all multiples of p
                for (; i < high_prime_bound; i += p)
                {
                    high_primes[i] = false;
                }
            }
        }

        //print results
        for (i = 0; i < high_prime_bound; i++)
        {
            if (high_primes[i])
                std::cout << i + lo << std::endl;
        }
        std::cout << std::endl;

        //free memory
        delete[] high_primes;
        delete[] low_primes;
    }
    return 0;
}

