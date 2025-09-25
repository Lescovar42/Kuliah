# Program   : Belajar Tenang
# Deskripsi : Program untuk menghitung jarak berdasarkan level suara (dB)
#             dan membandingkannya dengan jarak yang diinginkan (m).
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/23/2024
#**************************************************************
# DEFINISI DAN SPESIFIKASI
# **************************************************************
# calcDist : real ==> real
#   calcDist(L1) menghitung jarak (dalam meter) dari sumber suara 
#   berdasarkan level suara L1 (dB). Rumus yang digunakan adalah 
#   15 * 10^((L1-40)/20).
#
# BelajarTenang : 2 real ==> string
#   BelajarTenang(dB, m) akan mengecek jarak yang dihitung menggunakan 
#   fungsi calcDist(dB), lalu membandingkannya dengan m. Jika jarak 
#   yang dihitung lebih kecil dari m, akan mengembalikan jarak dalam 
#   meter dengan format "{distance:.3f} meter". Jika tidak, akan 
#   mengembalikan "Isi bensin dulu, bang".
# **************************************************************
# REALISASI
# **************************************************************
def calcDist(L1):
    return 15 * 10 ** ((L1 - 40) / 20)

def BelajarTenang(dB, m):
    distance = calcDist(dB)
    if distance < m:
        return f"{distance:.3f} meter"
    else:
        return "Isi bensin dulu, bang"

# **************************************************************
# APLIKASI
# **************************************************************
print(BelajarTenang(50,5000))