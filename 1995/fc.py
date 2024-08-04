import tkinter as tk
from tkinter import ttk, messagebox
import numpy as np
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure

class NegativeValueError(Exception):
    pass

class ZeroValueError(Exception):
    pass

def check_negative(value):
    if value < 0:
        raise NegativeValueError("El valor ingresado debe ser mayor a 0")

def check_zero(value):
    if value == 0:
        raise ZeroValueError("El valor ingresado debe ser distinto de 0")

def distancia_MRU(v, t):
    check_negative(t)
    return v * t

def velocidad_MRU(d, t):
    check_negative(t)
    check_zero(t)
    return d / t

def tiempo_MRU(d, v):
    check_zero(v)
    return abs(d / v)

def distancia_MRUV(vi, t, a):
    check_negative(t)
    return vi * t + a * t ** 2 / 2

def velocidad_MRUV(vi, t, a):
    check_negative(t)
    return vi + a * t

def draw(vi, t, a):
    check_zero(t)
    check_negative(t)
    paso = t / 10
    tiempos = np.arange(0, t + paso, paso)
    x = [distancia_MRUV(vi, i, a) for i in tiempos]
    fig = Figure(figsize=(6, 4), dpi=100)
    ax = fig.add_subplot(111)
    ax.plot(tiempos, x)
    ax.set_title("Δx en función del tiempo")
    ax.set_xlabel("Tiempo (segundos)")
    ax.set_ylabel("Distancia (metros)")

    plot_frame = ttk.Frame(root)
    plot_frame.grid(row=17, column=0, columnspan=2, padx=10, pady=10)

    canvas = FigureCanvasTkAgg(fig, master=plot_frame)
    canvas.draw()
    canvas.get_tk_widget().pack()

def calcular():
    try:
        if opcion.get() == "MRU":
            tipo_calculo = tipo_calculo_mru.get()
            if tipo_calculo == "Distancia (Δx)":
                v = float(v_entry.get())
                t = float(t_entry.get())
                resultado = distancia_MRU(v, t)
                messagebox.showinfo("Resultado", f"Distancia (Δx): {resultado:.2f} m")
            elif tipo_calculo == "Velocidad (v)":
                d = float(d_entry.get())
                t = float(t_entry.get())
                resultado = velocidad_MRU(d, t)
                messagebox.showinfo("Resultado", f"Velocidad (v): {resultado:.2f} m/s")
            elif tipo_calculo == "Tiempo (Δt)":
                d = float(d_entry.get())
                v = float(v_entry.get())
                resultado = tiempo_MRU(d, v)
                messagebox.showinfo("Resultado", f"Tiempo (Δt): {resultado:.2f} s")
        elif opcion.get() == "MRUV":
            tipo_calculo = tipo_calculo_mruv.get()
            vi = float(vi_entry.get())
            t = float(t_entry.get())
            a = float(a_entry.get())
            if tipo_calculo == "Distancia (Δx)":
                resultado = distancia_MRUV(vi, t, a)
                messagebox.showinfo("Resultado", f"Distancia (Δx): {resultado:.2f} m")
            elif tipo_calculo == "Velocidad final (Vf)":
                resultado = velocidad_MRUV(vi, t, a)
                messagebox.showinfo("Resultado", f"Velocidad final (Vf): {resultado:.2f} m/s")
            elif tipo_calculo == "Gráfica de Δx en función de Δt":
                draw(vi, t, a)
    except ValueError:
        messagebox.showerror("Error", "Ingrese valores numéricos válidos")
    except NegativeValueError as e:
        messagebox.showerror("Error", str(e))
    except ZeroValueError as e:
        messagebox.showerror("Error", str(e))

# Configuración de la interfaz gráfica
root = tk.Tk()
root.title("Ecuaciones de MRU y MRUV")

# Configuración del estilo
style = ttk.Style()
style.configure('TFrame', background='#f0f0f0')
style.configure('TLabel', background='#f0f0f0')
style.configure('TRadiobutton', background='#f0f0f0')

# Variables
opcion = tk.StringVar()
tipo_calculo_mru = tk.StringVar()
tipo_calculo_mruv = tk.StringVar()

# Widgets
opcion_label = ttk.Label(root, text="Seleccione el tipo de movimiento:")
opcion_label.grid(row=1, column=0, padx=10, pady=10, sticky="w")

opcion_mru_radio = ttk.Radiobutton(root, text="MRU", variable=opcion, value="MRU")
opcion_mru_radio.grid(row=2, column=0, padx=10, pady=5, sticky="w")

opcion_mruv_radio = ttk.Radiobutton(root, text="MRUV", variable=opcion, value="MRUV")
opcion_mruv_radio.grid(row=3, column=0, padx=10, pady=5, sticky="w")

tipo_calculo_mru_label = ttk.Label(root, text="Seleccione el valor a calcular (MRU):")
tipo_calculo_mru_label.grid(row=4, column=0, padx=10, pady=10, sticky="w")

tipo_calculo_mru_distancia_radio = ttk.Radiobutton(root, text="Distancia (Δx)", variable=tipo_calculo_mru, value="Distancia (Δx)")
tipo_calculo_mru_distancia_radio.grid(row=5, column=0, padx=10, pady=5, sticky="w")

tipo_calculo_mru_velocidad_radio = ttk.Radiobutton(root, text="Velocidad (v)", variable=tipo_calculo_mru, value="Velocidad (v)")
tipo_calculo_mru_velocidad_radio.grid(row=6, column=0, padx=10, pady=5, sticky="w")

tipo_calculo_mru_tiempo_radio = ttk.Radiobutton(root, text="Tiempo (Δt)", variable=tipo_calculo_mru, value="Tiempo (Δt)")
tipo_calculo_mru_tiempo_radio.grid(row=7, column=0, padx=10, pady=5, sticky="w")

tipo_calculo_mruv_label = ttk.Label(root, text="Seleccione el valor a calcular (MRUV):")
tipo_calculo_mruv_label.grid(row=8, column=0, padx=10, pady=10, sticky="w")

tipo_calculo_mruv_distancia_radio = ttk.Radiobutton(root, text="Distancia (Δx)", variable=tipo_calculo_mruv, value="Distancia (Δx)")
tipo_calculo_mruv_distancia_radio.grid(row=9, column=0, padx=10, pady=5, sticky="w")

tipo_calculo_mruv_velocidad_radio = ttk.Radiobutton(root, text="Velocidad final (Vf)", variable=tipo_calculo_mruv, value="Velocidad final (Vf)")
tipo_calculo_mruv_velocidad_radio.grid(row=10, column=0, padx=10, pady=5, sticky="w")

# Entradas
d_label = ttk.Label(root, text="Distancia (d):")
d_label.grid(row=11, column=0, padx=10, pady=5, sticky="w")
d_entry = ttk.Entry(root)
d_entry.grid(row=11, column=1, padx=10, pady=5)

v_label = ttk.Label(root, text="Velocidad (v):")
v_label.grid(row=12, column=0, padx=10, pady=5, sticky="w")
v_entry = ttk.Entry(root)
v_entry.grid(row=12, column=1, padx=10, pady=5)

t_label = ttk.Label(root, text="Tiempo (t):")
t_label.grid(row=13, column=0, padx=10, pady=5, sticky="w")
t_entry = ttk.Entry(root)
t_entry.grid(row=13, column=1, padx=10, pady=5)

vi_label = ttk.Label(root, text="Velocidad inicial (vi):")
vi_label.grid(row=14, column=0, padx=10, pady=5, sticky="w")
vi_entry = ttk.Entry(root)
vi_entry.grid(row=14, column=1, padx=10, pady=5)

a_label = ttk.Label(root, text="Aceleración (a):")
a_label.grid(row=15, column=0, padx=10, pady=5, sticky="w")
a_entry = ttk.Entry(root)
a_entry.grid(row=15, column=1, padx=10, pady=5)

# Botón de cálculo
calcular_button = ttk.Button(root, text="Calcular", command=calcular)
calcular_button.grid(row=16, column=0, columnspan=2, padx=10, pady=10)

root.mainloop()
