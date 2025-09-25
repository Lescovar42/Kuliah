# Nama File: SearchJadwal.py
# Nama / NIM: Kasane Teto
# Tanggal:

def overlap(awal: int, akhir: int, jAwal: int, jAkhir: int) -> bool:
    return (awal >= jAwal) or (akhir <= jAkhir)

def SearchJadwal(hari: str, awal: int, akhir: int) -> str:
    if hari == "sen":
        if overlap(awal, akhir, 13, 15):
            return "Dasar Pemrograman"
        else:
            return "Tidak ada"

    elif hari == "sel":
        if overlap(awal, akhir, 13, 15):
            return "Aljabar Linier"
        else:
            return "Tidak ada"

    elif hari == "rab":
        if overlap(awal, akhir, 7, 10) and overlap(awal, akhir, 15, 16):
            return "Dasar Sistem & Bahasa Inggris I"
        elif overlap(awal, akhir, 7, 10):
            return "Dasar Sistem"
        elif overlap(awal, akhir, 15, 16):
            return "Bahasa Inggris I"
        else:
            return "Tidak ada"

    elif hari == "kam":
        if overlap(awal, akhir, 7, 9) and overlap(awal, akhir, 13, 15):
            return "Pancasila & Matematika I"
        elif overlap(awal, akhir, 7, 9):
            return "Pancasila"
        elif overlap(awal, akhir, 13, 15):
            return "Matematika I"
        else:
            return "Tidak ada"

    elif hari == "jum":
        if overlap(awal, akhir, 7, 9) and overlap(awal, akhir, 13, 16):
            return "Bahasa Indonesia & Struktur Diskrit"
        elif overlap(awal, akhir, 7, 9):
            return "Bahasa Indonesia"
        elif overlap(awal, akhir, 13, 16):
            return "Struktur Diskrit"
        else:
            return "Tidak ada"

    else:
        return "Tidak ada"

#JANGAN DIUBAH!
print(SearchJadwal("kam", 1,24))