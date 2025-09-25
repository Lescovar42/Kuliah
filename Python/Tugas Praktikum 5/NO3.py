# Program   : Type Bentukan Garis
# Deskripsi : Program untuk mendefinisikan tipe data segi empat, membuat segi empat, mengecek apakah segi empat tersebut bujur sangkar atau jajargenjang, serta menghitung luas bujur sangkar.
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/30/2024
# **************************************************************
# DEFINISI DAN SPESIFIKASI TYPE
# **************************************************************
# type Line : <x1:real, y1:real, x2:real, y2:real>
    # {<x1, y1, x2, y2> adalah dua titik yang membentuk sebuah garis dalam bidang kartesian}
# **************************************************************
# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# **************************************************************
# MakeLine : 4 real --> Line
    # {MakeLine(a, b, x, y) membentuk sebuah garis dengan dua titik (a, b) dan (x, y)}
# **************************************************************
# DEFINISI DAN SPESIFIKASI SELEKTOR
# **************************************************************
# x1 : Line --> real
    # {x1(L) memberikan koordinat x dari titik pertama (x1, y1) dari garis L}
# y1 : Line --> real
    # {y1(L) memberikan koordinat y dari titik pertama (x1, y1) dari garis L}
# x2 : Line --> real
    # {x2(L) memberikan koordinat x dari titik kedua (x2, y2) dari garis L}
# y2 : Line --> real
    # {y2(L) memberikan koordinat y dari titik kedua (x2, y2) dari garis L}
# **************************************************************
# DEFINISI DAN SPESIFIKASI FUNGSI OPERATOR
# **************************************************************
# gradient : Line --> real / string
    # {gradient(L) menghitung gradien dari garis L. Jika gradien tidak terdefinisi, kembalikan "undefined"}
# linelength : Line --> float
    # {linelength(L) menghitung panjang garis L menggunakan rumus jarak antara dua titik}
# **************************************************************
# DEFINISI DAN SPESIFIKASI PREDIKAT
# **************************************************************
# isSejajar : Line, Line --> boolean
    # {isSejajar(L1,L2) benar jika gradien L1 sama dengan gradien L2 (garis sejajar)}
# **************************************************************
# REALISASI
# **************************************************************
def MakeLine(a, b, x, y):
    return [a, b, x, y]

def x1(L):
    return L[0]

def y1(L):
    return L[1]

def x2(L):
    return L[2]

def y2(L):
    return L[3]

def gradient(L):
    return (y2(L) - y1(L)) / (x2(L) - x1(L)) if (x2(L) - x1(L)) != 0 else "undefined"

def linelength(L):
    if x1(L) == x2(L):
        return abs(y2(L) - y1(L))
    elif y1(L) == y2(L):
        return abs(x2(L) - x1(L))
    else:
        return ((x2(L) - x1(L))**2 + (y2(L) - y1(L))**2)**0.5

def isSejajar(L1, L2):
    return gradient(L1) == gradient(L2)
# **************************************************************
# APLIKASI
# **************************************************************
print("Panjang:", linelength(MakeLine(5, 8, 1, 4)))
print("Apakah sejajar?", isSejajar(MakeLine(5, 8, 1, 4), MakeLine(45, 48, 41, 44)))