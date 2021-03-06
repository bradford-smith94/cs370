# Aidan Racaniello, Bradford Smith, and Nicholas Zubrycki
# CS 370 Assignment 6 SPOJ #33 TRIP
# 03/14/2016
# "We pledge our honor that we have abided by the Stevens Honor System."

def lcs(x, y):
    n = len(x)
    m = len(y)
    tMax = 0
    table = [[0 for x in range(m+1)] for x in range(n+1)]

    for i in range(n+1):     # i=0,1,...,n
        for j in range(m+1):  # j=0,1,...,m
            if i == 0 or j == 0:
                table[i][j] = 0
            elif x[i-1] == y[j-1]:
                table[i][j] = table[i-1][j-1] + 1
                if table[i][j] > tMax:
                    tMax = table[i][j]
            else:
                table[i][j] = max(table[i-1][j], table[i][j-1])
                if table[i][j] > tMax:
                    tMax = table[i][j]
# these are the DEBUG print statements
#    print(tMax)
#    print(table)

    # Now, table[n][m] is the length of LCS of x and y.

    # Let's go one step further and reconstruct
    # the actual sequence from DP table:

    def recon(i, j):
        if i == 0 or j == 0:
            return []
        elif x[i-1] == y[j-1]:
            return recon(i-1, j-1) + [x[i-1]]
        elif table[i-1][j] > table[i][j-1]:
            return recon(i-1, j)
        else:
            return recon(i, j-1)

    print(''.join(recon(n, m)))

# this is the attempt at finding multiple LCS'
#    for i in range(1, n+1):
#        for j in range(1, m+1):
#            s = ''.join(recon(n, m))
#            if len(s) == tMax:
#                print(s)


# Execution starts here
# read inputs
numTests = int(input())
while (numTests > 0):
    a = input()
    b = input()
    lcs(a, b)
    numTests -= 1

