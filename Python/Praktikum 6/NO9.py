def S(n):
    if n == 1:
        return 1
    return ((S(n-1)   )*3)

print (S(2))