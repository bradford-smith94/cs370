# Bradford Smith
# CS 370 HackerRank Maximum Subarray subarrays.py
# 03/07/2016

# Kadane's Algorithm

def doThings(array):
    max_max = array[0] #max contiguous subarray sum
    super_max = array[0] #max non-contiguous subarray sum
    max_ending_here = array[0]
    for i in range(1, len(array)):
        max_ending_here += array[i]
        if (max_ending_here < 0):
            max_ending_here = 0
        if (max_max < max_ending_here):
            max_max = max_ending_here
    print(max_max + " " + super_max)


numCases = int(input())
if (numCases > 0):
    size = int(input())
    if (size > 0):
        array = list(map(int, input().split()))
        if (len(array) == numCases):
            doThings(array)
