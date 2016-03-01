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

numSkyscrapers = int(input())
skyscrapers = list(map(int, input().split()))
print(2*routesForward(skyscrapers, numSkyscrapers))
