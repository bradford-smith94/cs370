# Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
# CS 370 Assignment 5 skyscrapers.py
# 02/29/2016
# "We pledge our honor that we have abided by the Stevens Honor System."

# this loops through skyscrapers and counts connected routes
# however, worst case this will run O(n^2)
def routes(skyscrapers, size):
    count = 0
    for i in range(0, size): #for each building
        for j in range(i + 1, size): #for each building after it
            if skyscrapers[j] > skyscrapers[i]: #if this one is taller than the pervious
                break
            elif skyscrapers[j] == skyscrapers[i]: #else if it is reachable
                count += 2
    return count

# this uses a stack to count connected routes
def routesWithStack(skyscrapers, size):
    count = 0
    stack = [] #stack will store [height, numberOfBuildingsAtThatHeight]
    #stack[-1][0] is height on top of stack (last thing that got added to list)

    #for each skyscraper
    for i in range(0, size):

        #while the stack is not empty and this building is taller than the one on the stack
        while len(stack) != 0 and skyscrapers[i] > stack[-1][0]:
            #there were previous buildings shorter than this one, they cannot reach any further
            item = stack.pop() #pop the previous building off the stack
            count += item[1] * (item[1] - 1) #add the number of that height building * (that number -1)

        #if stack is not empty and this building is the same height as the on on the stack
        if len(stack) != 0 and skyscrapers[i] == stack[-1][0]:
            stack[-1][1] += 1 #increment the number of buildings at this height on the stack
        else:
            stack.append([skyscrapers[i], 1]) #add a new building height to the stack

    #for all buildings still in the stack (any same or decreasing height buildings left)
    for i in stack:
        count += i[1] * (i[1] - 1) #add the number of that height building * (that number -1)
    return count


# Execution starts here
# read inputs
numSkyscrapers = int(input())
skyscrapers = list(map(int, input().split()))

# Print results
#print(routes(skyscrapers, numSkyscrapers))
print(routesWithStack(skyscrapers, numSkyscrapers))
