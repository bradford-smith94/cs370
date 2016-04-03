def isSorted(arr):
    for i in range(0, len(arr) - 1):
        if arr[i] > arr[i+1]:
            return i
    return -1 
    

def findUnsorted(arr):
    index = isSorted(arr)
    if (index >= 0):
        for i in range(index, len(arr)):
            tempArr = arr[:]
            tmp = tempArr[index]
            tempArr[index] = tempArr[i]
            tempArr[i] = tmp
            if (isSorted(tempArr) == -1):
                return "yes\nswap " + str(index + 1) + " " + str(i + 1)
        
        
        num = index + 1
        while (num < (len(arr) - 1) and arr[num] > arr[num + 1]):
            num += 1
        if (num < len(arr)):
            temparr = reversed(arr[index:num])
        if (isSorted(arr[0:index] + list(reversed(arr[index:num])) + arr[num + 1:]) == -1):
            return "yes\nreverse " + str(index + 1) + " " + str(num)
        return "no"
    else:
        return "yes"
    
    
size = int(input())
if (size > 0):
    arr = list(map(int, input().split()))
    print(findUnsorted(arr))