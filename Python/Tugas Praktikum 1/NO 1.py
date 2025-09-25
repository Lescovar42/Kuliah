    # Program   : Mean Olypmique (MO)
    # Deskripsi : Definisikan sebuah fungsi yang menerima 4 bilangan bulat positif, menghasilkan harga rata-rata dari dua 
    #             di antara empat buah bilangan tersebut, dengan mengabaikan nilai terbesar dan nilai terkecil. 
    # NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
    # Tanggal   : 09/02/2024
    # **************************************************************
    # DEFINISI DAN SPESIFIKASI
    #   Mean Olypmique (MO)  : 4 integer > 0 ----> real
    #   MO menghitung rata-rata dari dua buah bilangan integer, yang bukan maksimum dan dan bukan minimum dari 4 buah integer:
    #   (k+l+m+n-min4(w,x,y,z)-max4(w,x,y,z))/2
    # 
    # max4 : 4 int > 0 ---> int
    #   min4 (w,x,y,z) menentukan maximum dari 4 buah bilangan integer
    # 
    # min4 : 4 int > 0 ---> int
    #   min4 (w,x,y,z) menentukan minimum dari 4 buah bilangan integer
    # 
    # max2 : 2 int > 0 ---> int
    #   max2 (a,b) menentukan maksimum dari 2 bilangan integer, hanya dengan ekspresi aritmatika:  
    #   jumlah dari kedua bilangan ditambah dengan selisih kedua bilangan, hasilnya dibagi 2
    # 
    # min2 : 2 int > 0 ---> int
    #   min2 (a,b) menentukan minimum dari 2 bilangan integer, hanya dengan ekspresi aritmatika:
    #   jumlah dari kedua bilangan - selisih kedua bilangan, hasilnya dibagi 2
    # **************************************************************
    # REALISASI
    # **************************************************************
def max2(a,b):
     return ((a+b) + abs(a-b)) / 2

def max4(w,x,y,z):
    return max2(max2(w,x),max2(y,z))

def min2(a,b):
     return ((a+b) - abs(a-b)) / 2

def min4(w,x,y,z):
    return min2(min2(w,x),min2(y,z))

def MO(k,l,m,n):
     return (k+l+m+n-min4(k,l,m,n) - max4(k,l,m,n)) / 2

    # APLIKASI
    # **************************************************************

print(MO(11,23,45,21))