import numpy as np
import scipy.stats as stats
import seaborn as sns
import matplotlib.pyplot as plt

# --- Parameter dari contoh soal ---
mu0 = 500      # Rata-rata populasi di bawah H0 (klaim perusahaan)
x_bar = 495    # Rata-rata sampel
sigma = 10     # Standar deviasi populasi (diketahui)
n = 36         # Ukuran sampel
alpha = 0.05   # Tingkat signifikansi

# --- Perhitungan Uji Z ---
# 1. Standar Error (SE)
SE = sigma / np.sqrt(n)

# 2. Z-statistik
Z_stat = (x_bar - mu0) / SE

# 3. P-value (untuk uji dua arah)
p_value = 2 * stats.norm.cdf(-np.abs(Z_stat)) # P(Z <= -|Z_stat|) atau P(Z >= |Z_stat|)

# 4. Nilai Kritis Z
Z_crit_lower = stats.norm.ppf(alpha / 2)
Z_crit_upper = stats.norm.ppf(1 - alpha / 2)

# 5. Nilai Kritis pada skala data (gram)
crit_val_lower_data = mu0 + Z_crit_lower * SE
crit_val_upper_data = mu0 + Z_crit_upper * SE

# --- Menyiapkan data untuk plot distribusi sampling di bawah H0 ---
# Kita akan memplot distribusi normal dengan rata-rata mu0 dan standar deviasi SE
x_values = np.linspace(mu0 - 4*SE, mu0 + 4*SE, 500)
y_values_pdf = stats.norm.pdf(x_values, loc=mu0, scale=SE)

# --- Membuat Visualisasi dengan Seaborn dan Matplotlib ---
plt.figure(figsize=(12, 7))
sns.set_style("whitegrid")

# Plot distribusi sampling di bawah H0
sns.lineplot(x=x_values, y=y_values_pdf, label=f'Distribusi Sampling Rata-rata di bawah H₀\n(μ₀={mu0}g, SE={SE:.2f}g)', color='royalblue', lw=2)

# Area penolakan (kiri)
plt.fill_between(x_values, 0, y_values_pdf, where=(x_values <= crit_val_lower_data), color='salmon', alpha=0.5, label=f'Daerah Penolakan (α/2 = {alpha/2:.3f})')

# Area penolakan (kanan)
plt.fill_between(x_values, 0, y_values_pdf, where=(x_values >= crit_val_upper_data), color='salmon', alpha=0.5)

# Garis vertikal untuk rata-rata hipotesis (μ0)
plt.axvline(mu0, color='green', linestyle='--', lw=2, label=f'Rata-rata H₀ (μ₀) = {mu0}g')

# Garis vertikal untuk rata-rata sampel (x_bar)
plt.axvline(x_bar, color='purple', linestyle='-', lw=2, label=f'Rata-rata Sampel (x̄) = {x_bar}g\nZ-stat = {Z_stat:.2f}')

# Garis vertikal untuk nilai kritis
plt.axvline(crit_val_lower_data, color='red', linestyle=':', lw=1.5, label=f'Nilai Kritis Bawah = {crit_val_lower_data:.2f}g')
plt.axvline(crit_val_upper_data, color='red', linestyle=':', lw=1.5, label=f'Nilai Kritis Atas = {crit_val_upper_data:.2f}g')


# Anotasi P-value
plt.text(mu0 - 3.5*SE, max(y_values_pdf)*0.8, f'P-value = {p_value:.4f}', fontsize=12, color='darkred')

# Judul dan Label
plt.title(f'Visualisasi Uji Z Dua Arah (α = {alpha})\nBerat Kotak Sereal', fontsize=16)
plt.xlabel('Berat Rata-rata Sampel (gram)', fontsize=14)
plt.ylabel('Kepadatan Probabilitas (PDF)', fontsize=14)
plt.legend(fontsize=10, loc='upper right')
plt.grid(True, which='both', linestyle='--', alpha=0.7)

# Menampilkan plot
plt.show()

# Mencetak hasil uji
print("--- Hasil Uji Hipotesis ---")
print(f"Rata-rata Populasi H₀ (μ₀): {mu0} g")
print(f"Rata-rata Sampel (x̄): {x_bar} g")
print(f"Standar Deviasi Populasi (σ): {sigma} g")
print(f"Ukuran Sampel (n): {n}")
print(f"Standar Error (SE): {SE:.4f} g")
print(f"Z-statistik (Z_stat): {Z_stat:.4f}")
print(f"P-value (dua arah): {p_value:.4f}")
print(f"Tingkat Signifikansi (α): {alpha}")
print(f"Nilai Z Kritis (bawah): {Z_crit_lower:.4f}")
print(f"Nilai Z Kritis (atas): {Z_crit_upper:.4f}")
print(f"Nilai Kritis Data (bawah): {crit_val_lower_data:.4f} g")
print(f"Nilai Kritis Data (atas): {crit_val_upper_data:.4f} g")

if p_value < alpha:
    print("\nKeputusan: Tolak Hipotesis Nol (H₀).")
    print(f"Ada cukup bukti pada tingkat signifikansi {alpha*100}% untuk menyatakan bahwa berat rata-rata kotak sereal tidak sama dengan {mu0} gram.")
else:
    print("\nKeputusan: Gagal Tolak Hipotesis Nol (H₀).")
    print(f"Tidak ada cukup bukti pada tingkat signifikansi {alpha*100}% untuk menyatakan bahwa berat rata-rata kotak sereal tidak sama dengan {mu0} gram.")