# Nama File: determine.py
# Nama / NIM:
# Tanggal:


def isPrime(n: int) -> bool:
    if n == 2 or n == 3 or n == 5 or n == 7:
        return True
    if n < 2:
        return False
    elif n % 2 == 0:
        return False
    elif n % 3 == 0:
        return False
    elif n % 5 == 0:
        return False
    elif n % 7 == 0:
        return False
    else:
        return True
    
def Determine(n: int) -> str:
    if isPrime(n):
        return "Ya"
    else:
        return "Tidak"

#JANGAN DIUBAH!
print(Determine(96))