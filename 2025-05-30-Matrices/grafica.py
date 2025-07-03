import matplotlib.pyplot as plt
import numpy as np

# read data
N, t = np.loadtxt("resultados.txt", unpack=True)
fig, ax = plt.subplots(figsize=(12, 7))

ax.plot(N, t, color='royalblue', linewidth = 2, linestyle = '-', marker = 'o', markersize = 5, label = 'Datos experimentales')
ax.set_xlabel('N', fontsize = 12)
#ax.set_xlim(0.5e15, 1.22e15)
#ax.set_ylim(0.2, 3.4)
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_ylabel('Tiempo Normalizado', fontsize = 12)
ax.set_title('N vs t', fontsize = 14, pad = 20, color = 'black')
ax.legend()
ax.grid(True, linestyle='-', alpha=0.7)
fig.savefig('grafica.pdf')
plt.show()