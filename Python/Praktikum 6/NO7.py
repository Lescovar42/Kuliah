def seq(n):
    if n == 1:
        return 1
    else:
        return n+seq(n-1)

print(seq(2))