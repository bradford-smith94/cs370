# Bradford Smith
# CS 370 Project Euler pandigitalProds.py
# 03/28/2016

import itertools

permutations = list(itertools.permutations([1,2,3,4,5,6,7,8,9]))

res = []
for p in permutations:
    a = int(''.join(map(str, p[0:2]))) #first two digits
    b = int(''.join(map(str, p[2:5]))) #next three digits
    c = int(''.join(map(str, p[5:9]))) #last four digits
    if a * b == c:
        #print(a, b, c)
        res.append(c)

    a = int(''.join(map(str, p[0:1]))) #first digit
    b = int(''.join(map(str, p[1:5]))) #next four digits
    c = int(''.join(map(str, p[5:9]))) #last four digits
    if a * b == c:
        #print(a, b, c)
        res.append(c)

res = list(set(res))
#sum these

print(res)
