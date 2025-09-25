# Program   : Tipe bentukan mahasiswa
# Deskripsi : Tipe bentukan yang merepresentasikan data mahasiswa, nilai, dan mata kulah.
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/30/2024
# **************************************************************
# DEFINISI DAN SPESIFIKASI TYPE
#     type MHS1 : <NIM: integer, Nama: string, TanggalLahir: date>
#         { <NIM: integer, Nama: string, TanggalLahir: date> merepresentasikan sebuah mahasiswa dalam bidang 1 dimensi. NIM adalah nomor identifikasi mahasiswa, Nama adalah nama mahasiswa, dan TanggalLahir adalah tanggal lahir mahasiswa }
#     type MHS2 : <NIM: integer, KodeMatkul: string, Nilai: real>
#         { <NIM: integer, KodeMatkul: string, Nilai: real> merepresentasikan sebuah mahasiswa dalam bidang 2 dimensi. NIM adalah nomor identifikasi mahasiswa, KodeMatkul adalah kode matkul mahasiswa, dan Nilai adalah nilai mahasiswa }
#     type MHS3 : <KodeMatkul: string, NamaMatkul: string>
#         { <KodeMatkul: string, NamaMatkul: string> merepresentasikan sebuah matkul dalam bidang 1 dimensi. KodeMatkul adalah kode matkul, dan NamaMatkul adalah nama matkul }
#     type RangeNilai : <KodeMatkul: string, NilaiTertinggi: real, NilaiTerendah: real, RangeNilai: real>
#         { <KodeMatkul: string, NilaiTertinggi: real, NilaiTerendah: real, RangeNilai: real> merepresentasikan sebuah range nilai dalam bidang 2 dimensi. KodeMatkul adalah kode matkul, NilaiTertinggi adalah nilai tertinggi, NilaiTerendah adalah nilai terendah, dan RangeNilai adalah range nilai }
# **************************************************************
# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
#     MakeMHS1 : integer, string, date → MHS1
#         { MakeMHS1(NIM, Nama, TanggalLahir) membentuk sebuah mahasiswa dengan informasi NIM, Nama, dan TanggalLahir }
#     MakeMHS2 : integer, string, real → MHS2
#         { MakeMHS2(NIM, KodeMatkul, Nilai) membentuk sebuah mahasiswa dengan informasi NIM, KodeMatkul, dan Nilai }
#     MakeMHS3 : string, string → MHS3
#         { MakeMHS3(KodeMatkul, NamaMatkul) membentuk sebuah matkul dengan informasi KodeMatkul dan NamaMatkul }
#     MakeRangeNilai : string, real, real, real → RangeNilai
#         { MakeRangeNilai(KodeMatkul, NilaiTertinggi, NilaiTerendah, RangeNilai) membentuk sebuah range nilai dengan informasi KodeMatkul, NilaiTertinggi, NilaiTerendah, dan RangeNilai }
# **************************************************************
# DEFINISI DAN SPESIFIKASI OPERATOR
#     HitungRangeNilai : 4 MHS2 → RangeNilai
#         { HitungRangeNilai(MHS2) menghitung range nilai dari MHS2 }
# **************************************************************
# DEFINISI DAN SPESIFIKASI SELEKTOR
#     MHS1Nim : MHS1 → integer
#         { MHS1Nim(MHS1) memberikan informasi NIM dari MHS1 }
#     MHS1Nama : MHS1 → string
#         { MHS1Nama(MHS1) memberikan informasi Nama dari MHS1 }
#     MHS1TanggalLahir : MHS1 → date
#         { MHS1TanggalLahir(MHS1) memberikan informasi TanggalLahir dari MHS1 }
#     MHS2Nim : MHS2 → integer
#         { MHS2Nim(MHS2) memberikan informasi NIM dari MHS2 }
#     MHS2KodeMatkul : MHS2 → string
#         { MHS2KodeMatkul(MHS2) memberikan informasi KodeMatkul dari MHS2 }
#     MHS2Nilai : MHS2 → real
#         { MHS2Nilai(MHS2) memberikan informasi Nilai dari MHS2 }
#     MHS3KodeMatkul : MHS3 → string
#         { MHS3KodeMatkul(MHS3) memberikan informasi KodeMatkul dari MHS3 }
#     MHS3NamaMatkul : MHS3 → string
#         { MHS3NamaMatkul(MHS3) memberikan informasi NamaMatkul dari MHS3 }
#     RangeNilaiKodeMatkul : RangeNilai → string
#         { RangeNilaiKodeMatkul(RangeNilai) memberikan informasi KodeMatkul dari RangeNilai }
#     RangeNilaiNilaiTertinggi : RangeNilai → real
#         { RangeNilaiNilaiTertinggi(RangeNilai) memberikan informasi NilaiTertinggi dari RangeNilai }
#     RangeNilaiNilaiTerendah : RangeNilai → real
#         { RangeNilaiNilaiTerendah(RangeNilai) memberikan informasi NilaiTerendah dari RangeNilai }
#     RangeNilaiRangeNilai : RangeNilai → real
#         { RangeNilaiRangeNilai(RangeNilai) memberikan informasi RangeNilai dari RangeNilai }
# **************************************************************
# DEFINISI DAN SPESIFIKASI FUNGSI TAMBAHAN
#     max4 : 4 integer >0 → integer 
#         {max4 (i,j,k,l) menentukan maksimum dari 4 buah bilangan integer} 
#     min4 : 4 integer > 0 → integer 
#         {min4 (i,j,k,l) menentukan minimum dari 4 buah bilangan integer} 
#     max2 : 2 integer > 0 → integer 
#         {max2 (a,b) menentukan maksimum dari 2 bilangan intege, hanya dengan ekspresi aritmatika: jumlah dari kedua bilangan ditambah denganselisih kedua bilangan, hasilnya dibagi 2} 
#     min2 : 2 integer > 0 → integer 
#         {min2 (a,b) menentukan minimum dari 2 bilangan integer, , hanya dengan ekspresi aritmatika :jumlah dari kedua bilangan – selisih kedua bilangan , hasilnya dibagi 2} 
# **************************************************************
# Realisasi
# **************************************************************

def MakeMHS1(NIM, Nama, TanggalLahir):
    return [NIM, Nama, TanggalLahir]


def MHS1Nim(MHS1):
    return MHS1[0]


def MHS1Nama(MHS1):
    return MHS1[1]


def MHS1TanggalLahir(MHS1):
    return MHS1[2]


def MakeMHS2(NIM, KodeMatkul, Nilai):
    return [NIM, KodeMatkul, Nilai]


def MHS2Nim(MHS2):
    return MHS2[0]


def MHS2KodeMatkul(MHS2):
    return MHS2[1]


def MHS2Nilai(MHS2):
    return MHS2[2]


def MakeMHS3(KodeMatkul, NamaMatkul):
    return [KodeMatkul, NamaMatkul]


def MHS3KodeMatkul(MHS3):
    return MHS3[0]


def MHS3NamaMatkul(MHS3):
    return MHS3[1]


def MakeRangeNilai(KodeMatkul, NilaiTertinggi, NilaiTerendah, RangeNilai):
    return [KodeMatkul, NilaiTertinggi, NilaiTerendah, RangeNilai]


def RangeNilaiKodeMatkul(RangeNilai):
    return RangeNilai[0]


def RangeNilaiNilaiTertinggi(RangeNilai):
    return RangeNilai[1]


def RangeNilaiNilaiTerendah(RangeNilai):
    return RangeNilai[2]


def RangeNilaiRangeNilai(RangeNilai):
    return RangeNilai[3]


def hitungRangeNilai(MHS2satu, MHS2dua, MHS2tiga, MHS2empat):
    return MakeRangeNilai(
        MHS2KodeMatkul(MHS2satu),
        max4(
            MHS2Nilai(MHS2satu),
            MHS2Nilai(MHS2dua),
            MHS2Nilai(MHS2tiga),
            MHS2Nilai(MHS2empat),
        ),
        min4(
            MHS2Nilai(MHS2satu),
            MHS2Nilai(MHS2dua),
            MHS2Nilai(MHS2tiga),
            MHS2Nilai(MHS2empat),
        ),
        max4(
            MHS2Nilai(MHS2satu),
            MHS2Nilai(MHS2dua),
            MHS2Nilai(MHS2tiga),
            MHS2Nilai(MHS2empat),
        )
        - min4(
            MHS2Nilai(MHS2satu),
            MHS2Nilai(MHS2dua),
            MHS2Nilai(MHS2tiga),
            MHS2Nilai(MHS2empat),
        ),
    )


def max2(a, b):
    return (a + b + abs(a - b)) // 2


def max4(i, j, k, l):
    return max2(max2(i, j), max2(k, l))


def min2(a, b):
    return (a + b - abs(a - b)) // 2


def min4(i, j, k, l):
    return min2(min2(i, j), min2(k, l))


# **************************************************************
# APLIKASI
# **************************************************************

print(hitungRangeNilai(
    MakeMHS2(24060124110142, "69", 100),
    MakeMHS2(24060124110142, "69", 43),
    MakeMHS2(24060124110142, "69", 76),
    MakeMHS2(24060124110142, "69", 69),
))

print("Kode Matkul:", RangeNilaiKodeMatkul(hitungRangeNilai(
    MakeMHS2(24060124110142, "69", 100),
    MakeMHS2(24060124110142, "69", 43),
    MakeMHS2(24060124110142, "69", 76),
    MakeMHS2(24060124110142, "69", 69),
)))

print("Nilai Tertinggi:", RangeNilaiNilaiTertinggi(hitungRangeNilai(
    MakeMHS2(24060124110142, "69", 100),
    MakeMHS2(24060124110142, "69", 43),
    MakeMHS2(24060124110142, "69", 76),
    MakeMHS2(24060124110142, "69", 69),
)))

print("Nilai Terendah:", RangeNilaiNilaiTerendah(hitungRangeNilai(
    MakeMHS2(24060124110142, "69", 100),
    MakeMHS2(24060124110142, "69", 43),
    MakeMHS2(24060124110142, "69", 76),
    MakeMHS2(24060124110142, "69", 69),
)))

print("Range Nilai:", RangeNilaiRangeNilai(hitungRangeNilai(
    MakeMHS2(24060124110142, "69", 100),
    MakeMHS2(24060124110142, "69", 43),
    MakeMHS2(24060124110142, "69", 76),
    MakeMHS2(24060124110142, "69", 69),
)))