# Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
# CS 370 Group Project 1 SPOJ CPCRC1C
# 04/09/2016
# "We pledge our honor that we have abided by the Stevens Honor System."

# pre: takes in an integer `x` and integer `mult`
# post: computes the sum of the digits of the numbers from 1 to `x`
# return: an integer of the computed sum
def onetox(x, mult):
    # if we can find the sum from 1 to x
    # we can then find the sum from 1 to y
    # then we can run the sumofdigits(x, y) and just subtract onetox(x-1) from onetox(y)
    if(x <= 0): return 0
    if(x > 1000000000): return 0
    
    return (sum(range(0, x % 10 + 1)) * mult) + (sum(map(int, str(x // 10))) * (1 + (x % 10)) * mult) + ((x // 10) * 45 * mult) + onetox(x // 10 - 1, mult * 10)
    
# main execution starts here
while True:
    # read inputs into `line`
    line = list(map(int, input().split()))
    if (len(line) == 2):
        a = line[0] #`a` is the first number
        b = line[1] #`b` is the second number
    else: #incorrect number of numbers on a line, ignore and continue
        continue
    
    # if both inputs are -1 end execution
    if a == -1 and b == -1:
        break
    elif a == -1 or b == -1: #if either are -1 ignore and continue
        continue
    
    # onetox of b with mult 1, and onetox of a - 1 with mult 1
    print(onetox(b, 1) - onetox(a - 1, 1))
    