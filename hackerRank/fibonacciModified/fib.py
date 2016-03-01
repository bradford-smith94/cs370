def fib(n, first, second):
    if n <= 0:
        return 0
    if n == 1:
        return first
    elif n == 2:
        return second
    elif n == 3:
        return pow(second, 2) + first
    else:
        return pow(fib(n - 1, first, second), 2) + fib(n - 2, first, second)

inputs = list(map(int, input().split()))
#inputs[0] is A
#inputs[1] is B
#inputs[2] is C
print(fib(inputs[2], inputs[0], inputs[1]))
