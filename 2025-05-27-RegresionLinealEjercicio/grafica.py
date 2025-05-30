import matplotlib.pyplot as plt
import numpy as np

# read data
x, y = np.loadtxt("datos.txt", unpack=True)
fig, ax = plt.subplots(figsize=(12, 7))
m, b, deltam, deltab, h = np.loadtxt("resultados.txt", unpack=True)

# Generar valores x
x1 = np.linspace(0.5e15, 1.22e15, 100)  # 100 puntos entre -10 y 10
y2 = m * x1 + b  # Calcular y

ax.plot(x, y, color='royalblue', linewidth = 2, linestyle = '', marker = 'o', markersize = 5, label = 'Datos experimentales')
ax.plot(x1, y2, '-r', label=f'y = ({m} ± {deltam})x - ({-1*b} ± {deltab}) ') # Linea roja ('-r')
ax.plot(0, 0, ' ', label=f'h={h} J*s\nϕ={b} J')
ax.set_xlabel('Frecuencia (Hz)', fontsize = 12)
ax.set_xlim(0.5e15, 1.22e15)
ax.set_ylim(0.2, 3.4)
ax.set_ylabel('Voltaje (V)', fontsize = 12)
ax.set_title('Efecto fotoeléctrico: Voltaje vs Frecuencia', fontsize = 14, pad = 20, color = 'black')
ax.legend()
ax.grid(True, linestyle='-', alpha=0.7)
fig.savefig('grafica.pdf')
plt.show()