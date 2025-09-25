import pandas as pd

# Membaca dataset
df = pd.read_csv("C:/Users/asus/Kerja/Kuliah/Python/Latihan.csv")

# Menampilkan nama-nama kolom agar bisa memilih
print(df.columns)

# Misal kita pilih kolom 'Nilai'
mean_awal = df["Tipe1"].mean()
median_awal = df["Tipe1"].median()

print("Mean sebelum modifikasi:", mean_awal)
print("Median sebelum modifikasi:", median_awal)
