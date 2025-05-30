import matplotlib.pyplot as plt
import numpy as np

# read data
xp, yp = np.loadtxt("datosPolinomio.txt", unpack=True)
fig, ax = plt.subplots(figsize=(12, 7))
xd, yd = np.loadtxt("datosDerivada.txt", unpack=True)


ax.plot(xp, yp, color='darkblue', linewidth = 2, linestyle = '-', label = 'Grafica polinomio')
ax.plot(xd, yd, color='red', linewidth = 2, linestyle = '-', label = 'Grafica derivada')
ax.set_xlabel('x', fontsize = 12)
ax.set_xlim(-10, 10)
ax.set_ylim(-10, 10)
ax.set_ylabel('y', fontsize = 12)
ax.set_title('Polinomio y Derivada', fontsize = 14, pad = 20, color = 'black')
ax.legend()
ax.grid(True, linestyle='-', alpha=0.7)
fig.savefig('grafica.pdf')
plt.show()