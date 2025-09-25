# Nama File : MeanOlympique.py
# Pembuat   : Rafa Azlan
# Tanggal   : 2 September 2025
# Deskripsi : menghitung rata-rata dari dua buah bilangan yang bukan maksimum dan minimum dari 4 buah bilangan integer

# Definisi dan Spesifikasi:
# Mo : 4 integer >= 0 --> real
#   {MO (u,v,w,x) menghitung rata-rata dari dua buah bilangan integer yang bukan maksimum dan bukan minimum dari 4 buah integer: (u+v+w+x+min4(u,v,w,x)-max4(u,v,w,x))/2 }
# Max4 : 4 integer >= 0 --> integer >= 0
#   {max4 (i,j,k,l) menghasilkan nilai maksimum dari 4 bilangan integer}
# Min4 : 4 integer >= 0 --> integer >= 0
#   {min4 (i,j,k,l) menghasilkan nilai minimum dari 4 bilangan integer}
# Max2 : 2 integer >= 0 --> integer >= 0
#  {max2 (a,b) menentukan maksimum dari 2 bilangan integer, hanya dengan ekspresi aritmatika: jumlah dari kedua bilangan ditambah dengan selisih kedua bilangan, hasilnya dibagi 2}
# Min2 : 2 integer >= 0 --> integer >= 0
#  {min2 (a,b) menentukan minimum dari 2 bilangan integer, hanya dengan ekspresi aritmatika: jumlah dari kedua bilangan dikurangi dengan selisih kedua bilangan, hasilnya dibagi 2}

# Realisasi
def max2(a: int,b: int) -> int:
    return (a+b+abs(a-b))//2

def min2(a: int,b:int) -> int:
    return (a+b-abs(a-b))//2

def max4(i: int,j:int,k:int,l:int) -> int:
    return max2(max2(i,j), max2(k,l))

def min4(i:int, j:int,k:int,l:int) -> int:
    return min2(min2(i,j), min2(k,l))

def MO(u: int,v:int,w:int,x:int) -> float:
    return (u+v+w+x-min4(u,v,w,x)-max4(u,v,w,x))/2

# Aplikasi
print(MO(8,12,10,20)) # 11.0
print(MO(4,5,6,7)) # 5.5
print(MO(1,1,1,1,2)) # 1.0
