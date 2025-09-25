# Program   : Jam Pasir Ajaib
# Deskripsi : Program untuk memvalidasi input waktu (jam, menit, dan detik)
#             serta menampilkannya jika valid.
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/23/2024
#**************************************************************
# DEFINISI DAN SPESIFIKASI
# **************************************************************
# jam : 3 integer => string
#   jam(j, m, s) memeriksa apakah waktu yang diberikan valid atau tidak. 
#   Waktu dianggap valid jika:
#     - jam (j) berada dalam rentang 0 ≤ j ≤ 24,
#     - menit (m) berada dalam rentang 0 ≤ m ≤ 59,
#     - detik (s) berada dalam rentang 0 ≤ s ≤ 59.
#   Jika waktu valid, fungsi akan mengembalikan string dengan format 
#   "Jam: j, Menit: m, Detik: s". Jika tidak valid, fungsi akan 
#   mengembalikan pesan "Waktu tidak valid".
# **************************************************************
# REALISASI
# **************************************************************
def jam(j, m, s):
    if j > 24 or j < 0:
        return "Waktu tidak valid"
    elif m > 59 or m < 0:
        return "Waktu tidak valid"
    elif s > 59 or s < 0:
        return "Waktu tidak valid"
    else:
        return f"Jam: {j}, Menit: {m}, Detik: {s}"

# **************************************************************
# APLIKASI
# **************************************************************
print(jam(12,45,60))