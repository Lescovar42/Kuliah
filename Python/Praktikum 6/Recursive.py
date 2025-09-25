def fac(n): #factorial
    if n == 1: #base 1
        return 1
    else:
        return n*fac(n-1)
    
def faciter(n,count,hasil):
    if n == count:
        return hasil*count
    else:
        return faciter(n,count+1,hasil*count)

def callfaciter(n):
    return faciter(n,1,1)

print(callfaciter(10))