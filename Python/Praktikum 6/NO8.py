def S(n):
    if n == 1:
        return 3
    return S(n-1) + (n*3)

print (S(3))