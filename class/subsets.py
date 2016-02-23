# Bradford Smith (bsmith8)
# CS 370
# 02/22/2016
# "I pledge my honor that I have abided by the Stevens Honor System."


# return whether or not a target sum is possible
def subset(target, lst):
    if target == 0:
        return True
    if lst == []: #if not lst
        return False
    return subset(target - lst[0], lst[1:]) or subset(target, lst[1:])

# return whether or not a target sum is possible and the numbers that make it
# possible e.g. (target, lst) -> [True, [2, 5]]
def subset_with_values(target, lst):
    if target == 0:
        return [True, []]
    if not lst:
        return [False, []]
    use_it = subset_with_values(target - lst[0], lst[1:])
    if use_it[0]:
        return [True, [lst[0]] + use_it[1]]
    return subset_with_values(target, lst[1:])

# return whether or not a target sum is possible and all the numbers that make
# it possible
def subset_helper(target, lst):
    if target == 0:
        return (True, [[]])
    if lst == []:
        return (False, [[]])
    result = (False, [[]])
    use_it = subset_helper(target - lst[0], lst[1:])
    if use_it[0]:
        for solution in use_it[1]:
            solution.append(lst[0])
        result = (True, use_it[1])
    lose_it = subset_helper(target, lst[1:])
    if lose_it[0]:
        result = (True, lose_it[1] + result[1]) if result[0] else (True, lose_it[1])
    return result

def all_subsets(target, lst):
    result = subset_helper(target, lst)
    if result[0]:
        for subset in result[1]:
            subset.sort()
        result[1].sort()
        deduped = [result[1][0]]
        for i in range(1, len(result[1])):
            if result[1][i] != deduped[-1]:
                deduped.append(result[1][i])
            return (True, deduped)
        return result

# return whether or not a target sum is possible
def subset_sum(target, lst):
    s = 0
    for i in lst:
        s += lst[i]
    table = [False]*s
    table[0] = True

    for i in range(0, len(lst)):
        for j in range(len(table) - 1, -1, -1):
            if table[j]: #or table[j - lst[i]]:
                table[j] = True
            elif j - lst[i] >= 0 and table[j - lst[i]]:
                table[j] = True

    return table[target]

# return the smallest value that cannot be achieved by a subset
# URI online judge #1690
def uri_subset_sum(lst):
    s = 0
    for i in range(0, len(lst)):
        s += lst[i]
    table = [False]*s
    table[0] = True

    for i in range(0, len(lst)):
        for j in range(len(table) - 1, -1, -1):
            if table[j]: #or table[j - lst[i]]:
                table[j] = True
            elif j - lst[i] >= 0 and table[j - lst[i]]:
                table[j] = True

    for i in range(0, len(table)):
        if not table[i]:
            return i
    return len(table)


