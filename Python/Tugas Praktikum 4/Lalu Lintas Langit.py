# Program   : Lalu Lintas Langit
# Deskripsi : Program untuk memantau kondisi penerbangan pesawat berdasarkan 
#             ketinggian (x), kecepatan (y), dan jumlah bahan bakar (z).
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/23/2024
#**************************************************************
# DEFINISI DAN SPESIFIKASI
# **************************************************************
# monitor_pesawat : 3 real => string
#   monitor_pesawat(x, y, z) menerima tiga input:
#     - x: ketinggian (meter),
#     - y: kecepatan (km/jam),
#     - z: jumlah bahan bakar (liter).
#   Berdasarkan nilai-nilai ini, fungsi akan mengevaluasi kondisi penerbangan
#   dan mengembalikan salah satu dari pesan berikut:
#     - "Terlalu Tinggi" jika ketinggian melebihi 12.000 meter,
#     - "Kecepatan Berbahaya" jika kecepatan di luar rentang 200 hingga 900 km/jam,
#     - "Bahan Bakar Rendah" jika bahan bakar kurang dari 20 liter,
#     - "Aman untuk Mendarat" jika ketinggian < 5000 meter, kecepatan di rentang aman, 
#       dan bahan bakar > 50 liter,
#     - "Berjalan Normal" untuk kondisi yang tidak termasuk dalam kategori di atas.
# **************************************************************
# REALISASI
# **************************************************************
def monitor_pesawat(x, y, z):
    if x > 12000:
        return "Terlalu Tinggi"
    elif y > 900 or y < 200:
        return "Kecepatan Berbahaya"
    elif z < 20:
        return "Bahan Bakar Rendah"
    elif x < 5000 and (y < 900 and y > 200) and z > 50:
        return "Aman untuk Mendarat"
    else:
        return "Berjalan Normal"

# **************************************************************
# APLIKASI
# **************************************************************
print(monitor_pesawat(4000,850,55))