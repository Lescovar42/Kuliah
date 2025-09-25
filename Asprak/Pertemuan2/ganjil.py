def ganjil(x:int) -> bool:
    if x %2!=0:
        return True
    else:
        return False

print(ganjil(5))
print(ganjil(12))

def angkaipk(x: float) -> str:
    if (x <= 4.0 and x > 3.0):
        return 'A'
    elif (x <= 3.0 and x >= 2.0):
        return 'B'
    elif (x <= 2.0 and x >= 1.0):
        return 'C'
    elif (x <= 1.0 and x >= 0.0):
        return 'D'
    else:
        return "error"

print(angkaipk(3.2))
print(angkaipk(2.9))
print(angkaipk(0.5))
