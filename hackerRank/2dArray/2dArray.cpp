/* Bradford Smith (bsmith8)
 * HackerRank 2dArray.cpp
 * 02/08/2016
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <vector>
#include <iostream>
#include <climits>

int sumHourglass(int x, int y, std::vector<std::vector<int>> v)
{
    int sum = 0;
    int i;
    int j;

    if ((x + 2) < v.size() && (y + 2) < v[x].size())
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if ((j == 1 || j == 2) && i == 1)
                    continue;
                sum += v[x + i][y + j];
            }
        }
    }

    return sum;
}

int main()
{
    std::vector<std::vector<int>> arr(6, std::vector<int>(6));
    int arr_i;
    int arr_j;
    int m;
    int temp;

    for(arr_i = 0;arr_i < 6;arr_i++)
    {
        for(arr_j = 0;arr_j < 6;arr_j++)
        {
            std::cin >> arr[arr_i][arr_j];
        }
    }

    m = INT_MIN;
    for (arr_i = 0; arr_i < arr.size(); arr_i++)
    {
        for (arr_j = 0; arr_j < arr[arr_i].size(); arr_j++)
        {
            temp = sumHourglass(arr_i, arr_j, arr);
            if (temp > m)
                m = temp;
        }
    }

    std::cout << m << std::endl;

    return 0;
}
