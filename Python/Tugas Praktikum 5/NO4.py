# Program   : Tipe Bentukan Segi Empat
# Deskripsi : Program untuk mendefinisikan tipe data segi empat, membuat segi empat, mengecek apakah segi empat tersebut bujur sangkar atau jajargenjang, serta menghitung luas bujur sangkar.
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/30/2024
# **************************************************************
# DEFINISI DAN SPESIFIKASI TYPE
# **************************************************************
# type SegiEmpat : <x1:real, y1:real, x2:real, y2:real, x3:real, y3:real, x4:real, y4:real>
#   {<x1, y1, x2, y2, x3, y3, x4, y4> adalah empat titik yang membentuk sebuah segi empat dalam bidang kartesian.}
# **************************************************************
# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# **************************************************************
# MakeSegiEmpat : 8 real --> SegiEmpat
#   {MakeSegiEmpat(x1, y1, x2, y2, x3, y3, x4, y4) membentuk tipe SegiEmpat dengan 4 titik (x1, y1), (x2, y2), (x3, y3), dan (x4, y4)}
# **************************************************************
# DEFINISI DAN SPESIFIKASI SELEKTOR
# **************************************************************
# x1 : SegiEmpat --> real
#   {x1(S) memberikan koordinat x dari titik pertama (x1, y1) dari segi empat S}
# y1 : SegiEmpat --> real
#   {y1(S) memberikan koordinat y dari titik pertama (x1, y1) dari segi empat S}
# x2 : SegiEmpat --> real
#   {x2(S) memberikan koordinat x dari titik kedua (x2, y2) dari segi empat S}
# y2 : SegiEmpat --> real
#   {y2(S) memberikan koordinat y dari titik kedua (x2, y2) dari segi empat S}
# x3 : SegiEmpat --> real
#   {x3(S) memberikan koordinat x dari titik ketiga (x3, y3) dari segi empat S}
# y3 : SegiEmpat --> real
#   {y3(S) memberikan koordinat y dari titik ketiga (x3, y3) dari segi empat S}
# x4 : SegiEmpat --> real
#   {x4(S) memberikan koordinat x dari titik keempat (x4, y4) dari segi empat S}
# y4 : SegiEmpat --> real
#   {y4(S) memberikan koordinat y dari titik keempat (x4, y4) dari segi empat S}
# **************************************************************
# DEFINISI DAN SPESIFIKASI PREDIKAT
# **************************************************************
# isBujurSangkar : SegiEmpat --> boolean
#   {isBujurSangkar(S) benar jika S adalah bujur sangkar, semua sisi sama panjang dan sudut siku-siku.}
# isJajargenjang : SegiEmpat --> boolean
#   {isJajargenjang(S) benar jika S adalah jajar genjang, sisi yang berlawanan sama panjang.}
# AreaBujurSangkar : SegiEmpat --> real / string
#   {AreaBujurSangkar(S) menghitung luas bujur sangkar jika S adalah bujur sangkar, jika tidak, mengembalikan pesan "Bukan Bujur Sangkar".}
# **************************************************************
# REALISASI
# **************************************************************
def MakeSegiEmpat(x1, y1, x2, y2, x3, y3, x4, y4):
    return [x1, y1, x2, y2, x3, y3, x4, y4]

def x1(S):
    return S[0]

def y1(S):
    return S[1]

def x2(S):
    return S[2]

def y2(S):
    return S[3]

def x3(S):
    return S[4]

def y3(S):
    return S[5]

def x4(S):
    return S[6]

def y4(S):
    return S[7]

def distance(x1, y1, x2, y2):
    return ((x2 - x1)**2 + (y2 - y1)**2)**0.5

def isBujurSangkar(S):
    return (distance(x1(S), y1(S), x2(S), y2(S)) == distance(x2(S), y2(S), x3(S), y3(S)) == 
            distance(x3(S), y3(S), x4(S), y4(S)) == distance(x4(S), y4(S), x1(S), y1(S)) and
            isRightAngle(S))

def dotProduct(x1, y1, x2, y2, x3, y3):
    return (x2 - x1) * (x3 - x2) + (y2 - y1) * (y3 - y2)

def isRightAngle(S):
    return (dotProduct(x1(S), y1(S), x2(S), y2(S), x3(S), y3(S)) == 0 and
            dotProduct(x2(S), y2(S), x3(S), y3(S), x4(S), y4(S)) == 0 and
            dotProduct(x3(S), y3(S), x4(S), y4(S), x1(S), y1(S)) == 0 and
            dotProduct(x4(S), y4(S), x1(S), y1(S), x2(S), y2(S)) == 0)

def isJajargenjang(S):
    return (distance(x1(S), y1(S), x2(S), y2(S)) == distance(x3(S), y3(S), x4(S), y4(S)) and
            distance(x2(S), y2(S), x3(S), y3(S)) == distance(x4(S), y4(S), x1(S), y1(S)))

def AreaBujurSangkar(S):
    if isBujurSangkar(S):
        return distance(x1(S), y1(S), x2(S), y2(S)) ** 2
    else:
        return "Bukan Bujur Sangkar"
# **************************************************************
# APLIKASI
# **************************************************************
print("Apakah Bujur Sangkar?", isBujurSangkar(MakeSegiEmpat(0, 0, 0, -2, -2, 2, 2, 0)))
print("Jajar Genjang?", isJajargenjang(MakeSegiEmpat(0, 0, 0, -2, -2, 2, 2, 0)))
print("Luas Bujur Sangkar:", AreaBujurSangkar(MakeSegiEmpat(0, 0, 0, -2, -2, 2, 2, 0)))