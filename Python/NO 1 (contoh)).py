    # Program   : Jomokerto
    # Deskripsi : Mengembalikan emuach sebanyak n kali    
    # NIM/Nama  : 24060123140152/Kayis Hilmi Farih
    # Tanggal   : 10/31/2023
    # **************************************************************
    # DEFINISI DAN SPESIFIKASI
    # Jomokerto  : integer > 0 ---> string
    #       Jomokerto(n) mengembalikan kata 'emuach' sebanyak n kali 
    #       sehingga membentuk satu kata atau satu kalimat
    # **************************************************************
    # REALISASI
    # **************************************************************

def Jomokerto(n):
    return 'emuach' + ' emuach' * (n-1)
    
    # APLIKASI
    # **************************************************************

print(Jomokerto(10))