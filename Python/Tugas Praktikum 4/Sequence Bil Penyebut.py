# Program   : Sequence Bilangan Penyebut
# Deskripsi : Program untuk memeriksa apakah suatu bilangan bisa menjadi penyebut 
#             dari sebuah pecahan yang menghasilkan bilangan bulat jika pembilang 
#             terdiri dari digit berulang (misalnya 111, 222, dll).
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/16/2024
#**************************************************************
# DEFINISI DAN SPESIFIKASI
# **************************************************************
# denumeratorSeq : string => string
#   denumeratorSeq(x) menerima input string x yang merepresentasikan bilangan.
#   menentukan apakah urutan angka x terulang tersebut sesuai dengan 
#   desimal hasil pembagian 1 dengan sebuah bilangan bulat.
#   Jika iya, berapa nilai bilangan bulat pembagi tersebut? Jika tidak, akan keluarkan string “Tidak ada”
# **************************************************************
# REALISASI
# **************************************************************
def denumeratorSeq(x):
    if (((10**len(x))-1)/int(x)) % 1 == 0: #help
        return f"Ada: {int((10**len(x)-1)/int(x))}"
    else:
        return "Tidak ada"
# **************************************************************
# APLIKASI
# **************************************************************
print(denumeratorSeq('33'))