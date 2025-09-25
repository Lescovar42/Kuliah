# Nama File : IsPositif.py
# Pembuat   : Mamat Alkatiri
# Tanggal   : 2 September 2025
# Deskripsi : menentukan apakah sebuah bilangan integer positif

# Definisi dan Spesifikasi:
# IsPositif : integer --> boolean
#   {IsPositif(x) benar jika x positif}

# Realisasi
def IsPositif(x: int) -> bool:
    return x > 0

# Aplikasi
print(IsPositif(1))  # True
print(IsPositif(0))  # False
print(IsPositif(-1))  # False
