def S(n):
    if n == 1:
        return 1
    elif n == 0:
        return 0
    return ((S(n-1))+(3+S(n-2)))

print (S(2))