def f(n):
    if n == 1:
        return 3
    else:
        return f(n-1) + 3

print(f(50))