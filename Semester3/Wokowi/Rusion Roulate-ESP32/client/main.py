import tkinter as tk
import paho.mqtt.client as mqtt
import random

# --- MQTT setup ---
broker = "broker.hivemq.com"
topic = "AKM_RUSSIAN_ROULATE"
client = mqtt.Client()
client.connect(broker, 1883, 60)
client.loop_start()

# --- Game parameters ---
NUM_CHAMBERS = 5
BULLET_COUNT = 1  # jumlah peluru isi (default 1)

# --- State variables (global, non-OOP) ---
bullet_positions = set()
current_index = 0
game_over = False

# --- Tkinter UI setup ---
root = tk.Tk()
root.title("Russian Roulette - IoT")

main_frame = tk.Frame(root, padx=20, pady=20)
main_frame.pack(expand=True)

status_label = tk.Label(main_frame, text="Status: Siap", font=("Arial", 12))
status_label.pack(pady=8)

chambers_frame = tk.Frame(main_frame)
chambers_frame.pack(pady=8)

chamber_labels = []
for i in range(NUM_CHAMBERS):
    lbl = tk.Label(chambers_frame, text=f"[{i+1}]", width=6, relief="ridge")
    lbl.pack(side="left", padx=4)
    chamber_labels.append(lbl)

btn_frame = tk.Frame(main_frame)
btn_frame.pack(pady=8)

shoot_self_btn = tk.Button(btn_frame, text="Tembak Diri", width=12, bg="black", fg="white")
shoot_self_btn.pack(side="left", padx=6)

shoot_away_btn = tk.Button(btn_frame, text="Tembak Keluar", width=12, bg="orange", fg="black")
shoot_away_btn.pack(side="left", padx=6)

control_frame = tk.Frame(main_frame)
control_frame.pack(pady=10)

reset_btn = tk.Button(control_frame, text="Reset (Acak ulang)")
reset_btn.pack(side="left", padx=6)

spin_btn = tk.Button(control_frame, text="Spin (acak posisi sekarang)")
spin_btn.pack(side="left", padx=6)


# --- Functions (non-OOP) ---
def update_chamber_visual():
    """Tampilkan relief berbeda pada chamber yang sedang dipilih."""
    for i, lbl in enumerate(chamber_labels):
        if i == current_index:
            lbl.config(relief="solid", bd=3)
        else:
            lbl.config(relief="ridge", bd=1)


def disable_buttons():
    """Non-aktifkan tombol aksi saat game over — termasuk spin."""
    shoot_self_btn.config(state="disabled")
    shoot_away_btn.config(state="disabled")
    spin_btn.config(state="disabled")  


def enable_buttons():
    """Aktifkan kembali tombol aksi (dipanggil saat reset)."""
    shoot_self_btn.config(state="normal")
    shoot_away_btn.config(state="normal")
    spin_btn.config(state="normal")


def reset_game():
    """Mulai ulang game: acak posisi peluru dan index current."""
    global bullet_positions, current_index, game_over
    indices = list(range(NUM_CHAMBERS))
    bullet_positions = set(random.sample(indices, BULLET_COUNT))
    current_index = random.randrange(NUM_CHAMBERS)
    game_over = False
    update_chamber_visual()
    client.publish(topic, "3")
    status_label.config(text="Status: Game baru — siap menembak")
    enable_buttons() 


def spin_position():
    """Acak posisi current_index saja (peluru tetap)."""
    global current_index
    current_index = random.randrange(NUM_CHAMBERS)
    update_chamber_visual()
    status_label.config(text="Status: Cylinder diputar (spin).")


def advance_chamber():
    """Lanjutkan ke ruang berikutnya."""
    global current_index
    current_index = (current_index + 1) % NUM_CHAMBERS
    update_chamber_visual()


def shoot_self():
    """Aksi ketika pemain memilih menembak diri sendiri."""
    global game_over
    if game_over:
        return
    if current_index in bullet_positions:
        client.publish(topic, "2") 
        status_label.config(text=f"Status: PELURU! Kamu MATI. (Ruang #{current_index+1})")
        game_over = True
        disable_buttons()
    else:
        client.publish(topic, "3")  
        status_label.config(text=f"Status: Kosong — kamu selamat. (Ruang #{current_index+1})")
        advance_chamber()


def shoot_away():
    """Aksi ketika pemain memilih menembak keluar (away)."""
    global game_over
    if game_over:
        return
    if current_index in bullet_positions:
        client.publish(topic, "1") 
        status_label.config(text=f"Status: Peluru keluar — kamu SELAMAT! (Ruang #{current_index+1})")
        game_over = True
        disable_buttons()  
    else:

        client.publish(topic, "3") 
        status_label.config(text=f"Status: Tidak ada peluru — tidak terjadi apa-apa. (Ruang #{current_index+1})")
        advance_chamber()


# --- Bind tombol ke fungsi ---
shoot_self_btn.config(command=shoot_self)
shoot_away_btn.config(command=shoot_away)
reset_btn.config(command=reset_game)
spin_btn.config(command=spin_position)

# --- Inisialisasi pertama ---
reset_game()

# --- Mainloop ---
root.mainloop()
