/* Bradford Smith (bsmith8)
 * spoj Challenge1 fortytwo.cpp
 * 02/01/2016
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <iostream>

int main()
{
    int n;
    while (std::cin >> n)
    {
        if (n == 42)
            break;
        std::cout << n << std::endl;
    }
}
