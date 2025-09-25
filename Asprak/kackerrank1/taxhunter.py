# Nama File: TaxCollector.py
# Nama / NIM:
# Tanggal:


def pajak(g: float) -> float:
    if g < 50.0:
        return 0.15
    elif g >= 50.0 and g <= 150.0:
        return 0.1
    elif g > 150.0 and g <= 500.0:
        return 0.05
    elif g > 500.0:
        return 0.0
    
def kali(a, b):
    return a*b
    
def TaxCollector(G: float, J: int) -> float:
    return kali(G, J) - (G*J * pajak(G))


#JANGAN DIUBAH!
print(eval(input()))