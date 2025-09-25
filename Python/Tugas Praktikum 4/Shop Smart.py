# Program   : Shop Smart
# Deskripsi : Program untuk menghitung harga akhir suatu barang berdasarkan 
#             kategori, keanggotaan VIP, lokasi pengiriman, dan hari pembelian.
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/23/2024
#**************************************************************
# DEFINISI DAN SPESIFIKASI
# **************************************************************
# hargaAkhir : int, string, boolean, string, string => int
#   hargaAkhir(harga, kategori, VIP, lokasi, hari) menghitung harga akhir dari 
#   suatu barang berdasarkan:
#     - harga: harga awal barang (int),
#     - kategori: kategori barang (elektronik, pakaian, makanan) (string),
#     - VIP: status keanggotaan VIP (boolean),
#     - lokasi: lokasi pengiriman (dalam negeri atau luar negeri) (string),
#     - hari: hari pembelian (string).
#   Fungsi akan memperhitungkan diskon berdasarkan kategori barang dan status VIP,
#   diskon tambahan berdasarkan hari tertentu (Jumat, Sabtu, Rabu, Minggu),
#   dan faktor pengiriman tergantung lokasi (dalam atau luar negeri).
#   Fungsi mengembalikan harga akhir barang (int) yang telah disesuaikan.
# **************************************************************
# REALISASI
# **************************************************************
def hargaAkhir(harga, kategori, VIP, lokasi, hari):
    return int  ((((
                harga * (0.7 if VIP else 0.9) if kategori == "elektronik" else 
                harga * (0.8 if VIP else 0.95) if kategori == "pakaian" else 
                harga * (0.85 if VIP else 0.98) if kategori == "makanan" else 
                harga)
                * (0.95 if (hari == "Jumat" or hari == "Sabtu") and VIP else 1)
                * (0.95 if hari == "Rabu" and kategori == "pakaian" else 1)
                * (1.05 if hari == "Minggu" else 1))
                * (1.10 if lokasi == "dalam negeri" else 1.20
                )))
# **************************************************************
# APLIKASI
# **************************************************************
print(hargaAkhir(500000, "pakaian", False, "luar negeri", "Rabu"))