# Nama File: aljabar.py
# Nama / NIM:
# Tanggal:


def diskriminan(a: int, b: int, c: int) -> float:
    return b**2 - 4*a*c

def akar1(a: int, b: int, c: int) -> float:
    return (-b + (diskriminan(a, b, c) ** 0.5)) / (2 * a)

def akar2(a: int, b: int, c: int) -> float:
    return (-b - (diskriminan(a, b, c) ** 0.5)) / (2 * a)

def Aljabar(a: int, b: int, c: int) -> float:
    if diskriminan(a, b, c) < 0:
        return -999
    else:
        return round(
            min(abs(akar1(a, b, c)), abs(akar2(a, b, c))) /
            max(abs(akar1(a, b, c)), abs(akar2(a, b, c))),
            5
        )


#JANGAN DIUBAH!
print(Aljabar(99, -5, 6))