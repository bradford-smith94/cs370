# Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
# CS 370 Assignment 5 skyscrapers.py
# 02/29/2016
# "We pledge our honor that we have abided by the Stevens Honor System."

def routesForward(skyscrapers):
    count = 0
    for i in range(0, len(skyscrapers)):
        height = skyscrapers[i]
        for j in range(i + 1, len(skyscrapers)):
            if skyscrapers[j] == height:
                count += 1
            elif skyscrapers[j] > height:
                break
    return count

numSkyscrapers = int(input())
skyscrapers = list(map(int, input().split()))
print(2*routesForward(skyscrapers))
