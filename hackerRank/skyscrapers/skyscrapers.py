# Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
# CS 370 Assignment 5 skyscrapers.py
# 02/29/2016
# "We pledge our honor that we have abided by the Stevens Honor System."

def routesForward(skyscrapers, size):
    count = 0
    for i in range(0, size):
        for j in range(i + 1, size):
            if skyscrapers[j] > skyscrapers[i]:
                break
            elif skyscrapers[j] == skyscrapers[i]:
                count += 1
    return count

def routesWithStack(skyscrapers, size):
    count = 0
    stack = []
    for i in range(0, size):
        while len(stack) != 0 and skyscrapers[i] > stack[-1][0]:
            item = stack.pop()
            if item[1] > 1:
                count += item[1] * (item[1] - 1)
        if len(stack) != 0 and skyscrapers[i] == stack[-1][0]:
            stack[-1][1] += 1
        else:
            stack.append([skyscrapers[i], 1])
    for i in stack:
        count += i[1] * (i[1] - 1)
    return count

numSkyscrapers = int(input())
skyscrapers = list(map(int, input().split()))
#print(2*routesForward(skyscrapers, numSkyscrapers))
print(routesWithStack(skyscrapers, numSkyscrapers))
