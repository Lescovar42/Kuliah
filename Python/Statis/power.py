import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

def power_method(matrix_A, x0=None, tol=1e-9, max_iter=1000):
    """
    Implementasi Metode Pangkat untuk mencari nilai eigen dominan dan eigenvektornya.

    Args:
        matrix_A (np.ndarray): Matriks persegi input.
        x0 (np.ndarray, optional): Vektor awal. Jika None, akan dibuat vektor acak.
                                   Defaults to None.
        tol (float, optional): Toleransi untuk kriteria konvergensi.
                               Defaults to 1e-9.
        max_iter (int, optional): Jumlah maksimum iterasi.
                                  Defaults to 1000.

    Returns:
        tuple: (eigenvalue, eigenvector, eigenvalue_history)
               eigenvalue (float): Aproksimasi nilai eigen dominan.
               eigenvector (np.ndarray): Aproksimasi eigenvektor dominan.
               eigenvalue_history (list): Riwayat aproksimasi nilai eigen per iterasi.
    """
    n = matrix_A.shape[0]
    if matrix_A.shape[0] != matrix_A.shape[1]:
        raise ValueError("Matriks harus persegi.")

    if x0 is None:
        # Buat vektor awal acak jika tidak disediakan
        x = np.random.rand(n)
    else:
        x = np.array(x0, dtype=float)

    if x.shape[0] != n:
        raise ValueError(f"Vektor awal harus memiliki panjang {n}")

    x = x / np.linalg.norm(x) # Normalisasi vektor awal

    eigenvalue_old = 0.0
    eigenvalue_history = []

    print("Iterasi | Eigenvalue Aproksimasi | Perubahan Eigenvalue")
    print("-" * 60)

    for i in range(max_iter):
        # Perkalian matriks dengan vektor
        Ax = np.dot(matrix_A, x)

        # Aproksimasi nilai eigen (Rayleigh quotient)
        eigenvalue_new = np.dot(x.T, Ax) # Karena x sudah ternormalisasi (x.T @ x = 1)

        # Normalisasi vektor hasil untuk iterasi selanjutnya
        x_next = Ax / np.linalg.norm(Ax)

        eigenvalue_history.append(eigenvalue_new)
        change = np.abs(eigenvalue_new - eigenvalue_old)

        print(f"{i+1:^7} | {eigenvalue_new:^25.8f} | {change:^20.8e}")

        # Cek konvergensi
        if change < tol:
            print(f"\nKonvergensi tercapai setelah {i+1} iterasi.")
            return eigenvalue_new, x_next, eigenvalue_history

        eigenvalue_old = eigenvalue_new
        x = x_next

    print(f"\nMetode Pangkat tidak konvergen setelah {max_iter} iterasi.")
    return eigenvalue_new, x, eigenvalue_history

# --- Contoh Penggunaan ---
if __name__ == "__main__":
    # Definisikan matriks A (contoh)
    # Pastikan matriks memiliki nilai eigen dominan yang jelas untuk konvergensi yang baik
    # A = np.array([[4, 1, 1],
    #               [1, 3, -1],
    #               [1, -1, 2]])

    A = np.array([[2, -1, 0],
                  [-1, 2, -1],
                  [0, -1, 2]])

    # A = np.array([[5, 2],
    #               [2, 1]])

    print("Matriks A:")
    print(A)
    print("\nMemulai Metode Pangkat...\n")

    # Vektor awal (opsional)
    # x_initial = np.array([1.0, 1.0, 1.0])
    x_initial = None # Akan menggunakan vektor acak

    dominant_eigenvalue, dominant_eigenvector, history = power_method(A, x0=x_initial, tol=1e-7, max_iter=50)

    print("\n--- Hasil Metode Pangkat ---")
    print(f"Nilai Eigen Dominan Aproksimasi: {dominant_eigenvalue:.8f}")
    print(f"Eigenvektor Dominan Aproksimasi: {dominant_eigenvector}")

    # Verifikasi dengan NumPy (untuk perbandingan)
    eigenvalues_np, eigenvectors_np = np.linalg.eig(A)
    print("\n--- Hasil dari np.linalg.eig (untuk perbandingan) ---")
    print(f"Semua Nilai Eigen: {eigenvalues_np}")
    # Temukan indeks nilai eigen dengan magnitudo terbesar
    dominant_idx_np = np.argmax(np.abs(eigenvalues_np))
    print(f"Nilai Eigen Dominan (NumPy): {eigenvalues_np[dominant_idx_np]:.8f}")
    print(f"Eigenvektor Dominan (NumPy): {eigenvectors_np[:, dominant_idx_np]}")
    print("\nCatatan: Eigenvektor bisa berbeda tanda (arah) namun tetap valid.")

    # Visualisasi konvergensi nilai eigen menggunakan Seaborn dan Matplotlib
    if history:
        plt.figure(figsize=(10, 6))
        sns.lineplot(x=range(len(history)), y=history, marker='o', label='Aproksimasi Nilai Eigen')
        plt.axhline(dominant_eigenvalue, color='r', linestyle='--', label=f'Nilai Eigen Konvergen ({dominant_eigenvalue:.6f})')
        if 'dominant_idx_np' in locals(): # Cek jika verifikasi NumPy dijalankan
             plt.axhline(eigenvalues_np[dominant_idx_np], color='g', linestyle=':', label=f'Nilai Eigen NumPy ({eigenvalues_np[dominant_idx_np]:.6f})')
        plt.title('Konvergensi Nilai Eigen (Metode Pangkat)')
        plt.xlabel('Iterasi')
        plt.ylabel('Nilai Eigen Aproksimasi')
        plt.legend()
        plt.grid(True)
        plt.show()