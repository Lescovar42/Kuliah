import numpy as np
import scipy.stats as stats
import seaborn as sns
import matplotlib.pyplot as plt

# --- Parameter dari contoh soal ---
mu0 = 15       # Rata-rata populasi di bawah H0 (batas hipotesis)
x_bar = 16     # Rata-rata sampel
sigma = 4      # Standar deviasi populasi (diketahui)
n = 40         # Ukuran sampel
alpha = 0.05   # Tingkat signifikansi (untuk uji arah kanan)

# --- Perhitungan Uji Z ---
# 1. Standar Error (SE)
SE = sigma / np.sqrt(n)

# 2. Z-statistik
Z_stat = (x_bar - mu0) / SE

# 3. P-value (untuk uji arah kanan)
p_value = 1 - stats.norm.cdf(Z_stat) # P(Z > Z_stat)

# 4. Nilai Kritis Z (untuk uji arah kanan)
Z_crit_upper = stats.norm.ppf(1 - alpha)

# 5. Nilai Kritis pada skala data (jam)
crit_val_upper_data = mu0 + Z_crit_upper * SE

# --- Menyiapkan data untuk plot distribusi sampling di bawah H0 ---
# Distribusi normal dengan rata-rata mu0 dan standar deviasi SE
x_values = np.linspace(mu0 - 4*SE, mu0 + 4*SE, 500)
y_values_pdf = stats.norm.pdf(x_values, loc=mu0, scale=SE)

# --- Membuat Visualisasi dengan Seaborn dan Matplotlib ---
plt.figure(figsize=(12, 7))
sns.set_style("whitegrid")

# Plot distribusi sampling di bawah H0
sns.lineplot(x=x_values, y=y_values_pdf, label=f'Distribusi Sampling Rata-rata di bawah H₀\n(μ₀={mu0} jam, SE={SE:.2f} jam)', color='royalblue', lw=2)

# Area penolakan (kanan)
plt.fill_between(x_values, 0, y_values_pdf, where=(x_values >= crit_val_upper_data), color='salmon', alpha=0.5, label=f'Daerah Penolakan (α = {alpha:.2f})')

# Garis vertikal untuk rata-rata hipotesis (μ0)
plt.axvline(mu0, color='green', linestyle='--', lw=2, label=f'Batas H₀ (μ₀) = {mu0} jam')

# Garis vertikal untuk rata-rata sampel (x_bar)
plt.axvline(x_bar, color='purple', linestyle='-', lw=2, label=f'Rata-rata Sampel (x̄) = {x_bar} jam\nZ-stat = {Z_stat:.3f}')

# Garis vertikal untuk nilai kritis
plt.axvline(crit_val_upper_data, color='red', linestyle=':', lw=1.5, label=f'Nilai Kritis Data = {crit_val_upper_data:.2f} jam\n(Z-kritis = {Z_crit_upper:.3f})')

# Anotasi P-value
# Menyesuaikan posisi teks p-value agar tidak tumpang tindih
text_x_position = mu0 + 2.5*SE
text_y_position = max(y_values_pdf) * 0.6
if x_bar > crit_val_upper_data: # Jika x_bar di daerah penolakan, geser teks
    text_x_position = mu0 - 3.5*SE

plt.text(text_x_position, text_y_position, f'P-value = {p_value:.4f}', fontsize=12, color='darkred', ha='left')


# Judul dan Label
plt.title(f'Visualisasi Uji Z Satu Arah (Kanan) (α = {alpha})\nWaktu Belajar Mahasiswa per Minggu', fontsize=16)
plt.xlabel('Rata-rata Waktu Belajar Sampel (Jam/Minggu)', fontsize=14)
plt.ylabel('Kepadatan Probabilitas (PDF)', fontsize=14)
plt.legend(fontsize=10, loc='upper left') # Mengubah lokasi legenda agar tidak tumpang tindih
plt.grid(True, which='both', linestyle='--', alpha=0.7)

# Menampilkan plot
plt.tight_layout() # Menyesuaikan layout agar tidak ada yang terpotong
plt.show()

# Mencetak hasil uji
print("--- Hasil Uji Hipotesis Waktu Belajar Mahasiswa ---")
print(f"Hipotesis Nol (H₀): μ ≤ {mu0} jam")
print(f"Hipotesis Alternatif (H₁): μ > {mu0} jam")
print(f"Rata-rata Sampel (x̄): {x_bar} jam")
print(f"Standar Deviasi Populasi (σ): {sigma} jam")
print(f"Ukuran Sampel (n): {n}")
print(f"Standar Error (SE): {SE:.4f} jam")
print(f"Z-statistik (Z_stat): {Z_stat:.4f}")
print(f"P-value (satu arah kanan): {p_value:.4f}")
print(f"Tingkat Signifikansi (α): {alpha}")
print(f"Nilai Z Kritis (atas): {Z_crit_upper:.4f}")
print(f"Nilai Kritis Data (atas): {crit_val_upper_data:.4f} jam")

if p_value < alpha:
    print("\nKeputusan: Tolak Hipotesis Nol (H₀).")
    print(f"Ada cukup bukti pada tingkat signifikansi {alpha*100}% untuk menyatakan bahwa rata-rata waktu belajar mahasiswa lebih dari {mu0} jam per minggu.")
else:
    print("\nKeputusan: Gagal Tolak Hipotesis Nol (H₀).")
    print(f"Tidak ada cukup bukti pada tingkat signifikansi {alpha*100}% untuk menyatakan bahwa rata-rata waktu belajar mahasiswa lebih dari {mu0} jam per minggu.")