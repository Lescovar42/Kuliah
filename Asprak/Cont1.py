# Nama File: add.py
# Pembuat: Thomas Shelby
# Tanggal: 30 Februari 2024
# Deskripsi: Menambahkan dua bilangan secara kompleks

# Definisi dan Spesifikasi
# add 2 integer -> integer
# add (a,b) menghitung hasil dari penjumlahan a dan b secara kompleks

#Realisasi
def add (a: int, b: int) -> int:
    return a * 2 + b * 2 - a - b

# Aplikasi
add (4,5) #9
add (7, 20) # 27