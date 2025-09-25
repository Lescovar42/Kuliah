# Program   : Tipe Bentukan Penanggalan
# Deskripsi : Didefinisikan suatu type Date yang terdiri dari thari, bulan dan tahun dan membentuk komposisi <Hr,Bln,Thn >.
# NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
# Tanggal   : 09/30/2024
# **************************************************************
# DEFINISI DAN SPESIFIKASI TYPE
# **************************************************************
# type Hr : integer[1..31]
    # {Definisi ini hanyalah untuk menamakan type integer dengan daerah nilai tertentu supaya mewakili hari}
# type Bln : integer[1..12]
    # {Definisi ini hanyalah untuk menamakan type integer dengan daerah nilai tertentu supaya mewakili bulan}
# type Thn : integer > 0
    # {Definisi ini hanyalah untuk menamakan type integer    yang lebih dari nol supaya mewakili tahun}
# type date : <d:Hr, m:Bln, y:Thn>
    # {<d,m,y> adalah tanggal d bulan m dan tahun y}
# **************************************************************
# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# **************************************************************
# MakeDate : Hr, Bln, Thn --> date
    # {MakeDate(Hr,Bln,Thn) Mengubah Hr, Bln, Thn menjadi tipe bentukan date, <Hr,Bln,Thn>}
# **************************************************************
# DEFINISI DAN SPESIFIKASI SELEKTOR
# **************************************************************
# Day : date --> Hr
    # {Day(D) memberikan hari d dari D yang terdiri dari <d,m,y>}
# Month : date --> Bln
    # {Month(D) memberikan bulan m dari D yang terdiri dari <d,m,y>}
# Year : date --> Thn
    # {Year(D) memberikan tahun y dari D yang terdiri dari <d,m,y>}
# **************************************************************
# DEFINISI DAN SPESIFIKASI FUNGSI OPERATOR
# **************************************************************
# NextDay : date --> date
    # {NextDay(D) menghitung date yang merupakan keesokan hari dari date D yang diberikan}
# Yesterday : date --> date
    # {Yesterday(D) menghitung date yang merupakan 1 hari sebelum date D yang diberikan}
# NextNDay : date, integer > 0 --> date
    # {NextNDay(D,n) menghitung date setelah n hari}
# dpm : Bln --> integer
    # {dpm(b) memberikan jumlah hari perbulan yang diakumulasikan dari bulan 1}
# Harike : Hr, Bln, Thn --> integer
    # {Harike(d,m,y) menghitung total hari yang dihitung dari 1 Januari di tahun terkait}
# pengurangan : integer, Thn --> date
    # {pengurangan(hari, y) menghitung total pengurangan total hari untuk mengembalikan date}
# **************************************************************
# DEFINISI DAN SPESIFIKASI FUNGSI PREDIKAT
# **************************************************************
# isBefore : 2 date --> boolean
    # {isBefore(D1,D2) bernilai benar jika date D1 sebelum date D2}
# isAfter : 2 date --> boolean
    # {isAfter(D1,D2) bernilai benar jika date D1 setelah date D2} 
# isEq : 2 date --> boolean
    # {isEq(D1,D2) bernilai benar jika date D1 sama dengan date D2}
# isKabisat : integer --> boolean
    # {isKabisat(y) benar jika y habis dibagi 4 dan tidak habis dibagi 100, atau habis dibagi 400}
# **************************************************************
# REALISASI
# **************************************************************
def MakeDate(Hr,Bln,Thn) :
    return [Hr,Bln,Thn]

def Day(D):
    return D[0]

def Month(D):
    return D[1]

def Year(D):
    return D[2]

def isBefore(D1,D2):
    if (Year(D1) != Year(D2)):
        return Year(D1) < Year(D2)
    elif (Month(D1) != Month(D2)) :
        return Month(D1) < Month(D2)
    else :
        return Day(D1) < Day(D2)

def isAfter(D1,D2) :
    if (Year(D1) != Year(D2)):
        return Year(D1) > Year(D2)
    elif (Month(D1) != Month(D2)) :
        return Month(D1) > Month(D2)
    else :
        return Day(D1) > Day(D2)

def isKabisat (Y) :
    return (Y % 4 == 0 and Y % 100 != 0) or (Y % 400 == 0)

def isEq(D1,D2) :
    return (Year(D1) == Year(D2)) and (Month(D1) == Month(D2)) and (Day(D1) == Day(D2))

def NextDay(D) :
    if (Month(D) in [1,3,5,7,8,10]) :
        if Day(D) < 31 :
            return MakeDate(Day(D) + 1, Month(D), Year(D))
        else :
            return MakeDate(1, Month(D) + 1, Year(D))
    
    elif Month(D) == 2:
        if Day(D) < 28 :
            return MakeDate(Day(D) + 1, Month(D), Year(D))
        elif Day(D) == 28 and isKabisat(Year(D)):
            return MakeDate(Day(D) + 1, Month(D), Year(D))
        else :
            return MakeDate(1, Month(D) + 1, Year(D))
    
    elif (Month(D) in [4,6,9,11]) :
        if Day(D) < 30:
            return MakeDate(Day(D) + 1, Month(D), Year(D))
        else :
            return MakeDate(1, Month(D) + 1, Year(D))
    
    elif Month(D) == 12:
        if Day(D) < 31:
            return MakeDate(Day(D) + 1, Month(D), Year(D))
        else:
            return MakeDate(1,1,Year(D) + 1)
        
def Yesterday(D) :
    if Day(D) == 1:
        if (Month(D) in [5,7,10,12]) :
            return MakeDate(30,Month(D) - 1, Year(D))
        elif (Month(D) in [2,4,6,8,9,11]) :
            return MakeDate(31, Month(D) - 1, Year(D))
        elif Month(D) == 3:
            if isKabisat(Year(D)) :
                return MakeDate(29, Month(D) - 1, Year(D))
            else :
                return MakeDate(28, Month(D) - 1, Year(D))
        elif Month(D) == 1:
            return MakeDate(31,12,Year(D) - 1)
    else :
        return MakeDate(Day(D) - 1, Month(D), Year(D))

def dpm (b) : 
    if b == 1:
        return 1
    elif b == 2:
        return 32
    elif b == 3:
        return 60
    elif b == 4 : 
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
    elif b == 12 :
        return 335

def Harike (d,m,y):
    if isKabisat(y) and m > 2:
        return dpm(m) + d
    else :
        return dpm(m) + d - 1
   

def pengurangan(hari,y):
    if hari > (306 + (29 if isKabisat(y) else 28)):
        return MakeDate(hari - (306 + (29 if isKabisat(y) else 28)),12,y)
    elif hari > (276 + (29 if isKabisat(y) else 28)):
        return MakeDate(hari - (276 + (29 if isKabisat(y) else 28)),11,y)
    elif hari > (245 + (29 if isKabisat(y) else 28)):
        return MakeDate(hari -  (245 + (29 if isKabisat(y) else 28)),10,y)
    elif hari > (215 + (29 if isKabisat(y) else 28)):
        return MakeDate(hari -  (215 + (29 if isKabisat(y) else 28)),9,y)
    elif hari >  (184 + (29 if isKabisat(y) else 28)):
        return MakeDate(hari - (184 + (29 if isKabisat(y) else 28)),8,y)
    elif hari > (153 + (29 if isKabisat(y) else 28)):
        return MakeDate(hari -  (153 + (29 if isKabisat(y) else 28)),7,y)
    elif hari > (123 + (29 if isKabisat(y) else 28)):
        return MakeDate(hari - (123 + (29 if isKabisat(y) else 28)),6,y)
    elif hari > (92 + (29 if isKabisat(y) else 28)):
        return MakeDate(hari - (92 + (29 if isKabisat(y) else 28)),5,y)
    elif hari >  (62 + (29 if isKabisat(y) else 28)) :
        return MakeDate(hari - (62 + (29 if isKabisat(y) else 28)),4,y)
    elif hari > (31 + (29 if isKabisat(y) else 28)) :
        return MakeDate(hari -  (31 + (29 if isKabisat(y) else 28)), 3, y)
    elif hari > 31:
        return MakeDate(hari - 31, 2, y)
    
def NextNDay(D,n):
    
    if (Harike(Day(D) + n, Month(D),Year(D))) > (366 if isKabisat(Year(D)) else 365):
        return pengurangan(Harike(Day(D) + n, Month(D),Year(D)) 
                           - (366 if isKabisat(Year(D)) else 365)
                           ,Year(D) + 1
                           )
    elif Harike(Day(D) + n, Month(D),Year(D)) <= 31:
        return MakeDate(Harike(Day(D) + n, Month(D),Year(D)),1,Year(D))
    else:
        return pengurangan(Harike(Day(D) + n, Month(D),Year(D)),Year(D))
# **************************************************************
# APLIKASI
# **************************************************************
print(NextNDay(MakeDate(1,1,1999),10))
print(Yesterday(MakeDate(11,1,2000)))
print(Yesterday(MakeDate(12,1,2001)))
print(NextDay(MakeDate(12,12,2000)))
print(NextDay(MakeDate(31,12,2001)))
print(isAfter(MakeDate(18,2,2000),MakeDate(18,3,2999)))
print(isBefore(MakeDate(3,11,2021),MakeDate(4,12,2024)))
print(isEq(MakeDate(12,3,2000),MakeDate(12,3,2000)))
print(isKabisat(2000))