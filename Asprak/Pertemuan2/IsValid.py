# Nama File : IsValid.py
# Pembuat   : Mamat Alkatiri
# Tanggal   : 2 September 2025
# Deskripsi : menentukan apakah sebuah bilangan integer valid

# Definisi dan Spesifikasi:
# IsValid : integer --> boolean
#   {IsValid(x) benar jika (x) bernilai lebih kecil 5 atau lebih besar dari 500}

# Realisasi
def IsValid(x: int) -> bool:
    return x > 5 or x < 500

# Aplikasi
print(IsValid(5))    # False
print(IsValid(0))    # False
print(IsValid(3))    # False
print(IsValid(500))  # False
print(IsValid(6000)) # False
print(IsValid(100))  # True