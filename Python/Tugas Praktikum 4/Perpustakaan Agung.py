# Program   : Perpustakaan Agung
# Deskripsi : Program untuk memperkirakan aktivitas atau jumlah pengunjung di perpustakaan 
#             berdasarkan data historis dan parameter waktu, siang atau malam, serta 
#             berbagai variabel lainnya.
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/23/2024
#**************************************************************
# DEFINISI DAN SPESIFIKASI
# **************************************************************
# EstimateGreatLib : string, 8 integer => real
#   EstimateGreatLib(D, X, Y, SS, SR, AS, AM, AIP, R) menerima:
#     - D: hari dalam seminggu,
#     - X: jam mulai,
#     - Y: jam berakhir,
#     - SS: batas jam siang,
#     - SR: batas jam malam,
#     - AS: data aktivitas siang,
#     - AM: data aktivitas malam,
#     - AIP: data aktivitas individual,
#     - R: rasio.
#   Fungsi akan memperkirakan nilai aktivitas berdasarkan jam
#   dan apakah waktu tersebut siang atau malam. Data historis yang tersedia 
#   dalam dictionary digunakan untuk membantu dalam perhitungan.
#   Fungsi mengembalikan hasil estimasi yang dibulatkan hingga 5 desimal.
#
# calc_estimate : integer, boolean => real
#   calc_estimate(time, is_night) adalah fungsi lokal di dalam EstimateGreatLib.
#   Fungsi ini digunakan untuk menghitung estimasi berdasarkan lamanya waktu (time)
#   dan apakah waktunya malam (is_night). Jika is_night bernilai True, rumus perhitungan
#   berbeda dari siang, dan R (rasio) digunakan untuk menyesuaikan hasil.
# **************************************************************
# REALISASI
# **************************************************************
def EstimateGreatLib(D, X, Y, SS, SR, AS, AM, AIP, R):
    history = {
        "senin": [5000, 6000, 4000],
        "selasa": [7000, 5000, 2000],
        "rabu": [4500, 3500, 3000],
        "kamis": [2900, 2100, 2000],
        "jumat": [3000, 3000, 3000],
        "sabtu": [2000, 2500, 2300],
        "minggu": [1100, 900, 1000]
    }
    
    def calc_estimate(time, is_night):
        range_val = max(AS, AM, AIP) - min(AS, AM, AIP)
        avg = sum(history[D]) / 3

        if is_night:
            return ((time * range_val) / avg) * R / 100
        else:
            return (time * range_val) / avg

    if X >= SR and Y <= SS:
        hasil = calc_estimate(Y - X, False)

    elif X >= SS or Y <= SR:
        hasil = calc_estimate(Y - X, True)

    elif X < SR and Y > SR and Y <= SS:
        hasil = (calc_estimate(SR - X, True) + calc_estimate(Y - SR, False))/2 #ternyata

    elif X >= SR and X < SS and Y > SS:
        hasil = (calc_estimate(SS - X, False) + calc_estimate(Y - SS, True))/2 #ternyata kurang dibagi

    elif X < SR and Y > SS:
        hasil = (calc_estimate(SR - X, True) + calc_estimate(SS - SR, False) + calc_estimate(Y - SS, True))/3 #plis

    return round(hasil, 5)
# **************************************************************
# APLIKASI
# **************************************************************
print(EstimateGreatLib("jumat", 7, 8, 17, 6, 4000, 5500, 5000, 3))