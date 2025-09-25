# Program   : Jalan Semut
# Deskripsi : Program untuk menghitung jarak terpendek yang ditempuh oleh 
#             semut dari satu titik ke titik lainnya dengan 3 pilihan jalur.
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/23/2024
#**************************************************************
# DEFINISI DAN SPESIFIKASI
# **************************************************************
# jalanSemut : 3 real => real
#   jalanSemut(x, y, z) menghitung jarak terpendek dari tiga jalur
#   yang tersedia dengan menggunakan rumus:
#     - path1 = √((x + y)^2 + z^2)
#     - path2 = √((x + z)^2 + y^2)
#     - path3 = √((y + z)^2 + x^2)
#   Fungsi mengembalikan nilai terkecil dari tiga jalur tersebut 
#   yang telah dibulatkan hingga tiga desimal.
#
# min2 : 2 real => real
#   min2(a, b) menerima dua bilangan real dan mengembalikan nilai 
#   terkecil antara a dan b dengan menggunakan rumus:
#     min(a, b) = (a + b - abs(a - b)) / 2
#
# min3 : 3 real → real
#   min3(w, x, y) menerima tiga bilangan real dan mengembalikan nilai 
#   terkecil antara w, x, dan y dengan menggunakan min2 dua kali.
# **************************************************************
# REALISASI
# **************************************************************
def jalanSemut(x, y, z):
    path1 = ((x + y) ** 2 + z ** 2) ** 0.5
    path2 = ((x + z) ** 2 + y ** 2) ** 0.5
    path3 = ((y + z) ** 2 + x ** 2) ** 0.5
    return round(min3(path1, path2, path3), 3)

def min2(a, b):
    return ((a + b) - abs(a - b)) / 2

def min3(w, x, y):
    return min2(min2(w, x), y)

# **************************************************************
# APLIKASI
# **************************************************************
print(jalanSemut(3,4,5))