    # Program   : Is Valid
    # Deskripsi : Definisikan sebuah fungsi yang menerima sebuah bilangan bulat dan akan mengembalikan value boolean true ketika bilangan tersebut lebih dari 5 dan kurang dari 500
    # NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
    # Tanggal   : 09/02/2024
    # **************************************************************
    # DEFINISI DAN SPESIFIKASI
    # isValid : int ---> bool
    #   isValid menyatakan variable (x) true jika x bernilaih lebih kecil dari 5 atau lebih besar dari 500
    #       
    # **************************************************************
    # REALISASI
    # **************************************************************

def isValid(x):
    return 5 < x < 500

    # APLIKASI
    # **************************************************************

print(isValid(501))
print(isValid(500))
print(isValid(6))