# Bradford Smith
# CS 370 HackerRank Candies candies.py
# 03/07/2016

numChildren = int(input())
total = 0
candies = 1
prevRating = -1
while (numChildren > 0):
    rating = int(input())
    if ((rating > prevRating) and (prevRating != -1)):
        candies += 1
    elif (rating <= prevRating):
        candies = 1
    total += candies
    prevRating = rating
    numChildren -= 1

#need to store results in lists and make a reverse pass to check the other direction

print(total)
