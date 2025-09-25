# Program   : Gradien Magis
# Deskripsi : Program untuk menghitung gradien (kemiringan garis) 
#             antara dua titik pada fungsi kuadrat f(x).
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/23/2024
#**************************************************************
# DEFINISI DAN SPESIFIKASI
# **************************************************************
# f : real => real
#   f(x) adalah fungsi kuadrat yang didefinisikan sebagai 
#   f(x) = 3x^2 + 2x - 5.
#
# gradien : 2 real => real/string
#   gradien(a, b) menghitung gradien atau kemiringan garis antara
#   dua titik pada fungsi f(x) di x = a dan x = b, dengan rumus 
#   gradien = (f(a) - f(b)) / (a - b). Jika a sama dengan b, 
#   fungsi mengembalikan pesan "a != b".
# **************************************************************
# REALISASI
# **************************************************************
def f(x):
    return 3 * x ** 2 + 2 * x - 5

def gradien(a, b):
    if a == b:
        return "a != b"
    else:
        return (f(a) - f(b)) / (a - b)

# **************************************************************
# APLIKASI
# **************************************************************
print(gradien(1,5))