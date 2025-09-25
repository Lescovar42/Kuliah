# Nama File : IsAnA.py
# Pembuat   : Mamat Alkatiri
# Tanggal   : 2 September 2025
# Deskripsi : menentukan apakah sebuah karakter adalah huruf A

# Definisi dan Spesifikasi:
# IsAnA : karakter --> boolean
#   {IsAnA (C) benar jika c adalah huruf A}

# Realisasi
def IsAnA(c: str) -> bool:
    return c == 'A'

# Aplikasi
print(IsAnA('1'))  # False
print(IsAnA('0'))  # False
print(IsAnA('-1'))  # False
print(IsAnA('a'))  # False
print(IsAnA('A'))  # True