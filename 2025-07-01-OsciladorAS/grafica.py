import matplotlib.pyplot as plt
import numpy as np

# read data
fig, ax = plt.subplots(figsize=(12, 7))
x1, v1 = np.loadtxt("output-euler.txt", unpack=True)
x2, v2 = np.loadtxt("output-heun.txt", unpack=True)

ax.plot(x1, v1, color='royalblue', linewidth = 2, linestyle = '-', markersize = 5, label = 'Euler')
ax.plot(x2, v2, color='red', linewidth = 2, linestyle = '-', markersize = 5, label = 'Heun')

ax.set_xlabel('Posición x', fontsize = 12)
ax.set_ylabel('Velocidad $v$', fontsize = 12)
ax.set_title('Métodos Euler y Heun para el Oscilador Armónico Lineal', fontsize = 14, pad = 20, color = 'black')
ax.legend()
ax.grid(True, linestyle='-', alpha=0.7)
fig.savefig('grafica.pdf')
plt.show()