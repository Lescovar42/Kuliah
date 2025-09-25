# Nama File : LeastSquare.py
# Pembuat   : Mamat Alkatiri
# Tanggal   : 2 September 2025
# Deskripsi : menentukan dua pasang titik pada koordinat kartesian dan menghasilkan sebuah bilangan riil yang merupakan jarak dari kedia titik tersebut 

# Definisi dan Spesifikasi:
# LeastSquare : 4 float --> float
#   {LeastSquare (x1,y1,x2,y2) adalah jarak antara dua buah titik (x1,y1) dengan (x2,y2) pada koordinat kartesian}

# Definisi dan Spesifikasi Fungsi Antara:
# dif2 : 2 float --> float
#   {dif2 (x,y) adalah kuadrat dari selisih dua buah bilangan real x dan y}
# FX2 : float --> float
#   {FX2 (x) adalah fungsi kuadrat dari x, yaitu x^2}

# Realisasi
def FX2(x: float) -> float:
    return x*x

def dif2(x: float, y: float) -> float:
    return FX2(x-y)

def LeastSquare(x1: float, y1: float, x2: float, y2: float) -> float:
    return (dif2(y2,y1) + dif2(x2,x1))**0.5

# Aplikasi
print(LeastSquare(1,2,5,6)) # 5.656854249492381