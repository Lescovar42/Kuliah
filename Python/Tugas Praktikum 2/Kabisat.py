    # Program   : Hari-ke (dengan kabisat)
    # Deskripsi : Sebuah fungsi yang menghitung jumlah hari dari awal tahun sampai ke hari yang dimasukan. Fungsi
    #             ini memperhitungkan apakah sebuah tahun kabisat atau tidak.
    # NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
    # Tanggal   : 09/16/2024
    #**************************************************************
    # DEFINISI DAN SPESIFIKASI
    # harike1900 : integer[1,...,31], integer[1,...,12], integer[0,...,99] ---> integer [1,...,366]
    #   harike1900(d,m,y) dari suatu tanggal <d,m,y> adalah hari 'absolut' dihitung mulai 1
    #   Januari 1900+y. 1 Januari tahun 1900+y adalah hari ke 1
    # dpm : integer[1,...,12] ---> integer [1,...,36]
    #   dpm(b) adalah jumlah hari pada tahun ybs pada tanggal 1 bulan B. terhitung mulai satu
    #   januari: kumulatif jumlah hari dari tanggal 1 Januari s/d tanggal 1 bulan B, tanpa
    #   memperhitungkan tahun kabisat}
    # IsKabisat : integer[0,...,99] ---> boolean
    #   IsKabisat(y) true jika tahun 1900+y adalah tahun kabisat: habis dibagi 4 tetapi tidak
    #   habis dibagi 100, atau habis dibagi 400}
    # **************************************************************
    # REALISASI
    # **************************************************************
def harike1900(d, m, y):
    if m > 2 and IsKabisat(y):
        return dpm(m) + d
    else:
        return dpm(m) + d - 1

def dpm(b):
    if b == 1:
        return 1
    elif b == 2:
        return 32
    elif b == 3:
        return 60
    elif b == 4:
        return 91
    elif b == 5:
        return 121
    elif b == 6:
        return 152
    elif b == 7:
        return 182
    elif b == 8:
        return 213
    elif b == 9:
        return 244
    elif b == 10:
        return 274
    elif b == 11:
        return 305
    elif b == 12:
        return 335

def IsKabisat(y):
    return ((y % 4 == 0) and (y % 100 != 0)) or (y % 400 == 0)

print(harike1900(29,2,4))