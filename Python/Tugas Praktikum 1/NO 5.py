    # Program   : Jarak Dua Titik, Least Square
    # Deskripsi : fx2 adalah sebuah fungsi yang menerima dua buah bilangan riil dan dif2 menghasilkan  
    #             pangkat dua dari selisih kedua bilangan riil tersebut. Setelah itu akan dilakukan teorema pythagoras untuk mengetahui jarak dua titik.
    #             Fungsi-fungsi tersebut akan menghasilkan hasil akhir jarak dua titik di sebuah koordinat.
    # NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
    # Tanggal   : 09/02/2024
    # **************************************************************
    # DEFINISI DAN SPESIFIKASI
    # LS : 4 real ---> real
    #   LS(x1,y1,y2,y2) adalah jarak antara dua buah titik (x1,x2) dengan (y1,y2)
    # 
    # dif2 : 2 real ---> real
    #   dif(x,y) adalah kuadrat dari selsih antara x dan y
    # 
    # fx2 : real ---> real
    #   fx2(x) adalah hasil kuadrat dari variabel x (bilangan real)
    #
    # **************************************************************
    # REALISASI
    # **************************************************************
def fx2(x):
    return x*x
def dif2(x,y):
    return fx2(x-y)
def LS (x1,y1,x2,y2):
    return (dif2(y2,y1) + dif2(x2,x1))**0.5

    # APLIKASI
    # **************************************************************

print (LS(42,0,6,9))